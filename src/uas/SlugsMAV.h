/*=====================================================================

QGroundControl Open Source Ground Control Station

(c) 2009, 2010 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>

This file is part of the QGROUNDCONTROL project

    QGROUNDCONTROL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    QGROUNDCONTROL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QGROUNDCONTROL. If not, see <http://www.gnu.org/licenses/>.

======================================================================*/

#ifndef _SLUGSMAV_H_
#define _SLUGSMAV_H_

#include "UAS.h"
#include "mavlink.h"
#include <QTimer>

#ifdef MAVLINK_ENABLED_SLUGS
#include "slugs/slugs.h"
#endif

class SlugsMAV : public UAS
{
    Q_OBJECT
    Q_INTERFACES(UASInterface)

public:
    SlugsMAV(MAVLinkProtocol* mavlink, int id = 0);
    //~SlugsMAV(void);
    /** @brief Gets current navigation mode value. */
    int getNavMode();
    /** @brief Sets the SLUGS navigation mode. */
    void setNavMode(int navNavMode);
    /** @brief Returns the name of the SLUGS navigation mode. */
    QString getNavModeText(int mode);
    /** @brief Helper for getNavModeTex. */
    static QString getSlugsNavModeText(int mode);
    /** @brief Sends a request for current mid-level commands. */
    void requestMidLevelCommands();
    /** @brief Sets mid-level commands. */
    void setMidLevelCommands(double altitude, double airspeed, double turnrate);
    /** @brief Sets the selective passthrough surfaces for manual control. */
    void setPassthroughSurfaces(bool throttle, bool aileron, bool rudder, bool elevator);

public slots:
    /** @brief Receive a MAVLink message from this MAV */
    void receiveMessage(LinkInterface* link, mavlink_message_t message);

signals:
    void midLevelCommandsChanged(int id, double altitude, double airspeed, double turnrate);

};
 /*

    void slugsRawImu(int uasId, const mavlink_raw_imu_t& rawData);
    void slugsGPSCogSog(int uasId, double cog, double sog);

#ifdef MAVLINK_ENABLED_SLUGS

    void slugsCPULoad(int systemId, const mavlink_cpu_load_t& cpuLoad);
    void slugsAirData(int systemId, const mavlink_air_data_t& airData);
    void slugsSensorBias(int systemId, const mavlink_sensor_bias_t& sensorBias);
    void slugsDiagnostic(int systemId, const mavlink_diagnostic_t& diagnostic);
    void slugsNavegation(int systemId, const mavlink_slugs_navigation_t& slugsNavigation);
    void slugsDataLog(int systemId, const mavlink_data_log_t& dataLog);
    void slugsGPSDateTime(int systemId, const mavlink_gps_date_time_t& gpsDateTime);
    void slugsActionAck(int systemId, const mavlink_action_ack_t& actionAck);

    void slugsBootMsg(int uasId, mavlink_boot_t& boot);
    void slugsAttitude(int uasId, mavlink_attitude_t& attitude);

    void slugsScaled(int uasId, const mavlink_scaled_imu_t& scaled);
    void slugsServo(int uasId, const mavlink_servo_output_raw_t& servo);
    void slugsChannels(int uasId, const mavlink_rc_channels_raw_t& channels);

#endif

protected:
    unsigned char updateRoundRobin;
    QTimer* widgetTimer;
    mavlink_raw_imu_t mlRawImuData;

#ifdef MAVLINK_ENABLED_SLUGS
    mavlink_gps_raw_t mlGpsData;
    mavlink_attitude_t mlAttitude;
    mavlink_cpu_load_t mlCpuLoadData;
    mavlink_air_data_t mlAirData;
    mavlink_sensor_bias_t mlSensorBiasData;
    mavlink_diagnostic_t mlDiagnosticData;
    mavlink_boot_t mlBoot;
    mavlink_gps_date_time_t mlGpsDateTime;
    mavlink_mid_lvl_cmds_t mlMidLevelCommands;
    mavlink_set_mode_t mlApMode;

    mavlink_slugs_navigation_t mlNavigation;
    mavlink_data_log_t mlDataLog;
    mavlink_ctrl_srfc_pt_t mlPassthrough;
    mavlink_action_ack_t mlActionAck;

    mavlink_slugs_action_t mlAction;

    mavlink_scaled_imu_t mlScaled;
    mavlink_servo_output_raw_t mlServo;
    mavlink_rc_channels_raw_t mlChannels;


    // Standart messages MAVLINK used by SLUGS
private:


    void emitGpsSignals (void);
    void emitPidSignal(void);

    int uasId;

#endif // if SLUGS

};
*/


#endif // _SLUGSMAV_H_


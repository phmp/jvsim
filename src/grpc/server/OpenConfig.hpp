//
//  OpenConfig.hpp
//  Telemetry Agent
//
//  Created by NITIN KUMAR on 1/12/16.
//  Copyright © 2016 Juniper Networks. All rights reserved.
//

#ifndef OpenConfig_hpp
#define OpenConfig_hpp

#include <string>
#include <map>
#include "telemetry_top.pb.h"
#include "agent.grpc.pb.h"
#include "AgentServerLog.hpp"

class OpenConfig {
   
public:
    static void        load();
    static void        registerSelf(const std::string path_name, OpenConfig *handler);
    static void        display(AgentServerLog *logger);
    static OpenConfig *find(const std::string path_name);
    virtual void       iterate(JuniperNetworksSensors *handle, telemetry::OpenConfigData *datap) = 0;
    void               insertExportTimestamp(telemetry::OpenConfigData *datap);
};


void openconfigRegister(std::string name, OpenConfig *handler);

#endif /* OpenConfig_hpp */

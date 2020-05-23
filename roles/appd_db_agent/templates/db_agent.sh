#!/bin/bash

#
# Init file for AppDynamics Database Agent
#

JAVA="/usr/bin/java" # java exe
AGENT="{{agent_directory}}/db-agent.jar" # agent lib

# Agent Options
AGENT_OPTIONS=""
AGENT_OPTIONS="$AGENT_OPTIONS -Dappdynamics.agent.uniqueHostId={{ appd_unique_hostid }}"
AGENT_OPTIONS="$AGENT_OPTIONS -Dappdynamics.http.proxyHost={{ http_proxy_host }}"
AGENT_OPTIONS="$AGENT_OPTIONS -Dappdynamics.http.proxyPort={{ http_proxy_port }}"
AGENT_OPTIONS="$AGENT_OPTIONS -Dappdynamics.https.proxyHost={{ https_proxy_host }}"
AGENT_OPTIONS="$AGENT_OPTIONS -Dappdynamics.https.proxyPort={{ https_proxy_port }}"

start()
{
    $JAVA $AGENT_OPTIONS -Xmx1536m -jar $AGENT
}

stop()
{
    ps -opid,cmd |egrep "[0-9]+ $JAVA.*db-agent" | awk '{print $1}' | xargs --no-run-if-empty kill -9
}

case "$1" in
start)
start
;;

stop) 
stop 
;; 

restart)
stop
start
;;
*)
echo "Usage: $0 start|stop|restart"
esac

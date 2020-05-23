# ntp and proxy server
secret_ntp_server: "changeme"
secret_http_proxy_host: ""
secret_http_proxy_port: ""
secret_https_proxy_host: ""
secret_https_proxy_port: ""

# login data for https://download.appdynamics.com/download/
secret_download_username: "changeme"
secret_download_password: "changeme"

# database user and pwd for mysql database and jdbc connection string of tomcat server
secret_mysql_username: "supercars"
secret_mysql_password: "supercars"

# tomcat
secret_tomcat_username: "tomcat"
secret_tomcat_password: "changeme"

# DB monitoring users for db and os is used by the appd DB collector
secret_dbuser_username: "DBUSER"
secret_dbuser_password: "changeme"
secret_dbuser_os_username: "dbuser"
secret_dbuser_os_password: "changeme"

# appdynamics agent configuration
secret_controller_url: 'changeme' # account.saas.appdynamics.com
secret_controller_port: '443'
secret_controller_protocoll: 'https'
secret_ssl_enabled: 'true'

secret_account_name: 'changeme' # from account.saas.appdynamics.com -> settings -> license -> account
secret_account_name_global: 'changeme' # from account.saas.appdynamics.com -> settings -> license -> account
secret_account_key: 'changeme' # from account.saas.appdynamics.com -> settings -> license -> account

secret_application: 'supercars'
secret_tier: 'tomcat'
secret_node: 'computer'

secret_unique_hostid: '{{ ansible_host }}' # take from inventory

secret_sim_enabled: 'true'
secret_metric_path: ""

secret_analytics_agent_name: analytics-agent
secret_analytics_enabled: 'true'

secret_event_custer_url: 'fra-ana-api.saas.appdynamics.com' # saas or on-prem endpoint https://docs.appdynamics.com/display/PAA/SaaS+Domains+and+IP+Ranges
secret_event_custer_port: '443'
secret_event_custer_protocoll: 'https'
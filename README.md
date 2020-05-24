# Apply Playbook

To set your hosts/IPs, your ssh connection and your remote user, edit

* vi ./hosts
* vi ./ansible.cfg

To create your personal vault file, do the following

* cp ./group_vars/all/vault.yml.cp ./group_vars/all/vault.yml

Afterwards, all configuration settings can be done here:

* vi ./group_vars/all/vault.yml (most settings including secrets)
* vi ./group_vars/all/vars.yml

The settings are explained in the configuration files.
You can encrypt your personal vault file using

* ansible-vault encrypt vault.yml

The Playbooks were split chronologically to give a logical order
and to allow seperate deployment types:

* ansible-playbook 0_download_agents.yml --ask-vault-pass (optional, downloads appdynamics agents)
* ansible-playbook 1_deploy_centos.yml --ask-vault-pass (mandatory, basic setup for all centos server)
* ansible-playbook 2_deploy_supercars.yml --ask-vault-pass (mandatory, deploys the supercars application)
* ansible-playbook 3_deploy_appd.yml --ask-vault-pass (optional, depploys appdynamics machine agent, java agent, and DB agent)
* ansible-playbook 4_inject_java_agent.yml --ask-vault-pass (optional, injects the java agent to JAVA_OPTS)
* ansible-playbook 5_create_db_user.yml --ask-vault-pass (optional, create a DB user for monitoring)

# Github Links

The following github resources were used to create the playbook:

* https://github.com/Appdynamics/Cars_Sample_App (Supercars App Code)
* https://github.com/geerlingguy/ansible-role-mysql (MySQL Server)
* https://github.com/zaxos/tomcat-ansible-role (Tomcat Server)
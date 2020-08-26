# Content of the playbooks

This playbook creates a simple sample web application for the instrumentation using Appdynamics.
First, the plain application is deployed. Afterwards, the application is instrumented using
a Java Agent, a Server Agent, and a DB Agent.

[!Architecture](https://github.com/lhintzsc/ansible_supercars_app/blob/master/docs/Architecture.png)


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
and to allow seperate deployment types.

Downloads appdynamics agents (optional instrumentation):

* ansible-playbook 0_download_agents.yml --ask-vault-pass

Basic setup for all centos server (core deployment):

* ansible-playbook 1_deploy_centos.yml --ask-vault-pass

Deploy supercars application (core deployment):

* ansible-playbook 2_deploy_supercars.yml --ask-vault-pass

Depploys appdynamics machine agent, java agent, and DB agent (optional instrumentation):

* ansible-playbook 3_deploy_appd.yml --ask-vault-pass

Injects the java agent to JAVA_OPTS (optional instrumentation):

* ansible-playbook 4_inject_java_agent.yml --ask-vault-pass

Create DB user for monitoring the DB and the DB server (optional instrumentation):

* ansible-playbook 5_create_db_user.yml --ask-vault-pass

# Github Links

The following github resources were used to create the playbook:

* https://github.com/Appdynamics/Cars_Sample_App (Supercars App Code)
* https://github.com/geerlingguy/ansible-role-mysql (MySQL Server)
* https://github.com/zaxos/tomcat-ansible-role (Tomcat Server)
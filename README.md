# Content of the playbooks

This playbook deploys a simple sample web application for the instrumentation using Appdynamics.
First, the plain application is deployed. Afterwards, the application is instrumented using
a Java Agent, a Server Agent, and a DB Agent.

![Architecture](https://github.com/lhintzsc/ansible_supercars_app/blob/master/docs/Architecture.png)

Use cases for this deployment are:

* Appdynamics Masters Certification
* Training of partners and customers
* Preparation for a Proof of Concept (PoC)
* Preparation of personal lab environment


# Prerequisites

This playbook has the following requirements:

* 1-3 VMs based on CentOS with python 2.7 installed and a valid ssh pairing
* appdynamics controller and licenses (e.g. https://www.appdynamics.com/free-trial/)
* valid configurations files (hosts, ansible.cfg, vars.yml and vault.yml)

# Configuration files

To set your hosts/IPs, your ssh connection and your remote user, edit

* vi ./hosts
* vi ./ansible.cfg

You need to setup your credentials, appdynamics configurations, proxy and nts server in

* ./group_vars/all/vars.yml
* ./group_vars/all/vault.yml

The settings itself are described in the comments of the configuration files.
You can set the parameters in the test file or reference local system variables.

# Workflow

You can deploy the whole architecture using main.yml. However, you can start
the plays seperatly as well:

* Step 1: ansible-playbook 0_download_agents.yml
* Step 2: ansible-playbook 1_deploy_centos.yml
* Step 3: ansible-playbook 2_deploy_supercars.yml
* Step 4: ansible-playbook 3_deploy_appd.yml
* Step 5: ansible-playbook 4_inject_java_agent.yml
* Step 6: ansible-playbook 5_create_db_user.yml

# Manual execution

If you want to manually deploy appdynamics, you can perform the deployment
until steps 0-2. Afterwards, you can follow the description in the github
Wiki article to train a manual deployment and configuration of the Appdynamics
agents.

# Github Links

The following github resources were used to create the playbook:

* https://github.com/Appdynamics/Cars_Sample_App (Supercars App Code)
* https://github.com/geerlingguy/ansible-role-mysql (MySQL Server)
* https://github.com/zaxos/tomcat-ansible-role (Tomcat Server)
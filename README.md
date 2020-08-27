# Content of the playbooks

Using this playbooks, you can deploy a simple web application and monitor it with Appdynamics.
First, the plain application is deployed. Afterwards, the application is instrumented using
a Java Agent, a Server Agent, and a DB Agent.

![Architecture](https://github.com/lhintzsc/ansible_supercars_app/blob/master/docs/Architecture.png)

You can use this architecture for the following use cases:

* Appdynamics Masters Certification
* training of partners and customers
* preparation for a Proof of Concept (PoC)
* creation of a personal lab environment
* Webinars and DevNet events

The deployment automates every step on server side. However, the configurations in the Appdynamics
user interface must still be done manually.

# Prerequisites

This playbook has the following requirements:

* VMs based on CentOS7 (you can collapse the deployment using 1 VM for all 3 ansible hosts)
* Python 2.7 must be installed with valid ssh connection for ansible
* appdynamics controller and licenses (e.g. https://www.appdynamics.com/free-trial/)
* valid configurations files (hosts, ansible.cfg, vars.yml and vault.yml)

# Configuration files

To set your hosts/IPs, your ssh connection and your remote user, edit

* [./hosts](https://github.com/lhintzsc/ansible_supercars_app/blob/master/hosts)
* [./ansible.cfg](https://github.com/lhintzsc/ansible_supercars_app/blob/master/ansible.cfg)

You need to setup your credentials, appdynamics configurations, proxy and nts server in

* [./group_vars/all/vars.yml](https://github.com/lhintzsc/ansible_supercars_app/blob/master/group_vars/all/vars.yml)
* [./group_vars/all/vault.yml ](https://github.com/lhintzsc/ansible_supercars_app/blob/master/group_vars/all/vault.yml)

The settings itself are described in the comments of the configuration files. 
You can set the parameters in the files directly or reference environment variables.

# Workflow

You can deploy the whole architecture using main.yml. 
However, you can start the plays seperatly as well:

```ansible
ansible-playbook 0_download_agents.yml
ansible-playbook 1_deploy_centos.yml
ansible-playbook 2_deploy_supercars.yml
ansible-playbook 3_deploy_appd.yml
ansible-playbook 4_inject_java_agent.yml
ansible-playbook 5_create_db_user.yml
```

If you want to manually deploy appdynamics, you can perform the deployment steps 0-2. 
Afterwards, you can follow the description in the github [Wiki](https://github.com/lhintzsc/ansible_supercars_app/wiki) to train a manual 
deployment and configuration of the Appdynamics agents.

# Getting help

If you need help with this code, you can do the folloowing:

* create an issue (preferred)
* ping me on webex (lhintzsc)
* write me a mail (lhintzsc@cisco.com)

Please note that I will priotize my daily tasks. As a result, there will be no SLA
when you get an answer. However, I am happy to support if it is possible.


# Credits and references

The following github resources were used to create the playbook:

* [Supercars App](https://github.com/Appdynamics/Cars_Sample_App)
* [ansible role for MySQL server](https://github.com/geerlingguy/ansible-role-mysql)
* [ansible role for tomcat server](https://github.com/zaxos/tomcat-ansible-role)
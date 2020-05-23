# Apply Playbook

Set your hostnames or IPs:

* vi hosts

Set ntp server, proxy-server (optional), usernames, passwords,

* cp ./group_vars/all/vault.yml.cp ./group_vars/all/vault.yml
* vi ./group_vars/all/vault.yml

Set your default remote user

* vi ansible.cfg

If you do not have a ntp server available, you can set a public

* https://www.pool.ntp.org/zone/nl

Encrypt your passwards using ansible vault:

* ansible-vault encrypt vault.yml

Deploy application:

* ansible-playbook main.yml --ask-vault-pass

# Github Links

The following github resources were used to create the playbook:

* https://github.com/Appdynamics/Cars_Sample_App (Supercars App Code)
* https://github.com/geerlingguy/ansible-role-mysql (MySQL Server)
* https://github.com/zaxos/tomcat-ansible-role (Tomcat Server)
Chef::Log.info("[Adding proxy configuration for apt(8)]")
template "/etc/apt/apt.conf.d/01proxy" do
  source "apt-proxy.config"
  mode "0644"
  owner "root"
  group "root"
end

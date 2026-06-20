__int64 create_global_sysfs_nodes()
{
  __int64 v0; // x0

  if ( !bus_get_dev_root(&cpu_subsys) )
    return 4294967274LL;
  v0 = kobject_create_and_add("qcom_lpm");
  qcom_lpm_kobj = v0;
  if ( v0 )
    return sysfs_create_group(v0, &lpm_gov_attr_group);
  else
    return 4294967284LL;
}

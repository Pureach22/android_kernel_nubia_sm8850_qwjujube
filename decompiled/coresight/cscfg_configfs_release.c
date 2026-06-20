__int64 __fastcall cscfg_configfs_release(__int64 a1)
{
  return configfs_unregister_subsystem(a1 + 984);
}

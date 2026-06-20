__int64 __fastcall cdsprm_resmgr_pdkill_debugfs_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(
           a1,
           a2,
           cdsprm_resmgr_pdkill_override_read,
           &cdsprm_resmgr_pdkill_override_write,
           "%llu\n",
           a6);
}

bool __fastcall reg_query_database(__int64 a1)
{
  __int64 v3; // x19

  if ( !(unsigned int)rtnl_is_locked(a1) && (query_regdb_file___already_done & 1) == 0 )
  {
    query_regdb_file___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 1054);
    __break(0x800u);
  }
  if ( regdb )
    return (unsigned int)query_regdb(a1 + 28) == 0;
  v3 = kmemdup_noprof(a1 + 28, 2, 3264);
  if ( !v3 )
    return 0;
  if ( !(unsigned int)request_firmware_nowait(&_this_module, 1, "regulatory.db", reg_pdev + 16, 3264, v3, regdb_fw_cb) )
    return 1;
  kfree(v3);
  return 0;
}

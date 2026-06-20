__int64 __fastcall regdb_fw_cb(_QWORD *a1, unsigned __int8 *a2)
{
  __int64 valid; // x0
  __int64 v5; // x22
  char v6; // w23
  __int64 regdb; // x0
  void *v9; // x0

  if ( !a1 )
  {
    v5 = -61;
    v9 = &unk_B7824;
LABEL_17:
    valid = printk(v9);
    v6 = 0;
    goto LABEL_4;
  }
  valid = valid_regdb((_DWORD *)a1[1], *(_DWORD *)a1);
  if ( (valid & 1) == 0 )
  {
    v5 = -22;
    v9 = &unk_B9950;
    goto LABEL_17;
  }
  v5 = 0;
  v6 = 1;
LABEL_4:
  rtnl_lock(valid);
  if ( ::regdb && (unsigned __int64)::regdb < 0xFFFFFFFFFFFFF001LL )
    goto LABEL_13;
  if ( (v6 & 1) == 0 )
  {
    ::regdb = v5;
LABEL_13:
    regdb = restore_regulatory_settings(1, 0);
    goto LABEL_14;
  }
  if ( !a1 )
    goto LABEL_13;
  regdb = kmemdup_noprof(a1[1], *a1, 3264);
  if ( !regdb )
    goto LABEL_13;
  ::regdb = regdb;
  if ( a2 )
  {
    regdb = query_regdb(a2);
    if ( (_DWORD)regdb )
      goto LABEL_13;
  }
LABEL_14:
  rtnl_unlock(regdb);
  kfree(a2);
  return release_firmware(a1);
}

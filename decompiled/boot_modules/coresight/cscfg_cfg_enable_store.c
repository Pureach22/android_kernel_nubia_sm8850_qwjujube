__int64 __fastcall cscfg_cfg_enable_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  bool v7; // zf
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v5 = kstrtobool(a2, v8);
  if ( v5 || (v5 = cscfg_config_sysfs_activate(*(_QWORD *)(a1 - 8), v8[0])) != 0 )
  {
    a3 = v5;
  }
  else
  {
    v7 = v8[0] == 1;
    *(_BYTE *)(a1 + 136) = v8[0];
    if ( v7 )
      cscfg_config_sysfs_set_preset(*(unsigned int *)(a1 + 140));
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}

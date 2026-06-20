__int64 __fastcall cscfg_cfg_preset_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w0
  __int64 v6; // x0
  int v8; // w8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v5 = kstrtoint(a2, 0, &v9);
  if ( v5 )
    goto LABEL_5;
  v6 = (unsigned int)v9;
  if ( v9 < 1 || v9 > *(_DWORD *)(*(_QWORD *)(a1 - 8) + 48LL) )
  {
    v5 = -22;
LABEL_5:
    a3 = v5;
    goto LABEL_6;
  }
  v8 = *(unsigned __int8 *)(a1 + 136);
  *(_DWORD *)(a1 + 140) = v9;
  if ( v8 == 1 )
    cscfg_config_sysfs_set_preset(v6);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return a3;
}

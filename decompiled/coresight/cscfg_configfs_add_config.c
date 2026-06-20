__int64 __fastcall cscfg_configfs_add_config(__int64 *a1)
{
  __int64 v2; // x0
  __int64 **v3; // x0
  __int64 v4; // x1
  unsigned __int64 v5; // x20
  __int64 **v6; // x21
  __int64 inited; // x0
  __int64 *v8; // x27
  _QWORD *v9; // x22
  int v10; // w23
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x26
  __int64 *v14; // x8
  __int64 *v15; // x1
  __int64 result; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-20h] BYREF
  int v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ((__int64 (*)(void))cscfg_device)();
  if ( !v2 )
  {
    LODWORD(v5) = -22;
LABEL_16:
    result = (unsigned int)v5;
    goto LABEL_17;
  }
  v3 = (__int64 **)devm_kmalloc(v2, 152, 3520);
  if ( !v3 )
  {
LABEL_14:
    LODWORD(v5) = -12;
    goto LABEL_16;
  }
  v4 = *a1;
  v5 = (unsigned __int64)(v3 + 1);
  v6 = v3;
  *v3 = a1;
  inited = config_group_init_type_name(v3 + 1, v4, &cscfg_config_view_type);
  v8 = *v6;
  if ( *((int *)*v6 + 12) >= 1 )
  {
    v9 = v6 + 14;
    v10 = 1;
    v18 = 0;
    v17[0] = 0;
    v17[1] = 0;
    do
    {
      v11 = cscfg_device(inited);
      v12 = devm_kmalloc(v11, 152, 3520);
      if ( !v12 )
        goto LABEL_14;
      v13 = v12;
      snprintf((char *)v17, 0x14u, "preset%d", v10);
      v14 = *v6;
      *(_DWORD *)v13 = v10;
      *(_QWORD *)(v13 + 8) = v14;
      config_group_init_type_name(v13 + 16, v17, &cscfg_config_preset_type);
      inited = v13 + 136;
      v15 = v6[15];
      if ( (_QWORD *)(v13 + 136) == v9 || v15 == (__int64 *)inited || (_QWORD *)*v15 != v9 )
      {
        inited = _list_add_valid_or_report(inited, v15);
      }
      else
      {
        v6[15] = (__int64 *)inited;
        *(_QWORD *)(v13 + 136) = v9;
        *(_QWORD *)(v13 + 144) = v15;
        *v15 = inited;
      }
    }
    while ( ++v10 <= *((_DWORD *)v8 + 12) );
  }
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_16;
  result = configfs_register_group(&cscfg_configs_grp, v5);
  if ( !(_DWORD)result )
    a1[11] = v5;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

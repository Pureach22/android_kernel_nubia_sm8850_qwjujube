__int64 __fastcall cscfg_configfs_add_feature(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  int v5; // w26
  _QWORD *v6; // x22
  __int64 v7; // x0
  _QWORD *v8; // x21
  __int64 v9; // x0
  _QWORD *v10; // x0
  _QWORD *v11; // x23
  unsigned __int64 v12; // x20
  __int64 v13; // x1
  __int64 inited; // x0
  _QWORD *v15; // x2
  __int64 *v16; // x1
  __int64 v17; // x0
  __int64 v18; // x22
  __int64 v19; // x27
  __int64 v20; // x28
  _QWORD *v21; // x23
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x25
  _QWORD *v25; // x0
  _QWORD *v26; // x1
  __int64 result; // x0

  v2 = cscfg_device(a1);
  if ( !v2 )
  {
    LODWORD(v12) = -22;
    return (unsigned int)v12;
  }
  v3 = v2;
  v4 = devm_kmalloc(v2, 144, 3520);
  if ( !v4 )
    goto LABEL_26;
  v5 = *((_DWORD *)a1 + 9);
  v6 = (_QWORD *)v4;
  if ( v5 )
  {
    v7 = devm_kmalloc(v3, 136, 3520);
    if ( v7 )
    {
      v8 = (_QWORD *)v7;
      v9 = cscfg_device(v7);
      v10 = (_QWORD *)devm_kmalloc(v9, 40, 3520);
      if ( v10 )
      {
        v11 = v10;
        *v10 = &_this_module;
        goto LABEL_9;
      }
    }
LABEL_26:
    LODWORD(v12) = -12;
    return (unsigned int)v12;
  }
  v11 = nullptr;
  v8 = nullptr;
LABEL_9:
  v13 = *a1;
  *v6 = a1;
  v12 = (unsigned __int64)(v6 + 1);
  config_group_init_type_name(v6 + 1, v13, &cscfg_feature_view_type);
  if ( !v8 )
    goto LABEL_29;
  config_group_init_type_name(v8, "params", v11);
  inited = (__int64)(v8 + 15);
  v15 = v6 + 14;
  v16 = (__int64 *)v6[15];
  if ( v8 + 15 != v6 + 14 && v16 != (__int64 *)inited && (_QWORD *)*v16 == v15 )
  {
    v6[15] = inited;
    if ( v5 )
    {
      v8[15] = v15;
      v8[16] = v16;
      *v16 = inited;
      goto LABEL_15;
    }
LABEL_32:
    __break(1u);
  }
  inited = _list_add_valid_or_report(inited, v16);
LABEL_15:
  v17 = cscfg_device(inited);
  if ( *((int *)a1 + 9) >= 1 )
  {
    v18 = v17;
    v19 = 0;
    v20 = 0;
    v21 = v8 + 13;
    do
    {
      v22 = devm_kmalloc(v18, 152, 3520);
      if ( !v22 )
        goto LABEL_26;
      v23 = a1[5];
      v24 = v22;
      *(_QWORD *)(v22 + 8) = a1;
      *(_DWORD *)v22 = v20;
      inited = config_group_init_type_name(v22 + 16, *(_QWORD *)(v23 + v19), &cscfg_param_view_type);
      if ( !v5 )
        goto LABEL_32;
      v25 = (_QWORD *)(v24 + 136);
      v26 = (_QWORD *)v8[14];
      if ( (_QWORD *)(v24 + 136) == v21 || v26 == v25 || (_QWORD *)*v26 != v21 )
      {
        _list_add_valid_or_report(v25, v26);
      }
      else
      {
        v8[14] = v25;
        *(_QWORD *)(v24 + 136) = v21;
        *(_QWORD *)(v24 + 144) = v26;
        *v26 = v25;
      }
      ++v20;
      v19 += 16;
    }
    while ( v20 < *((int *)a1 + 9) );
  }
LABEL_29:
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)v12;
  result = configfs_register_group(&cscfg_features_grp, v12);
  if ( !(_DWORD)result )
    a1[9] = v12;
  return result;
}

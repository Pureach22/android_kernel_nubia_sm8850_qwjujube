__int64 __fastcall crm_probe_get_drvs(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x27
  __int64 v5; // x0
  __int64 v7; // x25
  unsigned __int64 v8; // x28
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  __int64 v11; // x19
  unsigned __int64 v12; // x23
  __int64 v13; // x24
  int variable_u32_array; // w0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w26
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-10h]
  __int64 v21; // [xsp+8h] [xbp-8h]

  if ( !a2 )
    return -22;
  v3 = a2;
  v5 = *(_QWORD *)(a1 + 296);
  LODWORD(v7) = a2;
  v8 = *(_QWORD *)(v5 + 744);
  v9 = 192LL * a2;
  v10 = devm_kmalloc(v5, v9, 3520);
  if ( !v10 )
    return -12;
  v11 = v10;
  v12 = 4 * v3;
  v13 = _kmalloc_noprof(4 * v3, 3520);
  if ( !v13 )
    return -12;
  while ( 1 )
  {
    variable_u32_array = of_property_read_variable_u32_array(v8, a3, v13, v3, 0);
    if ( variable_u32_array < 0 )
      break;
    if ( (int)v7 < 1 )
    {
LABEL_18:
      kfree(v13);
      return v11;
    }
    v3 = 0;
    v8 = 0;
    while ( v12 > v8 )
    {
      a3 = *(unsigned int *)(v13 + v8);
      v7 = v11 + v3;
      scnprintf(v11 + v3 + 4, 20, "%s_%s_%d", a1);
      if ( v9 < v3 + 32 )
        break;
      *(_DWORD *)(v7 + 32) = a3;
      if ( v9 < v3 + 24 )
        break;
      *(_QWORD *)(v11 + v3 + 24) = *(_QWORD *)(a1 + 32);
      if ( v9 < v3 + 168 )
        break;
      *(_DWORD *)(v11 + v3 + 168) = 0;
      if ( v9 < v3 + 172 )
        break;
      a3 = v11 + v3;
      *(_DWORD *)(v11 + v3 + 172) = 0;
      v15 = ipc_log_context_create(2, v7 + 4, 0);
      if ( v9 < v3 + 184 )
        break;
      *(_QWORD *)(a3 + 184) = v15;
      if ( v9 < v3 + 40 )
        break;
      v16 = *(_QWORD *)(a1 + 288);
      *(_QWORD *)(v11 + v3 + 40) = v16 + 68;
      if ( v9 < v3 + 36 )
        break;
      *(_DWORD *)(v11 + v3 + 36) = *(_DWORD *)(a1 + 56);
      if ( v9 < v3 + 180 )
        break;
      v17 = v11 + v3;
      *(_BYTE *)(v11 + v3 + 180) = 1;
      if ( v9 < v3 + 181 )
        break;
      v3 += 192;
      v8 += 4LL;
      *(_BYTE *)(v17 + 181) = *(_BYTE *)(v16 + 1);
      if ( v9 == v3 )
        goto LABEL_18;
    }
    __break(1u);
    v12 = 4 * v3;
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v13 = _kmalloc_noprof(4 * v3, 3520);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v13 )
      return -12;
  }
  v18 = variable_u32_array;
  kfree(v13);
  return v18;
}

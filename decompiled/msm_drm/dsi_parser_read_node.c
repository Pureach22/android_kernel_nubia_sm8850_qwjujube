__int64 __fastcall dsi_parser_read_node(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x23
  __int64 v9; // x22
  __int64 v10; // x27
  __int64 v11; // x28
  int v12; // w0
  int v13; // w25
  int v14; // w26
  int v15; // w8
  __int64 v16; // x9
  __int64 v17; // x24
  __int64 v18; // x19
  __int64 v19; // x28
  int v20; // w26
  const char *v21; // x3
  __int64 v22; // x23
  int v23; // w0
  int v24; // w23
  __int64 v25; // x24
  __int64 v26; // x4
  unsigned __int64 StatusReg; // x24
  __int64 v28; // x25
  __int64 v29; // [xsp+0h] [xbp-10h]
  __int64 v30; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
    return -19;
  if ( *a4 )
    return 0;
  v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v9 )
    return -12;
  while ( 1 )
  {
    v10 = *(_QWORD *)(v4 + 16);
    if ( !v10 )
    {
      v18 = -22;
      goto LABEL_47;
    }
    v11 = *(_QWORD *)(v10 + 16);
    v12 = scnprintf(v9, 4096, "node name=%s\n", *(const char **)v10);
    v13 = 4096;
    if ( v12 == 4096 )
      goto LABEL_44;
    v14 = scnprintf(v9 + v12, 4096 - v12, "children count=%d\n", *(_DWORD *)(v10 + 192)) + v12;
    v13 = 4096;
    if ( v14 == 4096 )
      goto LABEL_44;
    v30 = v11;
    if ( *(int *)(v10 + 192) < 1 )
      break;
    v4 = 0;
    while ( v4 != 20 )
    {
      v13 = 4096;
      v14 += scnprintf(v9 + v14, 4096 - v14, "child[%d]=%s\n", v4, **(const char ***)(v10 + 32 + 8 * v4));
      if ( v14 == 4096 )
        goto LABEL_44;
      if ( ++v4 >= *(int *)(v10 + 192) )
        goto LABEL_14;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v28 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dsi_parser_read_node__alloc_tag;
    v9 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    *(_QWORD *)(StatusReg + 80) = v28;
    if ( !v9 )
      return -12;
  }
LABEL_14:
  v15 = *(_DWORD *)(v10 + 24);
  v16 = v11;
  if ( v15 < 1 )
  {
    v13 = v14;
    goto LABEL_44;
  }
  v17 = 0;
  v13 = v14;
  while ( 1 )
  {
    v19 = v16 + 40 * v17;
    if ( !*(_QWORD *)v19 )
      goto LABEL_17;
    v20 = scnprintf(v9 + v13, 4096 - v13, "property=%s\n", *(const char **)v19) + v13;
    if ( v20 == 4096 )
      goto LABEL_43;
    v21 = *(const char **)(v19 + 16);
    if ( v21 )
      break;
LABEL_29:
    v29 = v17;
    if ( *(_DWORD *)(v19 + 36) )
    {
      v13 = 4096;
      v20 += scnprintf(v9 + v20, 4096 - v20, "items:\n");
      if ( v20 == 4096 )
        goto LABEL_44;
      if ( *(int *)(v19 + 36) >= 1 )
      {
        v13 = 4096;
        v20 += scnprintf(v9 + v20, 4096 - v20, "%s%c", **(const char ***)(v19 + 24), 32);
        if ( v20 == 4096 )
          goto LABEL_44;
        if ( *(int *)(v19 + 36) >= 2 )
        {
          v24 = -1;
          v25 = 1;
          do
          {
            v13 = 4096;
            v26 = v24 + 10 * ((unsigned int)v25 / 0xA) ? 32LL : 10LL;
            v20 += scnprintf(v9 + v20, 4096 - v20, "%s%c", *(_QWORD *)(*(_QWORD *)(v19 + 24) + 8 * v25), v26);
            if ( v20 == 4096 )
              goto LABEL_44;
            ++v25;
            --v24;
          }
          while ( v25 < *(int *)(v19 + 36) );
        }
      }
    }
    v13 = scnprintf(v9 + v20, 4096 - v20, "\n\n") + v20;
    if ( v13 == 4096 )
    {
LABEL_43:
      v13 = 4096;
      goto LABEL_44;
    }
    v15 = *(_DWORD *)(v10 + 24);
    v17 = v29;
LABEL_17:
    ++v17;
    v16 = v30;
    if ( v17 >= v15 )
      goto LABEL_44;
  }
  if ( !*(_DWORD *)(v19 + 32) )
  {
    v13 = 4096;
    v23 = scnprintf(v9 + v20, 4096 - v20, "value=%s\n", v21);
LABEL_28:
    v20 += v23;
    if ( v20 == 4096 )
      goto LABEL_44;
    goto LABEL_29;
  }
  if ( *(int *)(v19 + 36) < 1 )
  {
LABEL_26:
    v13 = 4096;
    v23 = scnprintf(v9 + v20, 4096 - v20, "\n");
    goto LABEL_28;
  }
  v22 = 0;
  while ( 1 )
  {
    v13 = 4096;
    v20 += scnprintf(v9 + v20, 4096 - v20, "%x", *(unsigned __int8 *)(*(_QWORD *)(v19 + 16) + v22));
    if ( v20 == 4096 )
      break;
    if ( ++v22 >= *(int *)(v19 + 36) )
      goto LABEL_26;
  }
LABEL_44:
  if ( simple_read_from_buffer(a2, a3, a4, v9, v13) )
    v18 = -14;
  else
    v18 = v13;
LABEL_47:
  kfree(v9);
  return v18;
}

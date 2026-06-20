__int64 __fastcall cam_soc_util_clk_wrapper_register_entry(
        unsigned int a1,
        __int64 a2,
        char a3,
        __int64 a4,
        void *a5,
        const char *a6)
{
  _UNKNOWN **v10; // x25
  unsigned int v11; // w9
  __int64 v12; // x0
  _QWORD *v13; // x20
  size_t v14; // x0
  unsigned __int64 v15; // x2
  _QWORD *v16; // x1
  _QWORD *v17; // x0
  _UNKNOWN **v18; // x2
  _QWORD *v19; // x1
  int v20; // w8
  unsigned int v21; // w22
  int v22; // w9
  char v23; // w2
  _QWORD *v24; // x24
  const char *v25; // x5
  __int64 v26; // x4

  mutex_lock(&wrapper_lock);
  v10 = &wrapper_clk_list;
  do
  {
    v10 = (_UNKNOWN **)*v10;
    v11 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 17);
    if ( v10 == &wrapper_clk_list )
    {
      if ( v11 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_clk_wrapper_register_entry",
          1245,
          "Adding new entry for clk id %d",
          a1);
      if ( mem_trace_en == 1 )
        v12 = cam_mem_trace_alloc(224, 0xCC0u, 0, "cam_soc_util_clk_wrapper_register_entry", 0x4DFu);
      else
        v12 = _kvmalloc_node_noprof(224, 0, 3520, 0xFFFFFFFFLL);
      v10 = (_UNKNOWN **)v12;
      if ( !v12 )
      {
        v25 = "Failed in allocating new clk entry %d";
        v26 = 1251;
        goto LABEL_51;
      }
      v14 = strnlen(a6, 0x80u);
      if ( v14 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v14 == 128 )
          v15 = 128;
        else
          v15 = v14 + 1;
        if ( v15 < 0x81 )
        {
          sized_strscpy(v10 + 11, a6);
          *((_DWORD *)v10 + 4) = a1;
          *v10 = v10;
          v10[1] = v10;
          v10[4] = v10 + 4;
          v10[5] = v10 + 4;
          v16 = off_3F00;
          if ( v10 != &wrapper_clk_list && off_3F00 != v10 && *off_3F00 == (_UNKNOWN *)&wrapper_clk_list )
          {
            off_3F00 = v10;
            *v10 = &wrapper_clk_list;
            v10[1] = v16;
            *v16 = v10;
            goto LABEL_27;
          }
          goto LABEL_47;
        }
      }
      _fortify_panic(7, 128, v15);
LABEL_47:
      _list_add_valid_or_report(v10);
      goto LABEL_27;
    }
    if ( v11 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_register_entry",
        1222,
        "Clk list id %d num clients %d",
        *((_DWORD *)v10 + 4),
        *((_DWORD *)v10 + 12));
  }
  while ( *((_DWORD *)v10 + 4) != a1 );
  v13 = v10 + 4;
  while ( 1 )
  {
    v13 = (_QWORD *)*v13;
    if ( v13 == v10 + 4 )
      break;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_wrapper_register_entry",
        1231,
        "Clk id %d entry client %s",
        *((_DWORD *)v10 + 4),
        *(const char **)(v13[2] + 24LL));
    if ( v13[2] == a4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_wrapper_register_entry",
        1235,
        "Register with same soc info, clk id %d, client %s",
        a1,
        *(const char **)(a4 + 24));
      v21 = -22;
      goto LABEL_52;
    }
  }
LABEL_27:
  if ( mem_trace_en == 1 )
  {
    v17 = (_QWORD *)cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_soc_util_clk_wrapper_register_entry", 0x4EFu);
    if ( !v17 )
    {
LABEL_49:
      v25 = "Failed in allocating new client entry %d";
      v26 = 1266;
LABEL_51:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_wrapper_register_entry",
        v26,
        v25,
        a1);
      v21 = -12;
      goto LABEL_52;
    }
  }
  else
  {
    v17 = (_QWORD *)_kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
    if ( !v17 )
      goto LABEL_49;
  }
  v17[2] = a4;
  v17[3] = a2;
  if ( (a3 & 1) != 0
    && !v10[7]
    && (v23 = *(_BYTE *)(a4 + 32),
        v24 = v17,
        v10[10] = a5,
        *((_BYTE *)v10 + 72) = v23,
        v10[8] = (_UNKNOWN *)a4,
        v21 = cam_soc_util_register_mmrm_client(a1, a2, v23, a4, a6, v10 + 7),
        v17 = v24,
        v21) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_clk_wrapper_register_entry",
      1285,
      "Failed in register mmrm client Dev %s clk id %d",
      *(const char **)(a4 + 24),
      a1);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v24, 0);
    else
      kvfree(v24);
  }
  else
  {
    *v17 = v17;
    v18 = v10 + 4;
    v17[1] = v17;
    v19 = v10[5];
    if ( v17 == v10 + 4 || v19 == v17 || (_UNKNOWN **)*v19 != v18 )
    {
      _list_add_valid_or_report(v17);
    }
    else
    {
      v10[5] = v17;
      *v17 = v18;
      v17[1] = v19;
      *v19 = v17;
    }
    v20 = debug_mdl;
    v21 = 0;
    v22 = *((_DWORD *)v10 + 12) + 1;
    *((_DWORD *)v10 + 12) = v22;
    if ( (v20 & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v20 & 0x20000LL,
        4,
        "cam_soc_util_clk_wrapper_register_entry",
        1297,
        "Adding new client %s for clk[%s] id %d, num clients %d",
        *(const char **)(a4 + 24),
        a6,
        a1,
        v22);
      v21 = 0;
    }
  }
LABEL_52:
  mutex_unlock(&wrapper_lock);
  return v21;
}

__int64 __fastcall ucfg_cfg_store_print(__int64 a1)
{
  _QWORD *comp_private_obj; // x0
  const char **v3; // x24
  __int64 v4; // x25
  __int64 v5; // x26
  int v6; // w8
  unsigned __int8 *v7; // x3
  int v8; // w5
  int v9; // w6
  int v10; // w7
  int v11; // w8
  const char *v12; // x4
  int v13; // w5

  qdf_trace_msg(80, 8, "%s: enter", "cfg_store_print");
  comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 7);
  if ( !comp_private_obj || !*comp_private_obj )
    return 16;
  v3 = (const char **)&cfg_meta_lookup_table;
  v4 = *comp_private_obj + 28LL;
  v5 = 1256;
  do
  {
    v6 = *((_DWORD *)v3 + 3);
    v7 = (unsigned __int8 *)(v4 + *((unsigned int *)v3 + 2));
    if ( v6 <= 2 )
    {
      if ( (unsigned int)v6 < 2 )
      {
        v12 = *v3;
        v13 = *(_DWORD *)v7;
      }
      else
      {
        if ( v6 != 2 )
          goto LABEL_5;
        v12 = *v3;
        v13 = *v7;
      }
      qdf_trace_msg(80, 8, "%pK %s %d", v7, v12, v13);
    }
    else if ( v6 > 4 )
    {
      if ( v6 == 5 )
      {
        qdf_trace_msg(80, 8, "%pK %s %pI4", v7, *v3, v4 + *((unsigned int *)v3 + 2));
      }
      else if ( v6 == 6 )
      {
        qdf_trace_msg(80, 8, "%pK %s %pI6c", v7, *v3, v4 + *((unsigned int *)v3 + 2));
      }
    }
    else if ( v6 == 3 )
    {
      qdf_trace_msg(80, 8, "%pK %s %s", v7, *v3, v4 + *((unsigned int *)v3 + 2));
    }
    else
    {
      if ( v7 )
      {
        v8 = *v7;
        v9 = v7[1];
        v10 = v7[2];
        v11 = v7[5];
      }
      else
      {
        v10 = 0;
        v8 = 0;
        v9 = 0;
        v11 = 0;
      }
      qdf_trace_msg(80, 8, "%pK %s %02x:%02x:%02x:**:**:%02x", v7, *v3, v8, v9, v10, v11);
    }
LABEL_5:
    --v5;
    v3 += 5;
  }
  while ( v5 );
  qdf_trace_msg(80, 8, "%s: exit", "cfg_store_print");
  return 0;
}

__int64 __fastcall ucfg_cfg_ini_config_print(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4)
{
  _QWORD *comp_private_obj; // x0
  const char **v9; // x28
  __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x27
  int v13; // w0
  int v14; // w8
  unsigned __int8 *v15; // x4
  int v16; // w8
  int v17; // w5
  int v18; // w6
  int v19; // w7
  const char *v20; // x3
  int v21; // w4

  qdf_trace_msg(80, 8, "%s: enter", "cfg_ini_config_print");
  comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 7);
  if ( !comp_private_obj || !*comp_private_obj )
    return 16;
  v9 = (const char **)&cfg_meta_lookup_table;
  v10 = *comp_private_obj + 28LL;
  v11 = 1256;
  v12 = a4;
  do
  {
    v14 = *((_DWORD *)v9 + 3);
    v15 = (unsigned __int8 *)(v10 + *((unsigned int *)v9 + 2));
    if ( v14 <= 2 )
    {
      if ( (unsigned int)v14 < 2 )
      {
        v20 = *v9;
        v21 = *(_DWORD *)v15;
        goto LABEL_19;
      }
      if ( v14 == 2 )
      {
        v20 = *v9;
        v21 = *v15;
LABEL_19:
        v13 = scnprintf(a2, v12, "%s %d\n", v20, v21);
        goto LABEL_5;
      }
    }
    else
    {
      if ( v14 <= 4 )
      {
        if ( v14 == 3 )
        {
          v13 = scnprintf(a2, v12, "%s %s\n", *v9);
        }
        else
        {
          if ( v15 )
          {
            v16 = *v15;
            v17 = v15[1];
            v18 = v15[2];
            v19 = v15[5];
          }
          else
          {
            v18 = 0;
            v16 = 0;
            v17 = 0;
            v19 = 0;
          }
          v13 = scnprintf(a2, v12, "%s %02x:%02x:%02x:**:**:%02x\n", *v9, v16, v17, v18, v19);
        }
        goto LABEL_5;
      }
      if ( v14 == 5 )
      {
        v13 = scnprintf(a2, v12, "%s %pI4\n", *v9);
LABEL_5:
        a2 += v13;
        v12 -= v13;
        goto LABEL_6;
      }
      if ( v14 == 6 )
      {
        v13 = scnprintf(a2, v12, "%s %pI6c\n", *v9);
        goto LABEL_5;
      }
    }
LABEL_6:
    --v11;
    v9 += 5;
  }
  while ( v11 );
  *a3 = a4 - v12;
  qdf_trace_msg(80, 8, "%s: exit", "cfg_ini_config_print");
  return 0;
}

__int64 __fastcall qcom_pdm_probe(__int64 a1)
{
  unsigned __int64 v3; // x20
  __int64 node_opts_by_path; // x0
  __int64 matched; // x0
  __int64 *v6; // x24
  __int64 v7; // x0
  int v8; // w0
  int v9; // w21
  __int64 v11; // x25
  int v12; // w26
  int v13; // w0
  char *v14; // x1
  int v15; // w28
  int v16; // w22
  int v17; // w0
  unsigned int v23; // w8

  mutex_lock(&qcom_pdm_mutex);
  _X0 = (unsigned int *)_qcom_pdm_data;
  if ( !_qcom_pdm_data )
  {
    node_opts_by_path = of_find_node_opts_by_path("/", 0);
    if ( !node_opts_by_path )
      goto LABEL_11;
    matched = of_match_node(&qcom_pdm_domains, node_opts_by_path);
    if ( !matched )
    {
      printk(&unk_8419);
      LODWORD(v3) = -19;
      goto LABEL_12;
    }
    v6 = *(__int64 **)(matched + 192);
    if ( !v6 )
    {
LABEL_11:
      LODWORD(v3) = -19;
      goto LABEL_12;
    }
    v7 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 328);
    v3 = v7;
    if ( !v7 )
    {
      LODWORD(v3) = -12;
      goto LABEL_12;
    }
    *(_QWORD *)(v7 + 312) = v7 + 312;
    *(_QWORD *)(v7 + 320) = v7 + 312;
    v8 = qmi_handle_init(v7 + 8, 74, 0, &qcom_pdm_msg_handlers);
    if ( v8 )
    {
      v9 = v8;
      kfree(v3);
      v3 = v9;
    }
    else
    {
      *(_DWORD *)v3 = 1;
      v11 = *v6;
      if ( *v6 )
      {
        v12 = 0;
        while ( 1 )
        {
          v13 = qcom_pdm_add_service_domain(v3, "tms/servreg");
          if ( v13 )
            break;
          v14 = *(char **)(v11 + 16);
          if ( v14 )
          {
            v15 = 1;
            do
            {
              v13 = qcom_pdm_add_service_domain(v3, v14);
              if ( v13 )
                goto LABEL_22;
              v14 = *(char **)(v11 + 16 + 8LL * v15++);
            }
            while ( v14 );
          }
          v11 = v6[++v12];
          if ( !v11 )
            goto LABEL_25;
        }
LABEL_22:
        v16 = v13;
      }
      else
      {
LABEL_25:
        v17 = qmi_add_server(v3 + 8, 64, 257, 0);
        if ( !v17 )
          goto LABEL_26;
        v16 = v17;
        printk(&unk_83C6);
      }
      qcom_pdm_stop(v3);
      v3 = v16;
    }
LABEL_26:
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_12;
    _qcom_pdm_data = v3;
    goto LABEL_4;
  }
  __asm { PRFM            #0x11, [X0] }
  do
    v23 = __ldxr(_X0);
  while ( __stxr(v23 + 1, _X0) );
  if ( !v23 || (((v23 + 1) | v23) & 0x80000000) != 0 )
    refcount_warn_saturate();
LABEL_4:
  LODWORD(v3) = 0;
LABEL_12:
  *(_QWORD *)(a1 + 152) = _qcom_pdm_data;
  mutex_unlock(&qcom_pdm_mutex);
  return (unsigned int)v3;
}

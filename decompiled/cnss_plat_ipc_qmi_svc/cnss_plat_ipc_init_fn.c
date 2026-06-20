__int64 cnss_plat_ipc_init_fn()
{
  __int64 result; // x0
  unsigned int v1; // w0
  __int64 v2; // x5
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 v5; // x9
  int v6; // w10
  const char *v7; // x1
  int v8; // w22
  unsigned int v9; // w0
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  const char *v12; // x1
  __int16 v13; // w10
  const char *v14; // x9
  __int16 v15; // w10
  const char *v16; // x9
  __int16 v17; // w9
  const char *v18; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  result = _kmalloc_cache_noprof(queue_work_on, 3520, 304);
  plat_ipc_qmi_svc[0] = result;
  if ( result )
  {
    if ( (qmi_handle_init(result, 0xFFFF, &cnss_plat_ipc_qmi_ops, &cnss_plat_ipc_qmi_req_handlers) & 0x80000000) != 0 )
    {
      v8 = 240;
      while ( 1 )
      {
        msleep(250);
        v9 = qmi_handle_init(plat_ipc_qmi_svc[0], 0xFFFF, &cnss_plat_ipc_qmi_ops, &cnss_plat_ipc_qmi_req_handlers);
        if ( (v9 & 0x80000000) == 0 )
          break;
        if ( !--v8 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v11 = "irq";
          }
          else
          {
            v17 = *(_DWORD *)(StatusReg + 16);
            v18 = (const char *)(StatusReg + 2320);
            if ( (v17 & 0xFF00) != 0 )
              v11 = "soft_irq";
            else
              v11 = v18;
          }
          cnss_plat_ipc_debug_log_print(
            cnss_plat_ipc_log_context,
            v11,
            "cnss_plat_ipc_init_fn",
            byte_80DC,
            "Failed to init QMI handle after %d ms * %d, err = %d\n",
            250,
            240,
            v9,
            vars0);
          return kfree(plat_ipc_qmi_svc[0]);
        }
      }
    }
    v1 = qmi_add_server(plat_ipc_qmi_svc[0], 1070, 1, 0);
    v5 = _ReadStatusReg(SP_EL0);
    v6 = *(_DWORD *)(v5 + 16) & 0xF0000;
    if ( (v1 & 0x80000000) != 0 )
    {
      if ( v6 )
      {
        v12 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(v5 + 16);
        v16 = (const char *)(v5 + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v12 = "soft_irq";
        else
          v12 = v16;
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v12,
        "cnss_plat_ipc_init_fn",
        byte_80DC,
        "Server add fail: %d\n",
        v1,
        v3,
        v4,
        vars0);
      qmi_handle_release(plat_ipc_qmi_svc[0]);
      return kfree(plat_ipc_qmi_svc[0]);
    }
    else
    {
      if ( v6 )
      {
        v7 = "irq";
      }
      else
      {
        v13 = *(_DWORD *)(v5 + 16);
        v14 = (const char *)(v5 + 2320);
        if ( (v13 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v14;
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v7,
        "cnss_plat_ipc_init_fn",
        byte_824A,
        "CNSS Platform IPC QMI Service is started\n",
        v2,
        v3,
        v4,
        vars0);
      qword_7D60 = 0x1000000400000000LL;
      qword_7D68 = 0;
      qword_7D70 = 0;
      return _mutex_init(&unk_7D78, "&svc->file_idr_lock", &cnss_plat_ipc_init_fn___key);
    }
  }
  return result;
}

__int64 __fastcall cnss_plat_ipc_qmi_file_upload(int a1, const char *a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int64 result; // x0
  __int64 *v9; // x24
  unsigned __int64 v10; // x22
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  const char **inited; // x0
  const char **v17; // x19
  int v18; // w5
  const char *v19; // x1
  const char *v20; // x1
  const char *v21; // x1
  unsigned int v22; // w20
  const char *v23; // x1
  _QWORD v24[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+28h] [xbp-18h]
  int v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v25 = 0;
  memset(v24, 0, sizeof(v24));
  if ( a1 >= 2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v15;
    }
    cnss_plat_ipc_debug_log_print(
      cnss_plat_ipc_log_context,
      v6,
      "cnss_plat_ipc_qmi_file_upload",
      &unk_80DC,
      "Invalid Client ID: %d\n",
      a1);
    goto LABEL_14;
  }
  if ( (unsigned int)a1 < 3 )
  {
    result = 4294967274LL;
    if ( !a3 )
      goto LABEL_15;
    if ( !a2 )
      goto LABEL_15;
    v9 = &plat_ipc_qmi_svc[5 * (unsigned int)a1];
    if ( (*((_BYTE *)v9 + 92) & 1) == 0 )
      goto LABEL_15;
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v10 + 2320);
    }
    cnss_plat_ipc_debug_log_print(
      cnss_plat_ipc_log_context,
      v13,
      "cnss_plat_ipc_qmi_file_upload",
      &unk_824A,
      "File name: %s Size: %d\n",
      a2,
      a4);
    if ( (a4 - 33554433) >> 25 == 127 )
    {
      inited = (const char **)cnss_plat_ipc_init_file_data(a2, a3, a4, a4);
      if ( inited )
      {
        v17 = inited;
        scnprintf(v24, 32, "%s", *inited);
        v26 = *((_DWORD *)v17 + 6);
        HIDWORD(v25) = *((_DWORD *)v17 + 4);
        v18 = qmi_send_indication(
                plat_ipc_qmi_svc[0],
                v9 + 10,
                4,
                49,
                &cnss_plat_ipc_qmi_file_upload_ind_msg_v01_ei,
                v24);
        if ( v18 < 0 )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
          {
            v21 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v21 = "soft_irq";
          }
          else
          {
            v21 = (const char *)(v10 + 2320);
          }
          cnss_plat_ipc_debug_log_print(
            cnss_plat_ipc_log_context,
            v21,
            "cnss_plat_ipc_qmi_file_upload",
            &unk_80DC,
            "QMI failed: %d\n",
            v18);
        }
        else if ( !(unsigned int)wait_for_completion_timeout(v17 + 5, 2500) )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v19 = "soft_irq";
          }
          else
          {
            v19 = (const char *)(v10 + 2320);
          }
          cnss_plat_ipc_debug_log_print(
            cnss_plat_ipc_log_context,
            v19,
            "cnss_plat_ipc_qmi_file_upload",
            &unk_80DC,
            "Timeout Uploading file: %s\n",
            *v17);
        }
        mutex_lock(&unk_7D78);
        idr_remove(&qword_7D60, *((unsigned int *)v17 + 4));
        mutex_unlock(&unk_7D78);
        if ( *((_DWORD *)v17 + 9) )
          v22 = 0;
        else
          v22 = -22;
        kfree(v17);
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v23 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v23 = "soft_irq";
        }
        else
        {
          v23 = (const char *)(v10 + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v23,
          "cnss_plat_ipc_qmi_file_upload",
          &unk_82E1,
          "Status: %d\n",
          v22);
        result = v22;
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
      {
        v20 = "irq";
      }
      else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
      {
        v20 = "soft_irq";
      }
      else
      {
        v20 = (const char *)(v10 + 2320);
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v20,
        "cnss_plat_ipc_qmi_file_upload",
        &unk_80DC,
        "Unable to initialize file transfer data\n");
    }
LABEL_14:
    result = 4294967274LL;
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))cnss_plat_ipc_debug_log_print)();
}

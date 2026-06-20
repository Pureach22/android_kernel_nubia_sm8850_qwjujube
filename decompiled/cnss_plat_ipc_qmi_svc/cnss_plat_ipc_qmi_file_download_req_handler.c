void __fastcall cnss_plat_ipc_qmi_file_download_req_handler(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  unsigned __int64 StatusReg; // x24
  const char *v8; // x1
  __int64 v9; // x19
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 v12; // x6
  __int64 v13; // x7
  const char *v14; // x1
  const char *v15; // x1
  __int64 v16; // x6
  const char *v17; // x1
  int v18; // w9
  __int64 v19; // x10
  int v20; // w8
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  const char *v24; // x1
  const char *v25; // x1
  char v26; // [xsp+0h] [xbp-30h]
  _DWORD v27[3]; // [xsp+1Ch] [xbp-14h] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  if ( a4 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v8 = "soft_irq";
    }
    else
    {
      v8 = (const char *)(StatusReg + 2320);
    }
    cnss_plat_ipc_debug_log_print(
      cnss_plat_ipc_log_context,
      v8,
      "cnss_plat_ipc_qmi_file_download_req_handler",
      byte_82E1,
      "File ID: %d Size: %d Seg Len: %d Index: %d End: %d\n",
      *a4,
      a4[1],
      a4[4],
      a4[3]);
    mutex_lock(&unk_7D78);
    v9 = idr_find(&qword_7D60, *a4);
    mutex_unlock(&unk_7D78);
    if ( v9 )
    {
      v12 = a4[1];
      v13 = *(unsigned int *)(v9 + 20);
      if ( (unsigned int)v12 > (unsigned int)v13 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v14 = "soft_irq";
        }
        else
        {
          v14 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v14,
          "cnss_plat_ipc_qmi_file_download_req_handler",
          byte_80DC,
          "File %s size %d larger than buffer size %d\n",
          *(_QWORD *)v9,
          v12,
          v13,
          v26);
        goto LABEL_29;
      }
      v16 = a4[4];
      if ( (unsigned int)v16 > 0xF000 || *(_DWORD *)(v9 + 24) + (int)v16 > (unsigned int)v13 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v17 = "soft_irq";
        }
        else
        {
          v17 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v17,
          "cnss_plat_ipc_qmi_file_download_req_handler",
          byte_80DC,
          "Segment buf ID: %d buffer size %d not allowed\n",
          a4[3],
          v16,
          v13,
          v26);
        goto LABEL_29;
      }
      if ( a4[3] != *(_DWORD *)(v9 + 28) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v25 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v25 = "soft_irq";
        }
        else
        {
          v25 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v25,
          "cnss_plat_ipc_qmi_file_download_req_handler",
          byte_80DC,
          "File %s transfer segment failure\n",
          *(_QWORD *)v9,
          v16,
          v13,
          v26);
        goto LABEL_29;
      }
      memcpy(*(void **)(v9 + 8), a4 + 5, a4[4]);
      v18 = *(_DWORD *)(v9 + 24);
      v19 = *(_QWORD *)(v9 + 8);
      v20 = *(_DWORD *)(v9 + 28) + 1;
      *(_DWORD *)(v9 + 28) = v20;
      *(_QWORD *)(v9 + 8) = v19 + a4[4];
      LODWORD(v19) = *(_DWORD *)(v9 + 16);
      *(_DWORD *)(v9 + 24) = v18 + a4[4];
      v27[1] = v19;
      v27[2] = v20;
      v21 = qmi_send_response(plat_ipc_qmi_svc[0], a2, a3, 3, 21, &cnss_plat_ipc_qmi_file_download_resp_msg_v01_ei, v27);
      if ( (v21 & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v24,
          "cnss_plat_ipc_qmi_file_download_req_handler",
          byte_80DC,
          "QMI failed: %d\n",
          v21,
          v22,
          v23,
          v26);
      }
      if ( *((_BYTE *)a4 + 8) )
      {
        *(_DWORD *)(v9 + 36) = 1;
LABEL_29:
        complete(v9 + 40);
      }
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v15 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v15 = "soft_irq";
      }
      else
      {
        v15 = (const char *)(StatusReg + 2320);
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v15,
        "cnss_plat_ipc_qmi_file_download_req_handler",
        byte_80DC,
        "Invalid File ID: %d\n",
        *a4,
        v10,
        v11,
        v26);
    }
  }
  _ReadStatusReg(SP_EL0);
}

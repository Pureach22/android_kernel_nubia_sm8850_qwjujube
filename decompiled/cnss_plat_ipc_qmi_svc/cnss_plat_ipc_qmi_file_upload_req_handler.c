void __fastcall cnss_plat_ipc_qmi_file_upload_req_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x26
  const char *v12; // x1
  __int64 v13; // x21
  __int64 v14; // x6
  __int64 v15; // x7
  const char *v16; // x1
  const char *v17; // x1
  __int64 v18; // x0
  __int64 v19; // x22
  unsigned int v20; // w23
  void *v21; // x0
  unsigned int v22; // w24
  unsigned int v23; // w28
  unsigned int v24; // w8
  size_t v25; // x25
  int v26; // w27
  const char *v27; // x1
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  __int64 v31; // x8
  __int64 v32; // x10
  const char *v33; // x1
  char v34; // [xsp+0h] [xbp-10h]
  char v35; // [xsp+0h] [xbp-10h]
  char v36; // [xsp+0h] [xbp-10h]

  if ( a4 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    cnss_plat_ipc_debug_log_print(
      cnss_plat_ipc_log_context,
      v12,
      "cnss_plat_ipc_qmi_file_upload_req_handler",
      byte_82E1,
      "File ID: %d Seg Index: %d\n",
      *a4,
      a4[1],
      a8,
      v34);
    mutex_lock(&unk_7D78);
    v13 = idr_find(&qword_7D60, *a4);
    mutex_unlock(&unk_7D78);
    if ( v13 )
    {
      if ( a4[1] != *(_DWORD *)(v13 + 28) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v16 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v16 = "soft_irq";
        }
        else
        {
          v16 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v16,
          "cnss_plat_ipc_qmi_file_upload_req_handler",
          byte_80DC,
          "File %s transfer segment failure\n",
          *(_QWORD *)v13,
          v14,
          v15,
          v35);
        complete(v13 + 40);
      }
      v18 = _kmalloc_large_noprof(61460, 3520);
      v19 = v18;
      if ( v18 )
      {
        v20 = *(_DWORD *)(v13 + 16);
        v21 = (void *)(v18 + 20);
        *(_DWORD *)(v19 + 4) = v20;
        v22 = *(_DWORD *)(v13 + 28);
        v23 = v22 + 1;
        *(_DWORD *)(v13 + 28) = v22 + 1;
        *(_DWORD *)(v19 + 12) = v22;
        v24 = *(_DWORD *)(v13 + 20);
        if ( v24 >= 0xF000 )
          v25 = 61440;
        else
          v25 = v24;
        *(_DWORD *)(v19 + 16) = v25;
        v26 = *(_DWORD *)(v13 + 32);
        *(_BYTE *)(v19 + 8) = v23 == v26;
        memcpy(v21, *(const void **)(v13 + 8), v25);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v27 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v27 = "soft_irq";
        }
        else
        {
          v27 = (const char *)(StatusReg + 2320);
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v27,
          "cnss_plat_ipc_qmi_file_upload_req_handler",
          byte_82E1,
          "ID: %d Seg ID: %d Len: %d End: %d\n",
          v20,
          v22,
          (unsigned int)v25,
          v23 == v26);
        v28 = qmi_send_response(
                plat_ipc_qmi_svc[0],
                a2,
                a3,
                5,
                61470,
                &cnss_plat_ipc_qmi_file_upload_resp_msg_v01_ei,
                v19);
        if ( (v28 & 0x80000000) != 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v33 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v33 = "soft_irq";
          }
          else
          {
            v33 = (const char *)(StatusReg + 2320);
          }
          cnss_plat_ipc_debug_log_print(
            cnss_plat_ipc_log_context,
            v33,
            "cnss_plat_ipc_qmi_file_upload_req_handler",
            byte_80DC,
            "QMI failed: %d\n",
            v28,
            v29,
            v30,
            v36);
        }
        else
        {
          v31 = *(unsigned int *)(v19 + 16);
          v32 = *(_QWORD *)(v13 + 8);
          *(_DWORD *)(v13 + 20) -= v31;
          *(_QWORD *)(v13 + 8) = v32 + v31;
          if ( *(_BYTE *)(v19 + 8) )
          {
            *(_DWORD *)(v13 + 36) = 1;
            complete(v13 + 40);
          }
        }
        kfree(v19);
      }
    }
    else
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
        "cnss_plat_ipc_qmi_file_upload_req_handler",
        byte_80DC,
        "Invalid File ID %d\n",
        *a4,
        v14,
        v15,
        v35);
    }
  }
}

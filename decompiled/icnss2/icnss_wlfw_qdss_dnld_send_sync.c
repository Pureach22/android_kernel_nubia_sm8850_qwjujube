__int64 __fastcall icnss_wlfw_qdss_dnld_send_sync(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x19
  unsigned __int16 *v4; // x20
  __int64 v5; // x8
  unsigned int v6; // w0
  unsigned int v7; // w23
  char *v8; // x22
  unsigned int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x22
  const char *v15; // x21
  __int64 v16; // x21
  __int64 v17; // x22
  __int64 result; // x0
  unsigned int *v19; // [xsp+8h] [xbp-C8h] BYREF
  _QWORD v20[9]; // [xsp+10h] [xbp-C0h] BYREF
  _QWORD v21[6]; // [xsp+58h] [xbp-78h] BYREF
  char s[24]; // [xsp+88h] [xbp-48h] BYREF
  __int64 v23; // [xsp+A0h] [xbp-30h]
  __int64 v24; // [xsp+A8h] [xbp-28h]
  __int64 v25; // [xsp+B0h] [xbp-20h]
  __int16 v26; // [xsp+B8h] [xbp-18h]
  __int64 v27; // [xsp+C0h] [xbp-10h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1832);
  v19 = nullptr;
  memset(v20, 0, sizeof(v20));
  memset(v21, 0, 45);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending QDSS config download message, state: 0x%lx\n", v2);
  v3 = _kmalloc_cache_noprof(icc_set_bw, 3520, 6172);
  if ( v3 )
  {
    v4 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
    if ( v4 )
    {
      v5 = *(_QWORD *)(a1 + 304);
      v26 = 0;
      v24 = 0;
      v25 = 0;
      v23 = 0;
      memset(s, 0, sizeof(s));
      if ( v5 == 30544 || v5 == 25680 )
        snprintf(s, 0x2Du, "qdss_trace_config_%s%s.cfg", "perf_", "v1");
      else
        strcpy(s, "qdss_trace_config.cfg");
      icnss_add_fw_prefix_name(a1, (const char *)v21, s);
      v6 = firmware_request_nowarn(&v19, v21, *(_QWORD *)(a1 + 8) + 16LL);
      if ( v6 )
      {
        v14 = v6;
        printk("%sicnss2_qmi: Failed to load QDSS: %s ret:%d\n", byte_130B32, (const char *)v21, v6);
        v13 = v14;
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: Failed to load QDSS: %s ret:%d\n",
          (const char *)&unk_12DBF3,
          (const char *)v21,
          v14);
      }
      else
      {
        v7 = *v19;
        v8 = *((char **)v19 + 1);
        ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Downloading QDSS: %s, size: %u\n", (const char *)v21, *v19);
        if ( v7 )
        {
          while ( 1 )
          {
            *(_BYTE *)v3 = 1;
            *(_DWORD *)(v3 + 4) = v7;
            *(_BYTE *)(v3 + 8) = 1;
            *(_BYTE *)(v3 + 16) = 1;
            *(_BYTE *)(v3 + 6168) = 1;
            if ( v7 < 0x1801 )
            {
              v9 = v7;
              *(_DWORD *)(v3 + 20) = v7;
              *(_BYTE *)(v3 + 6169) = 1;
            }
            else
            {
              v9 = 6144;
              *(_DWORD *)(v3 + 20) = 6144;
            }
            memcpy((void *)(v3 + 24), v8, v9);
            v10 = qmi_txn_init(a1 + 624, v20, &wlfw_qdss_trace_config_download_resp_msg_v01_ei, v4);
            if ( (v10 & 0x80000000) != 0 )
            {
              v15 = "%sicnss2_qmi: Failed to initialize txn for QDSS download request, err: %d\n";
LABEL_23:
              v17 = v10;
              printk(v15, byte_130B32, (unsigned int)v10);
              v13 = v17;
              ipc_log_string(icnss_ipc_log_context, v15, &unk_12DBF3, (unsigned int)v17);
              goto LABEL_25;
            }
            v11 = qmi_send_request(a1 + 624, 0, v20, 68, 6167, &wlfw_qdss_trace_config_download_req_msg_v01_ei, v3);
            if ( (v11 & 0x80000000) != 0 )
            {
              v16 = v11;
              qmi_txn_cancel(v20);
              printk("%sicnss2_qmi: Failed to send respond QDSS download request, err: %d\n", byte_130B32, v16);
              v13 = v16;
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2_qmi: Failed to send respond QDSS download request, err: %d\n",
                (const char *)&unk_12DBF3,
                v16);
              goto LABEL_25;
            }
            v10 = qmi_txn_wait(v20, *(unsigned int *)(a1 + 336));
            if ( (v10 & 0x80000000) != 0 )
            {
              v15 = "%sicnss2_qmi: Failed to wait for response of QDSS download request, err: %d\n";
              goto LABEL_23;
            }
            if ( *v4 )
              break;
            v12 = *(unsigned int *)(v3 + 20);
            v7 -= v12;
            v8 += v12;
            ++*(_DWORD *)(v3 + 12);
            if ( !v7 )
              goto LABEL_17;
          }
          printk("%sicnss2_qmi: QDSS download request failed, result: %d, err: %d\n", byte_130B32, *v4, v4[1]);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: QDSS download request failed, result: %d, err: %d\n",
            (const char *)&unk_12DBF3,
            *v4,
            v4[1]);
          v13 = (unsigned int)-*v4;
LABEL_25:
          release_firmware(v19);
        }
        else
        {
LABEL_17:
          release_firmware(v19);
          v13 = 0;
        }
      }
      kfree(v3);
    }
    else
    {
      v13 = 4294967284LL;
      v4 = (unsigned __int16 *)v3;
    }
    kfree(v4);
    result = v13;
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

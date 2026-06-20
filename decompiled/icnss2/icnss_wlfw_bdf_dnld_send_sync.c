__int64 __fastcall icnss_wlfw_bdf_dnld_send_sync(__int64 a1, unsigned int a2)
{
  const char *v4; // x2
  __int64 v5; // x3
  __int64 v6; // x19
  unsigned __int16 *v7; // x27
  unsigned int v8; // w3
  unsigned int v9; // w3
  size_t v10; // x0
  unsigned __int64 v11; // x2
  char v12; // w9
  char v13; // w10
  unsigned int v14; // w0
  unsigned int v15; // w23
  char *v16; // x24
  unsigned int *v17; // x9
  __int64 v18; // x8
  unsigned int v19; // w8
  unsigned int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  int v23; // w3
  __int64 v24; // x8
  unsigned int v25; // w22
  __int64 v26; // x0
  const char *v27; // x3
  __int64 v28; // x0
  const char *v29; // x3
  __int64 v30; // x0
  const char *v31; // x3
  unsigned __int64 StatusReg; // x20
  __int64 v33; // x21
  unsigned int *v35; // [xsp+0h] [xbp-F0h] BYREF
  _QWORD v36[9]; // [xsp+8h] [xbp-E8h] BYREF
  _QWORD v37[4]; // [xsp+50h] [xbp-A0h] BYREF
  _QWORD v38[2]; // [xsp+70h] [xbp-80h]
  __int128 string; // [xsp+80h] [xbp-70h] BYREF
  __int64 v40; // [xsp+90h] [xbp-60h]
  __int64 v41; // [xsp+98h] [xbp-58h]
  _BYTE v42[13]; // [xsp+A0h] [xbp-50h] BYREF
  __int128 s; // [xsp+B0h] [xbp-40h] BYREF
  __int64 v44; // [xsp+C0h] [xbp-30h]
  __int64 v45; // [xsp+C8h] [xbp-28h]
  _QWORD v46[4]; // [xsp+D0h] [xbp-20h]

  v46[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = nullptr;
  if ( a2 > 4 )
    v4 = "UNKNOWN";
  else
    v4 = off_12B408[a2];
  v5 = *(_QWORD *)(a1 + 1832);
  memset(v36, 0, sizeof(v36));
  memset(v37, 0, sizeof(v37));
  v38[0] = 0;
  *(_QWORD *)((char *)v38 + 5) = 0;
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending %s download message, state: 0x%lx, type: %d\n", v4, v5, a2);
  v6 = _kmalloc_cache_noprof(icc_set_bw, 3520, 6180);
  if ( !v6 )
  {
LABEL_66:
    v25 = -12;
    goto LABEL_69;
  }
  while ( 1 )
  {
    v7 = (unsigned __int16 *)_kmalloc_cache_noprof(_init_swait_queue_head, 3520, 16);
    if ( !v7 )
      break;
    v44 = 0;
    *(_QWORD *)((char *)v46 + 5) = 0;
    v45 = 0;
    v46[0] = 0;
    s = 0u;
    v41 = 0;
    memset(v42, 0, sizeof(v42));
    v40 = 0;
    string = 0u;
    if ( a2 )
    {
      if ( a2 == 4 )
      {
        strcpy((char *)&s, "regdb.bin");
LABEL_32:
        icnss_add_fw_prefix_name(a1, (const char *)v37, (const char *)&s);
        v14 = firmware_request_nowarn(&v35, v37, *(_QWORD *)(a1 + 8) + 16LL);
        if ( v14 )
        {
          v25 = v14;
          if ( a2 >= 2 )
          {
            printk("%sicnss2_qmi: Failed to load %s: %s ret:%d\n", byte_130B32, "REGDB", (const char *)v37, v14);
            v26 = icnss_ipc_log_context;
            v27 = "REGDB";
          }
          else
          {
            printk("%sicnss2_qmi: Failed to load %s: %s ret:%d\n", byte_130B32, "BDF", (const char *)v37, v14);
            v26 = icnss_ipc_log_context;
            v27 = "BDF";
          }
          ipc_log_string(
            v26,
            "%sicnss2_qmi: Failed to load %s: %s ret:%d\n",
            (const char *)&unk_12DBF3,
            v27,
            (const char *)v37,
            v25);
        }
        else
        {
          v15 = *v35;
          v16 = *((char **)v35 + 1);
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2_qmi: Downloading %s: %s, size: %u\n",
            off_12B408[a2],
            (const char *)v37,
            *v35);
          if ( v15 )
          {
            while ( 1 )
            {
              v17 = v35;
              *(_BYTE *)(v6 + 8) = 1;
              *(_WORD *)v6 = 257;
              *(_DWORD *)(v6 + 4) = *(_DWORD *)(a1 + 1848);
              v18 = *(_QWORD *)v17;
              *(_BYTE *)(v6 + 16) = 1;
              *(_BYTE *)(v6 + 24) = 1;
              *(_DWORD *)(v6 + 12) = v18;
              *(_BYTE *)(v6 + 6176) = 1;
              *(_BYTE *)(v6 + 6178) = 1;
              *(_BYTE *)(v6 + 6179) = a2;
              if ( v15 < 0x1801 )
              {
                v19 = v15;
                *(_DWORD *)(v6 + 28) = v15;
                *(_BYTE *)(v6 + 6177) = 1;
              }
              else
              {
                v19 = 6144;
                *(_DWORD *)(v6 + 28) = 6144;
              }
              memcpy((void *)(v6 + 32), v16, v19);
              v20 = qmi_txn_init(a1 + 624, v36, &wlfw_bdf_download_resp_msg_v01_ei, v7);
              if ( (v20 & 0x80000000) != 0 )
                break;
              v21 = qmi_send_request(a1 + 624, 0, v36, 37, 6182, &wlfw_bdf_download_req_msg_v01_ei, v6);
              if ( (v21 & 0x80000000) != 0 )
              {
                v25 = v21;
                qmi_txn_cancel(v36);
                if ( a2 >= 2 )
                {
                  printk(
                    "%sicnss2_qmi: Failed to send respond %s download request, err: %d\n",
                    byte_130B32,
                    "REGDB",
                    v25);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: Failed to send respond %s download request, err: %d\n",
                    &unk_12DBF3,
                    "REGDB",
                    v25);
                }
                else
                {
                  printk("%sicnss2_qmi: Failed to send respond %s download request, err: %d\n", byte_130B32, "BDF", v25);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: Failed to send respond %s download request, err: %d\n",
                    &unk_12DBF3,
                    "BDF",
                    v25);
                }
                goto LABEL_63;
              }
              v22 = qmi_txn_wait(v36, *(unsigned int *)(a1 + 336));
              if ( (v22 & 0x80000000) != 0 )
              {
                v25 = v22;
                if ( a2 >= 2 )
                {
                  printk(
                    "%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n",
                    byte_130B32,
                    "REGDB",
                    v22);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n",
                    &unk_12DBF3,
                    "REGDB",
                    v25);
                }
                else
                {
                  printk(
                    "%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n",
                    byte_130B32,
                    "BDF",
                    v22);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n",
                    &unk_12DBF3,
                    "BDF",
                    v25);
                }
                goto LABEL_63;
              }
              v23 = *v7;
              if ( *v7 )
              {
                if ( a2 >= 2 )
                {
                  printk(
                    "%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                    byte_130B32,
                    "REGDB",
                    v23,
                    v7[1]);
                  v31 = "REGDB";
                  v30 = icnss_ipc_log_context;
                }
                else
                {
                  printk(
                    "%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                    byte_130B32,
                    "BDF",
                    v23,
                    v7[1]);
                  v30 = icnss_ipc_log_context;
                  v31 = "BDF";
                }
                ipc_log_string(
                  v30,
                  "%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                  (const char *)&unk_12DBF3,
                  v31,
                  *v7,
                  v7[1]);
                v25 = -*v7;
                goto LABEL_63;
              }
              v24 = *(unsigned int *)(v6 + 28);
              v15 -= v24;
              v16 += v24;
              ++*(_DWORD *)(v6 + 20);
              if ( !v15 )
                goto LABEL_42;
            }
            v25 = v20;
            if ( a2 >= 2 )
            {
              printk(
                "%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n",
                byte_130B32,
                "REGDB",
                v20);
              v29 = "REGDB";
              v28 = icnss_ipc_log_context;
            }
            else
            {
              printk(
                "%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n",
                byte_130B32,
                "BDF",
                v20);
              v28 = icnss_ipc_log_context;
              v29 = "BDF";
            }
            ipc_log_string(
              v28,
              "%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n",
              &unk_12DBF3,
              v29,
              v25);
LABEL_63:
            release_firmware(v35);
          }
          else
          {
LABEL_42:
            release_firmware(v35);
            v25 = 0;
          }
        }
      }
      else
      {
        if ( a2 == 1 )
        {
          v8 = *(_DWORD *)(a1 + 1848);
          if ( v8 == 255 )
          {
            strcpy((char *)&s, "bdwlan.elf");
          }
          else if ( v8 > 0xFE )
          {
            snprintf(
              (char *)&s,
              0x2Du,
              "bdwlan%02x.e%02x",
              BYTE1(*(_DWORD *)(a1 + 1848)),
              (unsigned __int8)*(_DWORD *)(a1 + 1848));
          }
          else
          {
            snprintf((char *)&s, 0x2Du, "bdwlan.e%02x", v8);
          }
          goto LABEL_32;
        }
        printk("%sicnss2_qmi: Invalid BDF type: %d\n", byte_130B32, *(_DWORD *)(a1 + 340));
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: Invalid BDF type: %d\n",
          (const char *)&unk_12DBF3,
          *(_DWORD *)(a1 + 340));
        v25 = -22;
      }
      kfree(v6);
      goto LABEL_68;
    }
    v9 = *(_DWORD *)(a1 + 1848);
    if ( v9 == 255 )
    {
      strcpy((char *)&s, "bdwlan.bin");
    }
    else if ( v9 < 0x100 )
    {
      snprintf((char *)&s, 0x2Du, "bdwlan.b%02x");
    }
    else
    {
      snprintf((char *)&s, 0x2Du, "bdwlan.%03x");
    }
    if ( !*(_BYTE *)(a1 + 5844) )
      goto LABEL_32;
    v10 = strnlen((const char *)&s, 0x2Du);
    if ( v10 >= 0x2E )
      goto LABEL_64;
    if ( v10 == 45 )
      v11 = 45;
    else
      v11 = v10 + 1;
    if ( v11 >= 0x2E )
      goto LABEL_65;
    sized_strscpy(&string, &s);
    v12 = BYTE10(string);
    v13 = *(_BYTE *)(a1 + 5844);
    v42[12] = 0;
    *(_DWORD *)((char *)&string + 7) = *(_DWORD *)((char *)&string + 6);
    BYTE11(string) = v12;
    BYTE6(string) = v13;
    v10 = strnlen((const char *)&string, 0x2Du);
    if ( v10 >= 0x2E )
    {
LABEL_64:
      _fortify_panic(2, 45, v10 + 1);
    }
    else
    {
      if ( v10 == 45 )
        v11 = 45;
      else
        v11 = v10 + 1;
      if ( v11 < 0x2E )
      {
        sized_strscpy(&s, &string);
        goto LABEL_32;
      }
    }
LABEL_65:
    _fortify_panic(7, 45, v11);
    StatusReg = _ReadStatusReg(SP_EL0);
    v33 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &icnss_wlfw_bdf_dnld_send_sync__alloc_tag;
    v6 = _kmalloc_cache_noprof(icc_set_bw, 3520, 6180);
    *(_QWORD *)(StatusReg + 80) = v33;
    if ( !v6 )
      goto LABEL_66;
  }
  v25 = -12;
  v7 = (unsigned __int16 *)v6;
LABEL_68:
  kfree(v7);
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v25;
}

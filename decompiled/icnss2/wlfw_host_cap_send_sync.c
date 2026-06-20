__int64 __fastcall wlfw_host_cap_send_sync(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x19
  unsigned __int16 *v4; // x20
  int v5; // w2
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x3
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x2
  __int64 v16; // x0
  unsigned int v17; // w2
  int v18; // w9
  int v19; // w22
  unsigned int v20; // w0
  unsigned int v21; // w22
  unsigned int v22; // w0
  const char *v23; // x21
  __int64 v25; // [xsp+0h] [xbp-70h] BYREF
  __int64 v26; // [xsp+8h] [xbp-68h] BYREF
  __int64 v27; // [xsp+10h] [xbp-60h] BYREF
  __int64 v28; // [xsp+18h] [xbp-58h] BYREF
  _QWORD v29[10]; // [xsp+20h] [xbp-50h] BYREF

  v29[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1832);
  v28 = 0;
  memset(v29, 0, 72);
  v26 = 0;
  v27 = 0;
  v25 = 0;
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending host capability message, state: 0x%lx\n", v2);
  v3 = _kmalloc_cache_noprof(kfree, 3520, 1000);
  if ( v3 )
  {
    v4 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
    if ( !v4 )
    {
      v21 = -12;
      v4 = (unsigned __int16 *)v3;
      goto LABEL_46;
    }
    v5 = *(unsigned __int8 *)(a1 + 344);
    v6 = icnss_ipc_log_context;
    *(_BYTE *)v3 = 1;
    *(_DWORD *)(v3 + 4) = 1;
    *(_WORD *)(v3 + 154) = 257;
    *(_BYTE *)(v3 + 166) = 1;
    *(_BYTE *)(v3 + 167) = v5;
    ipc_log_string(v6, "icnss2_qmi: Calibration done is %d\n", v5);
    if ( *(_BYTE *)(a1 + 3251) == 1
      && !(unsigned int)icnss_get_iova(a1, &v28, &v27)
      && !(unsigned int)icnss_get_iova_ipa(a1, &v26, &v25) )
    {
      v8 = v27;
      v7 = v28;
      v9 = v25;
      *(_BYTE *)(v3 + 248) = 1;
      v10 = *(_QWORD *)(a1 + 1792);
      v11 = icnss_ipc_log_context;
      v12 = v9 + v8;
      v13 = *(unsigned int *)(a1 + 1816);
      *(_QWORD *)(v3 + 256) = v7;
      *(_QWORD *)(v3 + 264) = v12;
      *(_QWORD *)(v3 + 272) = v10;
      *(_QWORD *)(v3 + 280) = v13;
      ipc_log_string(v11, "icnss2_qmi: Sending iova starting 0x%llx with size 0x%llx\n", v7, v12);
      ipc_log_string(
        icnss_ipc_log_context,
        "icnss2_qmi: Sending msa starting 0x%llx with size 0x%llx\n",
        *(_QWORD *)(v3 + 272),
        *(_QWORD *)(v3 + 280));
    }
    v14 = *(_QWORD *)(a1 + 304);
    *(_BYTE *)(v3 + 304) = 1;
    *(_DWORD *)(v3 + 308) = 2;
    if ( v14 == 30544 )
    {
      *(_WORD *)(v3 + 312) = 257;
      *(_DWORD *)(v3 + 316) = 0x10000;
      *(_WORD *)(v3 + 322) = 32;
      *(_BYTE *)(v3 + 314) = 1;
      *(_BYTE *)(v3 + 320) = 1;
      *(_DWORD *)(v3 + 324) = 65793;
      *(_WORD *)(v3 + 328) = 1;
      *(_BYTE *)(v3 + 331) = 1;
    }
    if ( a1 )
    {
      v15 = *(_QWORD *)(a1 + 6120);
      v16 = icnss_ipc_log_context;
      *(_BYTE *)(v3 + 345) = 1;
      *(_QWORD *)(v3 + 352) = v15;
      ipc_log_string(v16, "icnss2_qmi: Sending feature list 0x%llx\n", v15);
    }
    v17 = *(_DWORD *)(a1 + 5780);
    if ( v17 >= 0x64 )
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Setting WLAN_EN delay: %d ms\n", v17);
      v18 = *(_DWORD *)(a1 + 5780);
      *(_BYTE *)(v3 + 372) = 1;
      *(_DWORD *)(v3 + 376) = v18;
    }
    v19 = *(_DWORD *)(a1 + 6280);
    if ( v19 >= 1 )
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: DDR Type: %d\n", v19);
      *(_DWORD *)(v3 + 384) = v19;
      *(_BYTE *)(v3 + 380) = 1;
    }
    if ( !*(_DWORD *)(a1 + 6340) || *(_DWORD *)(a1 + 6344) )
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))icnss_populate_gpio_config)(a1, v3, 0, a1 + 6284);
    if ( !*(_DWORD *)(a1 + 6404) || *(_DWORD *)(a1 + 6408) )
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))icnss_populate_gpio_config)(a1, v3, 1, a1 + 6348);
    if ( !*(_DWORD *)(a1 + 6468) || *(_DWORD *)(a1 + 6472) )
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))icnss_populate_gpio_config)(a1, v3, 2, a1 + 6412);
    if ( !*(_DWORD *)(a1 + 6532) || *(_DWORD *)(a1 + 6536) )
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))icnss_populate_gpio_config)(a1, v3, 3, a1 + 6476);
    if ( !*(_DWORD *)(a1 + 6596) || *(_DWORD *)(a1 + 6600) )
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))icnss_populate_gpio_config)(a1, v3, 4, a1 + 6540);
    if ( !*(_DWORD *)(a1 + 6660) || *(_DWORD *)(a1 + 6664) )
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))icnss_populate_gpio_config)(a1, v3, 5, a1 + 6604);
    *(_BYTE *)(v3 + 564) = 1;
    *(_DWORD *)(v3 + 568) = 6;
    *(_BYTE *)(v3 + 388) = 1;
    *(_DWORD *)(v3 + 392) = 6;
    v20 = qmi_txn_init(a1 + 624, v29, &wlfw_host_cap_resp_msg_v01_ei, v4);
    if ( (v20 & 0x80000000) != 0 )
    {
      v21 = v20;
      v23 = "%sicnss2_qmi: Failed to initialize txn for host capability request, err: %d\n";
      printk("%sicnss2_qmi: Failed to initialize txn for host capability request, err: %d\n", byte_130B32, v20);
    }
    else
    {
      v21 = qmi_send_request(a1 + 624, 0, v29, 52, 982, &wlfw_host_cap_req_msg_v01_ei, v3);
      if ( (v21 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v29);
        v23 = "%sicnss2_qmi: Failed to send host capability request, err: %d\n";
        printk("%sicnss2_qmi: Failed to send host capability request, err: %d\n", byte_130B32, v21);
      }
      else
      {
        v22 = qmi_txn_wait(v29, *(unsigned int *)(a1 + 336));
        if ( (v22 & 0x80000000) == 0 )
        {
          if ( *v4 )
          {
            printk("%sicnss2_qmi: Host capability request failed, result: %d, err: %d\n", byte_130B32, *v4, v4[1]);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2_qmi: Host capability request failed, result: %d, err: %d\n",
              (const char *)&unk_12DBF3,
              *v4,
              v4[1]);
            v21 = -*v4;
          }
          else
          {
            v21 = 0;
          }
          goto LABEL_38;
        }
        v21 = v22;
        v23 = "%sicnss2_qmi: Failed to wait for response of host capability request, err: %d\n";
        printk("%sicnss2_qmi: Failed to wait for response of host capability request, err: %d\n", byte_130B32, v22);
      }
    }
    ipc_log_string(icnss_ipc_log_context, v23, &unk_12DBF3, v21);
LABEL_38:
    kfree(v3);
LABEL_46:
    kfree(v4);
    goto LABEL_47;
  }
  v21 = -12;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v21;
}

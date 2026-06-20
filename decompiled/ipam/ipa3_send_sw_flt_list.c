__int64 __fastcall ipa3_send_sw_flt_list(unsigned __int64 a1)
{
  __int64 v1; // x0
  unsigned __int8 *v2; // x19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  int v27[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v28; // [xsp+8h] [xbp-18h]
  int v29; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v27 = 0;
  v28 = 0;
  if ( inline_copy_from_user((__int64)v27, a1, 0x10u) )
  {
    printk(&unk_3CF1F5, "ipa3_send_sw_flt_list");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d Copy ipa_ioc_sw_flt_list_type failure\n", "ipa3_send_sw_flt_list", 2677);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Copy ipa_ioc_sw_flt_list_type failure\n", "ipa3_send_sw_flt_list", 2677);
        result = 4294967282LL;
        goto LABEL_21;
      }
    }
LABEL_32:
    result = 4294967282LL;
    goto LABEL_21;
  }
  if ( (_DWORD)v28 != 472 )
  {
    printk(&unk_3DAB42, "ipa3_send_sw_flt_list");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(
          v15,
          "ipa %s:%d IPA_IOC_SET_SW_FLT size not match(%d,%lu)!\n",
          "ipa3_send_sw_flt_list",
          2685,
          v28,
          472);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d IPA_IOC_SET_SW_FLT size not match(%d,%lu)!\n",
          "ipa3_send_sw_flt_list",
          2685,
          v28,
          472);
        result = 4294967282LL;
        goto LABEL_21;
      }
    }
    goto LABEL_32;
  }
  v1 = _kmalloc_cache_noprof(scnprintf, 3520, 472);
  v2 = (unsigned __int8 *)v1;
  if ( v1 )
  {
    if ( inline_copy_from_user(v1, *(unsigned __int64 *)v27, 0x1D8u) )
    {
      printk(&unk_3A9047, "ipa3_send_sw_flt_list");
      v17 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(v18, "ipa %s:%d Failed to copy ipa_sw_flt_list_type\n", "ipa3_send_sw_flt_list", 2698);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(v19, "ipa %s:%d Failed to copy ipa_sw_flt_list_type\n", "ipa3_send_sw_flt_list", 2698);
      }
      kfree(v2);
      result = 4294967282LL;
    }
    else
    {
      v3 = ipa3_ctx;
      v29 = 30933041;
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(
            v4,
            "ipa %s:%d No of clients: %d, mac-flt enable: %d\n",
            "ipa3_send_sw_flt_list",
            2708,
            *((_DWORD *)v2 + 1),
            *v2);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d No of clients: %d, mac-flt enable: %d\n",
            "ipa3_send_sw_flt_list",
            2708,
            *((_DWORD *)v2 + 1),
            *v2);
          v3 = ipa3_ctx;
        }
        if ( v3 )
        {
          v6 = *(_QWORD *)(v3 + 34152);
          if ( v6 )
          {
            ipc_log_string(
              v6,
              "ipa %s:%d No of segs: %d, ipv4-seg-flt enable: %d v6-offload %d\n",
              "ipa3_send_sw_flt_list",
              2713,
              *((_DWORD *)v2 + 51),
              v2[200],
              v2[201]);
            v3 = ipa3_ctx;
          }
          v7 = *(_QWORD *)(v3 + 34160);
          if ( v7 )
          {
            ipc_log_string(
              v7,
              "ipa %s:%d No of segs: %d, ipv4-seg-flt enable: %d v6-offload %d\n",
              "ipa3_send_sw_flt_list",
              2713,
              *((_DWORD *)v2 + 51),
              v2[200],
              v2[201]);
            v3 = ipa3_ctx;
          }
          if ( v3 )
          {
            v8 = *(_QWORD *)(v3 + 34152);
            if ( v8 )
            {
              ipc_log_string(
                v8,
                "ipa %s:%d No of ifaces: %d, iface-flt enable: %d\n",
                "ipa3_send_sw_flt_list",
                2717,
                *((_DWORD *)v2 + 85),
                v2[336]);
              v3 = ipa3_ctx;
            }
            v9 = *(_QWORD *)(v3 + 34160);
            if ( v9 )
              ipc_log_string(
                v9,
                "ipa %s:%d No of ifaces: %d, iface-flt enable: %d\n",
                "ipa3_send_sw_flt_list",
                2717,
                *((_DWORD *)v2 + 85),
                v2[336]);
          }
        }
      }
      result = ipa_send_msg(&v29, v2, ipa3_general_free_cb);
      if ( (_DWORD)result )
      {
        v20 = result;
        printk(&unk_3A29B0, "ipa3_send_sw_flt_list");
        v21 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v22 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v22 )
          {
            ipc_log_string(
              v22,
              "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
              "ipa3_send_sw_flt_list",
              2724,
              v20,
              (unsigned __int8)v29);
            v21 = ipa3_ctx;
          }
          v23 = *(_QWORD *)(v21 + 34160);
          if ( v23 )
            ipc_log_string(
              v23,
              "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
              "ipa3_send_sw_flt_list",
              2724,
              v20,
              (unsigned __int8)v29);
        }
        kfree(v2);
        result = v20;
      }
    }
  }
  else
  {
    printk(&unk_3F482E, "ipa3_send_sw_flt_list");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d ipa_sw_flt_list_type mem-allocate failure\n", "ipa3_send_sw_flt_list", 2692);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(v26, "ipa %s:%d ipa_sw_flt_list_type mem-allocate failure\n", "ipa3_send_sw_flt_list", 2692);
    }
    result = 4294967284LL;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}

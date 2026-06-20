__int64 __fastcall ipa3_send_ippt_sw_flt_list(unsigned __int64 a1)
{
  __int64 v1; // x0
  unsigned __int8 *v2; // x19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  int v25[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h]
  int v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v25 = 0;
  v26 = 0;
  if ( inline_copy_from_user((__int64)v25, a1, 0x10u) )
  {
    printk(&unk_3CF1F5, "ipa3_send_ippt_sw_flt_list");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Copy ipa_ioc_sw_flt_list_type failure\n", "ipa3_send_ippt_sw_flt_list", 2740);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d Copy ipa_ioc_sw_flt_list_type failure\n", "ipa3_send_ippt_sw_flt_list", 2740);
        result = 4294967282LL;
        goto LABEL_16;
      }
    }
LABEL_27:
    result = 4294967282LL;
    goto LABEL_16;
  }
  if ( (_DWORD)v26 != 92 )
  {
    printk(&unk_3BD4F6, "ipa3_send_ippt_sw_flt_list");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d IPA_IOC_SET_IPPT_SW_FLT size not match(%d,%lu)!\n",
          "ipa3_send_ippt_sw_flt_list",
          2749,
          v26,
          92);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
      {
        ipc_log_string(
          v14,
          "ipa %s:%d IPA_IOC_SET_IPPT_SW_FLT size not match(%d,%lu)!\n",
          "ipa3_send_ippt_sw_flt_list",
          2749,
          v26,
          92);
        result = 4294967282LL;
        goto LABEL_16;
      }
    }
    goto LABEL_27;
  }
  v1 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 92);
  v2 = (unsigned __int8 *)v1;
  if ( v1 )
  {
    if ( inline_copy_from_user(v1, *(unsigned __int64 *)v25, 0x5Cu) )
    {
      printk(&unk_3CBB6D, "ipa3_send_ippt_sw_flt_list");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d Failed to copy ipa_ippt_sw_flt_list_type\n",
            "ipa3_send_ippt_sw_flt_list",
            2762);
          v15 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v15 + 34160);
        if ( v17 )
          ipc_log_string(
            v17,
            "ipa %s:%d Failed to copy ipa_ippt_sw_flt_list_type\n",
            "ipa3_send_ippt_sw_flt_list",
            2762);
      }
      kfree(v2);
      result = 4294967282LL;
    }
    else
    {
      v3 = ipa3_ctx;
      v27 = 6029366;
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(
            v4,
            "ipa %s:%d Num of ipv4: %d, ipv4 enable: %d \n",
            "ipa3_send_ippt_sw_flt_list",
            2772,
            *((_DWORD *)v2 + 1),
            *v2);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d Num of ipv4: %d, ipv4 enable: %d \n",
            "ipa3_send_ippt_sw_flt_list",
            2772,
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
              "ipa %s:%d Num of ports: %d, port enable: %d\n",
              "ipa3_send_ippt_sw_flt_list",
              2776,
              *((_DWORD *)v2 + 19),
              v2[72]);
            v3 = ipa3_ctx;
          }
          v7 = *(_QWORD *)(v3 + 34160);
          if ( v7 )
            ipc_log_string(
              v7,
              "ipa %s:%d Num of ports: %d, port enable: %d\n",
              "ipa3_send_ippt_sw_flt_list",
              2776,
              *((_DWORD *)v2 + 19),
              v2[72]);
        }
      }
      result = ipa_send_msg(&v27, v2, ipa3_general_free_cb);
      if ( (_DWORD)result )
      {
        v18 = result;
        printk(&unk_3A29B0, "ipa3_send_ippt_sw_flt_list");
        v19 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v20 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v20 )
          {
            ipc_log_string(
              v20,
              "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
              "ipa3_send_ippt_sw_flt_list",
              2783,
              v18,
              (unsigned __int8)v27);
            v19 = ipa3_ctx;
          }
          v21 = *(_QWORD *)(v19 + 34160);
          if ( v21 )
            ipc_log_string(
              v21,
              "ipa %s:%d ipa_send_msg failed: %d, msg_type %d\n",
              "ipa3_send_ippt_sw_flt_list",
              2783,
              v18,
              (unsigned __int8)v27);
        }
        kfree(v2);
        result = v18;
      }
    }
  }
  else
  {
    printk(&unk_3E3018, "ipa3_send_ippt_sw_flt_list");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(
          v23,
          "ipa %s:%d ipa_ippt_sw_flt_list_type mem-allocate failure\n",
          "ipa3_send_ippt_sw_flt_list",
          2756);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(
          v24,
          "ipa %s:%d ipa_ippt_sw_flt_list_type mem-allocate failure\n",
          "ipa3_send_ippt_sw_flt_list",
          2756);
    }
    result = 4294967284LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}

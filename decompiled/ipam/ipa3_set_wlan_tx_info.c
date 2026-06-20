__int64 __fastcall ipa3_set_wlan_tx_info(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  unsigned __int8 v13; // [xsp+6h] [xbp-Ah]
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v12 = 0;
  if ( (ipa_get_fnr_info(&v12) & 1) == 0 )
  {
    printk(&unk_3AA56F, "ipa3_set_wlan_tx_info");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d FNR counter haven't configured\n", "ipa3_set_wlan_tx_info", 1914);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d FNR counter haven't configured\n", "ipa3_set_wlan_tx_info", 1914);
    }
    goto LABEL_20;
  }
  if ( (unsigned int)ipa_set_flt_rt_stats((unsigned int)v13 + 2, 0, *a1) )
  {
    printk(&unk_3AA59B, "ipa3_set_wlan_tx_info");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d Failed to set stats to ul_wlan_tx %d\n", "ipa3_set_wlan_tx_info", 1924, v13 + 2);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d Failed to set stats to ul_wlan_tx %d\n",
          "ipa3_set_wlan_tx_info",
          1924,
          (unsigned int)v13 + 2);
    }
    goto LABEL_20;
  }
  result = ipa_set_flt_rt_stats((unsigned int)v13 + 3, 0, a1[1]);
  if ( (_DWORD)result )
  {
    printk(&unk_3F8915, "ipa3_set_wlan_tx_info");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Failed to set stats to dl_wlan_tx %d\n", "ipa3_set_wlan_tx_info", 1932, v13 + 3);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(
          v11,
          "ipa %s:%d Failed to set stats to dl_wlan_tx %d\n",
          "ipa3_set_wlan_tx_info",
          1932,
          (unsigned int)v13 + 3);
    }
LABEL_20:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

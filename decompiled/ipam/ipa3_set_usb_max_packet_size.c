__int64 __fastcall ipa3_set_usb_max_packet_size(__int16 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  int v6; // w0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 result; // x0
  int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // [xsp+20h] [xbp-10h] BYREF
  __int16 v15; // [xsp+24h] [xbp-Ch]
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d entry\n", "ipa3_set_usb_max_packet_size", 790);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d entry\n", "ipa3_set_usb_max_packet_size", 790);
  }
  ipa3_inc_client_enable_clks();
  v14 = 0;
  v5 = *(_QWORD *)(ipa3_ctx + 43296);
  BYTE2(v14) = 1;
  v15 = a1;
  v6 = gsi_write_device_scratch(v5, &v14);
  if ( v6 )
  {
    v10 = v6;
    printk(&unk_3F1C34, "ipa3_set_usb_max_packet_size");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d Error writing device scratch: %d\n", "ipa3_set_usb_max_packet_size", 802, v10);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d Error writing device scratch: %d\n", "ipa3_set_usb_max_packet_size", 802, v10);
    }
    result = 4294967282LL;
  }
  else
  {
    ipa3_dec_client_disable_clks();
    v7 = ipa3_ctx;
    if ( !ipa3_ctx )
    {
LABEL_12:
      result = 0;
      goto LABEL_13;
    }
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_set_usb_max_packet_size", 807);
      v7 = ipa3_ctx;
    }
    result = *(_QWORD *)(v7 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_set_usb_max_packet_size", 807);
      goto LABEL_12;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

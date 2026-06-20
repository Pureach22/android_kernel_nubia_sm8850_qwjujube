__int64 __fastcall ipa3_is_xdci_channel_empty(__int64 a1, char *a2)
{
  unsigned int v4; // w8
  __int64 v5; // x8
  bool v6; // zf
  char v7; // w8
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // [xsp+0h] [xbp-30h] BYREF
  __int64 v16; // [xsp+8h] [xbp-28h]
  __int64 v17; // [xsp+10h] [xbp-20h]
  __int64 v18; // [xsp+18h] [xbp-18h]
  __int64 v19; // [xsp+20h] [xbp-10h]
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  if ( !a1 || !a2 || !*(_DWORD *)a1 )
  {
    printk(&unk_3C0833, "ipa3_is_xdci_channel_empty");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Input Error\n", "ipa3_is_xdci_channel_empty", 1040);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d Input Error\n", "ipa3_is_xdci_channel_empty", 1040);
    }
    goto LABEL_26;
  }
  if ( (unsigned int)ipa3_get_gsi_chan_info(&v15, *(_QWORD *)(a1 + 8)) )
  {
    printk(&unk_3D8137, "ipa3_is_xdci_channel_empty");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Failed to get GSI channel info\n", "ipa3_is_xdci_channel_empty", 1046);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d Failed to get GSI channel info\n", "ipa3_is_xdci_channel_empty", 1046);
    }
LABEL_26:
    result = 4294967282LL;
    goto LABEL_15;
  }
  v4 = *(_DWORD *)(a1 + 4);
  if ( v4 <= 0x85 && (v4 & 1) != 0 )
  {
    v5 = *(_QWORD *)(a1 + 56);
    if ( v15 == v5 + *(unsigned int *)(a1 + 48) - 16 )
      v6 = v5 == v19;
    else
      v6 = v15 == v19;
  }
  else
  {
    v6 = v16 == v15;
  }
  v7 = v6;
  result = 0;
  *a2 = v7;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}

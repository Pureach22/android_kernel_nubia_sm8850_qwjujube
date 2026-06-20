__int64 __fastcall ipa3_write_mpm_uc_thresh(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v9);
  if ( v4 )
  {
    v3 = v4;
  }
  else if ( (unsigned __int8)(v9[0] - 1) > 3u )
  {
    printk(&unk_3E369B, "ipa3_write_mpm_uc_thresh");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d Invalid uc thresh =%d: range is 1 to %d\n",
          "ipa3_write_mpm_uc_thresh",
          673,
          v9[0],
          4);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d Invalid uc thresh =%d: range is 1 to %d\n",
          "ipa3_write_mpm_uc_thresh",
          673,
          v9[0],
          4);
    }
  }
  else
  {
    *(_DWORD *)(ipa3_ctx + 43288) = v9[0];
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}

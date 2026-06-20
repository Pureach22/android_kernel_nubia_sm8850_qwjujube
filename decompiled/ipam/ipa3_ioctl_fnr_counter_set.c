__int64 __fastcall ipa3_ioctl_fnr_counter_set(unsigned __int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // w4
  __int64 v6; // x8
  _BYTE *v7; // x9
  int v8; // w5
  __int64 v9; // x0
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w19
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  _QWORD v18[17]; // [xsp+8h] [xbp-88h] BYREF

  v18[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 128);
  if ( inline_copy_from_user((__int64)v18, a1, 2u) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_ioctl_fnr_counter_set__rs, "ipa3_ioctl_fnr_counter_set") )
      printk(&unk_3F47D5, "ipa3_ioctl_fnr_counter_set");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_set", 2511);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl_fnr_counter_set", 2511);
    }
    result = 4294967282LL;
    goto LABEL_18;
  }
  v5 = LOBYTE(v18[0]);
  if ( (unsigned int)LOBYTE(v18[0]) - 33 <= 0xFFFFFFDF )
  {
    v10 = LOBYTE(v18[0]);
    printk(&unk_3A8FFD, "ipa3_ioctl_fnr_counter_set");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d hw_counter_offset failed: num %d\n", "ipa3_ioctl_fnr_counter_set", 2519, v10);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d hw_counter_offset failed: num %d\n", "ipa3_ioctl_fnr_counter_set", 2519, v10);
    }
    goto LABEL_29;
  }
  v6 = ipa3_ctx;
  v7 = (_BYTE *)(ipa3_ctx + 45387);
  *(_BYTE *)(ipa3_ctx + 45388) = v18[0];
  v8 = BYTE1(v18[0]);
  if ( (unsigned int)BYTE1(v18[0]) - 33 <= 0xFFFFFFDF )
  {
    v14 = BYTE1(v18[0]);
    printk(&unk_3D7C38, "ipa3_ioctl_fnr_counter_set");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d sw_counter_offset failed: num %d\n", "ipa3_ioctl_fnr_counter_set", 2529, v14);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d sw_counter_offset failed: num %d\n", "ipa3_ioctl_fnr_counter_set", 2529, v14);
    }
LABEL_29:
    result = 0xFFFFFFFFLL;
    goto LABEL_18;
  }
  v7[2] = BYTE1(v18[0]);
  *v7 = 1;
  if ( !v6 )
  {
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  v9 = *(_QWORD *)(v6 + 34152);
  if ( v9 )
  {
    ipc_log_string(v9, "ipa %s:%d fnr_info hw=%d, hw=%d\n", "ipa3_ioctl_fnr_counter_set", 2537, v5, v8);
    v6 = ipa3_ctx;
  }
  result = *(_QWORD *)(v6 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d fnr_info hw=%d, hw=%d\n",
      "ipa3_ioctl_fnr_counter_set",
      2537,
      *(unsigned __int8 *)(v6 + 45388),
      *(unsigned __int8 *)(v6 + 45389));
    goto LABEL_17;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

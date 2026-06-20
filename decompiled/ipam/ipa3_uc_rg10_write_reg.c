__int64 __fastcall ipa3_uc_rg10_write_reg(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v4; // x2
  int v5; // w22
  int v6; // w21
  int v7; // w0
  __int64 v8; // x8
  int v9; // w22
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x0

  v4 = a2;
  if ( (*(_BYTE *)(ipa3_ctx + 43308) & 1) == 0 )
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))ipahal_write_reg_mn)(a1, 0, v4, a3);
  v5 = *(_DWORD *)(ipa3_ctx + 28640);
  v6 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 36LL);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(a1, 0, a2);
  v8 = ipa3_ctx;
  v9 = v5 + v7;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v10 )
    {
      ipc_log_string(
        v10,
        "ipa %s:%d Sending uC cmd to reg write: addr=0x%x val=0x%x\n",
        "ipa3_uc_rg10_write_reg",
        1494,
        v6 + v9,
        a3);
      v8 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v8 + 34160);
    if ( v11 )
      ipc_log_string(
        v11,
        "ipa %s:%d Sending uC cmd to reg write: addr=0x%x val=0x%x\n",
        "ipa3_uc_rg10_write_reg",
        1494,
        v6 + v9,
        a3);
  }
  result = ipa3_uc_send_cmd_64b_param(v6 + v9, a3, 9, 0, 1, 0);
  if ( (_DWORD)result )
  {
    a1 = printk(&unk_3C15B7, "ipa3_uc_rg10_write_reg");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d failed to send cmd to uC for reg write\n", "ipa3_uc_rg10_write_reg", 1498);
        v13 = ipa3_ctx;
      }
      a1 = *(_QWORD *)(v13 + 34160);
      if ( a1 )
        a1 = ipc_log_string(a1, "ipa %s:%d failed to send cmd to uC for reg write\n", "ipa3_uc_rg10_write_reg", 1498);
    }
    __break(0x800u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))ipahal_write_reg_mn)(a1, 0, v4, a3);
  }
  return result;
}

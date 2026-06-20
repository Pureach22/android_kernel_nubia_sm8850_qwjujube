__int64 __fastcall ipahal_construct_nop_imm_cmd(char a1, int a2, char a3)
{
  long double v4; // q0
  __int64 ipc_logbuf_low; // x0
  _DWORD *v6; // x8
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  __int64 v12; // [xsp+8h] [xbp-18h]
  int v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  BYTE4(v12) = a1;
  v13 = a2;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v4 = ipc_log_string(
           ipc_logbuf_low,
           "ipahal %s:%d construct IMM_CMD:%s\n",
           "ipahal_construct_imm_cmd",
           1188,
           "IPA_IMM_CMD_REGISTER_WRITE");
  }
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    __break(0x5512u);
  v6 = (_DWORD *)ipahal_imm_cmd_objs[51 * *(unsigned int *)ipahal_ctx + 21];
  if ( *(v6 - 1) != 1318571245 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, long double))v6)(7, &v11, a3 & 1, v4);
  if ( !result )
  {
    printk(&unk_3E8465, "ipahal_construct_nop_imm_cmd");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d failed to construct register_write imm cmd\n",
        "ipahal_construct_nop_imm_cmd",
        1256);
    }
    v9 = ipa3_get_ipc_logbuf_low();
    result = 0;
    if ( v9 )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipahal %s:%d failed to construct register_write imm cmd\n",
        "ipahal_construct_nop_imm_cmd",
        1256);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

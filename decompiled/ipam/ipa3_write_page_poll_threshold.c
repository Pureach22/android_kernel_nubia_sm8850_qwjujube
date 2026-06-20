__int64 __fastcall ipa3_write_page_poll_threshold(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  if ( a3 <= 0x1000 )
  {
    LODWORD(result) = kstrtou8_from_user(a2, a3, 0, v10);
    if ( (_DWORD)result )
    {
      result = (int)result;
      goto LABEL_13;
    }
    if ( (unsigned int)v10[0] - 1 > 0x1D )
    {
      printk(&unk_3A31F8, "ipa3_write_page_poll_threshold");
      v5 = ipa3_ctx;
      if ( !ipa3_ctx )
      {
LABEL_12:
        result = a3;
        goto LABEL_13;
      }
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Invalid value \n", "ipa3_write_page_poll_threshold", 3270);
        v5 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v5 + 34160);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Invalid value \n", "ipa3_write_page_poll_threshold", 3270);
        v5 = ipa3_ctx;
      }
    }
    else
    {
      v5 = ipa3_ctx;
      *(_BYTE *)(ipa3_ctx + 51103) = v10[0];
    }
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d Updated page poll threshold = %d",
          "ipa3_write_page_poll_threshold",
          3272,
          *(unsigned __int8 *)(v5 + 51103));
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(
          v7,
          "ipa %s:%d Updated page poll threshold = %d",
          "ipa3_write_page_poll_threshold",
          3272,
          *(unsigned __int8 *)(v5 + 51103));
    }
    goto LABEL_12;
  }
  result = -14;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

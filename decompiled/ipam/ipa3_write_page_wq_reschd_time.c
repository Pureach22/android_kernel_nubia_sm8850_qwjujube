__int64 __fastcall ipa3_write_page_wq_reschd_time(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // x0
  int v5; // w4
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( a3 <= 0x1000 )
  {
    LODWORD(result) = kstrtou8_from_user(a2, a3, 0, v9);
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      v5 = v9[0];
      v6 = ipa3_ctx;
      *(_DWORD *)(ipa3_ctx + 51400) = v9[0];
      if ( v6 )
      {
        v7 = *(_QWORD *)(v6 + 34152);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "ipa %s:%d Updated page WQ reschedule time = %d",
            "ipa3_write_page_wq_reschd_time",
            3238,
            v5);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
          ipc_log_string(
            v8,
            "ipa %s:%d Updated page WQ reschedule time = %d",
            "ipa3_write_page_wq_reschd_time",
            3238,
            *(_DWORD *)(v6 + 51400));
      }
      result = a3;
    }
  }
  else
  {
    result = -14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

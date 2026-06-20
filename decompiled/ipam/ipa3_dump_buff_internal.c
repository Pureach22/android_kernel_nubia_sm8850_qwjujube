__int64 __fastcall ipa3_dump_buff_internal(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x9
  __int64 v10; // x0
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = result;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  v11[0] = a2;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d system phys addr=%pa len=%u\n", "ipa3_dump_buff_internal", 10147, v11, a3);
      v5 = ipa3_ctx;
    }
    result = *(_QWORD *)(v5 + 34160);
    if ( result )
    {
      result = ipc_log_string(
                 result,
                 "ipa %s:%d system phys addr=%pa len=%u\n",
                 "ipa3_dump_buff_internal",
                 10147,
                 v11,
                 a3);
      v5 = ipa3_ctx;
    }
  }
  if ( a3 >= 4 )
  {
    v8 = 0;
    v9 = v5;
    do
    {
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d %2d %08x   %02x %02x %02x %02x\n",
            "ipa3_dump_buff_internal",
            10151,
            v8,
            *(_DWORD *)(v4 + 4 * v8),
            (unsigned __int8)*(_DWORD *)(v4 + 4 * v8),
            BYTE1(*(_DWORD *)(v4 + 4 * v8)),
            (unsigned __int8)BYTE2(*(_DWORD *)(v4 + 4 * v8)),
            HIBYTE(*(_DWORD *)(v4 + 4 * v8)));
          v5 = ipa3_ctx;
        }
        result = *(_QWORD *)(v5 + 34160);
        v9 = v5;
        if ( result )
        {
          result = ipc_log_string(
                     result,
                     "ipa %s:%d %2d %08x   %02x %02x %02x %02x\n",
                     "ipa3_dump_buff_internal",
                     10151,
                     v8,
                     *(_DWORD *)(v4 + 4 * v8),
                     (unsigned __int8)*(_DWORD *)(v4 + 4 * v8),
                     (unsigned __int8)BYTE1(*(_DWORD *)(v4 + 4 * v8)),
                     (unsigned __int8)BYTE2(*(_DWORD *)(v4 + 4 * v8)),
                     HIBYTE(*(_DWORD *)(v4 + 4 * v8)));
          v5 = ipa3_ctx;
          v9 = ipa3_ctx;
        }
      }
      ++v8;
    }
    while ( a3 >> 2 != v8 );
  }
  if ( v5 )
  {
    v7 = *(_QWORD *)(v5 + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d END\n", "ipa3_dump_buff_internal", 10153);
      v5 = ipa3_ctx;
    }
    result = *(_QWORD *)(v5 + 34160);
    if ( result )
      result = ipc_log_string(result, "ipa %s:%d END\n", "ipa3_dump_buff_internal", 10153);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

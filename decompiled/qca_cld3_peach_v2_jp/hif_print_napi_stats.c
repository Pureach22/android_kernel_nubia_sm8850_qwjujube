__int64 __fastcall hif_print_napi_stats(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x8
  unsigned __int64 v5; // x23
  __int64 i; // x27
  int v7; // w24
  int v8; // w24
  int v9; // w0
  _QWORD v10[7]; // [xsp+38h] [xbp-38h] BYREF

  v10[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v10, 0, 45);
  result = qdf_trace_msg(61, 5, "NAPI[#]CPU[#] |scheds |polls  |comps  |dones  |t-lim  |max(us)|hist(500us buckets)");
  if ( *(_DWORD *)(a1 + 27264) )
  {
    v3 = 0;
    do
    {
      if ( v3 == 18 )
LABEL_13:
        __break(0x5512u);
      v4 = *(_QWORD *)(a1 + 27120 + 8 * v3);
      if ( !v4 )
        break;
      v5 = 0;
      for ( i = v4 + 376; ; i += 72 )
      {
        result = _sw_hweight64(_cpu_possible_mask);
        if ( v5 >= (unsigned int)result )
          break;
        if ( v5 == 33 )
          goto LABEL_13;
        if ( *(_DWORD *)i )
        {
          v7 = scnprintf(v10, 45, "%u|", *(_DWORD *)(i + 56));
          v8 = scnprintf((char *)v10 + v7, 45 - v7, "%u|", *(_DWORD *)(i + 60)) + v7;
          v9 = scnprintf((char *)v10 + v8, 45 - v8, "%u|", *(_DWORD *)(i + 64));
          scnprintf((char *)v10 + v9 + v8, 45 - (v9 + v8), "%u|", *(_DWORD *)(i + 68));
          qdf_trace_msg(
            61,
            5,
            "NAPI[%d]CPU[%d]: %7u %7u %7u %7u %7u %7llu %s",
            v3,
            v5,
            *(_DWORD *)i,
            *(_DWORD *)(i + 4),
            *(_DWORD *)(i + 8),
            *(_DWORD *)(i + 12),
            *(_DWORD *)(i + 36),
            *(_QWORD *)(i + 48) / 0x3E8uLL,
            (const char *)v10);
        }
        ++v5;
      }
      ++v3;
    }
    while ( v3 < *(unsigned int *)(a1 + 27264) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

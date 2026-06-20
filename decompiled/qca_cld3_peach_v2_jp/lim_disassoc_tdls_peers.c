__int64 __fastcall lim_disassoc_tdls_peers(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int16 v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  result = dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, a1, a3, &v24, a2 + 360);
  if ( result )
  {
    if ( *(_DWORD *)(a2 + 88) == 2 )
    {
      v23 = *(_DWORD *)(result + 8);
      if ( v23 == 14 || v23 == 1 )
      {
        result = qdf_mem_cmp(a3, (const void *)(a2 + 24), 6u);
        if ( !(_DWORD)result )
          result = lim_delete_tdls_peers(a1, a2, 0);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Hash entry not found",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "lim_disassoc_tdls_peers");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

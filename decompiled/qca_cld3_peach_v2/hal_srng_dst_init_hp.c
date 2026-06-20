__int64 __fastcall hal_srng_dst_init_hp(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( a2 )
  {
    v3 = *(_QWORD *)(a2 + 160);
    *(_QWORD *)(a2 + 128) = a3;
    result = hal_write32_mb_confirm_retry(
               result,
               *(_DWORD *)(a2 + 104) + *(_DWORD *)(v3 + 74264) - *(_DWORD *)(result + 16),
               *(_DWORD *)(a2 + 136));
    if ( a3 )
    {
      **(_DWORD **)(a2 + 128) = *(_DWORD *)(a2 + 136);
      return qdf_trace_msg(
               0x45u,
               8u,
               "hp_addr=%pK, cached_hp=%d",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               *(_QWORD *)(a2 + 128));
    }
  }
  return result;
}

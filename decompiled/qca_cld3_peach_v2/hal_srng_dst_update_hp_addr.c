__int64 __fastcall hal_srng_dst_update_hp_addr(__int64 result, __int64 a2)
{
  void (__fastcall *v3)(__int64, __int64); // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && *(_QWORD *)(a2 + 128) )
  {
    v3 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(result + 74392) + 24LL);
    if ( *((_DWORD *)v3 - 1) != 1884881292 )
      __break(0x8228u);
    v3(result, a2);
    **(_DWORD **)(a2 + 128) = 0;
    result = qdf_trace_msg(0x45u, 8u, "hw_hp=%d", v4, v5, v6, v7, v8, v9, v10, v11, 0, v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall dp_init_ipa_rx_refill_buf_ring(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0 )
    return 0;
  v2 = *(_DWORD **)(a1 + 1792);
  if ( *(v2 - 1) != -386661336 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v2)(a1, a1 + 18544, 14, 2, 0);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %pK: dp_srng_init failed secondrx refill ring",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_init_ipa_rx_refill_buf_ring",
      a1);
    return 16;
  }
  return result;
}

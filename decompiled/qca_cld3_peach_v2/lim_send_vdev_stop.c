__int64 __fastcall lim_send_vdev_stop(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w21
  int v13; // w3
  __int16 v14; // w2

  v1 = *(_QWORD *)(a1 + 8608);
  result = lim_del_bss(v1, nullptr, *(unsigned __int8 *)(a1 + 10), a1);
  if ( (_DWORD)result )
  {
    v12 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: delBss failed for bss %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "lim_send_vdev_stop",
      *(unsigned __int8 *)(a1 + 10));
    v13 = *(_DWORD *)(a1 + 84);
    v14 = *(_WORD *)(a1 + 8);
    *(_DWORD *)(a1 + 80) = v13;
    qdf_trace(53, 1u, v14, v13);
    lim_send_stop_bss_response(v1, *(unsigned __int8 *)(a1 + 10), 533);
    return v12;
  }
  return result;
}

__int64 __fastcall dp_rx_dump_info_and_assert(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
    69,
    5,
    a3,
    (unsigned int)(4 * *(_DWORD *)(a2 + 44)));
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: rx_desc->nbuf: %pK, rx_desc->cookie: %d, rx_desc->pool_id: %d, rx_desc->in_use: %d, rx_desc->unmapped: %d",
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "dp_rx_desc_dump",
           *(_QWORD *)a4,
           *(unsigned int *)(a4 + 24),
           *(unsigned __int8 *)(a4 + 28),
           *(_BYTE *)(a4 + 30) & 1,
           (*(unsigned __int8 *)(a4 + 30) >> 1) & 1);
}

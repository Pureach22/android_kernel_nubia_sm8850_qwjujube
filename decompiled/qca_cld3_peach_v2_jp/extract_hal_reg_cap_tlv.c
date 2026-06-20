__int64 __fastcall extract_hal_reg_cap_tlv(
        int a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  int v24; // w10

  if ( a2 && (v11 = *(_QWORD *)(a2 + 16)) != 0 )
  {
    qdf_mem_copy(a3, (const void *)(v11 + 4), 0x24u);
    v14 = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 20LL);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Target wireless mode: 0x%x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "convert_wireless_modes_tlv",
      v14);
    result = 0;
    v24 = v14 & 0xF;
    if ( (v14 & 8) != 0 )
      v24 = v14 & 7 | 8;
    a3[4] = (v14 >> 14) & 0x80 | v14 & 0x1FFF60 | (v14 >> 3) & 0x200000 | (v14 >> 5) & 0x400000 | v24;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Invalid arguments", a4, a5, a6, a7, a8, a9, a10, a11, "extract_hal_reg_cap_tlv");
    return 16;
  }
  return result;
}

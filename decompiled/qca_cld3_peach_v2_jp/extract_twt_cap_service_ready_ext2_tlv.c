__int64 __fastcall extract_twt_cap_service_ready_ext2_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8

  if ( !a2 )
    return 4;
  v11 = *(_QWORD *)(a2 + 112);
  if ( !v11 )
    return 4;
  *(_BYTE *)a3 = *(_BYTE *)a3 & 0xFE | *(_BYTE *)(v11 + 4) & 1;
  if ( (wmi_service_enabled(a1, 0x145u, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0 )
  {
    v21 = *(_DWORD *)(v11 + 8);
    *(_WORD *)(a3 + 2) = v21;
    *(_WORD *)(a3 + 4) = HIWORD(*(_DWORD *)(v11 + 8));
    *(_DWORD *)(a3 + 6) = *(_DWORD *)(v11 + 12);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: max_wake_dur:%u min_wake_dur:%u max_wake_intvl:%u min_wake_intvl:%u",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "extract_twt_cap_service_ready_ext2_tlv",
      (unsigned __int16)v21);
  }
  return 0;
}

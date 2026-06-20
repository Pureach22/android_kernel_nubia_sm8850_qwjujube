__int64 __fastcall extract_msdu_idx_qtype_map_service_ready_ext2_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 a11,
        _BYTE *a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  int v14; // w8

  if ( !a10 || *(_DWORD *)(a10 + 136) <= (unsigned int)a11 )
    return 4;
  v14 = *(_DWORD *)(*(_QWORD *)(a10 + 128) + 8LL * a11 + 4);
  if ( (unsigned __int8)v14 == a11 )
  {
    *a12 = BYTE1(v14);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_htt_msdu_idx 0x%x is not same as idx 0x%x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_msdu_idx_qtype_map_service_ready_ext2_tlv",
      v12,
      v13);
    return 4;
  }
}

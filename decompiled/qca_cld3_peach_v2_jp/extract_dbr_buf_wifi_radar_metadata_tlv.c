__int64 __fastcall extract_dbr_buf_wifi_radar_metadata_tlv(
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
        _DWORD *a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  _DWORD *v14; // x8

  if ( !a10 )
    return 4;
  v14 = (_DWORD *)(*(_QWORD *)(a10 + 80) + 44LL * a11);
  if ( v14 )
  {
    *a12 = v14[1];
    a12[1] = v14[2];
    a12[2] = v14[3];
    a12[3] = v14[4];
    a12[4] = v14[5];
    a12[5] = v14[6];
    a12[6] = v14[7];
    a12[7] = v14[8];
    a12[8] = v14[9];
    a12[9] = v14[10];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wifi radar metadata is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dbr_buf_wifi_radar_metadata_tlv",
      v12,
      v13);
    return 16;
  }
}

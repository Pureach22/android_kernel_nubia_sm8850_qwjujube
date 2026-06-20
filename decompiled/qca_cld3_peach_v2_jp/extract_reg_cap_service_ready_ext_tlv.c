__int64 __fastcall extract_reg_cap_service_ready_ext_tlv(
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
        __int64 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // x8
  unsigned int v15; // w8
  __int64 result; // x0
  __int64 v17; // x8
  _DWORD *v18; // x20
  unsigned int v20; // w19
  int v21; // w10

  if ( !a10 )
    return 4;
  v14 = *(_QWORD *)(a10 + 64);
  if ( !v14 )
    return 4;
  v15 = *(_DWORD *)(v14 + 4);
  result = 4;
  if ( v15 > a11 && v15 <= *(_DWORD *)(a10 + 88) )
  {
    v17 = *(_QWORD *)(a10 + 80);
    if ( v17 )
    {
      v18 = (_DWORD *)(v17 + 44LL * a11);
      *(_DWORD *)a12 = v18[1];
      *(_DWORD *)(a12 + 4) = v18[2];
      *(_DWORD *)(a12 + 8) = v18[3];
      *(_DWORD *)(a12 + 12) = v18[4];
      *(_DWORD *)(a12 + 16) = v18[5];
      v20 = v18[6];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Target wireless mode: 0x%x",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "convert_wireless_modes_tlv",
        v20,
        v12,
        v13);
      result = 0;
      v21 = v20 & 0xF;
      if ( (v20 & 8) != 0 )
        v21 = v20 & 7 | 8;
      *(_QWORD *)(a12 + 24) = (v20 >> 14) & 0x80 | v20 & 0x1FFF60 | (v20 >> 3) & 0x200000 | (v20 >> 5) & 0x400000 | v21;
      *(_DWORD *)(a12 + 32) = v18[7];
      *(_DWORD *)(a12 + 36) = v18[8];
      *(_DWORD *)(a12 + 40) = v18[9];
      *(_DWORD *)(a12 + 44) = v18[10];
    }
  }
  return result;
}

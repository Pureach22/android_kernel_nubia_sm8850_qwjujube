__int64 __fastcall extract_service_ready_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int **a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  unsigned int *v13; // x8
  int v14; // w10
  __int64 result; // x0
  int v16; // w10
  int v17; // w9

  v13 = *a10;
  if ( *a10 )
  {
    v14 = *(_DWORD *)(a11 + 12);
    result = 0;
    *(_DWORD *)a11 = v13[8];
    *(_DWORD *)(a11 + 4) = v13[9];
    *(_DWORD *)(a11 + 8) = v13[10];
    v16 = v14 | v13[11] & 0xFFF;
    v17 = v16 | 0x3000;
    if ( (v13[11] & 0x40) == 0 )
      v17 = v16;
    *(_DWORD *)(a11 + 12) = v17;
    *(_DWORD *)(a11 + 16) = v13[12];
    *(_DWORD *)(a11 + 20) = v13[13];
    *(_DWORD *)(a11 + 24) = v13[14];
    *(_DWORD *)(a11 + 28) = v13[15];
    *(_DWORD *)(a11 + 32) = v13[16];
    *(_DWORD *)(a11 + 36) = v13[17];
    *(_DWORD *)(a11 + 40) = v13[18];
    *(_DWORD *)(a11 + 44) = v13[20];
    *(_DWORD *)(a11 + 48) = v13[27];
    *(_DWORD *)(a11 + 52) = v13[28];
    *(_DWORD *)(a11 + 56) = v13[30];
    *(_DWORD *)(a11 + 60) = v13[31];
    *(_DWORD *)(a11 + 64) = v13[32];
    *(_QWORD *)(a11 + 68) = v13[1];
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s: wmi_buf_alloc failed",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_service_ready_tlv",
      "extract_service_ready_tlv",
      v11,
      v12);
    return 16;
  }
  return result;
}

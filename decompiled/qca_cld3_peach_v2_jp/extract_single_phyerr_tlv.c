__int64 __fastcall extract_single_phyerr_tlv(
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
        unsigned __int16 a11,
        unsigned __int16 *a12,
        __int64 a13)
{
  __int64 v13; // x5
  int *v15; // x9
  unsigned int v16; // w8
  int v17; // w8

  v13 = *a12;
  if ( (unsigned int)v13 < a11 )
  {
    if ( a11 - (unsigned int)v13 <= 0x27 )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Not enough space. len=%d, n=%d, hdr=%zu",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_single_phyerr_tlv",
        a11);
      return 16;
    }
    v15 = (int *)(a10 + v13);
    v16 = *(_DWORD *)(a10 + v13 + 36);
    if ( v16 >= 0x7F000001 )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: buf_len is garbage 0x%x",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_single_phyerr_tlv",
        v16);
      return 16;
    }
    if ( v16 + (unsigned int)v13 > a11 )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: len exceeds n=%d, buf_len=%d, datalen=%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_single_phyerr_tlv",
        *a12,
        v16);
      return 16;
    }
    *(_DWORD *)(a13 + 40) = *((unsigned __int8 *)v15 + 10);
    v17 = *v15;
    *(_QWORD *)(a13 + 48) = v15 + 10;
    *(_DWORD *)(a13 + 44) = v17;
    *(_DWORD *)(a13 + 56) = v15[9];
    *(_BYTE *)a13 = v15[2];
    LOWORD(v13) = v13 + *((_WORD *)v15 + 18) + 44;
  }
  *a12 = v13;
  return 0;
}

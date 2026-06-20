__int64 __fastcall target_if_spectral_dump_phyerr_data_gen2(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2
  __int64 v12; // x4
  __int64 result; // x0
  unsigned int v15; // w23
  unsigned int v16; // w5
  unsigned __int16 *v17; // x0
  unsigned int v18; // w22

  if ( a2 >= 4 )
  {
    v15 = 0;
    v16 = a2;
    while ( 1 )
    {
      if ( v16 <= 3 )
      {
        v11 = "%s: Remaining PHY error data length %u too short to contain a TLV";
        v12 = v16;
        goto LABEL_3;
      }
      v17 = (unsigned __int16 *)(a1 + v15);
      v12 = *((unsigned __int8 *)v17 + 3);
      if ( (_DWORD)v12 != 187 )
      {
        v11 = "%s: Invalid signature 0x%x!";
        goto LABEL_3;
      }
      v18 = *v17 + 4;
      if ( v18 > v16 )
        break;
      result = target_if_spectral_dump_tlv_gen2();
      if ( (_DWORD)result == -1 )
        return result;
      v15 += v18;
      v16 = a2 - v15;
      if ( a2 <= v15 )
        return 0;
    }
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: TLV size %d greater than number of bytes remaining %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_dump_phyerr_data_gen2",
      v18);
  }
  else
  {
    v11 = "%s: Total PHY error data length %u too short to contain any TLVs";
    v12 = a2;
LABEL_3:
    qdf_trace_msg(0x56u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_dump_phyerr_data_gen2", v12);
  }
  return 0xFFFFFFFFLL;
}

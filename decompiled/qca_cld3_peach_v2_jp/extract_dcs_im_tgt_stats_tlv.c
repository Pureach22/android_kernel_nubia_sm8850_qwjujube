__int64 __fastcall extract_dcs_im_tgt_stats_tlv(
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
        _DWORD *a11)
{
  _DWORD *v11; // x8
  const char *v13; // x2

  if ( a10 )
  {
    v11 = *(_DWORD **)(a10 + 32);
    if ( v11 )
    {
      *a11 = v11[1];
      a11[1] = v11[2];
      a11[2] = v11[3];
      a11[3] = v11[4];
      a11[4] = v11[5];
      a11[5] = v11[6];
      a11[6] = v11[7];
      a11[7] = v11[8];
      a11[8] = v11[9];
      a11[9] = v11[10];
      a11[10] = v11[11];
      a11[11] = v11[12];
      a11[12] = v11[13];
      a11[13] = v11[14];
      a11[14] = v11[15];
      return 0;
    }
    v13 = "%s: Invalid wlan stat";
  }
  else
  {
    v13 = "%s: Invalid dcs interference event buffer";
  }
  qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_dcs_im_tgt_stats_tlv");
  return 4;
}

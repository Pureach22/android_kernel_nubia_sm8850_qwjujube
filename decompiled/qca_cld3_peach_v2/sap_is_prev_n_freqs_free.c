__int64 __fastcall sap_is_prev_n_freqs_free(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int16 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int chan_enum_for_freq; // w0
  unsigned int v17; // w8
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w8
  char *v37; // x9
  unsigned int v38; // w8
  __int64 v39; // x4
  char v40; // t1
  const char *v41; // x2

  chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(*a4, a5, a6, a7, a8, a9, a10, a11, a12);
  v17 = a4[1];
  v18 = chan_enum_for_freq;
  v27 = wlan_reg_get_chan_enum_for_freq(v17, v19, v20, v21, v22, v23, v24, v25, v26);
  v36 = 0;
  if ( v27 <= 0x65 && v18 <= 0x65 )
  {
    if ( v27 < a2 || v18 > a2 )
    {
      v41 = "%s: invalid chan index %d";
      v39 = a2;
LABEL_16:
      qdf_trace_msg(0x39u, 8u, v41, v28, v29, v30, v31, v32, v33, v34, v35, "sap_is_prev_n_freqs_free", v39);
      return 0;
    }
    if ( v18 - 1 < v27 )
    {
      v37 = (char *)(a1 + v18);
      v38 = v27 + 1;
      v39 = v18;
      while ( 1 )
      {
        v40 = *v37++;
        if ( (v40 & 1) == 0 )
          break;
        v39 = (unsigned int)(v39 + 1);
        if ( v38 == (_DWORD)v39 )
          goto LABEL_12;
      }
      v41 = "%s: chan_index %d not free";
      goto LABEL_16;
    }
    v38 = v18;
LABEL_12:
    if ( v38 - v18 < a3 )
    {
      v41 = "%s: previous %d are not validated";
      v39 = a3;
      goto LABEL_16;
    }
    return 1;
  }
  return v36;
}

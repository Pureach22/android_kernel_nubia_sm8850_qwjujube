void __fastcall lim_fill_oci_params(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned __int8 *a4,
        _WORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x0
  unsigned int v19; // w1
  char v20; // w0
  __int64 v21; // x2
  char v22; // w24
  __int64 v23; // x3
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w0
  char v34; // w8
  unsigned int v35; // w8
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int16 v54; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a1 + 21560);
  v19 = *(_DWORD *)(a2 + 284);
  v54 = 0;
  v20 = wlan_reg_freq_to_chan(v18, v19, a6, a7, a8, a9, a10, a11, a12, a13);
  v21 = *(unsigned int *)(a2 + 7176);
  v22 = v20;
  if ( (_DWORD)v21 == 2 )
  {
    v23 = 4;
  }
  else
  {
    v24 = *(_DWORD *)(a2 + 164);
    if ( v24 == 3 )
      v23 = 3;
    else
      v23 = v24 == 1;
  }
  v25 = lim_op_class_from_bandwidth(a1, *(unsigned int *)(a2 + 284), v21, v23);
  a3[2] = v22;
  a3[1] = v33;
  if ( *(_DWORD *)(a2 + 7176) == 4 )
    v34 = *(_BYTE *)(a2 + 7184);
  else
    v34 = 0;
  a3[3] = v34;
  *a3 = 1;
  if ( a5 )
  {
    v35 = *(_DWORD *)(a2 + 7176) - 1;
    if ( v35 > 6 )
    {
      *a5 = 20;
      if ( !a4 )
        goto LABEL_21;
    }
    else
    {
      *a5 = word_A0A0E8[v35];
      if ( !a4 )
        goto LABEL_21;
    }
    if ( *(_DWORD *)(a2 + 88) != 2 )
    {
      v36 = dph_lookup_hash_entry(v25, v26, v27, v28, v29, v30, v31, v32, a1, a4, &v54, a2 + 360);
      if ( v36 )
      {
        v45 = v36;
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284))
          && (unsigned __int16)*a5 >= 0x15u
          && (*(_BYTE *)(v45 + 334) & 8) == 0 )
        {
          *a5 = 20;
          qdf_trace_msg(
            0x35u,
            8u,
            "peer no support ht40 in 2g, %d :%02x:%02x:%02x:**:**:%02x",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            *(unsigned int *)(v45 + 348),
            *a4,
            a4[1],
            a4[2],
            a4[5]);
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "no find sta ds %02x:%02x:%02x:**:**:%02x",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          *a4,
          a4[1],
          a4[2],
          a4[5]);
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
}

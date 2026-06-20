__int64 __fastcall util_scan_get_phymode_11be(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19
  unsigned __int8 *v13; // x22
  unsigned __int8 v14; // w8
  const char *v15; // x2
  unsigned __int8 v16; // w8
  __int64 v17; // x19
  __int64 v18; // x20
  unsigned __int8 v19; // w21
  __int64 v20; // x23
  __int64 v21; // x20
  unsigned __int8 v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int16 v31; // w8

  v12 = a3;
  if ( *(_QWORD *)(a2 + 1800) )
  {
    v13 = *(unsigned __int8 **)(a2 + 1808);
    if ( v13 )
    {
      v14 = v13[3];
      if ( (v14 & 1) == 0 )
      {
        if ( a3 > 25 )
        {
          switch ( a3 )
          {
            case 26:
              v12 = 36;
              if ( (v13[3] & 2) != 0 )
                goto LABEL_30;
              goto LABEL_28;
            case 27:
              v12 = 37;
              if ( (v13[3] & 2) == 0 )
                goto LABEL_28;
              goto LABEL_30;
            case 29:
              v12 = 39;
              if ( (v13[3] & 2) != 0 )
                goto LABEL_30;
              goto LABEL_28;
          }
        }
        else
        {
          switch ( a3 )
          {
            case 21:
              v12 = 31;
              if ( (v13[3] & 2) != 0 )
                goto LABEL_30;
              goto LABEL_28;
            case 22:
              v12 = 32;
              break;
            case 23:
              v12 = 33;
              if ( (v13[3] & 2) != 0 )
                goto LABEL_30;
              goto LABEL_28;
          }
        }
LABEL_27:
        if ( (v14 & 2) == 0 )
        {
LABEL_28:
          *(_WORD *)(a2 + 1204) = 0;
          return v12;
        }
LABEL_30:
        if ( v13[1] > 0xAu )
        {
          v31 = v13[11];
          *(_WORD *)(a2 + 1204) = v31;
          *(_WORD *)(a2 + 1204) = v31 | (v13[12] << 8);
          return v12;
        }
        v15 = "%s: Invalid EHT OP IE len %d with dis_sc_bitmap";
        goto LABEL_32;
      }
      if ( v13[1] <= 8u )
      {
        v15 = "%s: Invalid EHT OP IE length %d with EHT OP info";
LABEL_32:
        qdf_trace_msg(0x15u, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "util_scan_get_phymode_11be");
        return v12;
      }
      v16 = v13[8];
      if ( (v16 & 7u) >= 5 )
      {
        v17 = a1;
        v18 = a2;
        v19 = a4;
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: Invalid eht_ops width: %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "util_scan_get_phymode_11be");
        v14 = v13[3];
        a1 = v17;
        a4 = v19;
        a2 = v18;
        v12 = 31;
        if ( (v14 & 1) == 0 )
          goto LABEL_27;
      }
      else
      {
        v12 = dword_AD8568[v16 & 7];
      }
      v20 = a2;
      v21 = a1;
      v22 = a4;
      *(_DWORD *)(a2 + 1196) = wlan_reg_chan_band_to_freq(a1, v13[9], a4, a5, a6, a7, a8, a9, a10, a11, a12);
      *(_DWORD *)(v20 + 1200) = wlan_reg_chan_band_to_freq(v21, v13[10], v22, v23, v24, v25, v26, v27, v28, v29, v30);
      a2 = v20;
      if ( (v13[3] & 2) != 0 )
        goto LABEL_30;
      goto LABEL_28;
    }
  }
  return v12;
}

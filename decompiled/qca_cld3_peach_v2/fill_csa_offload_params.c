__int64 __fastcall fill_csa_offload_params(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 result; // x0
  unsigned int v25; // w1
  int v26; // w8
  unsigned __int8 v27; // w1
  bool is_6ghz_op_class; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w1
  __int64 op_class_width; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int chwidth_from_bw; // w0
  unsigned __int16 v48[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v49; // [xsp+4h] [xbp-Ch] BYREF
  char v50; // [xsp+6h] [xbp-Ah]
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a3 + 80);
  v50 = 0;
  v49 = 0;
  v48[0] = 0;
  wlan_reg_read_current_country(v14, &v49, a4, a5, a6, a7, a8, a9, a10, a11);
  v23 = *(_DWORD *)(a1 + 52);
  if ( (v23 & 1) != 0 )
  {
    v25 = *(unsigned __int8 *)(a1 + 27);
    *(_BYTE *)a2 = v25;
    *(_DWORD *)(a2 + 4) = wlan_reg_legacy_chan_to_freq(a3, v25, v15, v16, v17, v18, v19, v20, v21, v22);
    v26 = 1;
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a1 + 26);
LABEL_9:
    result = 1;
    *(_DWORD *)(a2 + 24) |= v26;
    goto LABEL_10;
  }
  if ( (v23 & 2) != 0 )
  {
    *(_BYTE *)a2 = *(_BYTE *)(a1 + 36);
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a1 + 34);
    v27 = *(_BYTE *)(a1 + 35);
    *(_BYTE *)(a2 + 18) = v27;
    is_6ghz_op_class = wlan_reg_is_6ghz_op_class(a3, v27);
    v37 = *(unsigned __int8 *)(a1 + 36);
    if ( is_6ghz_op_class )
    {
      *(_DWORD *)(a2 + 4) = wlan_reg_chan_band_to_freq(a3, v37, 4u, v29, v30, v31, v32, v33, v34, v35, v36);
      op_class_width = wlan_reg_get_op_class_width();
    }
    else
    {
      *(_DWORD *)(a2 + 4) = wlan_reg_legacy_chan_to_freq(a3, v37, v29, v30, v31, v32, v33, v34, v35, v36);
      op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                         (unsigned __int8 *)&v49,
                         *(_BYTE *)(a1 + 36),
                         *(_BYTE *)(a1 + 35),
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46);
    }
    wlan_reg_convert_chan_spacing_to_width(op_class_width, (__int16 *)v48);
    chwidth_from_bw = wlan_reg_find_chwidth_from_bw(v48[0]);
    v26 = 2;
    *(_DWORD *)(a2 + 12) = chwidth_from_bw;
    goto LABEL_9;
  }
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}

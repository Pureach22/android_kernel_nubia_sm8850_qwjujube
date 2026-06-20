__int64 __fastcall lim_update_channel_width(__int64 a1, _BYTE *a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  int v9; // w25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  char v28; // w0
  int v29; // w25
  unsigned int v30; // w8
  unsigned int max_bw; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w24
  __int64 v41; // x27
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char v50; // w8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v60; // [xsp+0h] [xbp-20h]
  __int64 v61; // [xsp+8h] [xbp-18h]

  v9 = *(unsigned __int8 *)(a1 + 17196);
  if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284)) )
  {
LABEL_6:
    if ( !v9 )
      goto LABEL_16;
    if ( (a2[346] & 8) != 0 )
    {
      v30 = (unsigned __int8)a2[357];
      if ( v30 > 3 )
        v29 = 3;
      else
        v29 = v30 + 1;
    }
    else
    {
      v29 = 0;
    }
    max_bw = wlan_mlme_get_max_bw();
    if ( max_bw >= a4 )
    {
      v40 = a4;
      if ( v29 == a4 )
        goto LABEL_16;
    }
    else
    {
      v40 = max_bw;
      v41 = jiffies;
      if ( lim_update_channel_width___last_ticks - jiffies + 125 < 0 )
      {
        v40 = max_bw;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x: Downgrade new bw: %d to max %d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "lim_update_channel_width",
          (unsigned __int8)a2[350],
          (unsigned __int8)a2[351],
          (unsigned __int8)a2[352],
          (unsigned __int8)a2[355],
          a4,
          max_bw);
        max_bw = v40;
        lim_update_channel_width___last_ticks = v41;
      }
      if ( v29 == v40 )
        goto LABEL_16;
    }
    LODWORD(v61) = v40;
    LODWORD(v60) = v29;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: Current : %d, New: %d max %d ",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_update_channel_width",
      (unsigned __int8)a2[350],
      (unsigned __int8)a2[351],
      (unsigned __int8)a2[352],
      (unsigned __int8)a2[355],
      v60,
      v61,
      max_bw);
    if ( v40 == 4 )
    {
      a2[357] = 3;
    }
    else if ( v40 < 3 )
    {
      a2[357] = v40 == 2;
      if ( !v40 )
      {
        v50 = a2[346] & 0xF7;
        goto LABEL_24;
      }
    }
    else
    {
      a2[357] = 2;
    }
    v50 = a2[346] | 8;
LABEL_24:
    a2[346] = v50;
    *a5 = v40;
    lim_update_bcn_op_ch_width(*(_QWORD *)(a3 + 16), v40, v42, v43, v44, v45, v46, v47, v48, v49);
    v28 = lim_check_vht_op_mode_change((_QWORD *)a1, a3, *a5, a2 + 350, v51, v52, v53, v54, v55, v56, v57, v58);
    return v28 & 1;
  }
  if ( (wlan_cm_get_force_20mhz_in_24ghz(*(_QWORD *)(a3 + 16), v11, v12, v13, v14, v15, v16, v17, v18) & 1) == 0 )
  {
    v9 = *(unsigned __int8 *)(a1 + 17192);
    goto LABEL_6;
  }
  v27 = jiffies;
  if ( lim_get_cb_mode_for_freq___last_ticks - jiffies + 125 >= 0 )
  {
LABEL_16:
    v28 = 0;
    return v28 & 1;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d force 20 Mhz in 2.4 GHz",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "lim_get_cb_mode_for_freq",
    *(unsigned __int8 *)(a3 + 10));
  v28 = 0;
  lim_get_cb_mode_for_freq___last_ticks = v27;
  return v28 & 1;
}

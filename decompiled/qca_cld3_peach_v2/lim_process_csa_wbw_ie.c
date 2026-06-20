__int64 __fastcall lim_process_csa_wbw_ie(__int64 a1, __int64 a2, _BYTE *a3, __int64 a4)
{
  int vht_ch_width; // w0
  unsigned int v9; // w25
  int v10; // w23
  int v11; // w26
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w24
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int16 v29; // w0
  __int64 v30; // x2
  __int64 v31; // x3
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x1
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  int v50; // w9
  __int64 v51; // x21
  int v52; // w8
  unsigned int v53; // w8
  unsigned int v54; // w8
  unsigned int v55; // w23
  __int64 v56; // x0
  unsigned int v57; // w1
  char v58; // w9
  __int64 result; // x0
  const char *v60; // x2
  unsigned int v61; // w1
  __int64 v62; // x4
  int v63; // w8
  int v64; // w8
  int v65; // w9
  unsigned int v66; // [xsp+0h] [xbp-20h] BYREF
  __int64 v67; // [xsp+4h] [xbp-1Ch]
  __int64 v68; // [xsp+Ch] [xbp-14h]
  int v69; // [xsp+14h] [xbp-Ch]
  __int64 v70; // [xsp+18h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v68 = 0;
  v67 = 0;
  vht_ch_width = wma_get_vht_ch_width(a1);
  v9 = *(_DWORD *)(a2 + 12);
  v10 = vht_ch_width;
  if ( !*(_BYTE *)(a2 + 19) && !*(_BYTE *)(a2 + 20) )
    goto LABEL_46;
  v11 = *(_DWORD *)(a2 + 4);
  if ( !wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21632), *(_BYTE *)(a2 + 18)) )
  {
    v20 = wlan_reg_legacy_chan_to_freq(
            *(_QWORD *)(a1 + 21632),
            *(unsigned __int8 *)(a2 + 19),
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    v40 = (unsigned int)wlan_reg_legacy_chan_to_freq(
                          *(_QWORD *)(a1 + 21632),
                          *(unsigned __int8 *)(a2 + 20),
                          v41,
                          v42,
                          v43,
                          v44,
                          v45,
                          v46,
                          v47,
                          v48);
    if ( v9 == 4 )
      goto LABEL_29;
LABEL_9:
    if ( v9 != 3 )
    {
      if ( v9 != 2 )
      {
        v60 = "%s: CSA wide BW IE has ch_width %d";
        v61 = 8;
        v62 = v9;
LABEL_45:
        qdf_trace_msg(0x35u, v61, v60, v32, v33, v34, v35, v36, v37, v38, v39, "lim_process_csa_wbw_ie", v62);
        goto LABEL_46;
      }
      v49 = *(unsigned __int8 *)(a2 + 20);
      if ( *(_BYTE *)(a2 + 20) )
      {
        v50 = v49 - *(unsigned __int8 *)(a2 + 19);
        if ( v50 < 0 )
          v50 = *(unsigned __int8 *)(a2 + 19) - v49;
        if ( v50 == 8 )
        {
          *(_WORD *)(a2 + 19) = (unsigned __int8)v49;
LABEL_19:
          v52 = v40 - v11;
          if ( (int)v40 - v11 < 0 )
            v52 = v11 - v40;
          v53 = v52 - 10;
          if ( v53 > 0x3C || ((1LL << v53) & 0x1000010000100001LL) == 0 )
          {
            printk(&unk_95F115, v40, v30, v31);
            goto LABEL_46;
          }
          v54 = 3;
          goto LABEL_24;
        }
        if ( (unsigned int)v50 > 8 )
          goto LABEL_29;
      }
      if ( (int)(v20 - v11) >= 0 )
        v65 = v20 - v11;
      else
        v65 = v11 - v20;
      v54 = 2;
      if ( v65 == 10 || v65 == 30 )
        goto LABEL_24;
      goto LABEL_43;
    }
    v40 = v20;
    goto LABEL_19;
  }
  v20 = (unsigned __int16)wlan_reg_chan_opclass_to_freq(
                            *(_BYTE *)(a2 + 19),
                            *(_BYTE *)(a2 + 18),
                            0,
                            v12,
                            v13,
                            v14,
                            v15,
                            v16,
                            v17,
                            v18,
                            v19);
  v29 = wlan_reg_chan_opclass_to_freq(
          *(_BYTE *)(a2 + 20),
          *(_BYTE *)(a2 + 18),
          0,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28);
  if ( !v20 || !v29 )
  {
    v51 = jiffies;
    if ( lim_process_csa_wbw_ie___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Invalid op_class %d ch_seg_1 %d ch_seg_2 %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "lim_process_csa_wbw_ie",
        *(unsigned __int8 *)(a2 + 18),
        *(unsigned __int8 *)(a2 + 19),
        *(unsigned __int8 *)(a2 + 20));
      lim_process_csa_wbw_ie___last_ticks = v51;
    }
    goto LABEL_46;
  }
  v40 = v29;
  if ( v9 != 4 )
    goto LABEL_9;
LABEL_29:
  v63 = v20 - v11;
  if ( (int)(v20 - v11) < 0 )
    v63 = v11 - v20;
  if ( v63 != 10 && v63 != 30 )
  {
LABEL_43:
    v60 = "%s: CSA WBW 80MHz has invalid seg0 freq %d";
    v61 = 2;
    v62 = v20;
    goto LABEL_45;
  }
  if ( !(_DWORD)v40 )
  {
    v60 = "%s: CSA WBW 80MHz has invalid seg1 freq %d";
    v61 = 2;
    v62 = 0;
    goto LABEL_45;
  }
  v64 = v20 - v40;
  if ( (int)(v20 - v40) < 0 )
    v64 = v40 - v20;
  if ( v64 == 80 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: CSA WBW wrong bandwidth",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_process_csa_wbw_ie");
LABEL_46:
    result = 4;
    goto LABEL_47;
  }
  v54 = 4;
LABEL_24:
  v55 = v10 + 1;
  if ( v54 > v55 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: New BW is not supported, downgrade BW to %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_process_csa_wbw_ie",
      v55);
    v54 = v55;
  }
  v56 = *(_QWORD *)(a1 + 21632);
  v57 = *(_DWORD *)(a2 + 4);
  v66 = v54;
  wlan_reg_set_channel_params_for_pwrmode(v56, v57, 0, (__int64)&v66, 0, v32, v33, v34, v35, v36, v37, v38, v39);
  v58 = v66;
  result = 0;
  *(_WORD *)(a2 + 19) = *(_WORD *)((char *)&v67 + 1);
  *(_DWORD *)(a4 + 7200) = 2;
  *a3 = v58;
  a3[1] = *(_BYTE *)(a2 + 19);
  a3[2] = *(_BYTE *)(a2 + 20);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}

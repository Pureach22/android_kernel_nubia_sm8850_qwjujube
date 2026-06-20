__int64 __fastcall tdls_set_peer_caps(
        __int64 *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x24
  _BYTE *peer; // x0
  unsigned int v27; // w9
  _BYTE *v28; // x20
  int v29; // w10
  int v30; // w9
  unsigned __int8 v31; // w22
  const char *v32; // x2
  const char *v33; // x2
  const char *v34; // x3
  __int64 result; // x0
  _BYTE *v36; // x23
  unsigned __int8 v37; // w11
  unsigned __int8 v38; // w8
  __int64 v39; // x22
  int v40; // w26
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w9
  unsigned __int64 v51; // x24
  bool is_5ghz_ch_freq; // w28
  char v53; // w26
  unsigned int v54; // w27
  bool is_6ghz_chan_freq; // w0
  unsigned int v56; // w8
  unsigned int v57; // w25
  unsigned int chan_enum_for_freq; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w10
  bool v68; // zf
  unsigned __int16 max_chwidth; // w23
  unsigned __int64 v70; // x24
  unsigned int v71; // w25
  unsigned __int16 op_class_width; // w0
  unsigned int v73; // w21
  char v74; // w8
  _BYTE *v75; // x9
  bool v76; // w0
  char v77; // w2
  unsigned __int8 opclass_from_bandwidth; // w0
  __int64 v79; // x4
  __int64 v80; // x5
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // [xsp+4h] [xbp-1Ch]
  int v90; // [xsp+8h] [xbp-18h]
  unsigned int v91; // [xsp+Ch] [xbp-14h]
  unsigned int v92; // [xsp+10h] [xbp-10h]
  char v93[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v94; // [xsp+18h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*a1 )
  {
    v32 = "%s: NULL vdev";
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(*a1 + 216);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v32 = "%s: can't get psoc";
LABEL_10:
    qdf_trace_msg(0, 2u, v32, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_11:
    v33 = "%s: NULL psoc object";
    v34 = "tdls_set_peer_caps";
LABEL_12:
    result = qdf_trace_msg(0, 2u, v33, v17, v18, v19, v20, v21, v22, v23, v24, v34);
    goto LABEL_13;
  }
  v25 = comp_private_obj;
  peer = tdls_find_peer((__int64)a1, a2);
  if ( !peer )
  {
    v33 = "%s: NULL tdls peer";
    v34 = "tdls_set_peer_caps";
    goto LABEL_12;
  }
  v27 = a3[21];
  v28 = peer;
  v29 = (v27 >> 4) & 1;
  v30 = (v27 >> 6) & 1;
  if ( (*(_BYTE *)(v25 + 156) & 2) != 0 )
    v31 = a3[581];
  else
    v31 = 0;
  v36 = peer + 56;
  peer[48] = a3[145];
  v37 = a3[146];
  peer[50] = v29;
  peer[51] = v30;
  peer[49] = v37;
  qdf_mem_copy(peer + 56, a3 + 148, 4 * (unsigned int)a3[147]);
  v28[52] = a3[147];
  qdf_mem_copy(v28 + 457, a3 + 549, a3[548]);
  v38 = a3[548];
  v28[688] = v31;
  v93[0] = 0;
  v28[456] = v38;
  v39 = *(_QWORD *)(*a1 + 216);
  if ( !v39 )
  {
    v33 = "%s: pdev is NULL";
    v34 = "tdls_update_off_chan_peer_caps";
    goto LABEL_12;
  }
  v40 = *(_DWORD *)(v25 + 164);
  v41 = wlan_reg_legacy_chan_to_freq(
          *(_QWORD *)(*a1 + 216),
          *(_DWORD *)(v25 + 160),
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24);
  v50 = *((_DWORD *)v28 + 123);
  v91 = v41;
  if ( !v28[52] )
  {
    v54 = 0;
    v67 = 0;
    v51 = 0;
    v57 = *((_DWORD *)v28 + 123);
    goto LABEL_43;
  }
  v89 = *((_DWORD *)v28 + 123);
  v90 = v40;
  v51 = 0;
  is_5ghz_ch_freq = 0;
  v53 = 0;
  v54 = 0;
  v92 = 0;
  do
  {
    if ( v51 == 100 )
      goto LABEL_77;
    v57 = *(_DWORD *)&v36[4 * v51];
    chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(v57, v42, v43, v44, v45, v46, v47, v48, v49);
    if ( (wlan_reg_is_freq_idx_enabled(v39, chan_enum_for_freq, 6u, v59, v60, v61, v62, v63, v64, v65, v66) & 1) != 0 )
    {
      if ( wlan_reg_is_6ghz_chan_freq(v57)
        && (wlan_reg_is_6ghz_psc_chan_freq(v57, v42, v43, v44, v45, v46, v47, v48, v49) & 1) == 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: skipping non-psc channel %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "tdls_update_off_chan_peer_caps",
          v57);
      }
      else
      {
        if ( *((_DWORD *)v28 + 123) == v57 )
          goto LABEL_41;
        if ( v91 == v57 )
          v54 = v91;
        if ( v91 == v57 || is_5ghz_ch_freq )
        {
          is_5ghz_ch_freq = 1;
          if ( (v53 & 1) != 0 )
            goto LABEL_36;
        }
        else
        {
          is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v57);
          if ( is_5ghz_ch_freq )
            v54 = v57;
          if ( (v53 & 1) != 0 )
          {
LABEL_36:
            v53 = 1;
            goto LABEL_22;
          }
        }
        is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(v57);
        v56 = v92;
        v53 = is_6ghz_chan_freq;
        if ( is_6ghz_chan_freq )
          v56 = v57;
        v92 = v56;
      }
    }
LABEL_22:
    ++v51;
  }
  while ( v51 < (unsigned __int8)v28[52] );
  if ( (unsigned __int8)v51 > 0x63u )
    goto LABEL_77;
  v57 = *((_DWORD *)v28 + 123);
LABEL_41:
  v50 = v89;
  v40 = v90;
  v67 = v92;
LABEL_43:
  if ( v57 != *(_DWORD *)&v36[4 * v51] )
  {
    if ( v67 )
      v68 = v40 == v50;
    else
      v68 = 0;
    if ( v68 )
      v57 = v67;
    else
      v57 = v54;
    *((_DWORD *)v28 + 123) = v57;
  }
  max_chwidth = wlan_reg_get_max_chwidth(v39, v57, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( v28[456] )
  {
    v70 = 0;
    LOWORD(v71) = 0;
    while ( v70 != 32 )
    {
      op_class_width = wlan_reg_get_op_class_width();
      ++v70;
      if ( op_class_width <= (unsigned int)(unsigned __int16)v71 )
        v71 = (unsigned __int16)v71;
      else
        v71 = op_class_width;
      if ( v70 >= (unsigned __int8)v28[456] )
        goto LABEL_60;
    }
LABEL_77:
    __break(0x5512u);
  }
  v71 = 0;
LABEL_60:
  if ( v71 >= max_chwidth )
    v73 = max_chwidth;
  else
    v73 = v71;
  if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v28 + 123)) && v73 <= 0x9F )
  {
    v74 = v28[496];
    v28[496] = v74 & 0xF7;
    if ( v73 > 0x4F )
      goto LABEL_73;
    v75 = v28 + 496;
    v28[496] = v74 & 0xF3;
    if ( v73 >= 0x28 )
      goto LABEL_73;
LABEL_72:
    *v75 = v74 & 0xF1;
    goto LABEL_73;
  }
  if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v28 + 123)) && v73 <= 0x4F )
  {
    v74 = v28[496];
    v28[496] = v74 & 0xF3;
    if ( v73 <= 0x27 )
    {
      v75 = v28 + 496;
      goto LABEL_72;
    }
  }
LABEL_73:
  v76 = wlan_reg_is_5ghz_ch_freq(*((_DWORD *)v28 + 123));
  v77 = v28[496];
  if ( v76 && (v28[496] & 8) != 0 )
  {
    v77 &= ~8u;
    v28[496] = v77;
  }
  opclass_from_bandwidth = tdls_get_opclass_from_bandwidth(*a1, *((unsigned int *)v28 + 123), v77, v93);
  v79 = *((unsigned int *)v28 + 123);
  v80 = (unsigned __int8)v28[496];
  v28[490] = opclass_from_bandwidth;
  result = qdf_trace_msg(
             0,
             8u,
             "%s: Updated preff offchannel freq %d width %d opclass %d",
             v81,
             v82,
             v83,
             v84,
             v85,
             v86,
             v87,
             v88,
             "tdls_update_off_chan_peer_caps",
             v79,
             v80,
             opclass_from_bandwidth);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

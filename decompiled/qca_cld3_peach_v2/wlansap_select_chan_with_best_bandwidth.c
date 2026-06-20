__int64 __fastcall wlansap_select_chan_with_best_bandwidth(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *context; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  _QWORD *v28; // x25
  _QWORD *v29; // x0
  _QWORD *v30; // x24
  const char *v31; // x2
  unsigned int v32; // w1
  int v33; // w8
  __int16 v34; // w9
  unsigned int next_lower_bandwidth; // w25
  unsigned __int16 v36; // w8
  __int64 v37; // x27
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  unsigned int v47; // w1
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int16 v64; // w0
  __int64 v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w9
  unsigned int v76; // w10
  __int64 v77; // x6
  __int64 v78; // x7
  __int64 v79; // x8
  unsigned int v80; // w10
  unsigned __int16 bw_value; // w8
  int v82; // w5
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v96; // [xsp+0h] [xbp-110h]
  unsigned __int16 v97; // [xsp+14h] [xbp-FCh] BYREF
  __int64 v98; // [xsp+18h] [xbp-F8h] BYREF
  __int64 v99; // [xsp+20h] [xbp-F0h]
  __int64 v100; // [xsp+28h] [xbp-E8h]
  _QWORD v101[25]; // [xsp+30h] [xbp-E0h] BYREF
  int v102; // [xsp+F8h] [xbp-18h]
  __int64 v103; // [xsp+100h] [xbp-10h]

  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v99 = 0;
  v100 = 0;
  v98 = 0;
  v102 = 0;
  memset(v101, 0, sizeof(v101));
  v97 = 0;
  context = _cds_get_context(64, (__int64)"wlansap_select_chan_with_best_bandwidth", a6, a7, a8, a9, a10, a11, a12, a13);
  result = 4;
  if ( !a4 || !a5 )
    goto LABEL_14;
  if ( !context )
  {
    v31 = "%s: invalid qdf_ctx";
LABEL_11:
    v32 = 2;
    goto LABEL_12;
  }
  v28 = context;
  v29 = _cds_get_context(53, (__int64)"sap_get_mac_context", v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !v29 )
  {
    v31 = "%s: Invalid MAC context";
    goto LABEL_11;
  }
  v30 = v29;
  if ( (unsigned int)policy_mgr_mode_specific_connection_count(v29[2703], 0, nullptr)
    || (unsigned int)policy_mgr_mode_specific_connection_count(v30[2703], 2, nullptr)
    || (unsigned int)policy_mgr_mode_specific_connection_count(v30[2703], 3, nullptr) )
  {
    v31 = "%s: sta/p2p mode active, skip!";
    v32 = 8;
LABEL_12:
    qdf_trace_msg(0x39u, v32, v31, v19, v20, v21, v22, v23, v24, v25, v26, "wlansap_select_chan_with_best_bandwidth");
LABEL_13:
    result = 4;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  cnss_utils_get_wlan_unsafe_channel(v28[5], v101, &v97, 204);
  v33 = v97;
  if ( v97 >= 0x66u )
    v34 = 102;
  else
    v34 = v97;
  v97 = v34;
  if ( !v33 )
    goto LABEL_13;
  next_lower_bandwidth = *(unsigned __int16 *)(a1 + 1498);
  while ( !a3 )
  {
LABEL_39:
    next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth(next_lower_bandwidth);
    bw_value = wlan_reg_get_bw_value(next_lower_bandwidth);
    result = 4;
    if ( next_lower_bandwidth == 8 || bw_value <= 0x13u )
      goto LABEL_14;
  }
  v36 = 0;
  while ( 1 )
  {
    v37 = v36;
    if ( (wlan_reg_is_same_band_freqs(*(_DWORD *)a1, *(_DWORD *)(a2 + 4LL * v36)) & 1) != 0
      && (!wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 4 * v37))
       || (wlan_reg_is_6ghz_psc_chan_freq(*(_DWORD *)(a2 + 4 * v37), v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0) )
    {
      qdf_mem_set(&v98, 0x18u, 0);
      v46 = v30[2704];
      v47 = *(_DWORD *)(a2 + 4 * v37);
      LODWORD(v98) = next_lower_bandwidth;
      wlan_reg_set_channel_params_for_pwrmode(v46, v47, 0, (__int64)&v98, 0, v48, v49, v50, v51, v52, v53, v54, v55);
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 4 * v37))
        || (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                           v30[2704],
                           *(_DWORD *)(a2 + 4 * v37),
                           (int *)&v98,
                           0,
                           v56,
                           v57,
                           v58,
                           v59,
                           v60,
                           v61,
                           v62,
                           v63) == 3 )
      {
        v64 = wlan_reg_get_bw_value(v98);
        if ( (_DWORD)v99 )
        {
          _X28 = v64;
          v66 = wlan_reg_get_bw_value(next_lower_bandwidth);
          if ( (unsigned int)_X28 >= (unsigned __int16)v66 )
            break;
        }
      }
    }
LABEL_22:
    v36 = v37 + 1;
    if ( a3 <= (unsigned __int16)(v37 + 1) )
      goto LABEL_39;
  }
  v75 = v99;
  v76 = (unsigned int)_X28 >> 1;
  if ( HIDWORD(v99) )
    v75 = HIDWORD(v99);
  v77 = v75 - v76 + 10;
  v78 = v76 + v75 - 10;
  if ( !v97 )
  {
LABEL_42:
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: ch_freq %d bw %d bw start %d, bw end %d",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "wlansap_select_chan_with_best_bandwidth",
      *(unsigned int *)(a2 + 4 * v37),
      (unsigned int)_X28,
      v77,
      v78);
    v82 = v98;
    *a4 = *(_DWORD *)(a2 + 4 * v37);
    *a5 = v82;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: selected freq %d bw %d",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "wlansap_select_chan_with_best_bandwidth",
      *a4);
    result = 0;
    goto LABEL_14;
  }
  v79 = 0;
  while ( v79 != 204 )
  {
    v80 = *(unsigned __int16 *)((char *)v101 + v79);
    if ( (unsigned int)v77 <= v80 && (unsigned int)v78 >= v80 )
    {
      LODWORD(v96) = *(unsigned __int16 *)((char *)v101 + v79);
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: ch_freq %d bw %d bw start %d, bw end %d unsafe %d",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "wlansap_select_chan_with_best_bandwidth",
        *(unsigned int *)(a2 + 4 * v37),
        (unsigned int)_X28,
        v96);
      goto LABEL_22;
    }
    v79 += 2;
    if ( 2LL * v97 == v79 )
      goto LABEL_42;
  }
  __break(0x5512u);
  __break(1u);
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlansap_get_2g_first_safe_chan_freq(v66);
}

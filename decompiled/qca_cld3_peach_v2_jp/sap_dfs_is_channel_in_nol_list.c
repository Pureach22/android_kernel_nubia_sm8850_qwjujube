bool __fastcall sap_dfs_is_channel_in_nol_list(
        __int64 a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x26
  int v24; // w0
  unsigned int v25; // w1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  unsigned int v44; // w1
  unsigned int v45; // w25
  char v46; // w19
  unsigned int v47; // w22
  unsigned int v48; // w24
  unsigned int v49; // w23
  unsigned int v50; // w21
  unsigned int v51; // w12
  char v52; // w27
  char v53; // w28
  const char *v54; // x2
  _BOOL8 result; // x0
  unsigned int v56; // w8
  unsigned int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int channel_state_from_secondary_list_for_freq; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  int v84; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  char v93; // w8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v118; // [xsp+Ch] [xbp-4h]

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    v54 = "%s: Invalid MAC context";
LABEL_11:
    qdf_trace_msg(0x39u, 2u, v54, v15, v16, v17, v18, v19, v20, v21, v22, "sap_dfs_is_channel_in_nol_list");
    return 0;
  }
  v23 = context[2695];
  if ( !v23 )
  {
    v54 = "%s: null pdev";
    goto LABEL_11;
  }
  v24 = wlan_reg_legacy_chan_to_freq(
          context[2695],
          *(unsigned __int8 *)(a1 + 1505),
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22);
  v25 = *(unsigned __int8 *)(a1 + 1506);
  *(_DWORD *)(a1 + 1508) = v24;
  v34 = wlan_reg_legacy_chan_to_freq(v23, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  *(_DWORD *)(a1 + 1512) = v34;
  if ( (unsigned int)a3 < 0xB || *(_DWORD *)a1 != a2 )
  {
    v45 = 0;
    v46 = 1;
    if ( a3 > 7 )
    {
      switch ( a3 )
      {
        case 8:
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v52 = 0;
          v44 = a2 - 20;
          v47 = a2 + 20;
          v56 = a2 + 40;
          v45 = a2;
          goto LABEL_32;
        case 9:
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v52 = 0;
          v44 = a2 - 40;
          v45 = a2 - 20;
          v56 = a2 + 20;
          v47 = a2;
          goto LABEL_32;
        case 10:
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v52 = 0;
          v44 = a2 - 60;
          v45 = a2 - 40;
          v47 = a2 - 20;
          v53 = 1;
          goto LABEL_33;
      }
    }
    else
    {
      switch ( a3 )
      {
        case 1:
          v47 = 0;
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v53 = 0;
          v45 = a2 + 20;
          v52 = 1;
          v44 = a2;
          a2 = 0;
          goto LABEL_33;
        case 3:
          v47 = 0;
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v53 = 0;
          v44 = a2 - 20;
          v52 = 1;
          v45 = a2;
          a2 = 0;
          goto LABEL_33;
        case 7:
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v51 = 0;
          v46 = 0;
          v52 = 0;
          v45 = a2 + 20;
          v47 = a2 + 40;
          v56 = a2 + 60;
          v44 = a2;
LABEL_32:
          v53 = 1;
          a2 = v56;
          goto LABEL_33;
      }
    }
    v44 = a2;
    v47 = 0;
    a2 = 0;
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    goto LABEL_33;
  }
  v43 = *(_DWORD *)(a1 + 1500);
  v44 = *(_DWORD *)(a1 + 1508);
  v45 = 0;
  v46 = 1;
  if ( v43 > 2 )
  {
    if ( v43 == 4 )
    {
      v46 = 0;
      v52 = 0;
      v53 = 0;
      v45 = v44 - 10;
      v47 = v44 + 10;
      a2 = v44 + 30;
      v44 -= 30;
      v48 = v34 - 30;
      v49 = v34 - 10;
      v50 = v34 + 10;
      v51 = v34 + 30;
    }
    else
    {
      v47 = 0;
      a2 = 0;
      v48 = 0;
      v49 = 0;
      v50 = 0;
      v51 = 0;
      v52 = 0;
      v53 = 0;
      if ( v43 == 3 )
      {
        v46 = 0;
        v52 = 0;
        v53 = 0;
        v44 = v34 - 70;
        v45 = v34 - 50;
        v47 = v34 - 30;
        a2 = v34 - 10;
        v48 = v34 + 10;
        v49 = v34 + 30;
        v50 = v34 + 50;
        v51 = v34 + 70;
      }
    }
  }
  else if ( v43 == 1 )
  {
    v47 = 0;
    a2 = 0;
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v46 = 0;
    v53 = 0;
    v45 = v44 + 10;
    v52 = 1;
    v44 -= 10;
  }
  else
  {
    v47 = 0;
    a2 = 0;
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    if ( v43 == 2 )
    {
      v48 = 0;
      v49 = 0;
      v50 = 0;
      v51 = 0;
      v46 = 0;
      v52 = 0;
      v45 = v44 - 10;
      v47 = v44 + 10;
      a2 = v44 + 30;
      v53 = 1;
      v44 -= 30;
    }
  }
LABEL_33:
  v118 = v51;
  v57 = wlan_reg_get_channel_state_from_secondary_list_for_freq(v23, v44, v35, v36, v37, v38, v39, v40, v41, v42) - 4;
  result = v57 < 0xFFFFFFFE;
  if ( v57 >= 0xFFFFFFFE && (v46 & 1) == 0 )
  {
    channel_state_from_secondary_list_for_freq = wlan_reg_get_channel_state_from_secondary_list_for_freq(
                                                   v23,
                                                   v45,
                                                   v58,
                                                   v59,
                                                   v60,
                                                   v61,
                                                   v62,
                                                   v63,
                                                   v64,
                                                   v65);
    v75 = (unsigned int)(channel_state_from_secondary_list_for_freq - 4) < 0xFFFFFFFE ? 1 : v52;
    result = (unsigned int)(channel_state_from_secondary_list_for_freq - 4) < 0xFFFFFFFE;
    if ( (v75 & 1) == 0 )
    {
      if ( (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                           v23,
                           v47,
                           v67,
                           v68,
                           v69,
                           v70,
                           v71,
                           v72,
                           v73,
                           v74)
         - 4 < 0xFFFFFFFE )
        return 1;
      v84 = wlan_reg_get_channel_state_from_secondary_list_for_freq(v23, a2, v76, v77, v78, v79, v80, v81, v82, v83);
      if ( (unsigned int)(v84 - 4) < 0xFFFFFFFE )
        v93 = 1;
      else
        v93 = v53;
      result = (unsigned int)(v84 - 4) < 0xFFFFFFFE;
      if ( (v93 & 1) == 0 )
      {
        if ( (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                             v23,
                             v48,
                             v85,
                             v86,
                             v87,
                             v88,
                             v89,
                             v90,
                             v91,
                             v92)
           - 4 < 0xFFFFFFFE
          || (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                             v23,
                             v49,
                             v94,
                             v95,
                             v96,
                             v97,
                             v98,
                             v99,
                             v100,
                             v101)
           - 4 < 0xFFFFFFFE
          || (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                             v23,
                             v50,
                             v102,
                             v103,
                             v104,
                             v105,
                             v106,
                             v107,
                             v108,
                             v109)
           - 4 < 0xFFFFFFFE )
        {
          return 1;
        }
        return (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                               v23,
                               v118,
                               v110,
                               v111,
                               v112,
                               v113,
                               v114,
                               v115,
                               v116,
                               v117)
             - 4 < 0xFFFFFFFE;
      }
    }
  }
  return result;
}

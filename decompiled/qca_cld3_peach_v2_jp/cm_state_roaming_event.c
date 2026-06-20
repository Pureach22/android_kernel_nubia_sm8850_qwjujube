__int64 __fastcall cm_state_roaming_event(
        __int64 *a1,
        unsigned __int16 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  __int64 v14; // x8
  unsigned int v15; // w20
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  unsigned int v34; // w1
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v47; // w2
  __int64 v48; // x3
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7

  result = 0;
  if ( a2 > 0x1Cu )
  {
    switch ( a2 )
    {
      case 0x1Fu:
        wlan_sm_transition_to(a1[9], 2u, a5, a6, a7, a8, a9, a10, a11, a12);
        v33 = a1[9];
        v34 = 31;
        v47 = a3;
        v48 = a4;
LABEL_20:
        wlan_sm_dispatch(v33, v34, v47, v48, v17, v18, v19, v20, v21, v22, v23, v24);
        return 1;
      case 0x1Eu:
        v15 = a3;
        v16 = a4;
        if ( !(unsigned int)cm_add_fw_roam_cmd_to_list_n_ser(a1, a4) )
        {
          wlan_sm_transition_to(a1[9], 0xCu, v49, v50, v51, v52, v53, v54, v55, v56);
          goto LABEL_15;
        }
        break;
      case 0x1Du:
        v14 = *(_QWORD *)(*a1 + 152);
        if ( v14 )
        {
          result = *(_QWORD *)(v14 + 80);
          if ( !result )
            return result;
          v15 = a3;
          v16 = a4;
          if ( (cm_roam_offload_enabled(result) & 1) == 0 )
          {
            v25 = cm_add_roam_req_to_list(a1, v16);
            wlan_sm_transition_to(a1[9], 0xAu, v25, v26, v27, v28, v29, v30, v31, v32);
            v33 = a1[9];
            v34 = 17;
LABEL_16:
            v47 = v15;
            v48 = v16;
            goto LABEL_20;
          }
LABEL_15:
          v33 = a1[9];
          v34 = 30;
          goto LABEL_16;
        }
        break;
      default:
        return result;
    }
    return 0;
  }
  if ( a2 == 17 )
  {
    if ( !(unsigned int)cm_add_fw_roam_cmd_to_list_n_ser(a1, a4) )
    {
      wlan_sm_transition_to(a1[9], 0xCu, v57, v58, v59, v60, v61, v62, v63, v64);
      v33 = a1[9];
      v34 = 17;
      v47 = 0;
      v48 = 0;
      goto LABEL_20;
    }
    return 0;
  }
  if ( a2 == 18 )
  {
    wlan_sm_transition_to(a1[9], 0xDu, a5, a6, a7, a8, a9, a10, a11, a12);
    return (unsigned int)wlan_sm_dispatch(a1[9], 0x12u, a3, a4, v37, v38, v39, v40, v41, v42, v43, v44) == 0;
  }
  return result;
}

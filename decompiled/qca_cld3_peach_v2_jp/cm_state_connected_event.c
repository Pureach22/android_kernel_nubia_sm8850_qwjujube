bool __fastcall cm_state_connected_event(__int64 *a1, unsigned __int16 a2, unsigned int a3, unsigned int *a4)
{
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  unsigned int v24; // w1
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  unsigned __int16 v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x3
  unsigned int v44; // w2
  _BOOL8 result; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v71[2]; // [xsp+10h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  if ( a2 > 0xCu )
  {
    if ( a2 != 13 )
    {
      if ( a2 == 15 )
      {
        cm_disconnect_active(a1, a4);
      }
      else if ( a2 != 26 )
      {
        goto LABEL_15;
      }
      goto LABEL_24;
    }
    v6 = a3;
    if ( (unsigned int)cm_add_disconnect_req_to_list((__int64)a1, a4) )
      goto LABEL_43;
    wlan_sm_transition_to(a1[9], 3u, v7, v8, v9, v10, v11, v12, v13, v14);
    v23 = a1[9];
    v24 = 14;
LABEL_22:
    v44 = v6;
    v43 = (__int64)a4;
    goto LABEL_23;
  }
  if ( !a2 )
  {
    v6 = a3;
    if ( !(unsigned int)cm_check_and_prepare_roam_req(a1, a4, &v70) )
    {
      v43 = v70;
      v23 = a1[9];
      v24 = 29;
      v44 = 896;
LABEL_23:
      wlan_sm_dispatch(v23, v24, v44, v43, v15, v16, v17, v18, v19, v20, v21, v22);
      goto LABEL_24;
    }
    if ( (unsigned int)cm_handle_connect_req_in_non_init_state(a1, a4, 2) )
      goto LABEL_43;
    wlan_sm_transition_to(a1[9], 1u, v25, v26, v27, v28, v29, v30, v31, v32);
    v23 = a1[9];
    v24 = 6;
    goto LABEL_22;
  }
  if ( a2 != 8 )
  {
LABEL_15:
    v33 = *(_QWORD *)(*a1 + 152);
    if ( v33 )
    {
      v34 = a2;
      v6 = a3;
      if ( (cm_is_roam_enabled(*(_QWORD *)(v33 + 80)) & 1) == 0 )
        goto LABEL_43;
    }
    else
    {
      v34 = a2;
      v6 = a3;
      if ( (cm_is_roam_enabled(0) & 1) == 0 )
        goto LABEL_43;
    }
    if ( v34 == 29 )
    {
      wlan_sm_transition_to(a1[9], 4u, v35, v36, v37, v38, v39, v40, v41, v42);
      v23 = a1[9];
      v24 = 29;
      goto LABEL_22;
    }
    result = 0;
    v71[0] = 0;
    if ( v34 > 0x13u )
    {
      if ( v34 <= 0x1Eu )
      {
        if ( v34 != 20 )
        {
          if ( v34 != 30 )
            goto LABEL_44;
          wlan_sm_transition_to(a1[9], 4u, v35, v36, v37, v38, v39, v40, v41, v42);
          v23 = a1[9];
          v24 = 30;
          goto LABEL_22;
        }
LABEL_38:
        cm_remove_cmd(a1, a4);
        goto LABEL_24;
      }
      if ( v34 != 31 )
      {
        if ( v34 != 32 )
          goto LABEL_44;
        cm_fw_roam_complete(a1, a4);
        goto LABEL_24;
      }
LABEL_37:
      cm_roam_abort_event(*a1);
      goto LABEL_38;
    }
    switch ( v34 )
    {
      case 0x11u:
        if ( !(unsigned int)cm_prepare_roam_cmd(a1, v71, 3) )
        {
          wlan_sm_transition_to(a1[9], 4u, v46, v47, v48, v49, v50, v51, v52, v53);
          v43 = v71[0];
          v23 = a1[9];
          v24 = 17;
          v44 = 896;
          goto LABEL_23;
        }
        break;
      case 0x12u:
        if ( !(unsigned int)cm_prepare_roam_cmd(a1, v71, 3)
          && !(unsigned int)cm_add_fw_roam_cmd_to_list_n_ser(a1, v71[0]) )
        {
          wlan_sm_transition_to(a1[9], 4u, v54, v55, v56, v57, v58, v59, v60, v61);
          result = (unsigned int)wlan_sm_dispatch(a1[9], 0x12u, v6, (__int64)a4, v62, v63, v64, v65, v66, v67, v68, v69) == 0;
          goto LABEL_44;
        }
        break;
      case 0x13u:
        goto LABEL_37;
      default:
        goto LABEL_44;
    }
LABEL_43:
    result = 0;
    goto LABEL_44;
  }
  cm_connect_complete(a1, (__int64)a4);
LABEL_24:
  result = 1;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}

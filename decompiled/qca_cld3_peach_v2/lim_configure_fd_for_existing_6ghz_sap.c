__int64 __fastcall lim_configure_fd_for_existing_6ghz_sap(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v5; // x0
  __int64 sap_mode_info; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  char v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x25
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x23
  __int64 cmpt_obj; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x24
  char v53; // w8
  unsigned __int64 v54; // x25
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x23
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x24
  int v83; // [xsp+8h] [xbp-28h] BYREF
  char v84; // [xsp+Ch] [xbp-24h]
  __int64 v85; // [xsp+10h] [xbp-20h] BYREF
  __int64 v86; // [xsp+18h] [xbp-18h]
  int v87; // [xsp+20h] [xbp-10h]
  __int64 v88; // [xsp+28h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 7036) != 1 )
    goto LABEL_4;
  v2 = *(_QWORD *)(result + 8608);
  v3 = result;
  v84 = 0;
  v5 = *(_QWORD *)(v2 + 21624);
  v83 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  sap_mode_info = (unsigned __int8)policy_mgr_get_sap_mode_info(v5, (unsigned __int64)&v85, (unsigned __int64)&v83);
  if ( (unsigned int)sap_mode_info > 4 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: vdev_num:%u is out of bounds",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_configure_fd_for_existing_6ghz_sap",
               (unsigned int)sap_mode_info);
    goto LABEL_4;
  }
  if ( (_DWORD)sap_mode_info )
  {
    if ( (unsigned __int8)v83 != *(unsigned __int8 *)(v3 + 10) && !wlan_reg_is_6ghz_chan_freq(v85) )
    {
      v15 = 1;
      goto LABEL_19;
    }
    v15 = (_DWORD)sap_mode_info != 1;
    if ( (_DWORD)sap_mode_info == 1
      || BYTE1(v83) != *(unsigned __int8 *)(v3 + 10) && !wlan_reg_is_6ghz_chan_freq(WORD2(v85)) )
    {
      goto LABEL_19;
    }
    v15 = (unsigned int)sap_mode_info > 2;
    if ( (_DWORD)sap_mode_info == 2 || BYTE2(v83) != *(unsigned __int8 *)(v3 + 10) && !wlan_reg_is_6ghz_chan_freq(v86) )
      goto LABEL_19;
    v15 = (_DWORD)sap_mode_info == 4;
    if ( (_DWORD)sap_mode_info == 3
      || HIBYTE(v83) != *(unsigned __int8 *)(v3 + 10) && !wlan_reg_is_6ghz_chan_freq(WORD2(v86)) )
    {
      goto LABEL_19;
    }
  }
  v15 = 0;
LABEL_19:
  result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v3 + 284));
  if ( (a2 & 1) != 0 )
  {
    if ( (result & 1) != 0 )
    {
      result = wlan_mlme_disable_fd_in_6ghz_band(*(_QWORD *)(v3 + 16), v15, v16, v17, v18, v19, v20, v21, v22, v23);
      goto LABEL_4;
    }
    if ( !(_DWORD)sap_mode_info )
      goto LABEL_4;
    v24 = 0;
    while ( 4 * v24 <= 0x13 )
    {
      result = wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&v85 + v24));
      if ( (result & 1) != 0 )
      {
        if ( v24 > 4 )
          break;
        result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                   *(_QWORD *)(*(_QWORD *)(v3 + 8608) + 21624LL),
                   *((unsigned __int8 *)&v83 + v24),
                   7);
        if ( result )
        {
          v42 = result;
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(result, v34, v35, v36, v37, v38, v39, v40, v41);
          if ( cmpt_obj )
          {
            v52 = cmpt_obj;
            if ( (wlan_mlme_is_fd_disabled_in_6ghz_band(v42, v44, v45, v46, v47, v48, v49, v50, v51) & 1) == 0 )
            {
              wlan_mlme_disable_fd_in_6ghz_band(v42, 1, v26, v27, v28, v29, v30, v31, v32, v33);
              vdev_mgr_configure_fd_for_sap(v52);
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Unable to get mlme obj for vdev %d",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "lim_configure_fd_for_existing_6ghz_sap",
              *((unsigned __int8 *)&v83 + v24));
          }
          result = wlan_objmgr_vdev_release_ref(v42, 7u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
        }
      }
      if ( ++v24 == sap_mode_info )
        goto LABEL_4;
    }
LABEL_51:
    __break(1u);
  }
  if ( (result & 1) != 0 )
  {
    result = wlan_mlme_disable_fd_in_6ghz_band(*(_QWORD *)(v3 + 16), 0, v16, v17, v18, v19, v20, v21, v22, v23);
    goto LABEL_4;
  }
  if ( (_DWORD)sap_mode_info )
    v53 = v15;
  else
    v53 = 1;
  if ( (v53 & 1) == 0 )
  {
    v54 = 0;
    while ( 4 * v54 <= 0x13 )
    {
      result = wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&v85 + v54));
      if ( (result & 1) != 0 )
      {
        if ( v54 > 4 )
          goto LABEL_51;
        result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                   *(_QWORD *)(*(_QWORD *)(v3 + 8608) + 21624LL),
                   *((unsigned __int8 *)&v83 + v54),
                   7);
        if ( result )
        {
          v72 = result;
          v73 = wlan_vdev_mlme_get_cmpt_obj(result, v64, v65, v66, v67, v68, v69, v70, v71);
          if ( v73 )
          {
            v82 = v73;
            if ( (wlan_mlme_is_fd_disabled_in_6ghz_band(v72, v74, v75, v76, v77, v78, v79, v80, v81) & 1) != 0 )
            {
              wlan_mlme_disable_fd_in_6ghz_band(v72, 0, v56, v57, v58, v59, v60, v61, v62, v63);
              vdev_mgr_configure_fd_for_sap(v82);
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Unable to get mlme obj for vdev %d",
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              "lim_configure_fd_for_existing_6ghz_sap",
              *((unsigned __int8 *)&v83 + v54));
          }
          result = wlan_objmgr_vdev_release_ref(v72, 7u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
        }
      }
      if ( ++v54 == sap_mode_info )
        goto LABEL_4;
    }
    goto LABEL_51;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall policy_mgr_check_for_session_conc(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  unsigned int v16; // w0
  const char *v17; // x2
  unsigned int v19; // w22
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x23
  __int64 assoc_link_vdev; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  double v40; // d0
  char v41; // w0
  char v42; // w19
  unsigned int *v43; // x8
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v17 = "%s: Invalid Context";
    goto LABEL_8;
  }
  v15 = *(_DWORD **)(context + 304);
  if ( v15 )
  {
    if ( *(v15 - 1) != -1034201557 )
      __break(0x8228u);
    v16 = ((__int64 (__fastcall *)(__int64, _QWORD))v15)(a1, a2);
    if ( v16 == 7 )
    {
      v17 = "%s: Invalid mode";
LABEL_8:
      qdf_trace_msg(0x4Fu, 2u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "policy_mgr_check_for_session_conc");
      return 0;
    }
    if ( !a3 )
    {
      v17 = "%s: Invalid channel number 0";
      goto LABEL_8;
    }
    v19 = v16;
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
    if ( v20 )
    {
      v29 = v20;
      if ( *(_DWORD *)(v20 + 16) || (wlan_vdev_mlme_is_mlo_vdev(v20, v21, v22, v23, v24, v25, v26, v27, v28) & 1) == 0 )
      {
        v39 = 0;
      }
      else if ( (*(_BYTE *)(v29 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v29)) != 0 )
      {
        if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v31, v32, v33, v34, v35, v36, v37, v38) )
          v39 = 3;
        else
          v39 = 1;
      }
      else
      {
        v39 = 1;
      }
      v40 = ((double (__fastcall *)(__int64, _QWORD, _QWORD, __int64, __int64, _QWORD))policy_mgr_allow_concurrency)(
              a1,
              v19,
              a3,
              3,
              v39,
              a2);
      v42 = v41;
      wlan_objmgr_vdev_release_ref(v29, 0x18u, v43, v40, v44, v45, v46, v47, v48, v49, v50);
      if ( (v42 & 1) != 0 )
        return 1;
    }
    else if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                 a1,
                 v19,
                 a3,
                 3,
                 0,
                 a2)
             & 1) != 0 )
    {
      return 1;
    }
    v17 = "%s: Connection failed due to conc check fail";
    goto LABEL_8;
  }
  return 0;
}

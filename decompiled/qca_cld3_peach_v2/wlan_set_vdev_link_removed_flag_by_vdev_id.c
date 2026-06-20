__int64 __fastcall wlan_set_vdev_link_removed_flag_by_vdev_id(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w21
  __int64 ap_link_by_link_id; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // x22
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w20
  unsigned __int64 v59; // x9
  unsigned __int64 v61; // x10

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v5 )
  {
    v14 = v5;
    if ( (mlo_is_mld_sta(v5) & 1) != 0 )
    {
      if ( (mlo_is_mld_sta(v14) & 1) != 0 )
      {
        v31 = *(unsigned __int8 *)(v14 + 93);
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(v14 + 1360), *(unsigned __int8 *)(v14 + 93));
        if ( ap_link_by_link_id )
        {
          _X8 = (unsigned __int64 *)(*(_QWORD *)(ap_link_by_link_id + 16) & 1LL);
          if ( (_DWORD)_X8 != (a3 & 1) )
          {
            v42 = ap_link_by_link_id;
            qdf_trace_msg(
              0x1Fu,
              8u,
              "%s: mlo sta vdev %d link %d link removed flag %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "wlan_set_vdev_link_removed_flag",
              *(unsigned __int8 *)(v14 + 168),
              v31);
            if ( (a3 & 1) != 0 )
            {
              _X8 = (unsigned __int64 *)(v42 + 16);
              __asm { PRFM            #0x11, [X8] }
              do
                v59 = __ldxr(_X8);
              while ( __stxr(v59 | 1, _X8) );
            }
            else
            {
              _X8 = (unsigned __int64 *)(v42 + 16);
              __asm { PRFM            #0x11, [X8] }
              do
                v61 = __ldxr(_X8);
              while ( __stxr(v61 & 0xFFFFFFFFFFFFFFFELL, _X8) );
            }
          }
          v53 = 0;
        }
        else
        {
          qdf_trace_msg(
            0x1Fu,
            2u,
            "%s: link info null, id %d",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "wlan_set_vdev_link_removed_flag",
            v31);
          v53 = 4;
        }
      }
      else
      {
        qdf_trace_msg(
          0x1Fu,
          8u,
          "%s: vdev not mld sta",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_set_vdev_link_removed_flag");
        v53 = 4;
      }
      wlan_objmgr_vdev_release_ref(v14, 0x43u, (unsigned int *)_X8, v33, v34, v35, v36, v37, v38, v39, v40);
      return v53;
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: vdev %d not mld sta",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_set_vdev_link_removed_flag_by_vdev_id",
        v4);
      wlan_objmgr_vdev_release_ref(v14, 0x43u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev null for id %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_set_vdev_link_removed_flag_by_vdev_id",
      v4);
    return 4;
  }
}

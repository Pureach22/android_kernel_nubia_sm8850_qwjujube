__int64 __fastcall tdls_process_enable_for_vdev(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 *v30; // x21
  char tdls_prohibited; // w22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  char tdls_chan_switch_prohibited; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7

  v1 = *(_QWORD *)(result + 216);
  if ( v1 )
  {
    v2 = result;
    result = *(_QWORD *)(v1 + 80);
    if ( result )
    {
      result = policy_mgr_mode_specific_connection_count(result, 0, nullptr);
      if ( *(_DWORD *)(v2 + 16) == 2 && (_BYTE)result )
      {
        return qdf_trace_msg(
                 0,
                 8u,
                 "%s: STA + P2P concurrency. Don't allow TDLS on P2P vdev:%d",
                 v3,
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 "tdls_process_enable_for_vdev",
                 *(unsigned __int8 *)(v2 + 168));
      }
      else if ( v2 )
      {
        result = wlan_objmgr_vdev_get_comp_private_obj(v2, 0xAu);
        if ( result )
        {
          v19 = *(_QWORD *)(v2 + 216);
          if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
          {
            v21 = result;
            result = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xAu);
            if ( result )
            {
              if ( (*(_DWORD *)(v2 + 16) & 0xFFFFFFFD) == 0 )
              {
                v30 = (__int64 *)result;
                tdls_prohibited = mlme_get_tdls_prohibited(v2, v22, v23, v24, v25, v26, v27, v28, v29);
                tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                                v2,
                                                v32,
                                                v33,
                                                v34,
                                                v35,
                                                v36,
                                                v37,
                                                v38,
                                                v39);
                tdls_send_update_to_fw(
                  v21,
                  v30,
                  tdls_prohibited & 1,
                  tdls_chan_switch_prohibited & 1,
                  1,
                  *(unsigned __int8 *)(v2 + 168));
                return tdls_set_ct_mode(*v30, v2, v41, v42, v43, v44, v45, v46, v47, v48);
              }
            }
          }
          else
          {
            return qdf_trace_msg(
                     0,
                     2u,
                     "%s: can't get psoc",
                     v11,
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     "wlan_vdev_get_tdls_soc_obj");
          }
        }
      }
    }
  }
  return result;
}

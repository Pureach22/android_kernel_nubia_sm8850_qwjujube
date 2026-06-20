__int64 __fastcall tdls_set_ct_mode(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 comp_private_obj; // x0
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x24
  __int64 v25; // x0
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  unsigned int v36; // w22
  int v37; // w23
  int v38; // w0
  bool v39; // zf
  int v40; // w23
  int connection_count_with_mlo; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8

  result = tdls_check_is_tdls_allowed(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    if ( a2 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a2, 0xAu);
      if ( comp_private_obj )
      {
        v22 = *(_QWORD *)(a2 + 152);
        if ( v22 && (v23 = *(_QWORD *)(v22 + 80)) != 0 )
        {
          v24 = comp_private_obj;
          v25 = wlan_objmgr_psoc_get_comp_private_obj(v23, 0xAu);
          if ( v25 && (*(_DWORD *)(a2 + 16) & 0xFFFFFFFD) == 0 )
          {
            *(_DWORD *)(v25 + 620) = 0;
            v26 = v25;
            _qdf_mem_free(*(_QWORD *)(v24 + 952));
            *(_QWORD *)(v24 + 952) = 0;
            v35 = v24;
            v36 = *(_DWORD *)(v26 + 156);
            if ( *(_DWORD *)(v26 + 8) >= 2u
              && (v36 & 0x40) != 0
              && ((v37 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr),
                   v38 = policy_mgr_mode_specific_connection_count(a1, 2, nullptr),
                   v39 = v37 == 1,
                   v40 = v38,
                   v35 = v24,
                   v39)
               || (connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(a1),
                   v35 = v24,
                   connection_count_with_mlo == 1)
               && v40 == 1) )
            {
              if ( (v36 & 0x80) == 0 )
              {
                *(_BYTE *)(v26 + 212) = 1;
LABEL_21:
                tdls_implicit_enable(v35, v27, v28, v29, v30, v31, v32, v33, v34);
                return qdf_trace_msg(
                         0,
                         8u,
                         "%s: vdev:%d enable_tdls_connection_tracker %d current_mode:%d feature_flags:0x%x",
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         v48,
                         v49,
                         "tdls_set_ct_mode",
                         *(unsigned __int8 *)(a2 + 104),
                         *(unsigned __int8 *)(v26 + 212),
                         *(unsigned int *)(v26 + 8),
                         v36);
              }
              v50 = *(unsigned __int8 *)(v26 + 213);
              *(_BYTE *)(v26 + 212) = *(_BYTE *)(v26 + 213) != 0;
              if ( v50 )
                goto LABEL_21;
            }
            else
            {
              *(_BYTE *)(v26 + 212) = 0;
            }
            tdls_implicit_disable(v35, v27, v28, v29, v30, v31, v32, v33, v34);
            return qdf_trace_msg(
                     0,
                     8u,
                     "%s: vdev:%d enable_tdls_connection_tracker %d current_mode:%d feature_flags:0x%x",
                     v42,
                     v43,
                     v44,
                     v45,
                     v46,
                     v47,
                     v48,
                     v49,
                     "tdls_set_ct_mode",
                     *(unsigned __int8 *)(a2 + 104),
                     *(unsigned __int8 *)(v26 + 212),
                     *(unsigned int *)(v26 + 8),
                     v36);
          }
        }
        else
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: can't get psoc",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "wlan_vdev_get_tdls_soc_obj");
        }
      }
    }
    return qdf_trace_msg(
             0,
             2u,
             "%s: Failed to get TDLS objects",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "tdls_set_ct_mode");
  }
  return result;
}

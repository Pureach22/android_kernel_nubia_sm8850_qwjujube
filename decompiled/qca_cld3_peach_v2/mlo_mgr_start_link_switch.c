__int64 __fastcall mlo_mgr_start_link_switch(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x22
  unsigned int v11; // w20
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  int v22; // w9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  int v57; // w9
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w19
  __int64 v67; // [xsp+0h] [xbp-10h] BYREF
  __int64 v68; // [xsp+8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  v11 = *(unsigned __int8 *)(a1 + 168);
  WORD2(v67) = 0;
  v12 = *(_QWORD *)(v10 + 3880);
  LODWORD(v67) = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: VDEV %d start link switch",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "mlo_mgr_start_link_switch",
    v11,
    v67,
    v68);
  qdf_mutex_acquire(v10 + 1656);
  v21 = *(_QWORD *)(v10 + 3880);
  v22 = *(_DWORD *)(v21 + 164);
  if ( v22 <= 2 )
  {
    if ( v22 )
    {
      if ( v22 == 1 )
      {
        v22 = 2;
      }
      else if ( v22 == 2 )
      {
        v22 = 3;
      }
    }
    else
    {
      v22 = 1;
    }
  }
  else if ( v22 > 4 )
  {
    if ( v22 == 5 )
    {
      v22 = 0;
    }
    else if ( v22 == 6 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: State transition not allowed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "mlo_mgr_link_switch_trans_next_state");
      v21 = *(_QWORD *)(v10 + 3880);
      v22 = 6;
    }
  }
  else if ( v22 == 3 )
  {
    v22 = 4;
  }
  else
  {
    v22 = 5;
  }
  *(_DWORD *)(v21 + 164) = v22;
  qdf_mutex_release(v10 + 1656);
  if ( wlan_cm_is_vdev_connected(a1, v23, v24, v25, v26, v27, v28, v29, v30) )
  {
    result = wlan_vdev_get_bss_peer_mac(a1, &v67, v31, v32, v33, v34, v35, v36, v37, v38);
    if ( !(_DWORD)result )
    {
      result = wlan_vdev_get_bss_peer_mld_mac(a1, (void *)(v12 + 147), v40, v41, v42, v43, v44, v45, v46, v47);
      if ( !(_DWORD)result )
      {
        result = mlo_mgr_link_switch_notify(a1, v12 + 144);
        if ( !(_DWORD)result )
        {
          *(_DWORD *)(a1 + 64) |= 0x2000000u;
          qdf_mutex_acquire(v10 + 1656);
          v56 = *(_QWORD *)(v10 + 3880);
          v57 = *(_DWORD *)(v56 + 164);
          if ( v57 <= 2 )
          {
            if ( v57 )
            {
              if ( v57 == 1 )
              {
                v57 = 2;
              }
              else if ( v57 == 2 )
              {
                v57 = 3;
              }
            }
            else
            {
              v57 = 1;
            }
          }
          else if ( v57 > 4 )
          {
            if ( v57 == 5 )
            {
              v57 = 0;
            }
            else if ( v57 == 6 )
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: State transition not allowed",
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "mlo_mgr_link_switch_trans_next_state");
              *(_DWORD *)(*(_QWORD *)(v10 + 3880) + 164LL) = 6;
              qdf_mutex_release(v10 + 1656);
              result = 12;
              goto LABEL_25;
            }
          }
          else if ( v57 == 3 )
          {
            v57 = 4;
          }
          else
          {
            v57 = 5;
          }
          *(_DWORD *)(v56 + 164) = v57;
          qdf_mutex_release(v10 + 1656);
          result = wlan_cm_disconnect(a1, 18, 65516, (int *)&v67);
          if ( (_DWORD)result )
          {
            v66 = result;
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: VDEV %d disconnect request not handled",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "mlo_mgr_start_link_switch",
              *(unsigned __int8 *)(v12 + 144));
            result = v66;
          }
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV %d not in connected state",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "mlo_mgr_start_link_switch",
      v11);
    result = 4;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}

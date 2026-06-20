__int64 __fastcall mlo_mgr_link_switch_validate_request(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  int v11; // w8
  __int64 v12; // x5
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19
  const char *v23; // x2
  __int64 v24; // x4
  __int64 v25; // x8
  __int64 v26; // x21
  __int64 v27; // x8
  __int64 v28; // x21
  const char *v29; // x2
  unsigned int v30; // w1
  __int64 v31; // x4
  unsigned int v33; // w19
  __int64 v34; // x22
  int v36; // w8
  unsigned int v37; // w19
  __int64 v39; // x0
  __int64 v40; // x19
  unsigned int v41; // w23
  const char *v42; // x2
  __int64 v43; // x20
  char is_link_recfg_in_progress; // w21
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  v10 = *(unsigned __int8 *)(a1 + 168);
  v11 = a2[1];
  v12 = a2[2];
  if ( *((_DWORD *)a2 + 6) != 65534 )
  {
    if ( v11 == 255 || (_DWORD)v12 == 255 )
    {
      v23 = "%s: Invalid link params, curr link id %d, new link id %d";
      v24 = a2[1];
      goto LABEL_10;
    }
    if ( (unsigned int)v12 > 0xE )
      goto LABEL_28;
    v27 = *(_QWORD *)(a1 + 1360);
    if ( !v27 )
      goto LABEL_28;
    v28 = *(_QWORD *)(v27 + 3880);
    if ( *(unsigned __int8 *)(v28 + 6) != (_DWORD)v12 )
    {
      if ( *(unsigned __int8 *)(v28 + 54) == (_DWORD)v12 )
      {
        v28 += 48;
      }
      else
      {
        if ( *(unsigned __int8 *)(v28 + 102) != (_DWORD)v12 )
          goto LABEL_28;
        v28 += 96;
      }
    }
    if ( v28 )
    {
      if ( *(unsigned __int8 *)(v28 + 12) == 255 )
      {
        v33 = *(unsigned __int8 *)(a1 + 168);
        v34 = (__int64)a2;
        if ( mlo_is_mld_sta(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
        {
          if ( wlan_cm_is_vdev_connected(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
          {
            if ( mlo_mgr_is_link_switch_in_progress(a1) )
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: Link switch already in progress",
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                "mlo_mgr_link_switch_validate_request");
              return 4;
            }
            v12 = *(unsigned __int8 *)(a1 + 93);
            if ( (_DWORD)v12 == *(unsigned __int8 *)(v34 + 1) )
            {
              v12 = *(unsigned int *)(v34 + 12);
              v39 = a1;
              v24 = **(unsigned __int16 **)(v28 + 32);
              if ( (_DWORD)v12 == (_DWORD)v24 )
                goto LABEL_59;
              v23 = "%s: Host freq(%d) FW req freq(%d)";
            }
            else
            {
              v23 = "%s: VDEV %d link id wrong, curr link id %d";
              v24 = v33;
            }
LABEL_10:
            qdf_trace_msg(
              0x8Fu,
              2u,
              v23,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "mlo_mgr_link_switch_validate_request",
              v24,
              v12);
            return 4;
          }
          v29 = "%s: VDEV %d not in connected state";
        }
        else
        {
          v29 = "%s: Link switch req not valid for VDEV %d";
        }
        v30 = 2;
        v31 = v33;
      }
      else
      {
        v29 = "%s: requested link already active on other vdev:%d";
        v30 = 2;
        v31 = *(unsigned __int8 *)(v28 + 12);
      }
LABEL_29:
      qdf_trace_msg(0x8Fu, v30, v29, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_mgr_link_switch_validate_request", v31);
      return 4;
    }
LABEL_28:
    v29 = "%s: New link id %d not part of association";
    v30 = 2;
    v31 = (unsigned int)v12;
    goto LABEL_29;
  }
  if ( v11 == 255 || (_DWORD)v12 == 255 )
  {
    v13 = "%s: Invalid link params, curr link id %d, new link id %d";
    v10 = a2[1];
LABEL_5:
    qdf_trace_msg(
      0x8Fu,
      2u,
      v13,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_mgr_host_link_switch_validate_request",
      v10,
      v12);
LABEL_6:
    v22 = 4;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: link switch status %d for add link",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_mgr_link_switch_validate_request",
      4);
    return v22;
  }
  if ( (_DWORD)v10 != *a2 )
  {
    v13 = "%s: Invalid vdev params, curr id %d, req id %d";
    v12 = *a2;
    goto LABEL_5;
  }
  if ( (unsigned int)v12 > 0xE )
    goto LABEL_42;
  v25 = *(_QWORD *)(a1 + 1360);
  if ( !v25 )
    goto LABEL_42;
  v26 = *(_QWORD *)(v25 + 3880);
  if ( *(unsigned __int8 *)(v26 + 6) == (_DWORD)v12 )
    goto LABEL_38;
  if ( *(unsigned __int8 *)(v26 + 54) == (_DWORD)v12 )
  {
    v26 += 48;
    goto LABEL_38;
  }
  if ( *(unsigned __int8 *)(v26 + 102) != (_DWORD)v12 )
  {
LABEL_42:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: New link id %d not part of association",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_mgr_host_link_switch_validate_request",
      a2[2]);
    goto LABEL_6;
  }
  v26 += 96;
LABEL_38:
  if ( !v26 )
    goto LABEL_42;
  v36 = *(unsigned __int8 *)(v26 + 12);
  if ( v36 != 255 && v36 != (_DWORD)v10 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: requested link already active on other vdev:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_mgr_host_link_switch_validate_request",
      *(unsigned __int8 *)(v26 + 12));
    goto LABEL_6;
  }
  v37 = *(unsigned __int8 *)(a1 + 168);
  v34 = (__int64)a2;
  if ( !mlo_is_mld_sta(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v42 = "%s: Link switch req not valid for VDEV %d";
LABEL_54:
    qdf_trace_msg(0x8Fu, 2u, v42, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_mgr_host_link_switch_validate_request", v37);
    goto LABEL_6;
  }
  if ( !wlan_cm_is_vdev_connected(a1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v42 = "%s: VDEV %d not in connected state";
    goto LABEL_54;
  }
  v39 = a1;
  if ( a1 )
  {
    v40 = *(_QWORD *)(a1 + 1360);
    if ( v40 )
    {
      qdf_mutex_acquire(v40 + 1656);
      v41 = *(_DWORD *)(*(_QWORD *)(v40 + 3880) + 164LL);
      qdf_mutex_release(v40 + 1656);
      v39 = a1;
      if ( v41 >= 2 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Link switch already in progress",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "mlo_mgr_host_link_switch_validate_request");
        goto LABEL_6;
      }
    }
  }
  v12 = *(unsigned int *)(v34 + 12);
  v10 = **(unsigned __int16 **)(v26 + 32);
  if ( (_DWORD)v12 != (_DWORD)v10 )
  {
    v13 = "%s: Host freq(%d) FW req freq(%d)";
    goto LABEL_5;
  }
LABEL_59:
  v43 = v39;
  is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(v39);
  if ( (is_link_recfg_in_progress & 1) != 0 )
  {
    v31 = *(unsigned int *)(v34 + 24);
    if ( (_DWORD)v31 != 4 && (_DWORD)v31 != 7 && (_DWORD)v31 != 65534 )
    {
      v29 = "%s: unexpected link switch fw reason %d in link recfg prog";
      v30 = 8;
      goto LABEL_29;
    }
  }
  v22 = mlo_mgr_link_switch_notify(v43, v34);
  if ( v22 )
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Link switch rejected in pre-serialize notify",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "mlo_mgr_link_switch_validate_request");
  if ( (is_link_recfg_in_progress & 1) != 0 )
    mlo_link_recfg_linksw_start_indication(v43, v22);
  return v22;
}

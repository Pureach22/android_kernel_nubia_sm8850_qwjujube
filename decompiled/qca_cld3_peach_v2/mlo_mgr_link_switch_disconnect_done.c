__int64 __fastcall mlo_mgr_link_switch_disconnect_done(__int64 a1, int a2, char a3)
{
  __int64 v3; // x22
  __int64 v7; // x23
  __int64 v8; // x8
  int v9; // w21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x9
  unsigned int v27; // w8
  unsigned __int8 *v28; // x20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  int v38; // w9
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x21
  bool v49; // zf
  int v50; // w22
  int v51; // w4
  unsigned int v52; // w20
  const char *v54; // x2
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  int v64; // w9
  __int64 v65; // [xsp+0h] [xbp-20h]
  __int64 v66; // [xsp+8h] [xbp-18h]
  __int64 v67; // [xsp+10h] [xbp-10h]
  __int64 v68; // [xsp+18h] [xbp-8h]

  v3 = *(_QWORD *)(a1 + 1360);
  v7 = *(_QWORD *)(v3 + 3880);
  qdf_mutex_acquire(v3 + 1656);
  v8 = *(_QWORD *)(v3 + 3880);
  if ( (a3 & 1) == 0 )
  {
    *(_DWORD *)(v8 + 164) = 6;
    qdf_mutex_release(v3 + 1656);
    return 0;
  }
  v9 = *(_DWORD *)(v8 + 164);
  qdf_mutex_release(v3 + 1656);
  if ( a2 || v9 != 2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV %d link switch disconnect req failed",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "mlo_mgr_link_switch_disconnect_done",
      *(unsigned __int8 *)(v7 + 144));
    mlo_mgr_remove_link_switch_cmd(a1);
    return 0;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: VDEV %d link switch disconnect complete",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "mlo_mgr_link_switch_disconnect_done",
    *(unsigned __int8 *)(a1 + 168));
  v26 = *(_QWORD *)(a1 + 1360);
  if ( !v26 )
    goto LABEL_18;
  v27 = *(unsigned __int8 *)(v7 + 146);
  if ( v27 > 0xE )
    goto LABEL_18;
  v28 = *(unsigned __int8 **)(v26 + 3880);
  if ( v28[6] == v27 )
    goto LABEL_9;
  if ( v28[54] == v27 )
  {
    v28 += 48;
LABEL_9:
    if ( v28 )
      goto LABEL_10;
LABEL_18:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: New link not found in mlo dev ctx",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "mlo_mgr_link_switch_disconnect_done");
    mlo_mgr_remove_link_switch_cmd(a1);
    return 4;
  }
  if ( v28[102] != v27 )
    goto LABEL_18;
  v28 += 96;
  if ( !v28 )
    goto LABEL_18;
LABEL_10:
  qdf_mutex_acquire(v3 + 1656);
  v37 = *(_QWORD *)(v3 + 3880);
  v38 = *(_DWORD *)(v37 + 164);
  if ( v38 <= 2 )
  {
    if ( v38 )
    {
      if ( v38 == 1 )
      {
        v38 = 2;
      }
      else if ( v38 == 2 )
      {
        v38 = 3;
      }
    }
    else
    {
      v38 = 1;
    }
  }
  else if ( v38 > 4 )
  {
    if ( v38 == 5 )
    {
      v38 = 0;
    }
    else if ( v38 == 6 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: State transition not allowed",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "mlo_mgr_link_switch_trans_next_state");
      *(_DWORD *)(*(_QWORD *)(v3 + 3880) + 164LL) = 6;
      qdf_mutex_release(v3 + 1656);
      mlo_mgr_remove_link_switch_cmd(a1);
      return 12;
    }
  }
  else if ( v38 == 3 )
  {
    v38 = 4;
  }
  else
  {
    v38 = 5;
  }
  *(_DWORD *)(v37 + 164) = v38;
  qdf_mutex_release(v3 + 1656);
  v48 = *(_QWORD *)(a1 + 1360);
  if ( *(_DWORD *)(v7 + 168) == 65534 )
  {
    v49 = *(_DWORD *)v28 == *(_DWORD *)(a1 + 74) && *((unsigned __int16 *)v28 + 2) == *(unsigned __int16 *)(a1 + 78);
    v50 = !v49;
    if ( v49 )
    {
      v51 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: vdev MAC address %02x:%02x:%02x:**:**:%02x not equal link info self %02x:%02x:%02x:**:**:%02x",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "mlo_mgr_link_switch_decide_mac_addr_change",
        *(unsigned __int8 *)(a1 + 74),
        *(unsigned __int8 *)(a1 + 75),
        *(unsigned __int8 *)(a1 + 76),
        *(unsigned __int8 *)(a1 + 79),
        *v28,
        v28[1],
        v28[2],
        v28[5]);
      v51 = 4;
    }
    if ( *(_DWORD *)v28 != *(_DWORD *)(a1 + 86) || *((unsigned __int16 *)v28 + 2) != *(unsigned __int16 *)(a1 + 90) )
    {
      LODWORD(v66) = v28[1];
      LODWORD(v68) = v28[5];
      LODWORD(v67) = v28[2];
      LODWORD(v65) = *v28;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: vdev link address %02x:%02x:%02x:**:**:%02x not equal link info self %02x:%02x:%02x:**:**:%02x",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "mlo_mgr_link_switch_decide_mac_addr_change",
        *(unsigned __int8 *)(a1 + 74),
        *(unsigned __int8 *)(a1 + 75),
        *(unsigned __int8 *)(a1 + 76),
        *(unsigned __int8 *)(a1 + 79),
        v65,
        v66,
        v67,
        v68);
      v51 = 4;
LABEL_48:
      v54 = "%s: validate vdev mac addr failed status %d";
      v52 = v51;
LABEL_49:
      qdf_trace_msg(
        0x8Fu,
        2u,
        v54,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "mlo_mgr_link_switch_decide_mac_addr_change");
      goto LABEL_50;
    }
    if ( v50 )
      goto LABEL_48;
    qdf_mutex_acquire(v48 + 1656);
    v63 = *(_QWORD *)(v48 + 3880);
    v64 = *(_DWORD *)(v63 + 164);
    if ( v64 <= 2 )
    {
      if ( v64 )
      {
        if ( v64 == 1 )
        {
          v64 = 2;
        }
        else if ( v64 == 2 )
        {
          v64 = 3;
        }
      }
      else
      {
        v64 = 1;
      }
    }
    else if ( v64 > 4 )
    {
      if ( v64 == 5 )
      {
        v64 = 0;
      }
      else if ( v64 == 6 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: State transition not allowed",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "mlo_mgr_link_switch_trans_next_state");
        *(_DWORD *)(*(_QWORD *)(v48 + 3880) + 164LL) = 6;
        qdf_mutex_release(v48 + 1656);
        v54 = "%s: trans_next_state failed status %d";
        v52 = 12;
        goto LABEL_49;
      }
    }
    else if ( v64 == 3 )
    {
      v64 = 4;
    }
    else
    {
      v64 = 5;
    }
    *(_DWORD *)(v63 + 164) = v64;
    qdf_mutex_release(v48 + 1656);
    result = mlo_mgr_link_switch_start_connect(a1);
    v52 = result;
    if ( (_DWORD)result )
      goto LABEL_50;
  }
  else
  {
    result = wlan_vdev_mlme_send_set_mac_addr(
               *(unsigned int *)v28 | ((unsigned __int64)*((unsigned __int16 *)v28 + 2) << 32),
               *(unsigned int *)(v48 + 17) | ((unsigned __int64)*(unsigned __int16 *)(v48 + 21) << 32));
    v52 = result;
    if ( (_DWORD)result )
    {
LABEL_50:
      mlo_mgr_remove_link_switch_cmd(a1);
      return v52;
    }
  }
  return result;
}

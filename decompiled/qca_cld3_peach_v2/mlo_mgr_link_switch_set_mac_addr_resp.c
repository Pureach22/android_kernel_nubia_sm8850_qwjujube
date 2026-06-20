__int64 __fastcall mlo_mgr_link_switch_set_mac_addr_resp(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w20
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x22
  unsigned __int8 *v15; // x21
  int v16; // w23
  __int64 v17; // x9
  unsigned int v18; // w8
  int *v19; // x20
  const char *v20; // x2
  int v22; // w9
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 (__fastcall *v26)(__int64, __int64, __int64); // x8
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  __int64 v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  int v47; // w9

  v3 = a2;
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( v3 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV %d set MAC address response %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_mgr_link_switch_set_mac_addr_resp",
      *(unsigned __int8 *)(a1 + 168),
      v3);
LABEL_13:
    mlo_mgr_remove_link_switch_cmd(a1);
    return 4;
  }
  if ( !mlo_ctx )
  {
    v20 = "%s: global mlo ctx NULL";
LABEL_12:
    qdf_trace_msg(0x8Fu, 2u, v20, v5, v6, v7, v8, v9, v10, v11, v12, "mlo_mgr_link_switch_set_mac_addr_resp");
    goto LABEL_13;
  }
  v13 = *(_QWORD *)(a1 + 1360);
  v14 = mlo_ctx;
  v15 = *(unsigned __int8 **)(v13 + 3880);
  qdf_mutex_acquire(v13 + 1656);
  v16 = *(_DWORD *)(*(_QWORD *)(v13 + 3880) + 164LL);
  qdf_mutex_release(v13 + 1656);
  if ( v16 != 3 )
  {
    v20 = "%s: Link switch cmd flushed, there can be MAC addr mismatch with FW";
    goto LABEL_12;
  }
  v17 = *(_QWORD *)(a1 + 1360);
  if ( !v17 )
    goto LABEL_13;
  v18 = v15[146];
  if ( v18 > 0xE )
    goto LABEL_13;
  v19 = *(int **)(v17 + 3880);
  if ( *((unsigned __int8 *)v19 + 6) != v18 )
  {
    if ( *((unsigned __int8 *)v19 + 54) == v18 )
    {
      v19 += 12;
    }
    else
    {
      if ( *((unsigned __int8 *)v19 + 102) != v18 )
        goto LABEL_13;
      v19 += 24;
    }
  }
  if ( !v19 )
    goto LABEL_13;
  qdf_mem_copy((void *)(a1 + 74), v19, 6u);
  v22 = *v19;
  *(_WORD *)(a1 + 90) = *((_WORD *)v19 + 2);
  *(_DWORD *)(a1 + 86) = v22;
  v23 = v15[145];
  v24 = v15[146];
  v25 = v15[144];
  v26 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v14 + 360) + 8LL);
  if ( *((_DWORD *)v26 - 1) != -537248583 )
    __break(0x8228u);
  v27 = v26(v23, v24, v25);
  if ( v27 )
  {
    v36 = v27;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: VDEV %d OSIF MAC addr update failed %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "mlo_mgr_link_switch_set_mac_addr_resp",
      v15[144],
      v27);
    mlo_mgr_remove_link_switch_cmd(a1);
    return v36;
  }
  v37 = *(_QWORD *)(a1 + 1360);
  qdf_mutex_acquire(v37 + 1656);
  v46 = *(_QWORD *)(v37 + 3880);
  v47 = *(_DWORD *)(v46 + 164);
  if ( v47 <= 2 )
  {
    if ( v47 )
    {
      if ( v47 == 1 )
      {
        v47 = 2;
      }
      else if ( v47 == 2 )
      {
        v47 = 3;
      }
    }
    else
    {
      v47 = 1;
    }
  }
  else if ( v47 > 4 )
  {
    if ( v47 == 5 )
    {
      v47 = 0;
    }
    else if ( v47 == 6 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: State transition not allowed",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "mlo_mgr_link_switch_trans_next_state");
      *(_DWORD *)(*(_QWORD *)(v37 + 3880) + 164LL) = 6;
      qdf_mutex_release(v37 + 1656);
      mlo_mgr_remove_link_switch_cmd(a1);
      return 12;
    }
  }
  else if ( v47 == 3 )
  {
    v47 = 4;
  }
  else
  {
    v47 = 5;
  }
  *(_DWORD *)(v46 + 164) = v47;
  qdf_mutex_release(v37 + 1656);
  return mlo_mgr_link_switch_start_connect(a1);
}

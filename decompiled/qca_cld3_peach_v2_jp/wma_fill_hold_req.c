__int64 __fastcall wma_fill_hold_req(
        __int64 *a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned __int8 a4,
        const void *a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 StatusReg; // x8
  int inserted; // w0
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int opmode_from_vdev_id; // w0
  _QWORD *roam_vdev; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x21
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  v14 = _qdf_mem_malloc(0xD0u, "wma_fill_hold_req", 4380);
  if ( v14 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id %d msg %d type %d timeout %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_fill_hold_req",
      a2,
      a3,
      a4,
      a7);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 75);
    }
    else
    {
      raw_spin_lock_bh(a1 + 75);
      a1[76] |= 1uLL;
    }
    *(_BYTE *)(v14 + 204) = a2;
    *(_DWORD *)(v14 + 200) = a3;
    *(_BYTE *)(v14 + 205) = a4;
    *(_QWORD *)(v14 + 184) = a6;
    if ( a5 )
      qdf_mem_copy((void *)(v14 + 192), a5, 6u);
    inserted = qdf_list_insert_back(a1 + 72, (_QWORD *)(v14 + 168));
    v25 = a1[76];
    if ( inserted )
    {
      if ( (v25 & 1) != 0 )
      {
        a1[76] = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 75);
      }
      else
      {
        raw_spin_unlock(a1 + 75);
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed add request in queue",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wma_fill_hold_req");
      _qdf_mem_free(v14);
      return 0;
    }
    else
    {
      if ( (v25 & 1) != 0 )
      {
        a1[76] = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 75);
      }
      else
      {
        raw_spin_unlock(a1 + 75);
      }
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1[4], a2);
      if ( a4 == 1 && a3 == 4129 && opmode_from_vdev_id == 1 )
      {
        roam_vdev = wlan_objmgr_pdev_get_roam_vdev(a1[4], 8u);
        if ( roam_vdev )
        {
          v44 = (__int64)roam_vdev;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Roam active adjust peer assoc conf timeout to %d ms from %d ms",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wma_adjust_req_timeout",
            a7 + 7000,
            a7);
          wlan_objmgr_vdev_release_ref(v44, 8u, v45, v46, v47, v48, v49, v50, v51, v52, v53);
          a7 += 7000;
        }
      }
      qdf_mc_timer_init(v14, 0, (__int64)wma_hold_req_timer, v14);
      qdf_mc_timer_start(v14, a7);
    }
  }
  return v14;
}

__int64 __fastcall p2p_random_mac_handle_tx_done(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 comp_private_obj; // x0
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x23
  __int64 i; // x24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  _QWORD *v47; // x28
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  int v59; // w8
  unsigned int v60; // w27
  __int64 v61; // x8
  __int64 v62; // x0
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 result; // x0
  const char *v73; // x2
  __int64 v74; // [xsp+0h] [xbp-20h]
  __int64 v75; // [xsp+8h] [xbp-18h]
  int v76; // [xsp+10h] [xbp-10h] BYREF
  __int16 v77; // [xsp+14h] [xbp-Ch]
  __int64 v78; // [xsp+18h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d cookie %llu duration %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "p2p_random_mac_handle_tx_done",
    a2,
    a3,
    a4);
  v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( !v16 )
  {
    v73 = "%s: vdev is null";
LABEL_26:
    qdf_trace_msg(0x4Eu, 8u, v73, v17, v18, v19, v20, v21, v22, v23, v24, "p2p_random_mac_handle_tx_done");
    result = 4;
    goto LABEL_27;
  }
  v25 = v16;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v16, 5u);
  if ( !comp_private_obj )
  {
    wlan_objmgr_vdev_release_ref(v25, 0xFu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    v73 = "%s: p2p vdev object is NULL";
    goto LABEL_26;
  }
  v36 = comp_private_obj;
  v75 = v25;
  raw_spin_lock(comp_private_obj + 24);
  for ( i = 0; i != 4; ++i )
  {
    v46 = v36 + 40 + 216 * i;
    v77 = 0;
    v76 = 0;
    if ( *(_BYTE *)(v46 + 8) == 1 )
    {
      v47 = (_QWORD *)(v46 + 192);
      do
      {
        v47 = (_QWORD *)*v47;
        if ( v47 == (_QWORD *)(v46 + 192) )
          goto LABEL_6;
      }
      while ( v47[2] != a3 );
      if ( v47 )
      {
        if ( a4 )
        {
          qdf_mem_copy(&v76, (const void *)(v46 + 9), 6u);
          raw_spin_unlock(v36 + 24);
          if ( (unsigned int)qdf_mc_timer_get_current_state(v46 + 24) == 21 )
            qdf_mc_timer_stop(v46 + 24);
          qdf_mc_timer_start(v46 + 24, a4);
          LODWORD(v74) = HIBYTE(v77);
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: random_mac:start timer on vdev %d addr %02x:%02x:%02x:**:**:%02x",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "p2p_random_mac_handle_tx_done",
            a2,
            (unsigned __int8)v76,
            BYTE1(v76),
            BYTE2(v76),
            v74);
          goto LABEL_5;
        }
        qdf_list_remove_node(v46 + 192, v47);
        _qdf_mem_free((__int64)v47);
        if ( v46 == -9 )
        {
          v58 = 0;
          v56 = 0;
          v57 = 0;
          v59 = 0;
        }
        else
        {
          v56 = *(unsigned __int8 *)(v46 + 9);
          v57 = *(unsigned __int8 *)(v46 + 10);
          v58 = *(unsigned __int8 *)(v46 + 11);
          v59 = *(unsigned __int8 *)(v46 + 14);
        }
        LODWORD(v74) = v59;
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: random mac:clear mac addr on vdev %d addr %02x:%02x:%02x:**:**:%02x",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "p2p_random_mac_handle_tx_done",
          a2,
          v56,
          v57,
          v58,
          v74,
          v75);
        if ( qdf_list_empty((_QWORD *)(v46 + 192)) )
        {
          v60 = *(_DWORD *)(v46 + 16);
          *(_BYTE *)(v46 + 8) = 0;
          qdf_mem_copy(&v76, (const void *)(v46 + 9), 6u);
          raw_spin_unlock(v36 + 24);
          v61 = *(_QWORD *)(*(_QWORD *)v36 + 216LL);
          if ( v61 )
            v62 = *(_QWORD *)(v61 + 80);
          else
            v62 = 0;
          p2p_set_mac_filter(v62, a2, &v76, v60, 0, 0, 0);
LABEL_5:
          raw_spin_lock(v36 + 24);
          continue;
        }
      }
    }
LABEL_6:
    ;
  }
  raw_spin_unlock(v36 + 24);
  wlan_objmgr_vdev_release_ref(v75, 0xFu, v63, v64, v65, v66, v67, v68, v69, v70, v71);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}

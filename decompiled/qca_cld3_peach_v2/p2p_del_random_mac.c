__int64 __fastcall p2p_del_random_mac(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 comp_private_obj; // x0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 *v34; // x21
  int v35; // w8
  _QWORD *v36; // x23
  unsigned __int8 *v37; // x25
  _QWORD *v38; // x24
  unsigned int v39; // w22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int64 v49; // x0
  const char *v50; // x2
  __int64 result; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // [xsp+0h] [xbp-20h]
  int v70; // [xsp+10h] [xbp-10h] BYREF
  __int16 v71; // [xsp+14h] [xbp-Ch]
  __int64 v72; // [xsp+18h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d cookie %llu",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "p2p_del_random_mac",
    a2,
    a3);
  v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( !v14 )
  {
    v50 = "%s: vdev is null";
LABEL_30:
    qdf_trace_msg(0x4Eu, 8u, v50, v15, v16, v17, v18, v19, v20, v21, v22, "p2p_del_random_mac");
    result = 4;
    goto LABEL_34;
  }
  v23 = v14;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v14, 5u);
  if ( !comp_private_obj )
  {
    wlan_objmgr_vdev_release_ref(v23, 0xFu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
    v50 = "%s: p2p vdev object is NULL";
    goto LABEL_30;
  }
  v34 = (unsigned __int8 *)comp_private_obj;
  raw_spin_lock(comp_private_obj + 24);
  v35 = v34[48];
  v71 = 0;
  v70 = 0;
  if ( v35 == 1 )
  {
    v36 = v34 + 232;
    v37 = v34 + 40;
    v38 = v34 + 232;
    while ( 1 )
    {
      v38 = (_QWORD *)*v38;
      if ( v38 == v36 )
        break;
      if ( v38[2] == a3 )
      {
        if ( !v38 )
          break;
LABEL_23:
        qdf_list_remove_node((__int64)v36, v38);
        _qdf_mem_free((__int64)v38);
        if ( qdf_list_empty(v36) )
        {
          v39 = *((_DWORD *)v37 + 4);
          v37[8] = 0;
          qdf_mem_copy(&v70, v37 + 9, 6u);
          raw_spin_unlock(v34 + 24);
          if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v37 + 24)) == 21 )
          {
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: random_mac:stop timer on vdev %d addr %02x:%02x:%02x:**:**:%02x",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "p2p_del_random_mac",
              a2,
              (unsigned __int8)v70,
              BYTE1(v70),
              BYTE2(v70),
              HIBYTE(v71));
            qdf_mc_timer_stop((__int64)(v37 + 24));
          }
          v48 = *(_QWORD *)(*(_QWORD *)v34 + 216LL);
          if ( v48 )
            v49 = *(_QWORD *)(v48 + 80);
          else
            v49 = 0;
          p2p_set_mac_filter(v49, a2, &v70, v39, 0, 0, 0);
          raw_spin_lock(v34 + 24);
          LODWORD(v69) = HIBYTE(v71);
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: random_mac:noref on vdev %d addr %02x:%02x:%02x:**:**:%02x",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "p2p_del_random_mac",
            a2,
            (unsigned __int8)v70,
            BYTE1(v70),
            BYTE2(v70),
            v69);
        }
        goto LABEL_33;
      }
    }
  }
  v71 = 0;
  v70 = 0;
  if ( v34[264] == 1 )
  {
    v36 = v34 + 448;
    v37 = v34 + 256;
    v38 = v34 + 448;
    while ( 1 )
    {
      v38 = (_QWORD *)*v38;
      if ( v38 == v36 )
        break;
      if ( v38[2] == a3 )
      {
        if ( v38 )
          goto LABEL_23;
        break;
      }
    }
  }
  v71 = 0;
  v70 = 0;
  if ( v34[480] == 1 )
  {
    v36 = v34 + 664;
    v37 = v34 + 472;
    v38 = v34 + 664;
    while ( 1 )
    {
      v38 = (_QWORD *)*v38;
      if ( v38 == v36 )
        break;
      if ( v38[2] == a3 )
      {
        if ( v38 )
          goto LABEL_23;
        break;
      }
    }
  }
  v71 = 0;
  v70 = 0;
  if ( v34[696] == 1 )
  {
    v36 = v34 + 880;
    v37 = v34 + 688;
    v38 = v34 + 880;
    while ( 1 )
    {
      v38 = (_QWORD *)*v38;
      if ( v38 == v36 )
        break;
      if ( v38[2] == a3 )
      {
        if ( !v38 )
          break;
        goto LABEL_23;
      }
    }
  }
LABEL_33:
  raw_spin_unlock(v34 + 24);
  wlan_objmgr_vdev_release_ref(v23, 0xFu, v60, v61, v62, v63, v64, v65, v66, v67, v68);
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall wlan_ser_cancel_non_scan_cmd(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        int a7)
{
  __int64 pdev_queue_obj; // x24
  __int64 list_from_pdev_queue; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x8
  int v26; // w23
  bool v27; // cc
  _QWORD *v28; // x28
  int v29; // w9
  int v30; // w22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *v39; // x23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w24
  __int64 vdev_obj; // x0
  unsigned int v50; // w20
  __int64 list_from_vdev_queue; // x0
  char v52; // w19
  unsigned __int64 v53; // x23
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  void (__fastcall *v62)(__int64 *, __int64); // x8
  void (__fastcall *v63)(__int64 *, __int64); // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned __int64 v78; // x9
  const char *v79; // x2
  unsigned int v80; // w19
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v90; // [xsp+Ch] [xbp-84h]
  __int64 v91; // [xsp+10h] [xbp-80h]
  __int64 v92; // [xsp+20h] [xbp-70h]
  unsigned int v93; // [xsp+2Ch] [xbp-64h]
  __int64 v94; // [xsp+30h] [xbp-60h]
  int v95; // [xsp+3Ch] [xbp-54h]
  __int64 v96; // [xsp+40h] [xbp-50h]
  int v97; // [xsp+4Ch] [xbp-44h]
  _QWORD *v98; // [xsp+50h] [xbp-40h] BYREF
  __int64 v99; // [xsp+58h] [xbp-38h] BYREF
  void (__fastcall *v100)(__int64 *, __int64); // [xsp+60h] [xbp-30h]
  __int64 v101; // [xsp+68h] [xbp-28h]
  __int64 v102; // [xsp+70h] [xbp-20h]
  __int64 v103; // [xsp+78h] [xbp-18h]
  __int64 v104; // [xsp+80h] [xbp-10h]
  __int64 v105; // [xsp+88h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = nullptr;
  v98 = nullptr;
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(a1, a5);
  v92 = a1;
  list_from_pdev_queue = wlan_serialization_get_list_from_pdev_queue(a1, a5, a6);
  if ( !a2 )
  {
    if ( a3 )
    {
      v24 = *(_QWORD *)(a3 + 216);
      if ( v24 )
      {
LABEL_5:
        v94 = *(_QWORD *)(v24 + 80);
        goto LABEL_12;
      }
    }
    else if ( a4 && (v25 = *(_QWORD *)(a4 + 32)) != 0 )
    {
      v24 = *(_QWORD *)(v25 + 216);
      if ( v24 )
        goto LABEL_5;
    }
    else
    {
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: Can't find psoc",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_ser_cancel_non_scan_cmd");
    }
    v94 = 0;
    goto LABEL_12;
  }
  v94 = *(_QWORD *)(a2 + 80);
LABEL_12:
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  v26 = wlan_serialization_list_size(list_from_pdev_queue);
  if ( (wlan_serialization_list_empty(list_from_pdev_queue) & 1) != 0 )
  {
LABEL_64:
    v97 = 4;
LABEL_65:
    wlan_serialization_release_lock(pdev_queue_obj + 88);
    _ZF = (unsigned __int8)a6 == 0;
    v80 = v97;
    if ( !_ZF )
      goto LABEL_66;
    goto LABEL_69;
  }
  if ( a3 )
    v27 = a5 > 1;
  else
    v27 = 0;
  v91 = pdev_queue_obj + 72;
  v28 = nullptr;
  v29 = v27;
  v93 = a5;
  v30 = v26 + 1;
  v95 = v29;
  v97 = 4;
  v96 = pdev_queue_obj;
  while ( 1 )
  {
    if ( !--v30 )
      goto LABEL_65;
    if ( (unsigned int)wlan_serialization_get_cmd_from_queue(list_from_pdev_queue, &v98) )
    {
      v79 = "%s: can't read cmd from queue";
LABEL_63:
      qdf_trace_msg(0x4Cu, 2u, v79, v31, v32, v33, v34, v35, v36, v37, v38, "wlan_ser_cancel_non_scan_cmd");
      goto LABEL_64;
    }
    v39 = v98;
    if ( a4
      && ((wlan_serialization_match_cmd_id_type(v98, a4, 0) & 1) == 0
       || (wlan_serialization_match_cmd_vdev(v98, *(_QWORD *)(a4 + 32), 0) & 1) == 0)
      || a3 && (wlan_serialization_match_cmd_vdev(v98, a3, 0) & 1) == 0
      || a2 && (wlan_serialization_match_cmd_pdev(v98, a2, 0) & 1) == 0
      || v95
      && ((wlan_serialization_match_cmd_type(v98, v93, 0) & 1) == 0
       || (wlan_serialization_match_cmd_vdev(v98, a3, 0) & 1) == 0)
      || a7 == 2 && (wlan_serialization_match_cmd_blocking(v98, 0) & 1) != 0 )
    {
      v28 = v98;
      goto LABEL_35;
    }
    if ( (_BYTE)a6 )
      break;
LABEL_43:
    v90 = a7;
    qdf_mem_copy(&v99, v39 + 4, 0x30u);
    v48 = wlan_serialization_remove_node(list_from_pdev_queue, v39);
    vdev_obj = wlan_serialization_get_vdev_obj(v39[8]);
    v50 = a6;
    list_from_vdev_queue = wlan_serialization_get_list_from_vdev_queue(vdev_obj, v93, a6);
    if ( v48 | (unsigned int)wlan_serialization_remove_node(list_from_vdev_queue, v39 + 2) )
    {
      pdev_queue_obj = v96;
      v79 = "%s: can't remove cmd from pdev/vdev queue";
      goto LABEL_63;
    }
    qdf_mem_set(v39 + 4, 0x30u, 0);
    pdev_queue_obj = v96;
    v39[10] = 0;
    if ( (unsigned int)wlan_serialization_insert_back(v96 + 48, v39) )
    {
      v79 = "%s: can't remove cmd from queue";
      goto LABEL_63;
    }
    v52 = BYTE4(v101);
    v53 = *(unsigned __int8 *)(v103 + 168);
    v98 = v28;
    wlan_ser_update_cmd_history(v96, &v99, 2, 0, (unsigned __int8)v50 != 0);
    wlan_serialization_release_lock(v96 + 88);
    if ( v100 )
    {
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: Cancel command: type %d id %d vdev %d and Release memory",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "wlan_ser_cancel_non_scan_cmd",
        (unsigned int)v99,
        HIDWORD(v99),
        (unsigned int)v53);
      v62 = v100;
      if ( *((_DWORD *)v100 - 1) != -1491618541 )
        __break(0x8228u);
      v62(&v99, 1);
      v63 = v100;
      if ( *((_DWORD *)v100 - 1) != -1491618541 )
        __break(0x8228u);
      v63(&v99, 2);
    }
    wlan_serialization_acquire_lock(v96 + 88);
    if ( (_BYTE)v50 )
    {
      pdev_queue_obj = v96;
      if ( (v52 & 2) != 0 )
        *(_BYTE *)(v96 + 80) = 0;
      *(_QWORD *)(v91 + ((v53 >> 3) & 0x18)) &= ~(1LL << v53);
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: active_cmd_bitmap after resetting vdev %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "wlan_ser_cancel_non_scan_cmd",
        (unsigned int)v53);
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(76, 8, v91, 8);
    }
    else
    {
      pdev_queue_obj = v96;
      v97 = 0;
      if ( (v52 & 2) != 0 )
        --*(_WORD *)(v96 + 82);
    }
    a6 = v50;
    a7 = v90;
    if ( !(a2 | a3) )
      goto LABEL_65;
LABEL_35:
    if ( (wlan_serialization_list_empty(list_from_pdev_queue) & 1) != 0 )
      goto LABEL_65;
  }
  if ( !v94 || !v39 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: psoc:0x%pK, cmd_list:0x%pK",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wlan_ser_cancel_non_scan_cmd",
      v94,
      v39);
    pdev_queue_obj = v96;
    goto LABEL_74;
  }
  if ( (v39[10] & 2) != 0 )
  {
    pdev_queue_obj = v96;
    _X8 = v39 + 10;
    __asm { PRFM            #0x11, [X8] }
    do
      v78 = __ldxr(_X8);
    while ( __stxr(v78 | 8, _X8) );
    v97 = 3;
    goto LABEL_35;
  }
  pdev_queue_obj = v96;
  if ( !(unsigned int)wlan_serialization_find_and_stop_timer(
                        v94,
                        (unsigned int *)v39 + 8,
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        v36,
                        v37,
                        v38) )
  {
    v97 = 1;
    goto LABEL_43;
  }
  qdf_trace_msg(
    0x4Cu,
    2u,
    "%s: Can't find timer for active cmd",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wlan_ser_cancel_non_scan_cmd");
LABEL_74:
  wlan_serialization_release_lock(pdev_queue_obj + 88);
  v80 = 4;
LABEL_66:
  if ( (wlan_serialization_list_empty(list_from_pdev_queue) & 1) != 0
    && (wlan_serialization_any_vdev_cmd_active(pdev_queue_obj) & 1) == 0 )
  {
    wlan_ser_move_non_scan_pending_to_active(v92, 0, 0, v81, v82, v83, v84, v85, v86, v87, v88);
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v80;
}

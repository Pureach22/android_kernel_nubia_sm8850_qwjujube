__int64 __fastcall wlan_ser_move_non_scan_pending_to_active(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 vdev_obj; // x21
  const char *v14; // x2
  int v15; // w8
  _BOOL4 v16; // w9
  char v17; // w23
  __int64 v18; // x22
  int v19; // w0
  int v20; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  unsigned int v30; // w27
  __int64 v31; // x24
  __int64 v32; // x9
  unsigned __int64 v33; // x11
  __int64 v34; // x28
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 v45; // x10
  unsigned __int64 v52; // x9
  int v53; // w21
  __int64 v54; // x21
  int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int64 v66; // x9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+0h] [xbp-50h] BYREF
  __int64 v92; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v93[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v94[2]; // [xsp+40h] [xbp-10h] BYREF

  v94[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v94[0] = 0;
  memset(v93, 0, sizeof(v93));
  v91 = 0;
  v92 = 0;
  if ( !a1 )
  {
    v14 = "%s: Can't find ser_pdev_obj";
    goto LABEL_6;
  }
  if ( a2 )
  {
    vdev_obj = wlan_serialization_get_vdev_obj(a2);
    if ( !vdev_obj )
    {
      v14 = "%s: Can't find ser_vdev_obj";
LABEL_6:
      qdf_trace_msg(0x4Cu, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_ser_move_non_scan_pending_to_active", v91);
LABEL_15:
      result = 6;
      goto LABEL_16;
    }
  }
  else
  {
    vdev_obj = 0;
  }
  wlan_serialization_acquire_lock(a1 + 192);
  v15 = (*(_WORD *)(a1 + 186) == 0) & ~a3;
  v16 = vdev_obj != 0;
  v17 = v16 & v15;
  if ( (v16 & v15) != 0 )
    v18 = vdev_obj + 24;
  else
    v18 = a1 + 128;
  v19 = wlan_serialization_list_size(v18);
  if ( !v19 )
  {
LABEL_14:
    wlan_serialization_release_lock(a1 + 192);
    goto LABEL_15;
  }
  v20 = v19;
  if ( (unsigned int)wlan_serialization_peek_front(v18, &v92) )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: can't peek cmd",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_ser_move_non_scan_pending_to_active");
    goto LABEL_14;
  }
  v30 = 6;
  if ( (v17 & 1) != 0 )
    v31 = -16;
  else
    v31 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v32 = v92 + v31;
      v94[0] = v92 + v31;
      if ( !(v92 + v31) )
      {
        wlan_serialization_release_lock(a1 + 192);
        qdf_trace_msg(
          0x4Cu,
          8u,
          "%s: non scan cmd cannot move frm pendin to actv",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "wlan_ser_move_non_scan_pending_to_active");
        result = v30;
        goto LABEL_16;
      }
      v33 = *(unsigned __int8 *)(*(_QWORD *)(v32 + 64) + 104LL);
      v34 = *(_QWORD *)(a1 + 176 + ((v33 >> 3) & 0x18)) & (1LL << v33);
      if ( (v17 & 1) == 0 )
        break;
      if ( v34 || (*(_QWORD *)(v92 + 64) & 0x20) != 0 )
        goto LABEL_56;
LABEL_37:
      qdf_mem_copy(v93, (const void *)(v32 + 32), 0x30u);
      v53 = wlan_ser_remove_non_scan_cmd(a1, v94, v93, 0);
      wlan_ser_update_cmd_history(a1 + 104, v94[0] + 32, 5, 0, 0);
      if ( v53 )
      {
        wlan_serialization_release_lock(a1 + 192);
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: Can't remove cmd from pendingQ id-%d type-%d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "wlan_ser_move_non_scan_pending_to_active",
          *(unsigned int *)(v94[0] + 36),
          *(unsigned int *)(v94[0] + 32));
        goto LABEL_15;
      }
      v54 = v94[0];
      if ( (unsigned int)wlan_ser_add_non_scan_cmd(a1, v94[0], 1u) != 1 )
      {
        wlan_serialization_release_lock(a1 + 192);
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: Can't move cmd to activeQ id-%d type-%d",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "wlan_ser_move_non_scan_pending_to_active",
          *(unsigned int *)(v94[0] + 36),
          *(unsigned int *)(v94[0] + 32));
        wlan_serialization_insert_back(a1 + 152, v54);
        goto LABEL_15;
      }
      wlan_ser_update_cmd_history(a1 + 104, v54 + 32, 5, 1, 1);
      _X8 = (unsigned __int64 *)(v54 + 80);
      __asm { PRFM            #0x11, [X8] }
      do
        v66 = __ldxr(_X8);
      while ( __stxr(v66 | 2, _X8) );
      if ( (*(_BYTE *)(v54 + 52) & 2) != 0 )
        --*(_WORD *)(a1 + 186);
      wlan_serialization_release_lock(a1 + 192);
      wlan_serialization_activate_cmd(v54, a1, 5);
      wlan_serialization_acquire_lock(a1 + 192);
      if ( (v17 & 1) != 0 || (*(_BYTE *)(a1 + 184) & 1) != 0 )
      {
        v30 = 1;
        goto LABEL_56;
      }
      v55 = wlan_serialization_list_size(a1 + 128);
      if ( !v55 )
        goto LABEL_54;
      v20 = v55;
      if ( (unsigned int)wlan_serialization_peek_front(a1 + 128, &v92) )
      {
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: can't peek cmd",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "wlan_ser_move_non_scan_pending_to_active");
LABEL_54:
        wlan_serialization_release_lock(a1 + 192);
        result = 1;
        goto LABEL_16;
      }
      v30 = 1;
    }
    if ( (*(_BYTE *)(v92 + 52) & 2) != 0 && (wlan_serialization_any_vdev_cmd_active(a1 + 104) & 1) != 0 )
      goto LABEL_56;
    if ( !--v20 )
    {
      v32 = v94[0];
      if ( !v34 )
        goto LABEL_37;
      goto LABEL_31;
    }
    if ( (unsigned int)wlan_serialization_peek_next(a1 + 128, v92, &v91) )
      break;
    v92 = v91;
    _X8 = (unsigned __int64 *)(v91 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr(_X8);
    while ( __stxr(v52 | 0x20, _X8) );
    v32 = v94[0];
    if ( !v34 )
      goto LABEL_37;
LABEL_31:
    _X9 = (unsigned __int64 *)(v32 + 80);
    __asm { PRFM            #0x11, [X9] }
    do
      v45 = __ldxr(_X9);
    while ( __stxr(v45 & 0xFFFFFFFFFFFFFFDFLL, _X9) );
    if ( !v20 )
      goto LABEL_56;
  }
  qdf_trace_msg(
    0x4Cu,
    2u,
    "%s: can't peek cmd",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wlan_ser_move_non_scan_pending_to_active");
LABEL_56:
  wlan_serialization_release_lock(a1 + 192);
  result = v30;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}

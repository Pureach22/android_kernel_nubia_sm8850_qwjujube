__int64 __fastcall wlan_ser_cancel_scan_cmd(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        char a14)
{
  __int64 v19; // x26
  __int64 v20; // x8
  __int64 v21; // x8
  int v22; // w25
  __int64 v23; // x24
  int v24; // w27
  unsigned int v25; // w25
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x28
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  void (__fastcall *v43)(__int64 *, __int64); // x8
  void (__fastcall *v44)(__int64 *, __int64); // x8
  unsigned __int64 v51; // x9
  const char *v52; // x2
  __int64 v54; // [xsp+8h] [xbp-48h]
  __int64 v55; // [xsp+10h] [xbp-40h] BYREF
  __int64 v56; // [xsp+18h] [xbp-38h] BYREF
  void (__fastcall *v57)(__int64 *, __int64); // [xsp+20h] [xbp-30h]
  __int64 v58; // [xsp+28h] [xbp-28h]
  __int64 v59; // [xsp+30h] [xbp-20h]
  __int64 v60; // [xsp+38h] [xbp-18h]
  __int64 v61; // [xsp+40h] [xbp-10h]
  __int64 v62; // [xsp+48h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a14 )
    v19 = 0;
  else
    v19 = 24;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = nullptr;
  v55 = 0;
  if ( a2 )
  {
    v54 = *(_QWORD *)(a2 + 80);
    goto LABEL_15;
  }
  if ( a3 )
  {
    v20 = *(_QWORD *)(a3 + 216);
    if ( v20 )
    {
LABEL_8:
      v54 = *(_QWORD *)(v20 + 80);
      goto LABEL_15;
    }
  }
  else if ( a4 && (v21 = *(_QWORD *)(a4 + 32)) != 0 )
  {
    v20 = *(_QWORD *)(v21 + 216);
    if ( v20 )
      goto LABEL_8;
  }
  else
  {
    qdf_trace_msg(0x4Cu, 8u, "%s: Can't find psoc", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_ser_cancel_scan_cmd");
  }
  v54 = 0;
LABEL_15:
  wlan_serialization_acquire_lock(a1 + 88);
  v22 = wlan_serialization_list_size(a1 + v19);
  if ( (wlan_serialization_list_empty(a1 + v19) & 1) == 0 )
  {
    v23 = 0;
    v24 = v22 + 1;
    v25 = 4;
    while ( 1 )
    {
      if ( !--v24 )
        goto LABEL_49;
      if ( (unsigned int)wlan_serialization_get_cmd_from_queue(a1 + v19, &v55) )
      {
        v52 = "%s: can't read cmd from queue";
LABEL_47:
        qdf_trace_msg(0x4Cu, 2u, v52, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_ser_cancel_scan_cmd");
        break;
      }
      v34 = v55;
      if ( a4 && (wlan_serialization_match_cmd_id_type(v55, a4, 0) & 1) == 0
        || a3 && (wlan_serialization_match_cmd_vdev(v55, a3, 0) & 1) == 0
        || a2 && (wlan_serialization_match_cmd_pdev(v55, a2, 0) & 1) == 0 )
      {
        v23 = v55;
      }
      else
      {
        if ( a14 )
        {
          if ( !v54 || !v34 )
          {
            qdf_trace_msg(
              0x4Cu,
              2u,
              "%s: psoc:0x%pK, cmd_list:0x%pK",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "wlan_ser_cancel_scan_cmd",
              v54,
              v34);
            break;
          }
          if ( (*(_QWORD *)(v34 + 80) & 2) != 0 )
          {
            _X8 = (unsigned __int64 *)(v34 + 80);
            __asm { PRFM            #0x11, [X8] }
            do
              v51 = __ldxr(_X8);
            while ( __stxr(v51 | 8, _X8) );
            v25 = 3;
            goto LABEL_18;
          }
          if ( (unsigned int)wlan_serialization_find_and_stop_timer(
                               v54,
                               (unsigned int *)(v34 + 32),
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               v33) )
          {
            v52 = "%s: Can't fix timer for active cmd";
            goto LABEL_47;
          }
          v25 = 1;
        }
        else
        {
          v25 = 0;
        }
        qdf_mem_copy(&v56, (const void *)(v34 + 32), 0x30u);
        if ( (unsigned int)wlan_serialization_remove_node(a1 + v19, v34) )
        {
          v52 = "%s: can't remove cmd from pdev queue";
          goto LABEL_47;
        }
        qdf_mem_set((void *)(v34 + 32), 0x30u, 0);
        *(_QWORD *)(v34 + 80) = 0;
        if ( (unsigned int)wlan_serialization_insert_back(a1 + 48, v34) )
        {
          v52 = "%s: can't remove cmd from queue";
          goto LABEL_47;
        }
        v55 = v23;
        wlan_ser_update_cmd_history(a1, &v56, 2, 0, a14 != 0);
        wlan_serialization_release_lock(a1 + 88);
        if ( v57 )
        {
          qdf_trace_msg(
            0x4Cu,
            8u,
            "%s: Cancel command: type %d id %d vdev %d and Release memory",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "wlan_ser_cancel_scan_cmd",
            (unsigned int)v56,
            HIDWORD(v56),
            *(unsigned __int8 *)(v60 + 168));
          v43 = v57;
          if ( *((_DWORD *)v57 - 1) != -1491618541 )
            __break(0x8228u);
          v43(&v56, 1);
          v44 = v57;
          if ( *((_DWORD *)v57 - 1) != -1491618541 )
            __break(0x8228u);
          v44(&v56, 2);
        }
        wlan_serialization_acquire_lock(a1 + 88);
      }
LABEL_18:
      if ( (wlan_serialization_list_empty(a1 + v19) & 1) != 0 )
        goto LABEL_49;
    }
  }
  v25 = 4;
LABEL_49:
  wlan_serialization_release_lock(a1 + 88);
  _ReadStatusReg(SP_EL0);
  return v25;
}

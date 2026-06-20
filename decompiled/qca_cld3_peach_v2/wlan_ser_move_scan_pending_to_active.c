__int64 __fastcall wlan_ser_move_scan_pending_to_active(
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
  const char *v10; // x2
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x20
  unsigned __int64 v47; // x9
  __int64 v48; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v49[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v50[2]; // [xsp+40h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v49, 0, sizeof(v49));
  v48 = 0;
  if ( !a1 )
  {
    v10 = "%s: Can't find ser_pdev_obj";
LABEL_7:
    qdf_trace_msg(0x4Cu, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ser_move_scan_pending_to_active");
    goto LABEL_8;
  }
  wlan_serialization_acquire_lock(a1 + 88);
  if ( (wlan_serialization_list_empty(a1 + 24) & 1) != 0 )
  {
LABEL_3:
    wlan_serialization_release_lock(a1 + 88);
LABEL_8:
    result = 6;
    goto LABEL_9;
  }
  if ( (unsigned int)wlan_serialization_peek_front(a1 + 24, &v48) )
  {
    wlan_serialization_release_lock(a1 + 88);
    v10 = "%s: can't read from pending queue";
    goto LABEL_7;
  }
  v50[0] = v48;
  if ( !v48 )
    goto LABEL_3;
  qdf_mem_copy(v49, (const void *)(v48 + 32), 0x30u);
  if ( !wlan_serialization_is_active_scan_cmd_allowed((__int64)v49) )
  {
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: active scan command not allowed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_ser_move_scan_pending_to_active");
    goto LABEL_3;
  }
  v20 = wlan_serialization_remove_cmd_from_pdev_queue(a1, (__int64)v50, v49, 0, v12, v13, v14, v15, v16, v17, v18, v19);
  wlan_ser_update_cmd_history(a1, v50[0] + 32, 5, 0, 0);
  if ( v20 )
  {
    wlan_serialization_release_lock(a1 + 88);
    v37 = "%s: Can't remove from pendingQ id %d type %d";
    v39 = *(unsigned int *)(v50[0] + 32);
    v38 = *(unsigned int *)(v50[0] + 36);
LABEL_18:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v37,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_ser_move_scan_pending_to_active",
      v38,
      v39);
    goto LABEL_8;
  }
  v40 = v50[0];
  if ( (unsigned int)wlan_serialization_add_cmd_to_pdev_queue(a1, v50[0], 1, v21, v22, v23, v24, v25, v26, v27, v28) != 1 )
  {
    wlan_serialization_insert_back(a1 + 48, v40);
    wlan_serialization_release_lock(a1 + 88);
    v39 = *(unsigned int *)(v40 + 32);
    v38 = *(unsigned int *)(v40 + 36);
    v37 = "%s: Can't add cmd to activeQ id-%d type-%d";
    goto LABEL_18;
  }
  _X8 = (unsigned __int64 *)(v40 + 80);
  __asm { PRFM            #0x11, [X8] }
  do
    v47 = __ldxr(_X8);
  while ( __stxr(v47 | 2, _X8) );
  wlan_ser_update_cmd_history(a1, v40 + 32, 5, 1, 1);
  wlan_serialization_release_lock(a1 + 88);
  wlan_serialization_activate_cmd(v40, a1, 5);
  result = 1;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall wlan_serialization_activate_cmd(__int64 a1, __int64 a2, char a3)
{
  unsigned int *v5; // x19
  __int64 pdev_queue_obj; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x22
  __int64 v19; // x0
  unsigned int v20; // w25
  unsigned int started; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x4
  __int64 v31; // x5
  unsigned int v32; // w23
  _DWORD *v33; // x9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x4
  unsigned __int64 v50; // x10
  unsigned __int64 v53; // x9

  v5 = (unsigned int *)(a1 + 32);
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(a2, *(unsigned int *)(a1 + 32));
  v16 = *((_QWORD *)v5 + 4);
  v17 = *(_QWORD *)(v16 + 152);
  if ( v17 && (v18 = pdev_queue_obj, (v19 = *(_QWORD *)(v17 + 80)) != 0) )
  {
    v20 = *(unsigned __int8 *)(v16 + 104);
    started = wlan_serialization_find_and_start_timer(v19, v5);
    v30 = *(unsigned int *)(a1 + 32);
    v31 = *(unsigned int *)(a1 + 36);
    if ( started )
    {
      v32 = started;
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: Failed to start timer cmd type %d id %d vdev %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_serialization_activate_cmd",
        v30,
        v31,
        v20);
    }
    else
    {
      qdf_trace_msg(
        0x4Cu,
        8u,
        "%s: Activate type %d id %d vdev %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_serialization_activate_cmd",
        v30,
        v31,
        v20);
      v33 = *(_DWORD **)(a1 + 40);
      *(_BYTE *)(a1 + 52) = *(_BYTE *)(a1 + 52) & 0xC7 | (8 * (a3 & 7));
      if ( *(v33 - 1) != -1491618541 )
        __break(0x8229u);
      v32 = ((__int64 (__fastcall *)(unsigned int *, _QWORD))v33)(v5, 0);
    }
    wlan_serialization_acquire_lock(v18 + 88);
    _X8 = (unsigned __int64 *)(a1 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v50 = __ldxr(_X8);
    while ( __stxr(v50 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    _X8 = (unsigned __int64 *)(a1 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v53 = __ldxr(_X8);
    while ( __stxr(v53 | 4, _X8) );
    wlan_serialization_release_lock(v18 + 88);
    if ( v32 )
    {
      wlan_serialization_dequeue_cmd(v5, 4, 1);
    }
    else
    {
      if ( (*(_QWORD *)(a1 + 80) & 0x10) != 0 )
      {
        wlan_serialization_dequeue_cmd(v5, 1, 1);
      }
      else if ( (*(_QWORD *)(a1 + 80) & 8) != 0 )
      {
        if ( a2 )
        {
          v42 = *v5;
          if ( (_DWORD)v42 )
            wlan_ser_cancel_non_scan_cmd(a2, 0, 0, v5, v42, 1, 0);
          else
            wlan_ser_cancel_scan_cmd(a2, 0, 0, v5, v42, 1);
        }
        else
        {
          qdf_trace_msg(
            0x4Cu,
            2u,
            "%s: invalid serial object",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wlan_serialization_cmd_cancel_handler");
        }
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid psoc",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_serialization_activate_cmd");
    return 16;
  }
  return v32;
}

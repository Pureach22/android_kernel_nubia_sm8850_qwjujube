__int64 __fastcall wlan_serialization_cleanup_vdev_timers(
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
  __int64 v9; // x8
  __int64 v11; // x0
  __int64 comp_private_obj; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x27
  unsigned __int64 v24; // x28
  __int64 v25; // x25
  _QWORD *v26; // x23
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  __int64 v37; // x8

  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 )
  {
    v36 = "%s: pdev is null";
LABEL_23:
    qdf_trace_msg(0x4Cu, 2u, v36, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_cleanup_vdev_timers");
    return 16;
  }
  v11 = *(_QWORD *)(v9 + 80);
  if ( !v11 )
  {
    v36 = "%s: psoc is null";
    goto LABEL_23;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 2u);
  if ( !comp_private_obj )
  {
    v36 = "%s: Invalid psoc_ser_obj";
    goto LABEL_23;
  }
  v13 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 14976);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 14976);
    *(_QWORD *)(v13 + 14984) |= 1uLL;
  }
  if ( *(_BYTE *)(v13 + 14968) )
  {
    v23 = 0;
    v24 = 0;
    do
    {
      v25 = *(_QWORD *)(v13 + 14960);
      v26 = (_QWORD *)(v25 + v23);
      v27 = *(_QWORD *)(v25 + v23);
      if ( v27 && *(_QWORD *)(v27 + 32) == a1 )
      {
        qdf_trace_msg(
          0x4Cu,
          8u,
          "%s: Stopping the timer for vdev id[%d]",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_serialization_cleanup_vdev_timers",
          *(unsigned __int8 *)(a1 + 104));
        if ( v26 && *v26 )
        {
          timer_delete_sync(v25 + v23 + 8);
          *(_QWORD *)(v25 + v23) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x4Cu,
            8u,
            "%s: Invalid ser_timer",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_serialization_timer_destroy");
        }
      }
      ++v24;
      v23 += 64;
    }
    while ( v24 < *(unsigned __int8 *)(v13 + 14968) );
  }
  v37 = *(_QWORD *)(v13 + 14984);
  if ( (v37 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 14984) = v37 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 14976);
  }
  else
  {
    raw_spin_unlock(v13 + 14976);
  }
  return 0;
}

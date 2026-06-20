__int64 __fastcall wlan_objmgr_register_vdev_destroy_handler(
        unsigned int a1,
        __int64 a2,
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
  __int64 v15; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v17; // x8
  __int64 v18; // x10
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x23

  if ( a1 < 0x36 )
  {
    v15 = g_umac_glb_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v15 + 11712);
    }
    else
    {
      v30 = v15;
      raw_spin_lock_bh(v15 + 11712);
      *(_QWORD *)(v30 + 11720) |= 1uLL;
    }
    v17 = g_umac_glb_obj;
    if ( *(_QWORD *)(g_umac_glb_obj + 6088 + 8LL * a1) )
    {
      v18 = *(_QWORD *)(g_umac_glb_obj + 11720);
      if ( (v18 & 1) != 0 )
      {
        *(_QWORD *)(g_umac_glb_obj + 11720) = v18 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v17 + 11712);
      }
      else
      {
        raw_spin_unlock(g_umac_glb_obj + 11712);
      }
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: Callback for comp %d is already registered",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_objmgr_register_vdev_destroy_handler",
        a1);
      return 16;
    }
    else
    {
      v27 = 8LL * a1;
      *(_QWORD *)(g_umac_glb_obj + 6088 + v27) = a2;
      *(_QWORD *)(g_umac_glb_obj + v27 + 6520) = a3;
      v28 = g_umac_glb_obj;
      v29 = *(_QWORD *)(g_umac_glb_obj + 11720);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(g_umac_glb_obj + 11720) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v28 + 11712);
      }
      else
      {
        raw_spin_unlock(g_umac_glb_obj + 11712);
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Component %d is out of range",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_objmgr_register_vdev_destroy_handler",
      a1);
    return 38;
  }
}

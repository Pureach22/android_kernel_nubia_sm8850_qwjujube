__int64 __fastcall wlan_objmgr_unregister_psoc_status_handler(
        unsigned int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v13; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v15; // x8
  __int64 v16; // x10
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x22

  if ( a1 < 0x36 )
  {
    v13 = g_umac_glb_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 11712);
    }
    else
    {
      v28 = v13;
      raw_spin_lock_bh(v13 + 11712);
      *(_QWORD *)(v28 + 11720) |= 1uLL;
    }
    v15 = g_umac_glb_obj;
    if ( *(_QWORD *)(g_umac_glb_obj + 1768 + 8LL * a1) == a2 )
    {
      v25 = 8LL * a1;
      *(_QWORD *)(g_umac_glb_obj + 1768 + v25) = 0;
      *(_QWORD *)(g_umac_glb_obj + v25 + 2200) = 0;
      v26 = g_umac_glb_obj;
      v27 = *(_QWORD *)(g_umac_glb_obj + 11720);
      if ( (v27 & 1) != 0 )
      {
        *(_QWORD *)(g_umac_glb_obj + 11720) = v27 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v26 + 11712);
      }
      else
      {
        raw_spin_unlock(g_umac_glb_obj + 11712);
      }
      return 0;
    }
    else
    {
      v16 = *(_QWORD *)(g_umac_glb_obj + 11720);
      if ( (v16 & 1) != 0 )
      {
        *(_QWORD *)(g_umac_glb_obj + 11720) = v16 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v15 + 11712);
      }
      else
      {
        raw_spin_unlock(g_umac_glb_obj + 11712);
      }
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: Callback for comp %d is not registered",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_objmgr_unregister_psoc_status_handler",
        a1);
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Component %d is out of range",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_unregister_psoc_status_handler",
      a1);
    return 38;
  }
}

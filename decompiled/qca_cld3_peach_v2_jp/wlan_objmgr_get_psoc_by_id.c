__int64 __fastcall wlan_objmgr_get_psoc_by_id(
        unsigned __int8 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v13; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v15; // x8
  __int64 v16; // x20
  int ref; // w0
  __int64 v18; // x10
  __int64 v20; // x22

  if ( a1 < 5u )
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
      v20 = v13;
      raw_spin_lock_bh(v13 + 11712);
      *(_QWORD *)(v20 + 11720) |= 1uLL;
    }
    v15 = g_umac_glb_obj;
    v16 = *(_QWORD *)(g_umac_glb_obj + 8LL * a1);
    if ( v16 )
    {
      ref = wlan_objmgr_psoc_try_get_ref(v16, a2);
      v15 = g_umac_glb_obj;
      if ( ref )
        v10 = 0;
      else
        v10 = v16;
    }
    else
    {
      v10 = 0;
    }
    v18 = *(_QWORD *)(v15 + 11720);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(v15 + 11720) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v15 + 11712);
    }
    else
    {
      raw_spin_unlock(v15 + 11712);
    }
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s:  PSOC id[%d] is invalid",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_get_psoc_by_id");
    return 0;
  }
  return v10;
}

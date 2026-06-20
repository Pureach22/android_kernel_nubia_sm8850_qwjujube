__int64 __fastcall pmo_core_get_listen_interval(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8

  if ( a1 && a2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v12 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(v12 + 1064) |= 1uLL;
    }
    *a2 = *(_DWORD *)(v12 + 1044);
    v14 = *(_QWORD *)(v12 + 1064);
    if ( (v14 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 1064) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 1056);
    }
    else
    {
      raw_spin_unlock(v12 + 1056);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev NULL or NULL ptr",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pmo_core_get_listen_interval");
    return 29;
  }
}

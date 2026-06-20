__int64 wlan_objmgr_global_obj_can_destroyed()
{
  __int64 v0; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v2; // x8
  unsigned int v3; // w19
  __int64 v4; // x10
  __int64 v6; // x20

  v0 = g_umac_glb_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v0 + 11720);
  }
  else
  {
    v6 = v0;
    raw_spin_lock_bh(v0 + 11720);
    *(_QWORD *)(v6 + 11728) |= 1uLL;
  }
  v2 = g_umac_glb_obj;
  if ( *(_QWORD *)g_umac_glb_obj
    || *(_QWORD *)(g_umac_glb_obj + 8)
    || *(_QWORD *)(g_umac_glb_obj + 16)
    || *(_QWORD *)(g_umac_glb_obj + 24) )
  {
    v3 = 16;
  }
  else
  {
    v3 = 16 * (*(_QWORD *)(g_umac_glb_obj + 32) != 0);
  }
  v4 = *(_QWORD *)(g_umac_glb_obj + 11728);
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(g_umac_glb_obj + 11728) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 11720);
  }
  else
  {
    raw_spin_unlock(g_umac_glb_obj + 11720);
  }
  return v3;
}

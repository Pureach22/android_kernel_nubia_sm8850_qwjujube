__int64 __fastcall wlan_objmgr_psoc_object_detach(__int64 a1)
{
  unsigned __int64 v1; // x19
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x21

  v1 = *(unsigned __int8 *)(a1 + 48);
  if ( v1 > 4 )
    return 4;
  v3 = g_umac_glb_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v3 + 11712);
  }
  else
  {
    v7 = v3;
    raw_spin_lock_bh(v3 + 11712);
    *(_QWORD *)(v7 + 11720) |= 1uLL;
  }
  *(_QWORD *)(g_umac_glb_obj + 8 * v1) = 0;
  v5 = g_umac_glb_obj;
  v6 = *(_QWORD *)(g_umac_glb_obj + 11720);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(g_umac_glb_obj + 11720) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v5 + 11712);
  }
  else
  {
    raw_spin_unlock(g_umac_glb_obj + 11712);
  }
  return 0;
}

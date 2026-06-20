__int64 __fastcall wlan_objmgr_iterate_psoc_list(void (*a1)(void))
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x10
  _QWORD *v4; // x8
  __int64 v5; // x10
  __int64 v7; // x22

  v2 = g_umac_glb_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 11720);
  }
  else
  {
    v7 = v2;
    raw_spin_lock_bh(v2 + 11720);
    *(_QWORD *)(v7 + 11728) |= 1uLL;
  }
  v4 = (_QWORD *)g_umac_glb_obj;
  if ( *(_QWORD *)g_umac_glb_obj )
  {
    if ( *((_DWORD *)a1 - 1) != -1567798657 )
      __break(0x8233u);
    a1();
    v4 = (_QWORD *)g_umac_glb_obj;
  }
  if ( v4[1] )
  {
    if ( *((_DWORD *)a1 - 1) != -1567798657 )
      __break(0x8233u);
    a1();
    v4 = (_QWORD *)g_umac_glb_obj;
  }
  if ( v4[2] )
  {
    if ( *((_DWORD *)a1 - 1) != -1567798657 )
      __break(0x8233u);
    a1();
    v4 = (_QWORD *)g_umac_glb_obj;
  }
  if ( v4[3] )
  {
    if ( *((_DWORD *)a1 - 1) != -1567798657 )
      __break(0x8233u);
    a1();
    v4 = (_QWORD *)g_umac_glb_obj;
  }
  if ( v4[4] )
  {
    if ( *((_DWORD *)a1 - 1) != -1567798657 )
      __break(0x8233u);
    a1();
    v4 = (_QWORD *)g_umac_glb_obj;
  }
  v5 = v4[1466];
  if ( (v5 & 1) != 0 )
  {
    v4[1466] = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 1465);
  }
  else
  {
    raw_spin_unlock(v4 + 1465);
  }
  return 0;
}

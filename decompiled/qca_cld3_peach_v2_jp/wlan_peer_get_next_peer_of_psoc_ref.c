__int64 __fastcall wlan_peer_get_next_peer_of_psoc_ref(__int64 a1, unsigned __int8 a2, _QWORD *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x20
  __int64 v8; // x8
  unsigned int v16; // w9
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1536);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1536);
    *(_QWORD *)(a1 + 1544) |= 1uLL;
  }
  if ( a2 >= 0x41u )
    __break(0x5512u);
  v17[0] = 0;
  if ( a3 && !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 24LL * a2), a3, v17) )
  {
    v7 = v17[0];
    if ( v17[0] )
    {
      _X8 = (unsigned int *)(v17[0] + 96LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 + 1, _X8) );
    }
  }
  else
  {
    v7 = 0;
  }
  v8 = *(_QWORD *)(a1 + 1544);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1544) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1536);
  }
  else
  {
    raw_spin_unlock(a1 + 1536);
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}

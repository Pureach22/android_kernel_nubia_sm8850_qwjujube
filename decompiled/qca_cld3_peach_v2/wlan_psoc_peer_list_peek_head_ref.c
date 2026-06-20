__int64 __fastcall wlan_psoc_peer_list_peek_head_ref(__int64 a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  __int64 v6; // x8
  unsigned int v14; // w9
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v15[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 24LL * a2), v15) )
    v5 = 0;
  else
    v5 = v15[0];
  if ( v5 )
  {
    _X8 = (unsigned int *)(v5 + 104);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 + 1, _X8) );
    v6 = *(_QWORD *)(a1 + 1544);
    if ( (v6 & 1) == 0 )
      goto LABEL_11;
LABEL_18:
    *(_QWORD *)(a1 + 1544) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1536);
    goto LABEL_12;
  }
  v6 = *(_QWORD *)(a1 + 1544);
  if ( (v6 & 1) != 0 )
    goto LABEL_18;
LABEL_11:
  raw_spin_unlock(a1 + 1536);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v5;
}

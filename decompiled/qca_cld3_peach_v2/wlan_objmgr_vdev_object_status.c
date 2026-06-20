__int64 __fastcall wlan_objmgr_vdev_object_status(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned int v5; // w20
  int v6; // w10
  __int64 v7; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  v3 = 0;
  v4 = a1 + 688;
  v5 = 16;
  do
  {
    v6 = *(_DWORD *)(v4 + 4 * v3 + 432);
    if ( v6 == 40 )
    {
      if ( !*(_QWORD *)(v4 + 8 * v3) )
      {
        v5 = 40;
        v7 = *(_QWORD *)(a1 + 1352);
        if ( (v7 & 1) == 0 )
          goto LABEL_14;
        goto LABEL_17;
      }
    }
    else if ( v6 == 2 || v6 == 16 )
    {
      goto LABEL_13;
    }
    ++v3;
  }
  while ( v3 != 54 );
  v5 = 0;
LABEL_13:
  v7 = *(_QWORD *)(a1 + 1352);
  if ( (v7 & 1) == 0 )
  {
LABEL_14:
    raw_spin_unlock(a1 + 1344);
    return v5;
  }
LABEL_17:
  *(_QWORD *)(a1 + 1352) = v7 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 1344);
  return v5;
}

__int64 __fastcall dp_clear_peer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int v13; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  int v17; // [xsp+0h] [xbp-10h] BYREF
  __int16 v18; // [xsp+4h] [xbp-Ch]
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = a3;
  v18 = WORD2(a3);
  v3 = dp_peer_find_hash_find(a1, (unsigned __int16 *)&v17, 0, 0xFFu, 7u);
  if ( v3 )
  {
    v12 = v3;
    if ( (*(_BYTE *)(v3 + 120) & 4) != 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v3 + 128);
        v15 = *(_QWORD *)(v12 + 136);
      }
      else
      {
        raw_spin_lock_bh(v3 + 128);
        v15 = *(_QWORD *)(v12 + 136) | 1LL;
        *(_QWORD *)(v12 + 136) = v15;
      }
      *(_DWORD *)(v12 + 124) = 1;
      if ( (v15 & 1) != 0 )
      {
        *(_QWORD *)(v12 + 136) = v15 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v12 + 128);
      }
      else
      {
        raw_spin_unlock(v12 + 128);
      }
      dp_rx_flush_rx_cached(v12, 1);
      v13 = 0;
    }
    else
    {
      v13 = 5;
    }
    dp_peer_unref_delete(v12, 7u, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  else
  {
    v13 = 5;
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}

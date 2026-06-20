__int64 __fastcall dp_peer_find_hash_remove(__int64 a1, __int64 a2)
{
  int v2; // w24
  int v3; // w26
  unsigned int v5; // w25
  int v6; // w23
  int v8; // w22
  unsigned __int64 StatusReg; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x10
  _QWORD *v19; // x9
  __int64 v20; // x8

  v2 = *(unsigned __int16 *)(a2 + 44);
  v3 = *(unsigned __int16 *)(a2 + 46);
  v5 = *(unsigned __int16 *)(a2 + 48);
  v6 = *(_DWORD *)(a1 + 13100);
  v8 = *(_DWORD *)(a1 + 13096);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13240);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13240);
    *(_QWORD *)(a1 + 13248) |= 1uLL;
  }
  v18 = *(_QWORD *)(a2 + 72);
  v19 = *(_QWORD **)(a2 + 80);
  if ( v18 )
    *(_QWORD *)(v18 + 80) = v19;
  else
    *(_QWORD *)(*(_QWORD *)(a1 + 13104) + 16LL * ((((v3 ^ v2 ^ v5) >> v6) ^ v3 ^ v2 ^ v5) & v8) + 8) = v19;
  *v19 = *(_QWORD *)(a2 + 72);
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  dp_peer_unref_delete(a2, 0xCu, v10, v11, v12, v13, v14, v15, v16, v17);
  v20 = *(_QWORD *)(a1 + 13248);
  if ( (v20 & 1) == 0 )
    return raw_spin_unlock(a1 + 13240);
  *(_QWORD *)(a1 + 13248) = v20 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 13240);
}

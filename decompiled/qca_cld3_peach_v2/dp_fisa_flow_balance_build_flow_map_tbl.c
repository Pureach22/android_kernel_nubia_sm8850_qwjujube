__int64 __fastcall dp_fisa_flow_balance_build_flow_map_tbl(__int64 a1, __int64 a2, _DWORD *a3, _DWORD *a4)
{
  __int64 *v4; // x22
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w11
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  __int64 v12; // x11
  __int64 v13; // x12
  int v14; // w13
  int v15; // w13
  __int64 v16; // x8

  v4 = *(__int64 **)(a1 + 1480);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v4 + 6);
    v9 = *((unsigned __int16 *)v4 + 16);
    if ( !*((_WORD *)v4 + 16) )
      goto LABEL_12;
  }
  else
  {
    raw_spin_lock_bh(v4 + 6);
    v4[7] |= 1uLL;
    v9 = *((unsigned __int16 *)v4 + 16);
    if ( !*((_WORD *)v4 + 16) )
      goto LABEL_12;
  }
  v10 = *v4;
  v11 = 0;
  do
  {
    if ( *(_BYTE *)(v10 + 40) && *(_BYTE *)(v10 + 320) == 1 && *(unsigned __int8 *)(v10 + 144) <= 7uLL )
    {
      v12 = a2 + 24LL * *(unsigned __int8 *)(v10 + 144);
      v13 = *(_QWORD *)v12 + 8LL * *(unsigned int *)(v12 + 8);
      *(_WORD *)(v13 + 4) = *(_DWORD *)(v10 + 16);
      v14 = *(_DWORD *)(v10 + 296);
      *(_DWORD *)v13 = v14;
      LODWORD(v13) = *(_DWORD *)(v12 + 12) + v14;
      v15 = *(_DWORD *)(v12 + 8) + 1;
      *(_DWORD *)(v12 + 12) = v13;
      LOBYTE(v13) = *(_BYTE *)(v10 + 144);
      *(_DWORD *)(v12 + 8) = v15;
      *(_BYTE *)(v12 + 17) = v13;
      *a3 += *(_DWORD *)(v10 + 296);
      ++*a4;
      v9 = *((unsigned __int16 *)v4 + 16);
    }
    ++v11;
    v10 += 336;
  }
  while ( v11 < v9 );
LABEL_12:
  v16 = v4[7];
  if ( (v16 & 1) == 0 )
    return raw_spin_unlock(v4 + 6);
  v4[7] = v16 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v4 + 6);
}

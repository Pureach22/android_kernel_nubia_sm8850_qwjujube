__int64 __fastcall dp_get_link_peers_ref_from_mld_peer(int a1, __int64 a2, _BYTE *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  unsigned int v8; // w23
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0

  qdf_mem_set(a3, 0x28u, 0);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 480);
    if ( !*(_BYTE *)(a2 + 437) )
      goto LABEL_9;
  }
  else
  {
    raw_spin_lock_bh(a2 + 480);
    *(_QWORD *)(a2 + 488) |= 1uLL;
    if ( !*(_BYTE *)(a2 + 437) )
    {
LABEL_9:
      v8 = 0;
      if ( !*(_BYTE *)(a2 + 449) )
        goto LABEL_12;
      goto LABEL_10;
    }
  }
  v7 = dp_peer_find_hash_find(a1, (int)a2 + 428);
  if ( !v7 )
    goto LABEL_9;
  v8 = 1;
  *(_QWORD *)a3 = v7;
  if ( !*(_BYTE *)(a2 + 449) )
    goto LABEL_12;
LABEL_10:
  v9 = dp_peer_find_hash_find(a1, (int)a2 + 440);
  if ( v9 )
    *(_QWORD *)&a3[8 * v8++] = v9;
LABEL_12:
  if ( *(_BYTE *)(a2 + 461) )
  {
    v10 = dp_peer_find_hash_find(a1, (int)a2 + 452);
    if ( v10 )
      *(_QWORD *)&a3[8 * v8++] = v10;
  }
  if ( *(_BYTE *)(a2 + 473) )
  {
    v11 = dp_peer_find_hash_find(a1, (int)a2 + 464);
    if ( v11 )
    {
      *(_QWORD *)&a3[8 * v8] = v11;
      LOBYTE(v8) = v8 + 1;
    }
  }
  result = qdf_spin_unlock_bh_7(a2 + 480);
  a3[32] = v8;
  return result;
}

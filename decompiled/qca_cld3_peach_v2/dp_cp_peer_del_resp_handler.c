__int64 __fastcall dp_cp_peer_del_resp_handler(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x24
  unsigned __int64 StatusReg; // x8
  unsigned __int16 *v9; // x0
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v12; // x21
  _DWORD *v13; // x25
  __int64 v14; // x8
  __int64 v15; // x0

  v3 = a1 + 0x4000;
  if ( (*(_BYTE *)(a1 + 17706) & 1) != 0 )
    return 4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17632);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17632);
    *(_QWORD *)(a1 + 17640) |= 1uLL;
  }
  v9 = (unsigned __int16 *)dp_peer_ast_hash_find_by_vdevid(a1, a3, a2);
  if ( v9 && *((_BYTE *)v9 + 28) == 1 && (__int16)v9[1] == -1 )
  {
    if ( *((_BYTE *)v9 + 14) == 1 )
      *(_QWORD *)(*(_QWORD *)(a1 + 17608) + 8LL * *v9) = 0;
    v11 = (__int64)v9;
    if ( a1 )
      ++*(_DWORD *)(a1 + 13372);
    dp_peer_ast_hash_remove(a1, v9);
    v13 = *(_DWORD **)(v11 + 32);
    v12 = *(_QWORD *)(v11 + 40);
    *(_QWORD *)(v11 + 32) = 0;
    *(_QWORD *)(v11 + 40) = 0;
    v14 = *(_QWORD *)(a1 + 17640);
    --*(_DWORD *)(v3 + 2324);
    if ( (v14 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17640) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17632);
      if ( v13 )
        goto LABEL_19;
    }
    else
    {
      raw_spin_unlock(a1 + 17632);
      if ( v13 )
      {
LABEL_19:
        v15 = *(_QWORD *)(a1 + 16);
        if ( *(v13 - 1) != 1048469180 )
          __break(0x8239u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v13)(v15, a1, v12, 0);
      }
    }
    _qdf_mem_free(v11);
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 17640);
  if ( (v10 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17640) = v10 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17632);
  }
  else
  {
    raw_spin_unlock(a1 + 17632);
  }
  return 16;
}

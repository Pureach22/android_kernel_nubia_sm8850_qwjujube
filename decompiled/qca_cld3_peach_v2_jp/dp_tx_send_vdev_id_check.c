char *__fastcall dp_tx_send_vdev_id_check(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  char *v3; // x19
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x10
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v13; // x24

  v3 = (char *)a3;
  if ( a2 <= 5u )
  {
    v5 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v5 )
    {
      if ( (**(_BYTE **)(a3 + 224) & 1) == 0 )
      {
        v6 = a1;
        v7 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v7 + 17576);
        }
        else
        {
          v13 = v7;
          raw_spin_lock_bh(v7 + 17576);
          *(_QWORD *)(v13 + 17584) |= 1uLL;
        }
        v9 = dp_peer_ast_hash_find_by_vdevid();
        v10 = *(_QWORD *)(*(_QWORD *)(v5 + 24) + 8LL);
        v11 = *(_QWORD *)(v10 + 17584);
        if ( (v11 & 1) != 0 )
        {
          *(_QWORD *)(v10 + 17584) = v11 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 17576);
          a1 = v6;
          if ( v9 )
            return dp_tx_send(a1, a2, v3);
        }
        else
        {
          raw_spin_unlock(v10 + 17576);
          a1 = v6;
          if ( v9 )
            return dp_tx_send(a1, a2, v3);
        }
        ++*(_DWORD *)(v5 + 764);
        return v3;
      }
      return dp_tx_send(a1, a2, v3);
    }
  }
  return v3;
}

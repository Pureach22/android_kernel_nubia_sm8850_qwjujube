__int64 __fastcall qdf_flex_mem_free(__int64 result, unsigned __int64 a2)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x21
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x8

  if ( result && a2 )
  {
    v3 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 24);
    }
    else
    {
      raw_spin_lock_bh(result + 24);
      *(_QWORD *)(v3 + 32) |= 1uLL;
    }
    v5 = v3;
    while ( 1 )
    {
      v5 = *(_QWORD *)v5;
      if ( v5 == v3 )
        break;
      v6 = *(_QWORD *)(v5 + 24);
      if ( v6 <= a2 )
      {
        v7 = *(unsigned __int16 *)(v3 + 42);
        if ( v6 + 32 * v7 >= a2 )
        {
          v8 = (1 << ((__int64)(a2 - v6) / v7)) ^ *(_DWORD *)(v5 + 20);
          *(_DWORD *)(v5 + 20) = v8;
          if ( !v8 && *(_BYTE *)(v5 + 16) == 1 && *(_DWORD *)(v3 + 16) > (unsigned int)*(unsigned __int16 *)(v3 + 40) )
          {
            qdf_list_remove_node(v3, (_QWORD *)v5);
            kfree(v5);
          }
          break;
        }
      }
    }
    v9 = *(_QWORD *)(v3 + 32);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 32) = v9 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 24);
    }
    else
    {
      return raw_spin_unlock(v3 + 24);
    }
  }
  return result;
}

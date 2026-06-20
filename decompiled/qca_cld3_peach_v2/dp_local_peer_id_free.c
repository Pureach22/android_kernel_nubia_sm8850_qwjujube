__int64 __fastcall dp_local_peer_id_free(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8

  v2 = *(unsigned __int16 *)(a2 + 122);
  if ( (unsigned int)v2 <= 0x22 )
  {
    v3 = result;
    v4 = result + 94208;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 94448);
    }
    else
    {
      raw_spin_lock_bh(result + 94448);
      *(_QWORD *)(v4 + 248) |= 1uLL;
    }
    *(_BYTE *)(v3 + v2 + 94408) = *(_BYTE *)(v4 + 236);
    v6 = *(_QWORD *)(v4 + 248);
    *(_BYTE *)(v4 + 236) = v2;
    *(_QWORD *)(v3 + 8 * v2 + 94464) = 0;
    if ( (v6 & 1) != 0 )
    {
      *(_QWORD *)(v4 + 248) = v6 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 94448);
    }
    else
    {
      return raw_spin_unlock(v3 + 94448);
    }
  }
  return result;
}

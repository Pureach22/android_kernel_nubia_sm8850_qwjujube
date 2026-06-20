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
    v4 = result + 90112;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 93552);
    }
    else
    {
      raw_spin_lock_bh(result + 93552);
      *(_QWORD *)(v4 + 3448) |= 1uLL;
    }
    *(_BYTE *)(v3 + v2 + 93512) = *(_BYTE *)(v4 + 3436);
    v6 = *(_QWORD *)(v4 + 3448);
    *(_BYTE *)(v4 + 3436) = v2;
    *(_QWORD *)(v3 + 8 * v2 + 93568) = 0;
    if ( (v6 & 1) != 0 )
    {
      *(_QWORD *)(v4 + 3448) = v6 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 93552);
    }
    else
    {
      return raw_spin_unlock(v3 + 93552);
    }
  }
  return result;
}

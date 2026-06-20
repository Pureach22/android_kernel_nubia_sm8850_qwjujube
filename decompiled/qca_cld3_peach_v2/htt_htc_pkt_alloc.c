__int64 __fastcall htt_htc_pkt_alloc(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 120);
    v3 = *(_QWORD *)(a1 + 72);
    if ( !v3 )
      goto LABEL_6;
    goto LABEL_5;
  }
  raw_spin_lock_bh(a1 + 120);
  *(_QWORD *)(a1 + 128) |= 1uLL;
  v3 = *(_QWORD *)(a1 + 72);
  if ( v3 )
LABEL_5:
    *(_QWORD *)(a1 + 72) = *(_QWORD *)v3;
LABEL_6:
  v4 = *(_QWORD *)(a1 + 128);
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 128) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 120);
    if ( v3 )
      goto LABEL_9;
  }
  else
  {
    raw_spin_unlock(a1 + 120);
    if ( v3 )
    {
LABEL_9:
      *(_DWORD *)(v3 + 120) = 0;
      return v3;
    }
  }
  v3 = _qdf_mem_malloc(0x80u, "htt_htc_pkt_alloc", 104);
  if ( v3 )
    goto LABEL_9;
  return v3;
}

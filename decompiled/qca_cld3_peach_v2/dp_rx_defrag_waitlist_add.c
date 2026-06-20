__int64 __fastcall dp_rx_defrag_waitlist_add(
        unsigned __int16 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x19
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x8
  __int64 *v15; // x9
  __int64 v16; // x8

  if ( (unsigned int)a2 >= 0x12 )
  {
    __break(0x5512u);
    return dp_rx_defrag_waitlist_remove(a1, a2);
  }
  v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 8LL);
  v13 = (__int64)&a1[60 * (unsigned int)a2 + 88];
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Adding TID %u to waitlist for peer %pK with peer_id = %d ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_rx_defrag_waitlist_add",
    (unsigned int)a2,
    a1,
    a1[4],
    v10,
    v11);
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v12 + 13184);
      *(_QWORD *)(v12 + 13192) |= 1uLL;
      if ( *(_QWORD *)(v12 + 13160) )
        goto LABEL_7;
      goto LABEL_6;
    }
  }
  raw_spin_lock(v12 + 13184);
  if ( !*(_QWORD *)(v12 + 13160) )
LABEL_6:
    *(_DWORD *)(v12 + 13180) = *(_DWORD *)(v13 + 104);
LABEL_7:
  *(_QWORD *)(v13 + 8) = 0;
  v15 = *(__int64 **)(v12 + 13168);
  *(_QWORD *)(v13 + 16) = v15;
  *v15 = v13;
  *(_QWORD *)(v12 + 13168) = v13 + 8;
  if ( v12 )
    ++*(_DWORD *)(v12 + 13664);
  v16 = *(_QWORD *)(v12 + 13192);
  if ( (v16 & 1) == 0 )
    return raw_spin_unlock(v12 + 13184);
  *(_QWORD *)(v12 + 13192) = v16 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v12 + 13184);
}

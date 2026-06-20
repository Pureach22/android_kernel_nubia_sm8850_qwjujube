__int64 __fastcall dp_peer_flush_frags(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x19
  __int64 v13; // x21
  __int64 v14; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v16; // x22
  __int64 v17; // x8

  result = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( result )
  {
    v12 = (__int64 *)result;
    if ( *(_QWORD *)result )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Flushing fragments for peer %02x:%02x:%02x:**:**:%02x",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "dp_peer_flush_frags",
        *(unsigned __int8 *)(result + 44),
        *(unsigned __int8 *)(result + 45),
        *(unsigned __int8 *)(result + 46),
        *(unsigned __int8 *)(result + 49));
      v13 = *v12;
      v14 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = v13 + 248;
      do
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v16);
        }
        else
        {
          raw_spin_lock_bh(v16);
          *(_QWORD *)(v16 + 8) |= 1uLL;
        }
        dp_rx_defrag_waitlist_remove(v13, (unsigned int)v14);
        dp_rx_reorder_flush_frag(v13, (unsigned int)v14);
        v17 = *(_QWORD *)(v16 + 8);
        if ( (v17 & 1) != 0 )
        {
          *(_QWORD *)(v16 + 8) = v17 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v16);
        }
        else
        {
          raw_spin_unlock(v16);
        }
        ++v14;
        v16 += 120;
      }
      while ( v14 != 17 );
    }
    return dp_peer_unref_delete((__int64)v12, 7u, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  return result;
}

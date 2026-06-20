__int64 __fastcall dp_fisa_rx_fst_inv_peer_id(unsigned __int16 a1)
{
  __int64 result; // x0
  __int64 v3; // x21
  _QWORD *v4; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2

  result = dp_get_context();
  if ( *(_BYTE *)(result + 218) == 1 )
  {
    v3 = *(_QWORD *)(result + 1480);
    if ( *(_BYTE *)(v3 + 609) == 1 )
    {
      result = _qdf_mem_malloc(0x60u, "dp_fisa_rx_fst_inv_peer_id", 206);
      if ( result )
      {
        v4 = (_QWORD *)result;
        *(_WORD *)(result + 72) = a1;
        *(_DWORD *)(result + 80) = 2;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v3 + 48);
        }
        else
        {
          raw_spin_lock_bh(v3 + 48);
          *(_QWORD *)(v3 + 56) |= 1uLL;
        }
        qdf_list_insert_back((_QWORD *)(v3 + 408), v4);
        v6 = *(_QWORD *)(v3 + 56);
        if ( (v6 & 1) != 0 )
        {
          *(_QWORD *)(v3 + 56) = v6 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v3 + 48);
          if ( *(_DWORD *)(v3 + 612) )
            goto LABEL_10;
        }
        else
        {
          raw_spin_unlock(v3 + 48);
          if ( *(_DWORD *)(v3 + 612) )
          {
LABEL_10:
            v15 = "%s: Defer DP_FT_INV_PEER_ID task in WoW for peer %hu";
            *(_BYTE *)(v3 + 616) = 1;
            return qdf_trace_msg(0x45u, 5u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "dp_fisa_rx_fst_inv_peer_id", a1);
          }
        }
        queue_work_on(32, *(_QWORD *)(v3 + 400), v3 + 352);
        v15 = "%s: Queued DP_FT_INV_PEER_ID task in work for peer %hu";
        return qdf_trace_msg(0x45u, 5u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "dp_fisa_rx_fst_inv_peer_id", a1);
      }
    }
  }
  return result;
}

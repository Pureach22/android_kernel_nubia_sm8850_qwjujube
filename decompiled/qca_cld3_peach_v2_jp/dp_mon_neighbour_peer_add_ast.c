__int64 __fastcall dp_mon_neighbour_peer_add_ast(__int64 result, int a2, void *a3, __int64 a4)
{
  __int64 v4; // x24
  unsigned __int64 StatusReg; // x8
  _QWORD *v7; // x23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8

  v4 = *(_QWORD *)(result + 95560);
  if ( *(_BYTE *)(v4 + 37218) == 1 )
  {
    qdf_mem_copy(a3, (const void *)(*(_QWORD *)(a4 + 224) + 6LL), 6u);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v4 + 37224);
    }
    else
    {
      raw_spin_lock_bh(v4 + 37224);
      *(_QWORD *)(v4 + 37232) |= 1uLL;
    }
    v7 = *(_QWORD **)(v4 + 37240);
    if ( v7 )
    {
      while ( (unsigned int)qdf_mem_cmp(v7, a3, 6u) )
      {
        v7 = (_QWORD *)v7[4];
        if ( !v7 )
          goto LABEL_11;
      }
      dp_peer_add_ast();
      qdf_trace_msg(0x45u, 4u, "sa valid and nac roamed to wds", v8, v9, v10, v11, v12, v13, v14, v15);
    }
LABEL_11:
    v16 = *(_QWORD *)(v4 + 37232);
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(v4 + 37232) = v16 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v4 + 37224);
    }
    else
    {
      return raw_spin_unlock(v4 + 37224);
    }
  }
  return result;
}

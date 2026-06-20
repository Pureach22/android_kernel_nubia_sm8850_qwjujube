_QWORD *__fastcall dp_rx_desc_nbuf_free(__int64 a1, int *a2, char a3)
{
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  unsigned int v16; // w9
  _QWORD *v17; // x23
  _QWORD *v18; // x22
  unsigned int v19; // w10
  __int64 v20; // x11
  _QWORD *v21; // x13
  __int64 v22; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 14);
    if ( *((_QWORD *)a2 + 3) )
      goto LABEL_5;
LABEL_13:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: No pages found on this desc pool",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_rx_desc_nbuf_collect");
    goto LABEL_14;
  }
  raw_spin_lock_bh(a2 + 14);
  *((_QWORD *)a2 + 8) |= 1uLL;
  if ( !*((_QWORD *)a2 + 3) )
    goto LABEL_13;
LABEL_5:
  v15 = *a2;
  if ( !*a2 )
  {
LABEL_14:
    v17 = nullptr;
    v18 = nullptr;
    goto LABEL_15;
  }
  v16 = *((unsigned __int16 *)a2 + 4);
  v17 = nullptr;
  v18 = nullptr;
  v19 = 0;
  do
  {
    v20 = *(_QWORD *)(*((_QWORD *)a2 + 3) + 8LL * (unsigned __int16)(v19 / v16))
        + (int)(v19 % v16 * *((unsigned __int16 *)a2 + 2));
    if ( (*(_BYTE *)(v20 + 30) & 1) != 0 )
    {
      v21 = *(_QWORD **)v20;
      if ( (*(_BYTE *)(v20 + 30) & 2) != 0 )
      {
        *v21 = v18;
        v18 = *(_QWORD **)v20;
      }
      else
      {
        *v21 = v17;
        v17 = *(_QWORD **)v20;
        *(_BYTE *)(v20 + 30) |= 2u;
      }
    }
    ++v19;
  }
  while ( v15 != v19 );
LABEL_15:
  v22 = *((_QWORD *)a2 + 8);
  if ( (v22 & 1) != 0 )
  {
    *((_QWORD *)a2 + 8) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 14);
  }
  else
  {
    raw_spin_unlock(a2 + 14);
  }
  return dp_rx_desc_nbuf_cleanup(a1, v17, v18, *((_WORD *)a2 + 37), a3 & 1);
}

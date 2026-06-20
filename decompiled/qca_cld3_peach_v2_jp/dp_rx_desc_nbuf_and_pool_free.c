__int64 __fastcall dp_rx_desc_nbuf_and_pool_free(__int64 a1, __int64 a2, int *a3)
{
  unsigned __int64 StatusReg; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  unsigned int v15; // w9
  _QWORD *v16; // x22
  _QWORD *v17; // x21
  unsigned int v18; // w10
  __int64 v19; // x11
  _QWORD *v20; // x13
  __int64 v21; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a3 + 14);
    if ( *((_QWORD *)a3 + 3) )
      goto LABEL_5;
LABEL_13:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: No pages found on this desc pool",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_rx_desc_nbuf_collect");
    goto LABEL_14;
  }
  raw_spin_lock_bh(a3 + 14);
  *((_QWORD *)a3 + 8) |= 1uLL;
  if ( !*((_QWORD *)a3 + 3) )
    goto LABEL_13;
LABEL_5:
  v14 = *a3;
  if ( !*a3 )
  {
LABEL_14:
    v16 = nullptr;
    v17 = nullptr;
    goto LABEL_15;
  }
  v15 = *((unsigned __int16 *)a3 + 4);
  v16 = nullptr;
  v17 = nullptr;
  v18 = 0;
  do
  {
    v19 = *(_QWORD *)(*((_QWORD *)a3 + 3) + 8LL * (unsigned __int16)(v18 / v15))
        + (int)(v18 % v15 * *((unsigned __int16 *)a3 + 2));
    if ( (*(_BYTE *)(v19 + 30) & 1) != 0 )
    {
      v20 = *(_QWORD **)v19;
      if ( (*(_BYTE *)(v19 + 30) & 2) != 0 )
      {
        *v20 = v17;
        v17 = *(_QWORD **)v19;
      }
      else
      {
        *v20 = v16;
        v16 = *(_QWORD **)v19;
        *(_BYTE *)(v19 + 30) |= 2u;
      }
    }
    ++v18;
  }
  while ( v14 != v18 );
LABEL_15:
  v21 = *((_QWORD *)a3 + 8);
  if ( (v21 & 1) != 0 )
  {
    *((_QWORD *)a3 + 8) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a3 + 14);
  }
  else
  {
    raw_spin_unlock(a3 + 14);
  }
  return dp_rx_desc_nbuf_cleanup(a1, v16, v17, *((unsigned __int16 *)a3 + 37), 0);
}

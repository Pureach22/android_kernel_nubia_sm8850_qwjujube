_QWORD *__fastcall htt_soc_htc_dealloc(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x21
  __int64 v4; // x25
  __int64 v5; // x23
  __int64 v6; // x4
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *result; // x0
  _QWORD *v25; // x20

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 120);
    v3 = *(_QWORD *)(a1 + 80);
    if ( v3 )
      goto LABEL_7;
  }
  else
  {
    raw_spin_lock_bh(a1 + 120);
    *(_QWORD *)(a1 + 128) |= 1uLL;
    v3 = *(_QWORD *)(a1 + 80);
    if ( v3 )
    {
      do
      {
LABEL_7:
        while ( 1 )
        {
          v4 = *(_QWORD *)v3;
          if ( *(_DWORD *)(v3 + 120) == -559038737 )
            break;
          ++*(_DWORD *)(a1 + 100);
          v3 = v4;
          if ( !v4 )
            goto LABEL_11;
        }
        v5 = *(_QWORD *)(v3 + 112);
        _qdf_nbuf_unmap(*(_QWORD *)(a1 + 56), v5, 1);
        v6 = *(_QWORD *)(a1 + 8);
        ++*(_DWORD *)(a1 + 96);
        qdf_trace_msg(
          0x80u,
          5u,
          "%s: %pK: Pkt free count %d",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "htt_htc_misc_pkt_pool_free",
          v6);
        if ( v5 )
          _qdf_nbuf_free(v5);
        _qdf_mem_free(v3);
        v3 = v4;
      }
      while ( v4 );
    }
  }
LABEL_11:
  v15 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a1 + 80) = 0;
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 128) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 120);
  }
  else
  {
    raw_spin_unlock(a1 + 120);
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: HTC Packets, fail count = %d, skip count = %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "htt_htc_misc_pkt_pool_free",
    *(unsigned int *)(a1 + 104),
    *(unsigned int *)(a1 + 100));
  result = *(_QWORD **)(a1 + 72);
  if ( result )
  {
    do
    {
      v25 = (_QWORD *)*result;
      _qdf_mem_free((__int64)result);
      result = v25;
    }
    while ( v25 );
  }
  *(_QWORD *)(a1 + 72) = 0;
  return result;
}

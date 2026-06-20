__int64 __fastcall bam_tx_status(__int64 a1, signed int a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v7; // x0
  int v8; // w8
  int v9; // w9
  __int64 result; // x0
  __int64 v11; // x22
  __int64 desc; // x0
  __int64 v13; // x23
  _QWORD *v14; // x8
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x13
  unsigned __int16 *v19; // x14
  __int64 v20; // x15
  __int64 v21; // x16
  unsigned int v22; // t1
  __int64 v23; // x10
  unsigned __int16 *v24; // x11
  unsigned int v25; // t1

  v3 = *(_QWORD *)(a1 + 256);
  v7 = *(_QWORD *)(v3 + 536);
  if ( v7 )
  {
    ipc_log_string(v7, "%s chan id:%d\n", "bam_tx_status", *(_DWORD *)(a1 + 264));
    v3 = *(_QWORD *)(a1 + 256);
  }
  _ftrace_dbg(*(_QWORD *)(v3 + 8), "%s chan id:%d\n");
  v9 = *(_DWORD *)(a1 + 16);
  v8 = *(_DWORD *)(a1 + 20);
  if ( a3 )
  {
    *(_DWORD *)a3 = v8;
    *(_DWORD *)(a3 + 4) = v9;
    *(_QWORD *)(a3 + 8) = 0;
  }
  if ( v8 > v9 )
  {
    if ( v9 < a2 && v8 >= a2 )
      return 0;
    goto LABEL_11;
  }
  result = 0;
  if ( v9 >= a2 && v8 < a2 )
  {
LABEL_11:
    if ( !a3 )
      goto LABEL_15;
    v11 = raw_spin_lock_irqsave(a1 + 160);
    desc = vchan_find_desc(a1, (unsigned int)a2);
    if ( desc )
    {
      v13 = *(_QWORD *)(desc + 216);
LABEL_14:
      raw_spin_unlock_irqrestore(a1 + 160, v11);
      *(_DWORD *)(a3 + 8) = v13;
LABEL_15:
      if ( *(_DWORD *)(a1 + 368) )
        return 2;
      else
        return 1;
    }
    v14 = *(_QWORD **)(a1 + 376);
    if ( v14 == (_QWORD *)(a1 + 376) )
    {
      LODWORD(v13) = 0;
      goto LABEL_14;
    }
    v13 = 0;
    while ( 1 )
    {
      if ( *((_DWORD *)v14 - 48) != a2 )
        goto LABEL_21;
      v15 = *((unsigned int *)v14 - 6);
      if ( !(_DWORD)v15 )
        goto LABEL_21;
      v16 = *(v14 - 1);
      if ( (_DWORD)v15 == 1 )
      {
        v17 = 0;
      }
      else
      {
        v17 = (unsigned int)v15 & 0xFFFFFFFE;
        v18 = 0;
        v19 = (unsigned __int16 *)(v16 + 12);
        v20 = v17;
        do
        {
          v21 = *(v19 - 4);
          v22 = *v19;
          v19 += 8;
          v20 -= 2;
          v13 += v21;
          v18 += v22;
        }
        while ( v20 );
        v13 += v18;
        if ( v17 == v15 )
          goto LABEL_21;
      }
      v23 = v15 - v17;
      v24 = (unsigned __int16 *)(v16 + 8 * v17 + 4);
      do
      {
        v25 = *v24;
        v24 += 4;
        --v23;
        v13 += v25;
      }
      while ( v23 );
LABEL_21:
      v14 = (_QWORD *)*v14;
      if ( v14 == (_QWORD *)(a1 + 376) )
        goto LABEL_14;
    }
  }
  return result;
}

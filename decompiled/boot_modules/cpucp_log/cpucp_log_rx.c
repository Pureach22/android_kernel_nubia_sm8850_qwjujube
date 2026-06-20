__int64 __fastcall cpucp_log_rx(__int64 a1, __int64 *a2)
{
  int ***v3; // x19
  int **v4; // x21
  __int64 v5; // x9
  int ***v6; // x20
  int ****v7; // x8
  int **v8; // x10
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x9
  unsigned __int64 v12; // x10
  int v13; // w8
  int v14; // w11
  _DWORD **v15; // x10
  int v16; // w12
  _DWORD **v17; // x8
  unsigned int v18; // w2
  __int64 v19; // x10
  unsigned int v20; // w9
  _DWORD *v21; // x1
  unsigned int v22; // w21
  __int64 v23; // x0
  int ***v24; // x2
  int **v25; // x1
  __int64 v26; // x9
  int ***v27; // x19
  int **v28; // t1

  v3 = *(int ****)(*(_QWORD *)a1 + 152LL);
  v4 = v3[23];
  v5 = raw_spin_lock_irqsave(v3 + 35);
  v6 = (int ***)v3[31];
  if ( v6 == v3 + 31 )
  {
    raw_spin_unlock_irqrestore(v3 + 35, v5);
    return dev_err(v4, "global buffer full dropping buffers\n");
  }
  v7 = (int ****)v6[1];
  if ( *v7 == v6 && (v8 = *v6, (*v6)[1] == (int *)v6) )
  {
    v8[1] = (int *)v7;
    *v7 = (int ***)v8;
  }
  else
  {
    _list_del_entry_valid_or_report(v3[31]);
  }
  *v6 = (int **)0xDEAD000000000100LL;
  v6[1] = (int **)0xDEAD000000000122LL;
  result = raw_spin_unlock_irqrestore(v3 + 35, v5);
  if ( !v6 )
    return dev_err(v4, "global buffer full dropping buffers\n");
  v10 = *((_DWORD *)v3 + 48);
  if ( (unsigned int)(v10 - 1) >= 2 )
  {
    if ( v10 )
      return result;
    v17 = *v3;
    v18 = ***v3;
    if ( v18 <= *((_DWORD *)*v3 + 2) )
    {
      v19 = 0;
      *((_DWORD *)v3 + 52) = 0;
      v20 = 1;
    }
    else
    {
      if ( v18 > *((_DWORD *)v3 + 54) )
        return printk(&unk_84EF);
      v19 = 1;
      v20 = 0;
      *((_DWORD *)v3 + 52) = 1;
      v18 -= *((_DWORD *)v17 + 2);
    }
    v22 = v18 - v20 * 4;
    v21 = &v17[2 * v19][v20];
  }
  else
  {
    if ( !a2 )
      return dev_err(v4, "pdp_log error: mbox data is NULL\n");
    v11 = *a2;
    v12 = HIDWORD(*a2);
    *a2 = v12;
    v13 = *((_DWORD *)v3 + 53);
    if ( !v13 )
      return dev_err(v4, "pdp_log error: couldn't match buf_start addr\n");
    v14 = (_DWORD)v12 << 8;
    v15 = *v3;
    v16 = 0;
    while ( HIDWORD(v15[2 * v16 + 1]) != v14 )
    {
      if ( v13 == ++v16 )
        return dev_err(v4, "pdp_log error: couldn't match buf_start addr\n");
    }
    v21 = v15[2 * v16];
    if ( (HIWORD(v11) & 0xFF00u) + 256 >= *((_DWORD *)v15 + 2) )
      v22 = *((_DWORD *)v15 + 2);
    else
      v22 = (HIWORD(v11) & 0xFF00) + 256;
  }
  _memcpy_fromio((char *)v6[2] + *((unsigned int *)v6 + 7), v21, v22);
  *((_DWORD *)v6 + 6) = v22;
  v23 = raw_spin_lock_irqsave((char *)v3 + 284);
  v24 = v3 + 33;
  v25 = v3[34];
  v26 = v23;
  if ( v6 == v3 + 33 || v25 == (int **)v6 || *v25 != (int *)v24 )
  {
    _list_add_valid_or_report(v6, v25, v24);
  }
  else
  {
    v3[34] = (int **)v6;
    *v6 = (int **)v24;
    v6[1] = v25;
    *v25 = (int *)v6;
  }
  result = raw_spin_unlock_irqrestore((char *)v3 + 284, v26);
  v28 = v3[10];
  v27 = v3 + 10;
  if ( ((unsigned __int8)v28 & 1) == 0 )
    return queue_delayed_work_on(32, cpucp_wq, v27, 0);
  return result;
}

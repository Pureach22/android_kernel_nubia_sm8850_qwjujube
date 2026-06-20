__int64 __fastcall synx_util_insert_fence_entry(unsigned __int64 a1, _DWORD *a2, int a3)
{
  __int64 result; // x0
  _QWORD *v6; // x21
  __int64 v8; // x10
  unsigned __int64 v9; // x11
  __int64 v10; // x9
  int *v11; // x12
  bool v12; // zf
  _QWORD *v13; // x8
  _QWORD *v14; // x10
  unsigned int v15; // w20
  __int64 v16; // x12
  int v17; // w8

  result = 4294967274LL;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v6 = (_QWORD *)a1;
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
    v8 = v6[1];
    v9 = *(_QWORD *)(synx_dev + 152) + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * v8) >> 54);
    v10 = *(_QWORD *)(v9 + 2064);
    v11 = (int *)(v10 - 16);
    if ( v10 )
      v12 = v10 == 16;
    else
      v12 = 1;
    if ( v12 )
    {
LABEL_10:
      v13 = (_QWORD *)(v9 + 2064);
      v6[2] = v10;
      v14 = v6 + 2;
      if ( v10 )
        *(_QWORD *)(v10 + 8) = v14;
      *v13 = v14;
      v6[3] = v13;
      if ( (synx_debug & 0x80) != 0 )
        printk(&unk_2A16D, &unk_25D36, "synx_util_insert_fence_entry", 1592, v6, v6[1]);
      v15 = 0;
    }
    else
    {
      while ( *((_QWORD *)v11 + 1) != v8 )
      {
        v16 = *((_QWORD *)v11 + 2);
        if ( v16 )
        {
          v11 = (int *)(v16 - 16);
          if ( v11 )
            continue;
        }
        goto LABEL_10;
      }
      if ( a3 && (v17 = *v11, *a2 = *v11, v17) )
      {
        v15 = -114;
      }
      else
      {
        *a2 = v11[1];
        v15 = -114;
      }
    }
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
    return v15;
  }
  return result;
}

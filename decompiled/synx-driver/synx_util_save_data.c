__int64 __fastcall synx_util_save_data(unsigned int *a1, char a2, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w19
  __int64 v7; // x21
  unsigned __int64 v9; // x22
  __int64 v10; // x9
  _QWORD *v11; // x8
  bool v12; // zf
  __int64 v13; // x0
  __int64 v14; // x10
  __int64 v15; // x9
  __int64 *v16; // x10
  __int64 v17; // x8
  __int64 v18; // x8

  if ( (a2 & 8) != 0 )
  {
    v7 = *a1;
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
    v9 = (unsigned __int64)(0x61C8864680B583EBLL * v7) >> 56;
    v10 = *(_QWORD *)(*(_QWORD *)(synx_dev + 152) + 8 * v9 + 20520);
    v11 = (_QWORD *)(v10 - 24);
    if ( v10 )
      v12 = v10 == 24;
    else
      v12 = 1;
    if ( v12 )
    {
LABEL_10:
      v13 = _kmalloc_cache_noprof(raw_spin_lock_bh, 2336, 40);
      if ( v13 )
      {
        *(_DWORD *)(v13 + 8) = a3;
        *(_QWORD *)v13 = v7;
        *(_DWORD *)(v13 + 16) = 1;
        v14 = *(_QWORD *)(synx_dev + 152) + 8 * v9;
        v15 = *(_QWORD *)(v14 + 20520);
        v16 = (__int64 *)(v14 + 20520);
        *(_QWORD *)(v13 + 24) = v15;
        v17 = v13 + 24;
        if ( v15 )
          *(_QWORD *)(v15 + 8) = v17;
        *v16 = v17;
        *(_QWORD *)(v13 + 32) = v16;
        if ( (synx_debug & 0x80) != 0 )
          printk(&unk_2655E, &unk_25D36, "synx_util_save_data", 1743, *(_QWORD *)v13, v13);
        v6 = 0;
      }
      else
      {
        v6 = -12;
      }
    }
    else
    {
      while ( *v11 != v7 )
      {
        v18 = v11[3];
        if ( v18 )
        {
          v11 = (_QWORD *)(v18 - 24);
          if ( v11 )
            continue;
        }
        goto LABEL_10;
      }
      v6 = -114;
    }
    raw_spin_unlock_bh(*(_QWORD *)(synx_dev + 152) + 20512LL);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28371, &unk_29207, "synx_util_save_data", 1751, a5, a6);
    kfree(0);
    return (unsigned int)-22;
  }
  return v6;
}

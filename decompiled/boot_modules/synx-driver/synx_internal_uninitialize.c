__int64 __fastcall synx_internal_uninitialize(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x11
  __int64 v10; // x9
  bool v11; // zf
  __int64 v12; // x5
  __int64 v13; // x0
  unsigned int v14; // w19
  __int64 v15; // x9
  __int64 v16; // x20

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152));
    v7 = synx_dev;
    v8 = *(_QWORD *)(synx_dev + 152);
    v9 = *(_QWORD *)(v8 + 8 * ((0x61C8864680B583EBLL * a1) >> 56) + 8);
    v10 = v9 - 264960;
    if ( v9 )
      v11 = v9 == 264960;
    else
      v11 = 1;
    if ( v11 )
    {
LABEL_8:
      raw_spin_unlock_bh(v8);
      if ( (synx_debug & 1) != 0 )
      {
        v14 = -22;
        printk(&unk_27962, &unk_29207, "synx_internal_uninitialize", 3789, 4294967274LL, v12);
        v13 = 0;
      }
      else
      {
        v13 = 0;
        v14 = -22;
      }
    }
    else
    {
      while ( v10 != a1 )
      {
        v15 = *(_QWORD *)(v10 + 264960);
        if ( v15 )
        {
          v10 = v15 - 264960;
          if ( v10 )
            continue;
        }
        goto LABEL_8;
      }
      if ( *(_BYTE *)(v10 + 24) == 1 )
      {
        v14 = 0;
        v16 = v10;
        *(_BYTE *)(v10 + 24) = 0;
      }
      else if ( (synx_debug & 1) != 0 )
      {
        v14 = -114;
        printk(&unk_2A934, &unk_29207, "synx_internal_uninitialize", 3782, *(_QWORD *)(v10 + 104), 4294967182LL);
        v7 = synx_dev;
        v16 = 0;
      }
      else
      {
        v16 = 0;
        v14 = -114;
      }
      raw_spin_unlock_bh(*(_QWORD *)(v7 + 152));
      v13 = v16;
    }
    synx_put_client(v13);
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28B09, &unk_29207, "synx_internal_uninitialize", 3768, a5, a6);
    return (unsigned int)-22;
  }
  return v14;
}

__int64 __fastcall qcedev_unmap_all_buffers(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *v5; // x24
  __int64 v7; // x2
  __int64 v8; // x3
  _QWORD *v9; // x20
  _QWORD **v10; // x25
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x2
  __int64 v14; // x3
  void *v15; // x0

  if ( !a1 )
  {
    v15 = &unk_1258B;
    goto LABEL_21;
  }
  if ( !*a1 || (v5 = *(_DWORD **)(*a1 + 336LL)) == nullptr )
  {
    v15 = &unk_11B6A;
LABEL_21:
    printk(v15, "qcedev_unmap_all_buffers", a3, a4);
    return 4294967274LL;
  }
  if ( *v5 )
    return 0xFFFFFFFFLL;
  mutex_lock(a1 + 27);
  v10 = (_QWORD **)(a1 + 25);
  v9 = (_QWORD *)a1[25];
  if ( v9 != a1 + 25 )
  {
    do
    {
      if ( v9 )
      {
        if ( *v5 )
        {
          printk(&unk_1233D, "qcedev_unmap_buffer", v7, v8);
          printk(&unk_1263A, "qcedev_unmap_buffer", v13, v14);
        }
        else if ( *(_QWORD *)(*a1 + 320LL) != *a1 + 320LL )
        {
          dma_buf_unmap_attachment_unlocked(v9[5], v9[4], 0);
          dma_buf_detach(v9[6], v9[5]);
          dma_buf_put(v9[6]);
        }
      }
      v11 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v11 == v9 && (v12 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = 0xDEAD000000000100LL;
      v9[1] = 0xDEAD000000000122LL;
      kfree(v9);
      v9 = *v10;
    }
    while ( *v10 != v10 );
  }
  mutex_unlock(a1 + 27);
  return 0;
}

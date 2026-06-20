__int64 __fastcall qcedev_check_and_unmap_buffer(__int64 *a1, unsigned int a2, __int64 a3, __int64 a4)
{
  _DWORD *v5; // x21
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w8
  __int64 *v11; // x20
  __int64 **v12; // x8
  __int64 *v13; // x9
  void *v14; // x0
  __int64 *v15; // x0
  unsigned int v16; // w19
  __int64 v17; // x3
  __int64 v18; // x2
  __int64 v19; // x3
  unsigned int v26; // w10

  if ( !a1 || (a2 & 0x80000000) != 0 )
  {
    v14 = &unk_1258B;
LABEL_21:
    printk(v14, "qcedev_check_and_unmap_buffer", a3, a4);
    return 4294967274LL;
  }
  if ( !*a1 || (v5 = *(_DWORD **)(*a1 + 336)) == nullptr )
  {
    v14 = &unk_11B6A;
    goto LABEL_21;
  }
  if ( *v5 )
    return 0xFFFFFFFFLL;
  mutex_lock(a1 + 27);
  v10 = a2;
  v11 = a1 + 25;
  do
  {
    v11 = (__int64 *)*v11;
    if ( v11 == a1 + 25 )
    {
      v15 = a1 + 27;
      v16 = v10;
      mutex_unlock(v15);
      printk(&unk_11F6A, "qcedev_check_and_unmap_buffer", v16, v17);
      return 4294967274LL;
    }
  }
  while ( *((_DWORD *)v11 + 18) != v10 );
  _X8 = (unsigned int *)(v11 + 10);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 - 1, _X8) );
  if ( !*((_DWORD *)v11 + 20) )
  {
    if ( *v5 )
    {
      printk(&unk_1233D, "qcedev_unmap_buffer", v8, v9);
      printk(&unk_1263A, "qcedev_unmap_buffer", v18, v19);
    }
    else if ( *(_QWORD *)(*a1 + 320) != *a1 + 320 )
    {
      dma_buf_unmap_attachment_unlocked(v11[5], v11[4], 0);
      dma_buf_detach(v11[6], v11[5]);
      dma_buf_put(v11[6]);
    }
    v12 = (__int64 **)v11[1];
    if ( *v12 == v11 && (v13 = (__int64 *)*v11, *(__int64 **)(*v11 + 8) == v11) )
    {
      v13[1] = (__int64)v12;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    *v11 = 0xDEAD000000000100LL;
    v11[1] = 0xDEAD000000000122LL;
    kfree(v11);
  }
  mutex_unlock(a1 + 27);
  return 0;
}

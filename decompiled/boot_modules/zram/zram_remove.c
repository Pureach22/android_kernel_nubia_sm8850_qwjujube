__int64 __fastcall zram_remove(__int64 a1)
{
  __int64 v2; // x8
  int v4; // w20

  mutex_lock(*(_QWORD *)(a1 + 24) + 360LL);
  v2 = *(_QWORD *)(a1 + 24);
  if ( *(_DWORD *)(*(_QWORD *)(v2 + 64) + 64LL) )
  {
    mutex_unlock(v2 + 360);
    return 4294967280LL;
  }
  else
  {
    v4 = *(unsigned __int8 *)(a1 + 233);
    if ( (v4 & 1) != 0 )
    {
      mutex_unlock(v2 + 360);
    }
    else
    {
      *(_BYTE *)(a1 + 233) = 1;
      mutex_unlock(v2 + 360);
      sync_blockdev(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 64LL));
      zram_reset_device(a1);
    }
    printk(&unk_B476);
    del_gendisk(*(_QWORD *)(a1 + 24));
    if ( v4 )
    {
      if ( *(_BYTE *)(a1 + 233) == 1 )
        __break(0x800u);
    }
    zram_reset_device(a1);
    put_disk(*(_QWORD *)(a1 + 24));
    kfree(a1);
    return 0;
  }
}

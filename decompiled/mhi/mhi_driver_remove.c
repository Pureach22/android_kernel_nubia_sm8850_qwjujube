__int64 __fastcall mhi_driver_remove(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x24
  __int64 v4; // x21
  __int64 v5; // x20
  int v6; // w25
  __int64 v7; // x22
  int v8; // w23
  void (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x22
  __int64 v11; // x24
  int v12; // w8
  __int64 v13; // x22
  __int64 v14; // x23
  int v15; // w8

  if ( *(_DWORD *)(a1 + 912) == 1 )
    return 0;
  v1 = *(_QWORD *)(a1 - 8);
  v2 = *(_QWORD *)(a1 + 136);
  v4 = *(_QWORD *)(a1 - 24);
  v5 = a1 - 40;
  if ( v1 )
  {
    raw_write_lock_irq(v1 + 368);
    *(_DWORD *)(v1 + 264) = 0;
    complete_all(v1 + 336);
    raw_write_unlock_irq(v1 + 368);
    mutex_lock(v1 + 288);
    raw_write_lock_irq(v1 + 368);
    v6 = *(_DWORD *)(v1 + 260);
    *(_DWORD *)(v1 + 260) = 3;
    raw_write_unlock_irq(v1 + 368);
    if ( (*(_BYTE *)(v1 + 394) & 1) == 0 )
      mhi_reset_chan(v4, v1);
    mutex_unlock(v1 + 288);
    v7 = *(_QWORD *)(a1 - 16);
    if ( v7 )
      goto LABEL_6;
  }
  else
  {
    v6 = 0;
    v7 = *(_QWORD *)(a1 - 16);
    if ( v7 )
    {
LABEL_6:
      raw_write_lock_irq(v7 + 368);
      *(_DWORD *)(v7 + 264) = 0;
      complete_all(v7 + 336);
      raw_write_unlock_irq(v7 + 368);
      mutex_lock(v7 + 288);
      raw_write_lock_irq(v7 + 368);
      v8 = *(_DWORD *)(v7 + 260);
      *(_DWORD *)(v7 + 260) = 3;
      raw_write_unlock_irq(v7 + 368);
      if ( (*(_BYTE *)(v7 + 394) & 1) == 0 )
        mhi_reset_chan(v4, v7);
      mutex_unlock(v7 + 288);
      goto LABEL_11;
    }
  }
  v8 = 0;
LABEL_11:
  v9 = *(void (__fastcall **)(_QWORD))(v2 - 32);
  if ( *((_DWORD *)v9 - 1) != 809849700 )
    __break(0x8228u);
  v9(v5);
  v10 = *(_QWORD *)(a1 - 8);
  if ( v10 )
  {
    mutex_lock(v10 + 288);
    if ( (v6 == 4 || v6 == 1) && (*(_BYTE *)(v10 + 394) & 1) == 0 )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(v4 + 264) + 8LL) + 44LL * *(unsigned int *)(v10 + 200);
      if ( *(_QWORD *)(v11 + 12) )
      {
        dma_free_attrs(*(_QWORD *)(v4 + 8), *(_QWORD *)(v10 + 184), *(_QWORD *)(v10 + 128), *(_QWORD *)(v10 + 104), 0);
        vfree(*(_QWORD *)(v10 + 40));
        *(_QWORD *)(v10 + 136) = 0;
        *(_QWORD *)(v10 + 40) = 0;
        *(_QWORD *)(v10 + 120) = 0;
        v12 = *(_DWORD *)v11;
        *(_QWORD *)(v11 + 28) = 0;
        *(_QWORD *)(v11 + 36) = 0;
        *(_QWORD *)(v11 + 12) = 0;
        *(_QWORD *)(v11 + 20) = 0;
        *(_DWORD *)v11 = v12 & 0xFFFFFF00;
        __dmb(0xAu);
      }
    }
    *(_DWORD *)(v10 + 260) = 0;
    mutex_unlock(v10 + 288);
  }
  v13 = *(_QWORD *)(a1 - 16);
  if ( v13 )
  {
    mutex_lock(v13 + 288);
    if ( (v8 == 4 || v8 == 1) && (*(_BYTE *)(v13 + 394) & 1) == 0 )
    {
      v14 = *(_QWORD *)(*(_QWORD *)(v4 + 264) + 8LL) + 44LL * *(unsigned int *)(v13 + 200);
      if ( *(_QWORD *)(v14 + 12) )
      {
        dma_free_attrs(*(_QWORD *)(v4 + 8), *(_QWORD *)(v13 + 184), *(_QWORD *)(v13 + 128), *(_QWORD *)(v13 + 104), 0);
        vfree(*(_QWORD *)(v13 + 40));
        *(_QWORD *)(v13 + 136) = 0;
        *(_QWORD *)(v13 + 40) = 0;
        *(_QWORD *)(v13 + 120) = 0;
        v15 = *(_DWORD *)v14;
        *(_QWORD *)(v14 + 28) = 0;
        *(_QWORD *)(v14 + 36) = 0;
        *(_QWORD *)(v14 + 12) = 0;
        *(_QWORD *)(v14 + 20) = 0;
        *(_DWORD *)v14 = v15 & 0xFFFFFF00;
        __dmb(0xAu);
      }
    }
    *(_DWORD *)(v13 + 260) = 0;
    mutex_unlock(v13 + 288);
  }
  while ( *(_DWORD *)(a1 + 932) )
    mhi_device_put(v5);
  return 0;
}

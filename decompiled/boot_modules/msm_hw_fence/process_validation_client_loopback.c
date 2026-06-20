__int64 __fastcall process_validation_client_loopback(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  unsigned int v3; // w8
  __int64 v4; // x21
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x22
  __int64 v11; // x5

  v3 = *(_DWORD *)(a1 + 740);
  v4 = v2;
  if ( v3 > a2 || v3 + 11 < a2 )
  {
    printk(&unk_264FC, "process_validation_client_loopback", 1322, v2, a2, v3 > a2);
    return 4294967274LL;
  }
  else
  {
    mutex_lock(a1 + 680);
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 728) + 8LL * (int)a2);
    if ( v9 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
        printk(&unk_25957, "process_validation_client_loopback", 1336, a2, v7, v8);
      *(_DWORD *)(v9 + 224) = 1;
      _wake_up(v9 + 200, 3, 0, 0);
      mutex_unlock(a1 + 680);
      return 0;
    }
    else
    {
      mutex_unlock(a1 + 680);
      printk(&unk_295BC, "process_validation_client_loopback", 1330, v4, a2, v11);
      return 4294967274LL;
    }
  }
}

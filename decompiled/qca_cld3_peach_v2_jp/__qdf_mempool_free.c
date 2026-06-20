void __fastcall _qdf_mempool_free(__int64 a1, __int64 a2, _QWORD *a3)
{
  int v4; // w0
  unsigned int v12; // w9

  if ( a2 )
  {
    if ( prealloc_disabled == 1 )
    {
      if ( a3 && ((unsigned __int64)ksize(a3) <= 0x2000 || !(unsigned int)wcnss_prealloc_put(a3)) )
      {
        v4 = ksize(a3);
        _X8 = &qdf_mem_stat;
        __asm { PRFM            #0x11, [X8] }
        do
          v12 = __ldxr((unsigned int *)&qdf_mem_stat);
        while ( __stxr(v12 - v4, (unsigned int *)&qdf_mem_stat) );
        kfree(a3);
      }
    }
    else
    {
      raw_spin_lock_bh(a2 + 48);
      ++*(_DWORD *)(a2 + 56);
      *a3 = 0;
      **(_QWORD **)(a2 + 40) = a3;
      *(_QWORD *)(a2 + 40) = a3;
      raw_spin_unlock_bh(a2 + 48);
    }
  }
}

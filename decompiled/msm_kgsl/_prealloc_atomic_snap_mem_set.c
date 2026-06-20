__int64 __fastcall prealloc_atomic_snap_mem_set(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v6; // x0

  rt_mutex_lock(a1 + 11088);
  if ( !a2 )
    goto LABEL_4;
  if ( *(_QWORD *)(a1 + 11272) )
    goto LABEL_4;
  *(_DWORD *)(a1 + 11288) = *(_DWORD *)(a1 + 11232);
  __dmb(0xAu);
  v4 = dma_alloc_attrs(*(_QWORD *)(a1 + 11168) + 16LL, *(unsigned int *)(a1 + 11288), a1 + 11280, 3264, 0);
  *(_QWORD *)(a1 + 11272) = v4;
  if ( v4
    || (__break(0x800u),
        *(_DWORD *)(a1 + 11288) = 3145728,
        __dmb(0xAu),
        v6 = devm_kmalloc(*(_QWORD *)(a1 + 11168) + 16LL, *(unsigned int *)(a1 + 11288), 3520),
        (*(_QWORD *)(a1 + 11272) = v6) != 0) )
  {
LABEL_4:
    rt_mutex_unlock(a1 + 11088);
    return 0;
  }
  else
  {
    rt_mutex_unlock(a1 + 11088);
    dev_err(*(_QWORD *)a1, "Failed to allocate memory for atomic snapshot\n");
    return 4294967284LL;
  }
}

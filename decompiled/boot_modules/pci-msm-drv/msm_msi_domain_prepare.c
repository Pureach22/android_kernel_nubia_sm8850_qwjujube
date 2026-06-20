__int64 __fastcall msm_msi_domain_prepare(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v6; // x20
  _QWORD *v7; // x0
  _QWORD *v8; // x21
  __int64 v9; // x1
  __int64 v10; // x0
  _QWORD *v11; // x1

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 144) + 32LL);
  v7 = (_QWORD *)_kmalloc_cache_noprof(dev_info, 3520, 48);
  v8 = v7;
  if ( !v7 )
    return 4294967284LL;
  v7[2] = v6;
  v7[3] = a2;
  v9 = *(_QWORD *)(v6 + 128);
  v7[5] = v9;
  if ( !*(_DWORD *)(v6 + 140) )
  {
    v10 = dma_map_resource(a2, v9, *(unsigned int *)(v6 + 136), 2, 0);
    v8[5] = v10;
    if ( v10 == -1 )
    {
      dev_err(*(_QWORD *)(v6 + 16), "MSI: failed to map msi address\n");
      v8[5] = 0;
      kfree(v8);
      return 4294967284LL;
    }
  }
  mutex_lock(v6 + 64);
  v11 = *(_QWORD **)(v6 + 8);
  if ( v8 == (_QWORD *)v6 || v11 == v8 || *v11 != v6 )
  {
    _list_add_valid_or_report(v8, v11, v6);
  }
  else
  {
    *(_QWORD *)(v6 + 8) = v8;
    *v8 = v6;
    v8[1] = v11;
    *v11 = v8;
  }
  mutex_unlock(v6 + 64);
  a4[3] = 0;
  a4[4] = 0;
  a4[1] = 0;
  a4[2] = 0;
  *a4 = 0;
  return 0;
}

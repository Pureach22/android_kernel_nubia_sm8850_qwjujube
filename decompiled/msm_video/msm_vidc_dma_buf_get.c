unsigned __int64 __fastcall msm_vidc_dma_buf_get(__int64 a1, unsigned int a2)
{
  unsigned __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x8
  unsigned __int64 v7; // x19
  unsigned __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 *v12; // x1
  unsigned __int64 v13; // x0

  v4 = dma_buf_get(a2);
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94B27, "err ", 0xFFFFFFFFLL, "codec", a2);
    return 0;
  }
  v5 = a1 + 3992;
  v6 = a1 + 3992;
  while ( 1 )
  {
    v6 = *(_QWORD *)v6;
    if ( v6 == v5 )
      break;
    if ( *(_QWORD *)(v6 + 16) == v4 )
    {
      v7 = v4;
      ++*(_DWORD *)(v6 + 24);
      dma_buf_put(v4);
      return v7;
    }
  }
  v9 = v4;
  v10 = msm_vidc_pool_alloc(a1, 3u);
  if ( !v10 )
  {
    v13 = v9;
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_92669, "err ", a1 + 340, "msm_vidc_dma_buf_get", v11);
      v13 = v9;
    }
    dma_buf_put(v13);
    return 0;
  }
  *(_QWORD *)(v10 + 16) = v9;
  *(_DWORD *)(v10 + 24) = 1;
  *(_QWORD *)v10 = v10;
  *(_QWORD *)(v10 + 8) = v10;
  v12 = *(__int64 **)(a1 + 4000);
  if ( v10 == v5 || v12 == (__int64 *)v10 || *v12 != v5 )
  {
    _list_add_valid_or_report(v10);
    return v9;
  }
  else
  {
    *(_QWORD *)(a1 + 4000) = v10;
    *(_QWORD *)v10 = v5;
    *(_QWORD *)(v10 + 8) = v12;
    *v12 = v10;
    return v9;
  }
}

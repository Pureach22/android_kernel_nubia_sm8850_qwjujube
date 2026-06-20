__int64 __fastcall msm_gem_new_impl(__int64 a1, int a2, __int64 a3, __int64 *a4)
{
  int v4; // w4
  __int64 v9; // x0
  __int64 v10; // x23
  unsigned __int64 v11; // x8
  __int64 result; // x0

  v4 = a2 & 0xF0000;
  if ( (a2 & 0xF0000) == 0x10000 || v4 == 0x20000 || v4 == 0x40000 )
  {
    v9 = _kmalloc_cache_noprof(_wake_up, 3520, 672);
    v10 = v9;
    if ( v9 )
    {
      _mutex_init(v9 + 544, "&msm_obj->lock", &msm_gem_new_impl___key);
      *(_DWORD *)(v10 + 368) = a2;
      *(_BYTE *)(v10 + 372) = 0;
      if ( a3 )
      {
        *(_QWORD *)(v10 + 464) = a3;
      }
      else
      {
        *(_QWORD *)(v10 + 464) = v10 + 472;
        dma_resv_init();
      }
      *(_QWORD *)(v10 + 400) = v10 + 400;
      *(_QWORD *)(v10 + 408) = v10 + 400;
      *(_QWORD *)(v10 + 440) = v10 + 440;
      *(_QWORD *)(v10 + 448) = v10 + 440;
      *(_QWORD *)(v10 + 592) = v10 + 592;
      *(_QWORD *)(v10 + 600) = v10 + 592;
      v11 = msm_gem_smmu_address_space_get(a1, 0);
      result = 0;
      *(_BYTE *)(v10 + 616) = 0;
      *(_BYTE *)(v10 + 649) = 0;
      if ( v11 > 0xFFFFFFFFFFFFF000LL )
        v11 = 0;
      *a4 = v10;
      *(_QWORD *)(v10 + 608) = v11;
      *(_QWORD *)(v10 + 336) = &msm_gem_object_funcs;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 8), "[%s:%d] invalid cache flag: %x\n", "msm_gem_new_impl", 1019, v4);
    return 4294967274LL;
  }
  return result;
}

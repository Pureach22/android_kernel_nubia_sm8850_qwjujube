__int64 __fastcall qcom_add_cma_heap(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  char v4; // w9
  __int64 v5; // x10
  int v6; // w11
  __int64 v7; // x8
  int v8; // w9
  unsigned __int64 v9; // x0
  unsigned int v10; // w19
  __int64 dev; // x19
  __int64 v12; // x2
  __int64 v13; // x3
  _QWORD v15[4]; // [xsp+0h] [xbp-20h] BYREF

  v15[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 32) + 704LL) )
  {
    v2 = _kmalloc_cache_noprof(of_find_property, 3520, 16);
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 32);
      v4 = *(_BYTE *)(a1 + 40);
      v5 = *(_QWORD *)(a1 + 8);
      v6 = *(_DWORD *)(a1 + 48);
      v15[2] = v2;
      v7 = *(_QWORD *)(v3 + 704);
      *(_BYTE *)(v2 + 12) = v4;
      v15[0] = v5;
      v15[1] = &cma_heap_ops;
      if ( v6 )
        v8 = v6;
      else
        v8 = 8;
      *(_QWORD *)v2 = v7;
      *(_DWORD *)(v2 + 8) = v8;
      v9 = dma_heap_add(v15);
      v10 = v9;
      if ( v9 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_BYTE *)(v2 + 12) == 1 )
        {
          dev = dma_heap_get_dev(v9);
          *(_QWORD *)(dev + 640) = dev + 648;
          if ( !(unsigned int)dma_set_mask(dev, -1, v12, v13) )
            dma_set_coherent_mask(dev, -1);
        }
        v10 = 0;
      }
      else
      {
        kfree(v2);
      }
    }
    else
    {
      v10 = -12;
    }
  }
  else
  {
    printk(&unk_E421, "__add_cma_heap");
    v10 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}

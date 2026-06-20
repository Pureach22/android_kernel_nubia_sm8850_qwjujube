__int64 __fastcall qcom_secure_carveout_heap_create(__int64 a1, __int64 a2)
{
  char v2; // w8
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned int v6; // w21
  unsigned int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x9
  unsigned __int64 v10; // x0
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 (__fastcall **v13)(); // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 41);
  v13 = nullptr;
  v14 = 0;
  v12 = 0;
  if ( (v2 & 1) == 0 )
  {
    printk(&unk_E215, a2);
    v6 = -22;
    goto LABEL_15;
  }
  v4 = _kmalloc_cache_noprof(of_property_read_string, 3520, 112);
  v5 = v4;
  if ( !v4 )
  {
    v6 = -12;
    goto LABEL_15;
  }
  v6 = _carveout_heap_init((_QWORD *)a1, (_QWORD *)(v4 + 8));
  if ( !v6 )
  {
    v7 = hyp_assign_from_flags(*(_QWORD *)(a1 + 16), *(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 44));
    v8 = *(unsigned int *)(a1 + 44);
    if ( v7 )
    {
      v6 = v7;
      printk(&unk_DB1E, v8);
    }
    else
    {
      v9 = *(_QWORD *)(a1 + 8);
      *(_BYTE *)(v5 + 96) = 1;
      *(_DWORD *)v5 = v8;
      v12 = v9;
      v13 = &sc_heap_ops;
      v14 = v5;
      v10 = dma_heap_add(&v12);
      *(_QWORD *)(v5 + 8) = v10;
      if ( v10 < 0xFFFFFFFFFFFFF001LL )
      {
        v6 = 0;
        goto LABEL_15;
      }
      v6 = v10;
    }
    down_write(v5 + 16);
    if ( *(_QWORD *)(v5 + 80) )
      gen_pool_destroy();
    up_write(v5 + 16);
  }
  kfree(v5);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v6;
}

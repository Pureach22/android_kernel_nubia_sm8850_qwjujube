__int64 __fastcall qcom_carveout_heap_create(__int64 a1, __int64 a2)
{
  char v2; // w8
  __int64 v4; // x19
  unsigned __int64 v5; // x21
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  __int64 (__fastcall **v9)(); // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_BYTE *)(a1 + 41);
  v9 = nullptr;
  v10 = 0;
  v8 = 0;
  if ( (v2 & 1) == 0 )
  {
    printk(&unk_D8C0, a2);
    result = 4294967274LL;
    goto LABEL_11;
  }
  v4 = _kmalloc_cache_noprof(of_property_read_string, 3520, 104);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_11;
  }
  LODWORD(v5) = _carveout_heap_init(a1, v4);
  if ( (_DWORD)v5 )
    goto LABEL_8;
  v6 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(v4 + 88) = 0;
  v8 = v6;
  v9 = &carveout_heap_ops;
  v10 = v4;
  v5 = dma_heap_add(&v8);
  result = 0;
  *(_QWORD *)v4 = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    down_write(v4 + 8);
    if ( *(_QWORD *)(v4 + 72) )
      gen_pool_destroy();
    up_write(v4 + 8);
LABEL_8:
    kfree(v4);
    result = (unsigned int)v5;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}

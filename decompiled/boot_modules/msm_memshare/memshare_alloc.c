__int64 __fastcall memshare_alloc(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x0

  if ( a3 )
  {
    v4 = dma_alloc_attrs(a1, a2, a3 + 72, 3264, 0);
    *(_QWORD *)(a3 + 80) = v4;
    if ( v4 )
      return 0;
    else
      return 4294967284LL;
  }
  else
  {
    dev_err(*(_QWORD *)memsh_drv, "memshare: Failed memory block allocation\n");
    return 4294967284LL;
  }
}

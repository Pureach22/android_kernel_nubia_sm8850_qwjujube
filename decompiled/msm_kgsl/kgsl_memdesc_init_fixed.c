__int64 __fastcall kgsl_memdesc_init_fixed(_QWORD *a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v8; // x0
  int v9; // w23
  int v10; // w0
  __int64 v11; // x8
  int v12; // w21
  __int64 property; // x0
  __int64 v14; // x24
  unsigned __int64 v15; // x22
  int v16; // w8
  unsigned int *v17; // x9
  unsigned int v18; // t1
  unsigned int *v19; // x8
  unsigned __int64 v20; // x23
  unsigned int v21; // t1
  __int64 result; // x0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 760);
  v23 = 0;
  v9 = of_n_addr_cells(v8);
  v10 = of_n_size_cells(*(_QWORD *)(a2 + 760));
  v11 = *(_QWORD *)(a2 + 760);
  v12 = v10;
  property = of_get_property(v11, a3, &v23);
  if ( property )
  {
    v14 = 4LL * (v12 + v9);
    if ( v14 == v23 )
    {
      v15 = 0;
      if ( v9 )
      {
        v16 = v9;
        v17 = (unsigned int *)property;
        do
        {
          v18 = *v17++;
          --v16;
          v15 = bswap32(v18) | (v15 << 32);
        }
        while ( v16 );
      }
      if ( v12 )
      {
        v19 = (unsigned int *)(property + 4LL * v9);
        v20 = 0;
        do
        {
          v21 = *v19++;
          --v12;
          v20 = bswap32(v21) | (v20 << 32);
        }
        while ( v12 );
      }
      else
      {
        v20 = 0;
      }
      kgsl_memdesc_init((__int64)a1, a4, 0);
      *(_QWORD *)(a4 + 32) = v15;
      *(_QWORD *)(a4 + 40) = v20;
      result = kgsl_memdesc_sg_dma(a4, v15, v20);
    }
    else
    {
      if ( (unsigned int)__ratelimit(&kgsl_memdesc_init_fixed__rs, "kgsl_memdesc_init_fixed") )
        dev_err(*a1, "of property %s has len %d expected %lu\n", a3, v23, v14);
      result = 4294967289LL;
    }
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

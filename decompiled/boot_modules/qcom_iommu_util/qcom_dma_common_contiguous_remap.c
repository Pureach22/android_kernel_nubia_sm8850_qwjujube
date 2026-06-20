__int64 __fastcall qcom_dma_common_contiguous_remap(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x23
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x22
  __int64 v8; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x10
  bool v11; // cf
  __int64 v12; // x21
  __int64 v13; // x19
  unsigned __int64 StatusReg; // x24
  __int64 v16; // x25

  v3 = a2 + 4095;
  v6 = (unsigned __int64)(a2 + 4095) >> 12;
  if ( ((v6 << 32) & 0x8000000000000000LL) == 0 )
  {
    v7 = (8 * v6) & 0x7FFFFFFFFLL;
    v8 = _kmalloc_noprof(v7, 3264);
    while ( v8 )
    {
      if ( (int)v6 < 1 )
      {
LABEL_11:
        v12 = v8;
        v13 = vmap(v8, (unsigned int)v6, 16, a3);
        kfree(v12);
        return v13;
      }
      v9 = 0;
      v10 = v7;
      while ( (v9 & 0x8000000000000000LL) == 0 )
      {
        if ( v7 < v9 )
          break;
        v11 = v10 >= 8;
        v10 -= 8LL;
        if ( !v11 )
          break;
        *(_QWORD *)(v8 + v9) = a1;
        v9 += 8LL;
        a1 += 64;
        if ( 8 * ((v3 >> 12) & 0x7FFFFFFF) == v9 )
          goto LABEL_11;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &qcom_dma_common_contiguous_remap__alloc_tag;
      if ( ((v6 << 32) & 0x8000000000000000LL) != 0 )
      {
        v7 = 0;
        v8 = 0;
      }
      else
      {
        v7 = (8 * v6) & 0x7FFFFFFFFLL;
        v8 = _kmalloc_noprof(v7, 3264);
      }
      *(_QWORD *)(StatusReg + 80) = v16;
    }
  }
  return 0;
}

__int64 __fastcall kgsl_ioctl_gpumem_alloc_compat(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x9
  unsigned int v5; // w10
  __int64 result; // x0
  unsigned int v8; // w20
  unsigned __int64 v9; // x21
  unsigned int v10; // w8
  int v11; // w21
  int v12; // w20
  unsigned __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int64 v14; // [xsp+8h] [xbp-18h]
  unsigned int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v3 = a3[1];
  v5 = a3[2];
  v14 = v3;
  v16 = 0;
  v13 = v4;
  v15 = v5;
  if ( ((v3 + 4095) & 0x1FFFFF000LL) <= 0xFFFFFFFE )
  {
    LODWORD(result) = kgsl_ioctl_gpumem_alloc(a1, a2, (__int64)&v13);
    v8 = v13;
    if ( HIDWORD(v13) )
    {
      v11 = result;
      _warn_printk("Top 32 bits of gpuaddr have been set\n");
      LODWORD(result) = v11;
      __break(0x800u);
    }
    v9 = v14;
    *a3 = v8;
    if ( HIDWORD(v9) )
    {
      v12 = result;
      _warn_printk("Size greater than 4G\n");
      LODWORD(result) = v12;
      __break(0x800u);
    }
    v10 = v15;
    result = (int)result;
    a3[1] = v9;
    a3[2] = v10;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

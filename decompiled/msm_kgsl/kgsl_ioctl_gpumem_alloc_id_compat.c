__int64 __fastcall kgsl_ioctl_gpumem_alloc_id_compat(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w9
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x10
  __int64 result; // x0
  int v8; // w20
  int v9; // w9
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x21
  unsigned __int64 v12; // x20
  int v13; // w21
  int v14; // w20
  int v15; // w21
  int v16; // [xsp+8h] [xbp-38h] BYREF
  int v17; // [xsp+Ch] [xbp-34h]
  unsigned __int64 v18; // [xsp+10h] [xbp-30h]
  unsigned __int64 v19; // [xsp+18h] [xbp-28h]
  unsigned __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a3[1];
  v16 = *a3;
  v17 = v3;
  v5 = (unsigned int)a3[2];
  v4 = (unsigned int)a3[3];
  v20 = (unsigned int)a3[4];
  v18 = v5;
  v19 = v4;
  if ( ((v5 + 4095) & 0x1FFFFF000LL) <= 0xFFFFFFFE )
  {
    v21 = 0;
    v22 = 0;
    LODWORD(result) = kgsl_ioctl_gpumem_alloc_id(a1, a2, (__int64)&v16);
    v8 = v18;
    v9 = v17;
    v10 = HIDWORD(v18);
    *a3 = v16;
    a3[1] = v9;
    if ( v10 )
    {
      v13 = result;
      _warn_printk("Size greater than 4G\n");
      LODWORD(result) = v13;
      __break(0x800u);
    }
    v11 = v19;
    a3[2] = v8;
    if ( HIDWORD(v11) )
    {
      v14 = result;
      _warn_printk("Size greater than 4G\n");
      LODWORD(result) = v14;
      __break(0x800u);
    }
    v12 = v20;
    a3[3] = v11;
    if ( HIDWORD(v12) )
    {
      v15 = result;
      _warn_printk("Top 32 bits of gpuaddr have been set\n");
      LODWORD(result) = v15;
      __break(0x800u);
    }
    result = (int)result;
    a3[4] = v12;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

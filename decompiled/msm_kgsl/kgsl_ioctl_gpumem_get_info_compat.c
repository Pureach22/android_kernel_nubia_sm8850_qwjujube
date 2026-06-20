__int64 __fastcall kgsl_ioctl_gpumem_get_info_compat(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned __int64 v4; // x8
  unsigned int v5; // w9
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  __int64 result; // x0
  unsigned int v10; // w20
  unsigned int v11; // w21
  unsigned int v12; // w8
  unsigned int v13; // w9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x20
  unsigned int v16; // w8
  int v17; // w21
  int v18; // w20
  int v19; // w21
  unsigned __int64 v20; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v21; // [xsp+8h] [xbp-48h]
  unsigned int v22; // [xsp+Ch] [xbp-44h]
  unsigned __int64 v23; // [xsp+10h] [xbp-40h]
  unsigned __int64 v24; // [xsp+18h] [xbp-38h]
  __int64 v25; // [xsp+20h] [xbp-30h]
  __int64 v26; // [xsp+28h] [xbp-28h]
  __int64 v27; // [xsp+30h] [xbp-20h]
  __int64 v28; // [xsp+38h] [xbp-18h]
  __int64 v29; // [xsp+40h] [xbp-10h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v5 = a3[1];
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v20 = v4;
  LODWORD(v4) = a3[2];
  v6 = a3[3];
  v21 = v5;
  v22 = v4;
  v7 = a3[4];
  v8 = a3[5];
  v23 = v6;
  v24 = v7;
  v25 = v8;
  LODWORD(result) = kgsl_ioctl_gpumem_get_info(a1, a2, (__int64)&v20);
  v10 = v20;
  if ( HIDWORD(v20) )
  {
    v17 = result;
    _warn_printk("Top 32 bits of gpuaddr have been set\n");
    LODWORD(result) = v17;
    __break(0x800u);
  }
  v11 = v23;
  v12 = v21;
  v13 = v22;
  v14 = HIDWORD(v23);
  *a3 = v10;
  a3[1] = v12;
  a3[2] = v13;
  if ( v14 )
  {
    v18 = result;
    _warn_printk("Size greater than 4G\n");
    LODWORD(result) = v18;
    __break(0x800u);
  }
  v15 = v24;
  a3[3] = v11;
  if ( HIDWORD(v15) )
  {
    v19 = result;
    _warn_printk("Size greater than 4G\n");
    LODWORD(result) = v19;
    __break(0x800u);
  }
  v16 = v25;
  a3[4] = v15;
  a3[5] = v16;
  _ReadStatusReg(SP_EL0);
  return (int)result;
}

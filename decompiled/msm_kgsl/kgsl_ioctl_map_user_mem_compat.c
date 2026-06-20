__int64 __fastcall kgsl_ioctl_map_user_mem_compat(const char ****a1, __int64 a2, unsigned int *a3)
{
  unsigned int v4; // w8
  __int64 v5; // x10
  unsigned int v6; // w8
  unsigned int v7; // w9
  __int64 result; // x0
  unsigned int v9; // w20
  unsigned int v10; // w8
  int v11; // w21
  __int64 v12; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v13; // [xsp+10h] [xbp-30h]
  __int64 v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  unsigned int v17; // [xsp+30h] [xbp-10h]
  unsigned int v18; // [xsp+34h] [xbp-Ch]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v13 = a3[1];
  v12 = v4;
  v5 = a3[3];
  v14 = a3[2];
  v15 = v5;
  v6 = a3[5];
  v16 = a3[4];
  v7 = a3[6];
  v17 = v6;
  v18 = v7;
  LODWORD(result) = kgsl_ioctl_map_user_mem(a1, a2, (unsigned int *)&v12);
  v9 = v13;
  if ( HIDWORD(v13) )
  {
    v11 = result;
    _warn_printk("Top 32 bits of gpuaddr have been set\n");
    LODWORD(result) = v11;
    __break(0x800u);
  }
  v10 = v18;
  a3[1] = v9;
  a3[6] = v10;
  _ReadStatusReg(SP_EL0);
  return (int)result;
}

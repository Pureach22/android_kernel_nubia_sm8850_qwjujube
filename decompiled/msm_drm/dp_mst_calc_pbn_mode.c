__int64 __fastcall dp_mst_calc_pbn_mode(__int64 a1)
{
  int v1; // w21
  int v3; // w19
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x11
  unsigned int v10; // w11
  unsigned int v11; // w10
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  unsigned int v15; // w11
  unsigned int v16; // w10
  unsigned __int64 v17; // x21
  char v18; // w8

  v1 = *(unsigned __int8 *)(a1 + 64);
  if ( v1 == 1 )
    v3 = *(unsigned __int16 *)(a1 + 104) >> 4;
  else
    v3 = *(_DWORD *)(a1 + 52);
  v4 = drm_dp_calc_pbn_mode(*(unsigned int *)(a1 + 48), (unsigned int)(16 * v3));
  *(_DWORD *)(a1 + 760) = v4;
  if ( v4 >= 0 )
    v5 = (unsigned int)v4;
  else
    v5 = (unsigned int)-v4;
  v6 = v5 << 32;
  if ( v4 < 0 )
    v6 = -v6;
  if ( !v1 )
    goto LABEL_21;
  v7 = *(_QWORD *)(a1 + 784);
  v8 = 62;
  do
  {
    if ( (((unsigned __int64)v6 >> v8) & 1) != (unsigned __int64)v6 >> 63 )
      break;
    --v8;
  }
  while ( v8 );
  v9 = 62;
  do
  {
    if ( (((unsigned __int64)v7 >> v9) & 1) != (unsigned __int64)v7 >> 63 )
      break;
    --v9;
  }
  while ( v9 );
  v10 = v9 + v8;
  v11 = v10 - 61;
  if ( v10 <= 0x3D )
  {
    v6 *= v7;
    LOBYTE(v11) = 0;
LABEL_20:
    v6 >>= 32 - (unsigned __int8)v11;
    goto LABEL_21;
  }
  v6 = (v6 >> ((v11 >> 1) + (v11 & 1))) * (v7 >> (v11 >> 1));
  if ( v11 >= 0x21 )
  {
    v6 <<= (unsigned __int8)v10 - 93;
    goto LABEL_21;
  }
  if ( v10 != 93 )
    goto LABEL_20;
LABEL_21:
  v12 = *(_QWORD *)(a1 + 776);
  if ( !v12 )
    goto LABEL_33;
  v13 = 62;
  do
  {
    if ( (((unsigned __int64)v6 >> v13) & 1) != (unsigned __int64)v6 >> 63 )
      break;
    --v13;
  }
  while ( v13 );
  v14 = 62;
  do
  {
    if ( (((unsigned __int64)v12 >> v14) & 1) != (unsigned __int64)v12 >> 63 )
      break;
    --v14;
  }
  while ( v14 );
  v15 = v14 + v13;
  v16 = v15 - 61;
  if ( v15 <= 0x3D )
  {
    v6 *= v12;
    LOBYTE(v16) = 0;
LABEL_32:
    v6 >>= 32 - (unsigned __int8)v16;
    goto LABEL_33;
  }
  v6 = (v6 >> ((v16 >> 1) + (v16 & 1))) * (v12 >> (v16 >> 1));
  if ( v16 >= 0x21 )
  {
    v6 <<= (unsigned __int8)v15 - 93;
    goto LABEL_33;
  }
  if ( v15 != 93 )
    goto LABEL_32;
LABEL_33:
  v17 = HIDWORD(v6);
  v18 = _drm_debug;
  *(_DWORD *)(a1 + 764) = v17;
  if ( (v18 & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]pbn before overhead:%d pbn final:%d, bpp:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v4,
      v17,
      v3);
  return (unsigned int)v17;
}

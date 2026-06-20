__int64 __fastcall dp_tu_dsc_get_num_extra_pclk(__int64 a1, int *a2)
{
  int v3; // w8
  unsigned int v4; // w9
  int v5; // w10
  char v6; // w8
  unsigned int v7; // w20
  int v8; // w14
  unsigned __int64 v9; // x13
  unsigned int v10; // w11
  int v11; // w8
  __int64 v12; // x15
  unsigned __int64 v13; // x15
  __int64 v14; // x17
  bool v15; // cf
  int v16; // w13
  int v17; // w12
  int v18; // w14
  int v19; // w11
  int v20; // w15
  unsigned int v21; // w19
  bool v22; // vf
  int v23; // w8
  _DWORD v25[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[4];
  v4 = *((unsigned __int16 *)a2 + 4);
  v26 = 0;
  v5 = *a2;
  if ( v3 == 4 )
    v6 = 2;
  else
    v6 = 1;
  v7 = v4 >> v6;
  v25[0] = a2[1];
  v25[1] = v5;
  dp_panel_get_dto_params(a1, v25);
  v8 = -32;
  v9 = v7 / HIDWORD(v26);
  v10 = v26;
  v11 = v7 % HIDWORD(v26);
  v12 = v7 % HIDWORD(v26);
  do
  {
    v13 = 2 * v12;
    if ( v13 < HIDWORD(v26) )
      v14 = 0;
    else
      v14 = HIDWORD(v26);
    v15 = __CFADD__(v8++, 1);
    v9 = (v13 >= HIDWORD(v26)) | (2 * v9);
    v12 = v13 - v14;
  }
  while ( !v15 );
  if ( HIDWORD(v26) <= (unsigned __int64)(2 * v12) )
    ++v9;
  if ( (_DWORD)v26 )
  {
    v16 = a2[3] - v26 * HIDWORD(v9);
    if ( v16 < 1 )
    {
      v17 = 0;
    }
    else
    {
      v17 = 0;
      v18 = 0;
      do
      {
        v15 = v10 >= (unsigned int)v26;
        v19 = v10 - v26;
        ++v17;
        if ( v15 )
          v20 = 0;
        else
          v20 = HIDWORD(v26);
        v10 = v19 + v20;
        if ( v10 < (unsigned int)v26 )
          ++v18;
      }
      while ( v18 < v16 );
    }
    v22 = __OFSUB__(v17, v11);
    v23 = v17 - v11;
    if ( (v23 < 0) ^ v22 | (v23 == 0) )
      v21 = 0;
    else
      v21 = v23;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]extra pclks required: %d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v21);
  }
  else
  {
    v21 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}

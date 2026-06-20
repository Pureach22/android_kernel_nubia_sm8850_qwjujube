__int64 __fastcall sde_plane_setup_pixel_ext(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        unsigned int *a5,
        _BOOL4 *a6,
        int *a7,
        _DWORD *a8,
        __int64 a9,
        unsigned int a10,
        char a11)
{
  _BOOL4 v11; // w13
  unsigned __int64 v12; // x14
  int v13; // w10
  unsigned int v14; // w11
  unsigned int v15; // w15
  __int64 v16; // x14
  __int64 v17; // x17
  bool v18; // cc
  __int64 v19; // x15
  __int64 v20; // x16
  int v21; // w12
  int v22; // w13
  unsigned int v23; // w13
  __int64 v24; // x13
  __int64 v25; // x14
  __int64 v26; // x15
  __int64 v27; // x13
  int v28; // w13
  unsigned int v29; // w13
  __int64 v30; // x13
  __int64 v31; // x14
  __int64 v32; // x15
  __int64 v33; // x13
  int v34; // w12
  unsigned int v35; // w8
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x11
  int v40; // w8

  if ( a4 && a5 && a6 && a7 && a8 )
  {
    if ( (*(_QWORD *)(a9 + 32) & 1) != 0 )
    {
      v11 = *a8 == 3;
      v12 = (unsigned __int64)(*a8 == 3) << 21;
    }
    else
    {
      v11 = 0;
      v12 = 0;
    }
    v13 = a3 << 21;
    v14 = a2 - 1;
    if ( (a11 & 1) != 0 )
      v15 = a3;
    else
      v15 = result;
    if ( (*(_QWORD *)(a9 + 32) & 1) != 0 || v15 != a2 )
    {
      v17 = *a4;
      v18 = v15 > a2;
      v19 = (unsigned int)(v13 - 0x200000);
      v20 = (unsigned int)v17 * v14;
      if ( v18 )
      {
        v11 = 0;
        v16 = v19 - v17 - v20;
      }
      else
      {
        v16 = v19 - v12 - v20 - 0x8000;
      }
    }
    else
    {
      v11 = 0;
      v16 = 0;
    }
    v21 = a3 / a10;
    *a5 = a3;
    *a6 = v11;
    if ( v16 >= 0 )
      v22 = -((int)v16 >> 21);
    else
      v22 = (0x1FFFFF - (int)v16) >> 21;
    *a7 = v22;
    if ( (a11 & 1) != 0 )
      v23 = a3 / a10;
    else
      v23 = result;
    if ( (*(_QWORD *)(a9 + 32) & 1) != 0 || v23 != a2 )
    {
      v25 = a4[1];
      v18 = v23 > a2;
      v26 = (unsigned int)v25 * v14;
      v27 = (unsigned int)((v21 << 21) - 0x200000);
      if ( v18 )
        v24 = v27 - (v25 + v26);
      else
        v24 = v27 - v26 - 0x8000;
    }
    else
    {
      v24 = 0;
    }
    a5[1] = v21;
    a6[1] = 0;
    if ( v24 >= 0 )
      v28 = -((int)v24 >> 21);
    else
      v28 = (0x1FFFFF - (int)v24) >> 21;
    a7[1] = v28;
    if ( (a11 & 1) != 0 )
      v29 = a3 / a10;
    else
      v29 = result;
    if ( (*(_QWORD *)(a9 + 32) & 1) != 0 || v29 != a2 )
    {
      v31 = a4[2];
      v18 = v29 > a2;
      v32 = (unsigned int)v31 * v14;
      v33 = (unsigned int)((v21 << 21) - 0x200000);
      if ( v18 )
        v30 = v33 - (v31 + v32);
      else
        v30 = v33 - v32 - 0x8000;
    }
    else
    {
      v30 = 0;
    }
    a5[2] = v21;
    a6[2] = 0;
    if ( v30 >= 0 )
      v34 = -((int)v30 >> 21);
    else
      v34 = (0x1FFFFF - (int)v30) >> 21;
    a7[2] = v34;
    if ( (a11 & 1) != 0 )
      v35 = a3;
    else
      v35 = result;
    if ( (*(_QWORD *)(a9 + 32) & 1) != 0 || v35 != a2 )
    {
      v37 = a4[3];
      v18 = v35 > a2;
      v38 = (unsigned int)(v13 - 0x200000);
      v39 = (unsigned int)v37 * v14;
      if ( v18 )
        v36 = v38 - v37 - v39;
      else
        v36 = v38 - v39 - 0x8000;
    }
    else
    {
      v36 = 0;
    }
    a5[3] = a3;
    a6[3] = 0;
    if ( v36 >= 0 )
      v40 = -((int)v36 >> 21);
    else
      v40 = (0x1FFFFF - (int)v36) >> 21;
    a7[3] = v40;
  }
  return result;
}

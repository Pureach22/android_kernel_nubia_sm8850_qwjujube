unsigned int *__fastcall wma_derive_ext_vht_cap(unsigned int *result, unsigned int a2)
{
  unsigned int *v3; // x19
  unsigned int v4; // w8
  unsigned int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w11
  unsigned int v8; // w14
  unsigned int v9; // w10
  unsigned int v10; // w8
  unsigned int v11; // w12
  int v12; // w11
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w10
  int v16; // w11
  unsigned int v17; // w13
  unsigned int v18; // w15
  unsigned int v19; // w9
  int v20; // w8
  unsigned int v21; // w12
  unsigned int v22; // w8
  int v23; // w8
  _QWORD v24[8]; // [xsp+0h] [xbp-40h] BYREF

  v24[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 56);
  if ( result )
  {
    v3 = result;
    result = (unsigned int *)qdf_mem_cmp(result, v24, 0x38u);
    v4 = a2 & 1;
    if ( (a2 & 2) != 0 )
      v4 = 2;
    if ( (_DWORD)result )
    {
      if ( *v3 < v4 )
        v4 = *v3;
      v5 = a2 & 0x10;
      if ( (a2 & 4) != 0 )
        v6 = 8;
      else
        v6 = 4;
      if ( (a2 & 8) != 0 )
        v6 = 24;
      v7 = v3[2];
      v8 = v3[3];
      if ( v3[1] > v6 )
        v6 = v3[1];
      *v3 = v4;
      v3[1] = v6;
      v9 = a2 & 0x80;
      v10 = v3[4];
      v11 = v3[5];
      if ( v7 < v5 )
        v5 = v7;
      if ( v8 <= (a2 & 0x20) )
        v12 = a2 & 0x20;
      else
        v12 = v8;
      v3[2] = v5;
      v3[3] = v12;
      if ( v10 <= (a2 & 0x40) )
        v10 = a2 & 0x40;
      if ( v11 > v9 )
        v9 = v11;
      v3[4] = v10;
      v3[5] = v9;
      v14 = v3[6];
      v13 = v3[7];
      v15 = v3[10];
      if ( v14 >= (a2 & 0x300) )
        v14 = a2 & 0x300;
      if ( v3[11] >= ((a2 >> 23) & 7) )
        v16 = (a2 >> 23) & 7;
      else
        v16 = v3[11];
      v17 = v3[8];
      v18 = v3[9];
      if ( v13 <= (a2 & 0x800) )
        v13 = a2 & 0x800;
      v3[6] = v14;
      v3[7] = v13;
      v19 = a2 & 0x100000;
      if ( v17 <= (a2 & 0x1000) )
        v17 = a2 & 0x1000;
      if ( v18 <= (a2 & 0x80000) )
        v20 = a2 & 0x80000;
      else
        v20 = v18;
      v21 = v3[12];
      v3[8] = v17;
      v3[9] = v20;
      v22 = a2 & 0x200000;
      if ( v15 > v19 )
        v19 = v15;
      v3[10] = v19;
      v3[11] = v16;
      if ( v21 < v22 )
        v22 = v21;
    }
    else
    {
      *v3 = v4;
      if ( (a2 & 8) != 0 )
      {
        v23 = 24;
      }
      else if ( (a2 & 4) != 0 )
      {
        v23 = 8;
      }
      else
      {
        v23 = 4;
      }
      v3[1] = v23;
      v3[2] = a2 & 0x10;
      v3[3] = a2 & 0x20;
      v3[4] = a2 & 0x40;
      v3[5] = a2 & 0x80;
      v3[6] = a2 & 0x300;
      v3[7] = a2 & 0x800;
      v3[8] = a2 & 0x1000;
      v3[9] = a2 & 0x80000;
      v3[10] = a2 & 0x100000;
      v3[11] = (a2 >> 23) & 7;
      v22 = a2 & 0x200000;
    }
    v3[12] = v22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall chan_free_show(__int64 a1, __int64 a2, _WORD *a3)
{
  unsigned int *v4; // x20
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x21
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x12
  unsigned int *v14; // x13
  __int64 v15; // x12
  __int64 v16; // x14
  __int64 v17; // x15
  __int64 v18; // x16
  __int64 v19; // x17
  unsigned int *v20; // x11
  __int64 v21; // x3
  __int64 result; // x0
  _QWORD v23[2]; // [xsp+0h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int **)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 14);
  v5 = v4[17];
  if ( (int)v5 < 1 )
  {
    v8 = -1;
  }
  else
  {
    if ( (unsigned int)v5 >= 3 )
    {
      v9 = v5 - 1;
      v10 = 0;
      v11 = 0;
      if ( (unsigned __int64)(v5 - 1) >= 0x80 )
        v9 = 128;
      v12 = v9 + 1;
      v13 = v12 & 1;
      if ( (v12 & 1) == 0 )
        v13 = 2;
      v14 = v4;
      v6 = v12 - v13;
      v15 = v6;
      do
      {
        v16 = v14[35];
        v17 = v14[36];
        v18 = v14[163];
        v19 = v14[164];
        v15 -= 2;
        v14 += 2;
        v10 |= v16 | v18;
        v11 |= v17 | v19;
      }
      while ( v15 );
      v7 = v11 | v10;
    }
    else
    {
      v6 = 0;
      v7 = 0;
    }
    do
    {
      if ( v6 == 128 )
        __break(0x5512u);
      v20 = &v4[v6++];
      v7 |= v20[35] | (unsigned __int64)v20[163];
    }
    while ( v5 != v6 );
    v8 = ~v7;
  }
  raw_spin_unlock(v4 + 14);
  v21 = v4[16];
  v23[0] = v8;
  if ( v8 << -(char)v21 )
  {
    result = (int)bitmap_print_to_pagebuf(1, a3, v23, v21);
  }
  else
  {
    result = 1;
    *a3 = 10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

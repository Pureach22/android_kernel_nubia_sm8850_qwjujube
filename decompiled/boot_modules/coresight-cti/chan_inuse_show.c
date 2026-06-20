__int64 __fastcall chan_inuse_show(__int64 a1, __int64 a2, _WORD *a3)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x10
  __int64 v11; // x3
  __int64 result; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v13[0] = 0;
  v5 = *(_QWORD *)(v4 + 152);
  raw_spin_lock(v5 + 56);
  v6 = *(unsigned int *)(v5 + 68);
  if ( (int)v6 < 1 )
  {
    v9 = 0;
  }
  else
  {
    v7 = 4 * v6;
    v8 = 0;
    v9 = 0;
    do
    {
      if ( v8 == 512 )
        __break(0x5512u);
      v10 = v5 + v8;
      v8 += 4;
      v9 |= *(unsigned int *)(v10 + 140) | (unsigned __int64)*(unsigned int *)(v10 + 652);
      v13[0] = v9;
    }
    while ( v7 != v8 );
  }
  raw_spin_unlock(v5 + 56);
  v11 = *(unsigned int *)(v5 + 64);
  if ( v9 << -(char)v11 )
  {
    result = (int)bitmap_print_to_pagebuf(1, a3, v13, v11);
  }
  else
  {
    result = 1;
    *a3 = 10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

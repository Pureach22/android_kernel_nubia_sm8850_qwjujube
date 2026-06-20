__int64 __fastcall sde_set_possible_cpu_mask(unsigned __int64 a1)
{
  int v1; // w0
  char v2; // w12
  int v3; // w8
  unsigned __int64 v9; // x14
  unsigned __int64 v11; // x12
  unsigned __int64 v12; // x12
  __int64 v13; // x13
  bool v14; // cc
  unsigned __int64 v16; // x14
  unsigned __int64 v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = a1;
  v1 = _sw_hweight64((unsigned int)a1 & ~_cpu_possible_mask);
  v2 = 0;
  v3 = cpu_all_bits;
  _X11 = v18;
  do
  {
    v11 = (unsigned int)(-1LL << v2) & v3;
    if ( !(_DWORD)v11 )
      break;
    v12 = __clz(__rbit64(v11));
    v13 = 1LL << v12;
    if ( (_cpu_possible_mask & (1LL << v12)) == 0 || ((v18[0] & v13) == 0 ? (v14 = v1 < 1) : (v14 = 1), v14) )
    {
      if ( (v18[0] & v13) != 0 && (_cpu_possible_mask & v13) == 0 )
      {
        __asm { PRFM            #0x11, [X11] }
        do
          v16 = __ldxr(v18);
        while ( __stxr(v16 & ~v13, v18) );
      }
    }
    else
    {
      __asm { PRFM            #0x11, [X11] }
      do
        v9 = __ldxr(v18);
      while ( __stxr(v9 | v13, v18) );
      --v1;
    }
    _CF = v12 >= 0x1F;
    v2 = v12 + 1;
  }
  while ( !_CF );
  _ReadStatusReg(SP_EL0);
  return LODWORD(v18[0]);
}

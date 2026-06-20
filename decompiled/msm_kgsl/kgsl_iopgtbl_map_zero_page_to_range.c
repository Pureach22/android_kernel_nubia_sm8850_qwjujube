__int64 __fastcall kgsl_iopgtbl_map_zero_page_to_range(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x25
  unsigned __int64 v6; // x8
  __int64 v7; // x8
  _DWORD **v8; // x20
  unsigned __int64 v9; // x23
  unsigned __int64 v11; // x21
  __int64 v12; // x24
  _DWORD *v13; // x9
  __int64 v14; // x2
  __int64 result; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a4;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = kgsl_vbo_zero_page;
  if ( kgsl_vbo_zero_page )
  {
    v6 = *(_QWORD *)(a2 + 40);
    if ( v6 <= a3 || a4 + a3 > v6 )
    {
      __break(0x800u);
      result = 4294967262LL;
    }
    else
    {
      v7 = *(_QWORD *)(a2 + 24);
      v8 = (_DWORD **)a1[25];
      v16[0] = 0;
      if ( a4 )
      {
        v9 = v7 + a3;
        v11 = 0;
        v12 = v7 + a3;
        do
        {
          v13 = *v8;
          v14 = ((v5 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
          if ( *(*v8 - 1) != 2054949561 )
            __break(0x8229u);
          if ( ((unsigned int (__fastcall *)(_DWORD **, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD *))v13)(
                 v8,
                 v12,
                 v14,
                 4096,
                 1,
                 11,
                 3264,
                 v16) )
          {
            iopgtbl_unmap(a1, v9, v11);
            goto LABEL_13;
          }
          v4 -= 4096;
          v12 += 4096;
          v11 += v16[0];
        }
        while ( v4 );
        if ( !v11 )
          goto LABEL_13;
        result = 0;
      }
      else
      {
LABEL_13:
        result = 4294967284LL;
      }
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

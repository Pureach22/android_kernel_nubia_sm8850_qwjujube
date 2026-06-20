size_t __fastcall stm_generic_packet(
        __int64 a1,
        int a2,
        unsigned int a3,
        int a4,
        int a5,
        unsigned int a6,
        unsigned __int64 src)
{
  unsigned int v7; // w8
  __int64 v8; // x10
  __int64 v9; // x21
  __int64 v10; // x20
  size_t result; // x0
  size_t v12; // x19
  char v13; // w22
  __int64 v14; // x8
  __int64 v15; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 64 || !(unsigned int)*(_QWORD *)(*(_QWORD *)(a1 - 40) + 968LL) )
  {
    result = -13;
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(a1 + 96) <= a3 )
  {
    result = -22;
    goto LABEL_20;
  }
  v7 = *(_DWORD *)(a1 + 84);
  v8 = 1LL << ~(unsigned __int8)__clz(a6);
  v9 = (4 * a5) & 8
     | (((unsigned int)(*(_QWORD *)(*(_QWORD *)(a1 - 8) + (((unsigned __int64)a3 >> 3) & 0x1FFFFFF8)) >> a3) & 1) << 7);
  v10 = *(_QWORD *)(a1 - 24) + (a3 << 8);
  if ( v7 >= a6 )
    result = (unsigned int)v8;
  else
    result = v7;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = 1;
      *(_BYTE *)(v10 + (v9 ^ 0xE8)) = *(_BYTE *)src;
    }
    else
    {
      result = -524;
    }
    goto LABEL_20;
  }
  v16[0] = 0;
  if ( (((unsigned __int8)v7 - 1LL) & src) == 0 )
  {
LABEL_15:
    v14 = ((unsigned int)v9 | (16 * (a5 & 1))) ^ 0x98LL;
    if ( (int)result > 3 )
    {
      if ( (_DWORD)result == 4 )
      {
        *(_DWORD *)(v10 + v14) = *(_DWORD *)src;
      }
      else if ( (_DWORD)result == 8 )
      {
        *(_QWORD *)(v10 + v14) = *(_QWORD *)src;
      }
    }
    else if ( (_DWORD)result == 1 )
    {
      *(_BYTE *)(v10 + v14) = *(_BYTE *)src;
    }
    else if ( (_DWORD)result == 2 )
    {
      *(_WORD *)(v10 + v14) = *(_WORD *)src;
    }
    goto LABEL_20;
  }
  v12 = result;
  if ( (unsigned int)result < 9 )
  {
    v13 = a5;
    memcpy(v16, (const void *)src, result);
    result = v12;
    src = (unsigned __int64)v16;
    LOBYTE(a5) = v13;
    goto LABEL_15;
  }
  v15 = _fortify_panic(17, 8, result);
  return stm_mmio_addr(v15);
}

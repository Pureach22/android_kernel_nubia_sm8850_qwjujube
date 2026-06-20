__int64 __fastcall drv_add_interface(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 (*v4)(void); // x9
  __int64 result; // x0
  int v6; // w8

  v2 = *(_DWORD *)(a2 + 4720);
  if ( v2 == 4 || v2 == 6 && (*(_QWORD *)(a1 + 96) & 0x1000) == 0 && (*(_BYTE *)(a2 + 2264) & 0x40) == 0 )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  else
  {
    v4 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 48LL);
    if ( *((_DWORD *)v4 - 1) != 844051912 )
      __break(0x8229u);
    result = v4();
    if ( !(_DWORD)result )
    {
      v6 = *(_DWORD *)(a2 + 1624);
      result = 0;
      if ( (v6 & 0x20) == 0 )
        *(_DWORD *)(a2 + 1624) = v6 | 0x20;
    }
  }
  return result;
}

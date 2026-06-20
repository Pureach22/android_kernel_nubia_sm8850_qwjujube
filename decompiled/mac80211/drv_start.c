__int64 __fastcall drv_start(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 1469) == 1 )
  {
    __break(0x800u);
    return 4294967182LL;
  }
  else
  {
    *(_BYTE *)(a1 + 1469) = 1;
    __dmb(0xBu);
    v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 8LL);
    if ( *((_DWORD *)v2 - 1) != -1244592371 )
      __break(0x8228u);
    result = v2();
    if ( (_DWORD)result )
      *(_BYTE *)(a1 + 1469) = 0;
  }
  return result;
}

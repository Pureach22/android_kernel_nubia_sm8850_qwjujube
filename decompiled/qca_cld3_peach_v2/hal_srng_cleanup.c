__int64 __fastcall hal_srng_cleanup(__int64 result, __int64 a2, char a3)
{
  __int64 (*v3)(void); // x8

  *(_BYTE *)(a2 + 1) = 0;
  if ( (a3 & 1) != 0 )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)(result + 74392) + 16LL);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != -484425373 )
        __break(0x8228u);
      return v3();
    }
  }
  return result;
}

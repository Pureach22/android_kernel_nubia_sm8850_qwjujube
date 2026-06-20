__int64 __fastcall swr_reset_device(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 (__fastcall *v4)(_QWORD); // x9

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 208);
  result = 4294967274LL;
  if ( v1 && v1 != 72 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v1 - 16);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1952588086 )
        __break(0x8229u);
      return v4(a1);
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}

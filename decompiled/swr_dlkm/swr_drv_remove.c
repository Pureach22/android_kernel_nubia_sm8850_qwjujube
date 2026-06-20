__int64 __fastcall swr_drv_remove(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 (__fastcall *v4)(_QWORD); // x9
  __int64 v5; // x0

  v1 = *(_QWORD *)(a1 + 136);
  result = 4294967274LL;
  if ( v1 && v1 != 72 )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v1 - 64);
    if ( v4 )
    {
      if ( a1 )
        v5 = a1 - 72;
      else
        v5 = 0;
      if ( *((_DWORD *)v4 - 1) != 1952588086 )
        __break(0x8229u);
      return v4(v5);
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}

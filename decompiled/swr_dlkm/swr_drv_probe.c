__int64 __fastcall swr_drv_probe(__int64 a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  __int64 (__fastcall **v4)(_QWORD); // x9
  __int64 (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0

  v1 = *(_QWORD *)(a1 + 136);
  result = 4294967274LL;
  if ( v1 )
  {
    v4 = (__int64 (__fastcall **)(_QWORD))(v1 - 72);
    if ( v4 )
    {
      v5 = *v4;
      if ( v5 )
      {
        if ( a1 )
          v6 = a1 - 72;
        else
          v6 = 0;
        if ( *((_DWORD *)v5 - 1) != 1952588086 )
          __break(0x8229u);
        return v5(v6);
      }
      else
      {
        return 4294967277LL;
      }
    }
  }
  return result;
}

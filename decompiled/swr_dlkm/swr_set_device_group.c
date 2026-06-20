__int64 __fastcall swr_set_device_group(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 v4; // x8

  if ( !a1 )
    return 4294967274LL;
  result = 0;
  *(_BYTE *)(a1 + 992) = a2;
  if ( !a2 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    if ( v4 )
    {
      *(_BYTE *)(v4 + 8411) = 0;
      return 0;
    }
  }
  return result;
}

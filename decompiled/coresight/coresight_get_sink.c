__int64 __fastcall coresight_get_sink(__int64 result)
{
  if ( result )
  {
    result = *(_QWORD *)(*(_QWORD *)(result + 8) - 8LL);
    if ( (*(_DWORD *)(result + 8) | 2) != 2 )
      return 0;
  }
  return result;
}

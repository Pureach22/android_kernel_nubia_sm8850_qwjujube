__int64 __fastcall ulog_time_set(__int64 a1, unsigned __int64 a2)
{
  if ( *(_DWORD *)(a1 + 8428) == a2 )
    return 0;
  if ( a2 < 0x1F4 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 8428) = a2;
  return 0;
}

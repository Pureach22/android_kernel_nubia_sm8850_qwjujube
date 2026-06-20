__int64 __fastcall faultcount_store(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a3 )
    *(_DWORD *)(a1 + 11296) = 0;
  return a3;
}

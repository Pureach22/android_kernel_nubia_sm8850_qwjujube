__int64 __fastcall rndis_set_param_vendor(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0

  result = 0xFFFFFFFFLL;
  if ( a1 )
  {
    if ( a3 )
    {
      *(_DWORD *)(a1 + 48) = a2;
      *(_QWORD *)(a1 + 56) = a3;
      return 0;
    }
  }
  return result;
}

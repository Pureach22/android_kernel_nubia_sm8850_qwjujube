__int64 __fastcall msm_property_install_get_status(__int64 a1)
{
  __int64 result; // x0

  result = 4294967284LL;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 40) == *(_DWORD *)(a1 + 44) )
      return 0;
    else
      return 4294967284LL;
  }
  return result;
}

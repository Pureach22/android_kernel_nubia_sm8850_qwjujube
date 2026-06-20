__int64 __fastcall aiqe_is_client_registered(unsigned int a1, _DWORD *a2)
{
  char v2; // w8
  bool v3; // cc
  __int64 result; // x0

  v2 = a1;
  v3 = a1 > 5;
  result = 0;
  if ( !v3 )
  {
    if ( a2 )
      return (*a2 >> v2) & 1;
  }
  return result;
}

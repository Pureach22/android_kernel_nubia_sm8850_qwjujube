__int64 __fastcall wlansap_get_sec_channel(__int64 result, int a2, _DWORD *a3)
{
  int v3; // w9
  int v4; // w8

  v3 = a2 + 20;
  if ( (unsigned __int8)result != 1 )
    v3 = 0;
  if ( (unsigned __int8)result == 3 )
    v4 = a2 - 20;
  else
    v4 = v3;
  *a3 = v4;
  return result;
}

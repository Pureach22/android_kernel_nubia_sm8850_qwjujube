__int64 __fastcall ipa3_qmi_filter_request_ex_calc_length(__int64 a1)
{
  __int64 v2; // x9
  int v3; // w11
  __int64 result; // x0
  __int64 v5; // x8
  int v6; // w10
  int v7; // w9
  int v8; // w8

  v2 = a1 + 27680;
  if ( *(_BYTE *)a1 && (v3 = *(_DWORD *)(a1 + 4)) != 0 )
    result = (unsigned int)(216 * v3 + 1336);
  else
    result = 1336;
  v5 = a1 + 42032;
  if ( *(_BYTE *)v2 )
  {
    v6 = *(_DWORD *)(v2 + 4);
    if ( v6 )
      result = (unsigned int)(result + 4 * v6);
  }
  if ( *(_BYTE *)(v2 + 520) )
  {
    v7 = *(_DWORD *)(v2 + 524);
    if ( v7 )
      result = (unsigned int)(result + 216 * v7);
  }
  if ( *(_BYTE *)v5 )
  {
    v8 = *(_DWORD *)(v5 + 4);
    if ( v8 )
      return (unsigned int)(result + 4 * v8);
  }
  return result;
}

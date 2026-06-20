__int64 __fastcall dot11f_pack_ie_tpc_request(__int64 a1, _BYTE *a2, _BYTE *a3, __int64 a4, int *a5)
{
  int v5; // w8
  _BYTE *v6; // x2
  int v7; // w9

  if ( *a2 )
  {
    v5 = *a5;
    *a3 = 34;
    v6 = a3 + 1;
    v7 = *a5 + 2;
    *a5 = v7;
    if ( v6 )
      *v6 = v7 - v5 - 2;
  }
  return 0;
}

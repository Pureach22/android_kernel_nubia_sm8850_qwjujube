__int64 __fastcall wcd_mbhc_get_impedance(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // w8
  bool v4; // zf

  *a2 = *(_DWORD *)(a1 + 376);
  v3 = *(_DWORD *)(a1 + 380);
  *a3 = v3;
  if ( v3 )
    v4 = *a2 == 0;
  else
    v4 = 1;
  if ( v4 )
    return 4294967274LL;
  else
    return 0;
}

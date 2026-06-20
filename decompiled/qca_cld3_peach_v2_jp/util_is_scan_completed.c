__int64 __fastcall util_is_scan_completed(__int64 a1, _BYTE *a2)
{
  int v2; // w8
  int v3; // w8

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 == 6 || v2 == 4 )
    goto LABEL_5;
  if ( v2 == 1 )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 == 1 )
    {
LABEL_6:
      *a2 = v3;
      return 1;
    }
LABEL_5:
    LOBYTE(v3) = 0;
    goto LABEL_6;
  }
  *a2 = 0;
  return 0;
}

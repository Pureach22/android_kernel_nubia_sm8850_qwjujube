__int64 __fastcall dot11f_get_packed_ie_he_op(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w10
  int v4; // w8
  int v5; // w9

  if ( !*(_BYTE *)a2 )
    return 0;
  v3 = *a3;
  v4 = *a3 + 6;
  *a3 = v4;
  v5 = *(_DWORD *)(a2 + 1);
  if ( (v5 & 0x40000) == 0 )
  {
    if ( (v5 & 0x80000) == 0 )
      goto LABEL_4;
LABEL_8:
    *a3 = ++v4;
    if ( (*(_DWORD *)(a2 + 1) & 0x200000) == 0 )
      return 0;
    goto LABEL_5;
  }
  v4 = v3 + 9;
  *a3 = v3 + 9;
  v5 = *(_DWORD *)(a2 + 1);
  if ( (v5 & 0x80000) != 0 )
    goto LABEL_8;
LABEL_4:
  if ( (v5 & 0x200000) != 0 )
LABEL_5:
    *a3 = v4 + 5;
  return 0;
}

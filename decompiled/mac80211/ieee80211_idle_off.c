__int64 __fastcall ieee80211_idle_off(unsigned int *a1)
{
  unsigned int v1; // w8

  if ( *(_QWORD *)(*((_QWORD *)a1 + 58) + 472LL) )
  {
    if ( (*((_QWORD *)a1 + 587) & 1) != 0 )
      goto LABEL_3;
LABEL_6:
    v1 = *a1;
    if ( (*a1 & 4) == 0 )
      return 0;
    goto LABEL_7;
  }
  if ( (*((_QWORD *)a1 + 587) & 1) == 0 )
    goto LABEL_6;
LABEL_3:
  v1 = *a1;
  if ( (*a1 & 4) == 0 )
    return 0;
LABEL_7:
  *a1 = v1 & 0xFFFFFFFB;
  return 256;
}

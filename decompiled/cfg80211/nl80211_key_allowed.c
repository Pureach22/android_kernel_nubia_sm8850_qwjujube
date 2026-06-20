__int64 __fastcall nl80211_key_allowed(__int64 a1)
{
  unsigned int v1; // w9
  __int64 result; // x0
  bool v4; // zf

  v1 = *(_DWORD *)(a1 + 8);
  result = 4294967274LL;
  if ( v1 <= 0xD )
  {
    if ( ((1 << v1) & 0x2C60) != 0 )
      return result;
    if ( ((1 << v1) & 0x104) != 0 )
    {
      v4 = (*(_BYTE *)(a1 + 164) & 1) == 0;
      goto LABEL_11;
    }
    if ( v1 == 12 )
      return ~(*(char *)(*(_QWORD *)a1 + 119LL) >> 31) & 0xFFFFFFEA;
  }
  if ( !v1 )
    return result;
  if ( v1 != 1 )
    return 0;
  v4 = *(_QWORD *)(a1 + 280) == 0;
LABEL_11:
  if ( v4 )
    return 4294967229LL;
  else
    return 0;
}

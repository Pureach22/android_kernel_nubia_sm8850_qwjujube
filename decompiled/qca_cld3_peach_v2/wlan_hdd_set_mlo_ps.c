__int64 __fastcall wlan_hdd_set_mlo_ps(__int64 a1, char a2, unsigned int a3, int a4)
{
  __int64 v8; // x23
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10

  if ( !a1 )
    return 4294967274LL;
  if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v8 = a1 + 52840, a1 != -52840)
    || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v8 = a1 + 58928, a1 != -58928)
    || (v9 = *(_QWORD *)(a1 + 1640), result = 4294967274LL, (v9 & 4) != 0) && (v8 = a1 + 65016, a1 != -65016) )
  {
    result = 4294967274LL;
    do
    {
      if ( a4 < 0 || *(unsigned __int8 *)(*(_QWORD *)(v8 + 32) + 93LL) == a4 )
      {
        result = wlan_hdd_set_ps(v8, v8 + 72, a2 & 1, a3);
        if ( (_DWORD)result )
          break;
      }
      if ( (unsigned __int8)(73 * ((unsigned int)(v8 - *(_DWORD *)v8 - 52840) >> 3) + 1) > 2u )
        break;
      v11 = (unsigned __int8)(73 * ((unsigned int)(v8 - *(_DWORD *)v8 - 52840) >> 3) + 1);
      v8 = 0;
      v12 = a1 + 52840 + 6088LL * (unsigned int)v11;
      do
      {
        if ( v8 )
          break;
        v13 = *(_QWORD *)(a1 + 1640) >> v11++;
        v8 = (v13 << 63 >> 63) & v12;
        v12 += 6088;
      }
      while ( v11 != 3 );
    }
    while ( v8 );
  }
  return result;
}

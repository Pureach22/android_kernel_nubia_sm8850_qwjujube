__int64 __fastcall rmnet_wlan_connection_find(__int64 a1)
{
  __int64 *v1; // x8
  int v4; // w9

  v1 = (__int64 *)rmnet_wlan_connection_hash[(unsigned int)(1640531527 * *(_DWORD *)(a1 + 16)) >> 28];
  if ( !v1 )
    return 0;
  while ( 1 )
  {
    if ( (v1[11] & 1) != 0 )
      goto LABEL_7;
    v4 = *((unsigned __int8 *)v1 + 64);
    if ( v4 != *(unsigned __int8 *)(a1 + 32) )
      goto LABEL_7;
    if ( v4 != 4 )
      break;
    if ( *((_DWORD *)v1 + 8) == *(_DWORD *)a1 && *((_DWORD *)v1 + 12) == *(_DWORD *)(a1 + 16) )
      return v1[9];
LABEL_7:
    v1 = (__int64 *)*v1;
    if ( !v1 )
      return 0;
  }
  if ( v1[4] != *(_QWORD *)a1 || v1[5] != *(_QWORD *)(a1 + 8) )
    goto LABEL_7;
  if ( v1[6] != *(_QWORD *)(a1 + 16) || v1[7] != *(_QWORD *)(a1 + 24) )
    goto LABEL_7;
  return v1[9];
}

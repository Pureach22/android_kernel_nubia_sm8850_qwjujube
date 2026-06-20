__int64 __fastcall wma_find_vdev_id_by_addr(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned __int16 v3; // w11
  unsigned __int8 v4; // w8
  __int64 v5; // x12
  int v7; // w11
  int v8; // w12

  v3 = *(_WORD *)(a1 + 162);
  if ( !v3 )
    return 16;
  v4 = 0;
  while ( 1 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * v4);
    if ( v5 )
      break;
LABEL_3:
    if ( v3 <= (unsigned int)++v4 )
      return 16;
  }
  if ( *(_DWORD *)(v5 + 74) != *(_DWORD *)a2 || *(unsigned __int16 *)(v5 + 78) != *(unsigned __int16 *)(a2 + 4) )
  {
    v7 = *(_DWORD *)(v5 + 80);
    v8 = *(unsigned __int16 *)(v5 + 84);
    if ( v7 != *(_DWORD *)a2 || v8 != *(unsigned __int16 *)(a2 + 4) )
    {
      v3 = *(_WORD *)(a1 + 162);
      goto LABEL_3;
    }
  }
  *a3 = v4;
  return 0;
}

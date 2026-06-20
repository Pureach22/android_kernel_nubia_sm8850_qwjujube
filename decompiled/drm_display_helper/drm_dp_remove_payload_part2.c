__int64 __fastcall drm_dp_remove_payload_part2(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x1
  _QWORD *i; // x8
  _QWORD *v6; // t1
  int v8; // w9
  char v9; // w9

  v6 = *(_QWORD **)(a2 + 56);
  v4 = (_QWORD *)(a2 + 56);
  for ( i = v6; i != v4; i = (_QWORD *)*i )
  {
    if ( i - 4 != (_QWORD *)a4 )
    {
      v8 = *((char *)i - 24);
      if ( v8 > *(char *)(a4 + 8) )
        *((_BYTE *)i - 24) = v8 - *(_BYTE *)(a3 + 12);
    }
  }
  *(_BYTE *)(a4 + 8) = -1;
  v9 = *(_BYTE *)(result + 898);
  --*(_BYTE *)(result + 897);
  *(_BYTE *)(result + 898) = v9 - *(_BYTE *)(a3 + 12);
  if ( (*(_BYTE *)(a4 + 20) & 1) != 0 )
    result = drm_dp_mst_put_port_malloc(*(_QWORD *)a4);
  *(_DWORD *)(a4 + 24) = 0;
  return result;
}

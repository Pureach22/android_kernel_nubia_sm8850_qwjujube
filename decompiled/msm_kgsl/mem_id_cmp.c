__int64 __fastcall mem_id_cmp(_DWORD *a1, _DWORD *a2)
{
  unsigned int v2; // w8

  if ( *a1 > *a2 )
    v2 = 1;
  else
    v2 = -1;
  if ( *a1 == *a2 )
    return 0;
  else
    return v2;
}

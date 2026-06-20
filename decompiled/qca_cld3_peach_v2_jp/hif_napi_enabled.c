bool __fastcall hif_napi_enabled(__int64 a1, int a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a1 + 768);
  if ( a2 == -1 )
    return v2 == 3;
  if ( v2 == 3 )
    return (*(_DWORD *)(a1 + 772) >> a2) & 1;
  return 0;
}

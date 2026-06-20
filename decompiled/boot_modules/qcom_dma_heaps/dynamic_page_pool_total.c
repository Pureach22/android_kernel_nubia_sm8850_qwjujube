__int64 __fastcall dynamic_page_pool_total(_DWORD *a1, char a2)
{
  int v2; // w8

  v2 = a1[1];
  if ( (a2 & 1) != 0 )
    v2 += *a1;
  return (unsigned int)(v2 << a1[18]);
}

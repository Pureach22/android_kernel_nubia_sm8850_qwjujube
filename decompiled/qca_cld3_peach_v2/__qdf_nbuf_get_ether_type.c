__int64 __fastcall _qdf_nbuf_get_ether_type(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x8

  v1 = *(unsigned __int16 *)(a1 + 12);
  if ( v1 == 129 )
  {
    v3 = 16;
  }
  else
  {
    if ( v1 != 43144 )
      return *(unsigned __int16 *)(a1 + 12);
    v3 = 20;
  }
  return *(unsigned __int16 *)(a1 + v3);
}

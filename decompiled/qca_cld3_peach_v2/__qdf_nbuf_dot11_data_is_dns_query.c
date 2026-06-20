bool __fastcall _qdf_nbuf_dot11_data_is_dns_query(char *a1)
{
  int v1; // w8
  char *v2; // x8

  if ( *a1 < 0 )
  {
    if ( a1[24] < 0 )
      v1 = 40;
    else
      v1 = 26;
  }
  else
  {
    v1 = 24;
  }
  v2 = &a1[(((unsigned __int8)a1[1] >> 5) & 4 | v1) + (((unsigned __int8)a1[1] >> 3) & 8)];
  return *((_WORD *)v2 + 15) == 13568 && (*((_WORD *)v2 + 19) & 0xF8) == 0;
}

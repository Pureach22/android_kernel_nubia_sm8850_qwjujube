bool __fastcall _qdf_nbuf_dot11_data_is_tcp_rst(char *a1)
{
  int v1; // w8

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
  return a1[(((unsigned __int8)a1[1] >> 5) & 4 | v1) + 41 + (((unsigned __int8)a1[1] >> 3) & 8)] == 4;
}

unsigned __int64 *__fastcall glink_spss_rx_advance(unsigned __int64 *result, int a2)
{
  _DWORD *v2; // x8
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x9

  v2 = (_DWORD *)result[6];
  v3 = *result;
  v4 = (unsigned int)(*v2 + a2);
  if ( *result > v4 )
    LODWORD(v3) = 0;
  *v2 = v4 - v3;
  return result;
}

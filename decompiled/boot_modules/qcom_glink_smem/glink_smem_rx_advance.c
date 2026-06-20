unsigned __int64 *__fastcall glink_smem_rx_advance(unsigned __int64 *result, int a2)
{
  _DWORD *v2; // x8
  unsigned __int64 v3; // x9

  v2 = (_DWORD *)result[6];
  v3 = (unsigned int)(*v2 + a2);
  if ( *result <= v3 )
    LODWORD(v3) = (unsigned int)v3 % (unsigned int)*result;
  *v2 = v3;
  return result;
}

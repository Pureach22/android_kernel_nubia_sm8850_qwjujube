__int64 __fastcall glink_spss_tx_write_one(unsigned __int64 *a1, unsigned int a2, char *src, size_t a4)
{
  size_t v8; // x24
  size_t v9; // x22
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9

  v8 = *a1 - a2;
  if ( v8 >= a4 )
    v9 = a4;
  else
    v9 = *a1 - a2;
  if ( v9 )
    memcpy((void *)(a1[8] + a2), src, v9);
  if ( v8 < a4 )
    memcpy((void *)a1[8], &src[v9], a4 - v9);
  v10 = *a1;
  v11 = (unsigned int)a4 + a2;
  if ( *a1 > v11 )
    LODWORD(v10) = 0;
  return (unsigned int)(v11 - v10);
}

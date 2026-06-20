__int64 __fastcall glink_smem_tx_write_one(unsigned __int64 *a1, unsigned int a2, char *src, size_t a4)
{
  unsigned int v4; // w19
  size_t v5; // x24
  size_t v9; // x23
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9

  v4 = a2;
  v5 = *a1 - a2;
  if ( *a1 < a2 )
  {
    __break(0x800u);
  }
  else
  {
    if ( v5 >= a4 )
      v9 = a4;
    else
      v9 = *a1 - a2;
    if ( v9 )
      memcpy((void *)(a1[8] + a2), src, v9);
    if ( v5 < a4 )
      memcpy((void *)a1[8], &src[v9], a4 - v9);
    v10 = *a1;
    v11 = (unsigned int)a4 + v4;
    if ( *a1 > v11 )
      LODWORD(v10) = 0;
    return (unsigned int)(v11 - v10);
  }
  return v4;
}

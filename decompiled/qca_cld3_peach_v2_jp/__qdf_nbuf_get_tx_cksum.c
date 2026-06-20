__int64 __fastcall _qdf_nbuf_get_tx_cksum(__int64 a1)
{
  int v1; // w9

  v1 = (*(unsigned __int8 *)(a1 + 128) >> 5) & 3;
  if ( v1 == 2 )
    return 3;
  else
    return 2 * (unsigned int)(v1 == 3);
}

__int64 rmnet_qmap_next_txid()
{
  unsigned int v6; // w0
  __int64 result; // x0

  _X8 = &qmap_txid;
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v6 = __ldxr((unsigned int *)&qmap_txid);
    result = v6 + 1;
  }
  while ( __stlxr(result, (unsigned int *)&qmap_txid) );
  __dmb(0xBu);
  return result;
}

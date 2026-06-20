__int64 __fastcall glink_spss_tx_write(unsigned __int64 *a1, void *src, __int64 a3, void *a4)
{
  int v6; // w0
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9

  v6 = glink_spss_tx_write_one((int)a1, *(_DWORD *)a1[7], src);
  result = glink_spss_tx_write_one((int)a1, v6, a4);
  v8 = *a1;
  __dsb(0xEu);
  v9 = ((_DWORD)result + 7) & 0xFFFFFFF8;
  if ( v8 > v9 )
    LODWORD(v8) = 0;
  *(_DWORD *)a1[7] = v9 - v8;
  return result;
}

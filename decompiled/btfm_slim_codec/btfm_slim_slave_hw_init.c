__int64 __fastcall btfm_slim_slave_hw_init(__int64 a1)
{
  unsigned int v3; // w0
  int v4; // w0
  __int64 v5; // x2
  unsigned int v6; // w19
  void *v7; // x0

  if ( !a1 )
    return 4294967274LL;
  v3 = btfm_slim_read(a1, 1, 0);
  if ( (v3 & 0x80000000) != 0 )
    printk(&unk_8870, "btfm_slim_slave_hw_init", v3);
  v4 = btfm_slim_read(a1, 2, 0);
  v5 = (unsigned int)v4;
  v6 = v4 & (v4 >> 31);
  if ( v4 >= 0 )
    v7 = &unk_833A;
  else
    v7 = &unk_8870;
  printk(v7, "btfm_slim_slave_hw_init", v5);
  return v6;
}

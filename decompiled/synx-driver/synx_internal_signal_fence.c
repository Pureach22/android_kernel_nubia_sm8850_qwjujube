__int64 __fastcall synx_internal_signal_fence(
        unsigned int a1,
        char a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x4
  void *v7; // x0
  __int64 v8; // x3

  if ( a1 != 5 )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v6 = a1;
      v7 = &unk_284A4;
      v8 = 4004;
      goto LABEL_10;
    }
    return 4294967274LL;
  }
  v6 = a3;
  if ( (a3 & 0x100000) == 0 )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v7 = &unk_28B2F;
      v8 = 4009;
LABEL_10:
      printk(v7, &unk_29207, "synx_internal_signal_fence", v8, v6, a6);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  return synx_global_recover_index(5, a2 & 1, (unsigned __int16)a3);
}

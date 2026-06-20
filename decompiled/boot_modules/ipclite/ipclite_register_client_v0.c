__int64 __fastcall ipclite_register_client_v0(
        void *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v9; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    synx_client_0 = a1;
    synx_client_1 = a2;
    synx_client_2 = 1;
    if ( (ipclite_debug_level & 0x10) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_EAAB, "ipclite", "ipclite_register_client_v0");
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_5;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_5:
        ipclite_inmem_log("APPS:%s:Client Registration completed\n", (__int64)"LOW", a3, a4, a5, a6, a7, a8, v9);
    }
    return 0;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_F777, "ipclite", "ipclite_register_client_v0");
      if ( (ipclite_debug_control & 4) == 0 )
        return 4294967274LL;
      goto LABEL_10;
    }
    if ( (ipclite_debug_control & 4) != 0 )
LABEL_10:
      ipclite_inmem_log("APPS:%s:Invalid callback pointer\n", (__int64)"ERR", a3, a4, a5, a6, a7, a8, v9);
  }
  return 4294967274LL;
}

__int64 __fastcall synx_internal_recover(unsigned int a1)
{
  unsigned int v2; // w0
  __int64 v3; // x5

  v2 = synx_util_map_client_id_to_core();
  if ( v2 < 8 )
  {
    if ( ((1 << v2) & 0xDC) != 0 )
    {
      return synx_global_recover();
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B417, &unk_29207, "synx_internal_recover", 3976, a1, v3);
      return 4294967201LL;
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_262B5, &unk_29207, "synx_internal_recover", 3964, a1, v3);
    return 4294967274LL;
  }
}

__int64 __fastcall synx_gmem_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  void *v7; // x0
  __int64 v8; // x3

  if ( synx_gmem_2 )
  {
    if ( (get_ipclite_feature(4) & 1) != 0 || (synx_hwlock = hwspin_lock_request_specific(10)) != 0 )
    {
      ipclite_global_test_and_set_bit(0, synx_gmem_0);
      memset((void *)synx_gmem_2, 0, (unsigned int)glcoredata_size);
      return 0;
    }
    if ( (synx_debug & 1) != 0 )
    {
      v7 = &unk_2AE54;
      v8 = 181;
      goto LABEL_9;
    }
  }
  else if ( (synx_debug & 1) != 0 )
  {
    v7 = &unk_267BF;
    v8 = 174;
LABEL_9:
    printk(v7, &unk_29207, "synx_gmem_init", v8, a5, a6);
  }
  return 4294967284LL;
}

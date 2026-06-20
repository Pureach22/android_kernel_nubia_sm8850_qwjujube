__int64 __fastcall synx_internal_notify_recover(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x4

  if ( !qword_25050 || (unsigned __int64)qword_25050 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_262E0, &unk_29207, "synx_internal_notify_recover", 3986, a5, a6);
    return 4294967274LL;
  }
  v6 = a1;
  if ( a1 != 5 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_25D0E, &unk_29207, "synx_internal_notify_recover", 3991, a1, a6);
    return 4294967274LL;
  }
  if ( (synx_debug & 8) != 0 )
    printk(&unk_29470, &unk_2A972, "synx_internal_notify_recover", 3995, 5, a6);
  return synx_global_recover_interop(5, &hwfence_shared_ops, a3, a4, v6);
}

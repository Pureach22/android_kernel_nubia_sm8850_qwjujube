__int64 __fastcall synx_internal_init_ops(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( (unsigned __int64)&synx_internal_ops < 0xFFFFFFFFFFFFF001LL )
  {
    synx_internal_ops = (__int64)synx_internal_uninitialize;
    qword_25120 = (__int64)synx_internal_create;
    qword_25138 = (__int64)synx_internal_signal;
    qword_25170 = (__int64)synx_internal_get_fence;
    qword_25178 = (__int64)synx_internal_release;
    qword_25160 = (__int64)synx_internal_get_status;
    qword_25168 = (__int64)synx_internal_import;
    qword_25188 = (__int64)synx_internal_release_n;
    qword_25190 = (__int64)synx_internal_merge_n;
    qword_25148 = (__int64)synx_internal_merge;
    qword_25150 = (__int64)synx_internal_wait;
    qword_25128 = (__int64)synx_internal_async_wait;
    qword_25130 = (__int64)synx_internal_cancel_async_wait;
    return 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B514, &unk_29207, "synx_internal_init_ops", 4075, a5, a6);
    return 4294967274LL;
  }
}

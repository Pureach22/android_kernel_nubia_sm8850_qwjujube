__int64 __fastcall synx_test_fence_release(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x5

  kfree(*a1);
  result = kfree(a1);
  if ( (synx_debug & 0x80) != 0 )
    return printk(&unk_2864C, &unk_25D36, "synx_test_fence_release", 277, a1, v3);
  return result;
}

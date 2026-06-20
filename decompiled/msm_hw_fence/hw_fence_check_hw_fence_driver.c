__int64 __fastcall hw_fence_check_hw_fence_driver(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30

  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && (*(_BYTE *)(a1 + 8) & 1) != 0 )
    return 0;
  printk(&unk_217EB, "hw_fence_check_hw_fence_driver", 2743, v5, a5);
  return 4294967274LL;
}

__int64 __fastcall hw_fence_check_valid_fctl(
        unsigned __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  void *v7; // x0
  const char *v8; // x1
  __int64 v9; // x2

  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL || (*(_BYTE *)(a1 + 8) & 1) == 0 )
  {
    v7 = &unk_217EB;
    v8 = "hw_fence_check_hw_fence_driver";
    v9 = 2743;
LABEL_11:
    printk(v7, v8, v9, v5, a5);
    return 4294967274LL;
  }
  if ( !a2 || a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = &unk_211E0;
    v8 = "hw_fence_check_valid_client";
    v9 = 2759;
    goto LABEL_11;
  }
  if ( (*(_BYTE *)(a1 + 736) & 1) != 0 )
    return 0;
  printk(&unk_280DF, "hw_fence_check_valid_fctl", 2775, v5, a5);
  return 4294967285LL;
}

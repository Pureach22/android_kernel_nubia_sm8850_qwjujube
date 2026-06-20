__int64 __fastcall hw_fence_interop_to_hw_fence_error(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  unsigned int v6; // w19
  int v8; // w19
  int v9; // w19

  if ( a1 > 5 )
  {
    if ( a1 == 6 )
    {
      v6 = 1;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( a1 == 2 )
  {
    v6 = 0;
    goto LABEL_9;
  }
  if ( a1 )
  {
    if ( a1 != 1 )
    {
LABEL_8:
      v6 = a1;
      goto LABEL_9;
    }
    v8 = a1;
    printk(&unk_2B14E, "hw_fence_interop_to_hw_fence_error", 108, v5, a5);
    a1 = v8;
    v6 = 0;
  }
  else
  {
    v9 = (unsigned __int8)a1;
    printk(&unk_29B07, "hw_fence_interop_to_hw_fence_error", 104, v5, a5);
    a1 = v9;
    v6 = 22;
  }
LABEL_9:
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_294E6, "hw_fence_interop_to_hw_fence_error", 121, (unsigned int)a1, v6);
  return v6;
}

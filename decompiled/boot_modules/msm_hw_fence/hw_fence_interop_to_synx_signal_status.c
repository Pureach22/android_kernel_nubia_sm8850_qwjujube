__int64 __fastcall hw_fence_interop_to_synx_signal_status(unsigned int a1, unsigned int a2)
{
  __int64 v2; // x3
  __int64 result; // x0
  unsigned int v4; // w19

  v2 = a1;
  if ( (a1 & 1) != 0 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
        result = 6;
      else
        result = a2;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
  {
    v4 = result;
    printk(&unk_252B9, "hw_fence_interop_to_synx_signal_status", 93, v2, a2);
    return v4;
  }
  return result;
}

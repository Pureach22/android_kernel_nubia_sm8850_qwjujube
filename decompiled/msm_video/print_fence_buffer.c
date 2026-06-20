__int64 __fastcall print_fence_buffer(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( a3 && a2 && a6 )
  {
    if ( a5 )
    {
      if ( a4 )
      {
        if ( (msm_vidc_debug & (unsigned int)result) != 0 )
          return printk(&unk_81103, a2, a4 + 340, a3, a6 + 16);
      }
    }
    else if ( a4 && (msm_vidc_debug & (unsigned int)result) != 0 )
    {
      return printk(&unk_915A6, a2, a4 + 340, a3, a6 + 16);
    }
  }
  return result;
}

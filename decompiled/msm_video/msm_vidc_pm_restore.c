__int64 __fastcall msm_vidc_pm_restore(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8

  if ( result )
  {
    if ( *(_QWORD *)(result + 136) )
    {
      v1 = result;
      if ( !is_video_device(result) )
        return 0;
      v2 = *(_QWORD *)(v1 + 152);
      if ( v2 )
      {
        if ( *(_QWORD *)(v2 + 4672) )
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_90CDF, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_restore");
          return 0;
        }
        return 4294967201LL;
      }
      else
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_807F4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_restore");
        return 4294967274LL;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

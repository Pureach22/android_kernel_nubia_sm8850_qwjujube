__int64 __fastcall msm_v4l2_m2m_job_abort(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19

  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v5 = result;
      printk(&unk_7FC60, "high", result + 340, "msm_v4l2_m2m_job_abort", a5);
      result = v5;
    }
    return v4l2_m2m_job_finish(*(_QWORD *)(result + 1808), *(_QWORD *)(result + 1816));
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_m2m_job_abort");
  }
  return result;
}

__int64 __fastcall msm_vb2_request_complete(__int64 result)
{
  __int64 v1; // x19
  void *v2; // x0
  __int64 v3; // x20

  if ( !result )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return result;
    v2 = &unk_9283B;
    return printk(v2, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_request_complete");
  }
  v1 = *(_QWORD *)(*(_QWORD *)result + 72LL);
  if ( !v1 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return result;
    v2 = &unk_86867;
    return printk(v2, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_request_complete");
  }
  if ( (msm_vidc_debug & 4) != 0 )
  {
    v3 = result;
    printk(&unk_8B900, "low ", v1 + 340, "msm_vb2_request_complete", *(unsigned int *)(result + 12));
    result = v3;
  }
  return v4l2_ctrl_request_complete(*(_QWORD *)(result + 56), v1 + 1424);
}

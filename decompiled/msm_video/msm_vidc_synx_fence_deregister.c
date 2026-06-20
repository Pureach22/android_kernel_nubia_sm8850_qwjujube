__int64 __fastcall msm_vidc_synx_fence_deregister(__int64 a1)
{
  void *v2; // x0
  const char *v3; // x1

  if ( *(_QWORD *)(a1 + 4624) )
  {
    if ( (unsigned int)synx_uninitialize(*(_QWORD *)(a1 + 6624)) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v2 = &unk_8C31D;
        v3 = "err ";
LABEL_9:
        printk(v2, v3, 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_deregister");
      }
    }
    else if ( (msm_vidc_debug & 2) != 0 )
    {
      v2 = &unk_88709;
      v3 = "high";
      goto LABEL_9;
    }
    *(_QWORD *)(a1 + 6624) = 0;
  }
  return 0;
}

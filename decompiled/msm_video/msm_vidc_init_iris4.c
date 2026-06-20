__int64 __fastcall msm_vidc_init_iris4(__int64 a1)
{
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_iris4");
  *(_QWORD *)(a1 + 6544) = iris4_ops;
  *(_QWORD *)(a1 + 6560) = &msm_session_ops;
  return 0;
}

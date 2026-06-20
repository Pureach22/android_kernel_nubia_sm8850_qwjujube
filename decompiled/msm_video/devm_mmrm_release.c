__int64 __fastcall devm_mmrm_release(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_vidc_debug & 2) != 0 )
  {
    v2 = a1;
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "devm_mmrm_release");
    a1 = v2;
  }
  return mmrm_client_deregister(a1);
}

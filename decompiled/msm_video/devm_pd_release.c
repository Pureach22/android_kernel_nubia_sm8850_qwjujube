__int64 __fastcall devm_pd_release(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_vidc_debug & 2) != 0 )
  {
    v2 = a1;
    printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "devm_pd_release");
    a1 = v2;
  }
  return dev_pm_domain_detach(a1, 1);
}

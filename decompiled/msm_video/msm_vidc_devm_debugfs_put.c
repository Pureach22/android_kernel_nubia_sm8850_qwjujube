__int64 __fastcall msm_vidc_devm_debugfs_put(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_vidc_debug & 2) != 0 )
  {
    v2 = a1;
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_devm_debugfs_put");
    a1 = v2;
  }
  return debugfs_remove(a1);
}

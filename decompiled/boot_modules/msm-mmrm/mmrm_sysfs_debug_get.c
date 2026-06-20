__int64 __fastcall mmrm_sysfs_debug_get(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w19

  v3 = scnprintf(a3, 4096, "0x%x\n", msm_mmrm_debug);
  printk(&unk_C6AD, "mmrm_sysfs_debug_get", (unsigned int)msm_mmrm_debug);
  return v3;
}

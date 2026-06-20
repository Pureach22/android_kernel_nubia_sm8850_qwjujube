__int64 __fastcall mmrm_sysfs_allow_multiple_get(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w19

  v3 = scnprintf(a3, 4096, "0x%x\n", (unsigned __int8)msm_mmrm_allow_multiple_register);
  printk(&unk_C6AD, "mmrm_sysfs_allow_multiple_get", (unsigned __int8)msm_mmrm_allow_multiple_register);
  return v3;
}

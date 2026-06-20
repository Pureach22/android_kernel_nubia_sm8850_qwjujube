__int64 __fastcall debug_level_get_fw(__int64 a1)
{
  return scnprintf(a1, 4096, "%#x", msm_fw_debug);
}

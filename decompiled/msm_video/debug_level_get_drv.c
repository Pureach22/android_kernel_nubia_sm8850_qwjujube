__int64 __fastcall debug_level_get_drv(__int64 a1)
{
  return scnprintf(a1, 4096, "%#x", msm_vidc_debug);
}

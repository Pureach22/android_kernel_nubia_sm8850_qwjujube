__int64 __fastcall fw_dump_get(__int64 a1)
{
  return scnprintf(a1, 4096, "%#x", (unsigned __int8)msm_vidc_fw_dump);
}

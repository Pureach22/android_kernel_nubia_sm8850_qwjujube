__int64 __fastcall sub_2353A4(long double a1, float a2)
{
  short float v2; // h27
  short float v3; // h31

  *(short float *)&a2 = -(short float)(*(short float *)&a2 + (short float)(v3 * v2));
  return wmi_unified_save_fw_version_cmd(a1, a2);
}

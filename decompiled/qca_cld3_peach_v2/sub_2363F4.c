__int64 __fastcall sub_2363F4(long double a1, float a2)
{
  short float v2; // h27
  short float v3; // h31

  *(short float *)&a2 = -(short float)(*(short float *)&a2 + (short float)(v3 * v2));
  return wmi_save_fw_version(a1, a2);
}

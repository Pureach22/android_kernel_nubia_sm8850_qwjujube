__int64 __fastcall sub_231ADC(long double a1, float a2)
{
  short float v2; // h27
  short float v3; // h31

  *(short float *)&a2 = -(short float)(*(short float *)&a2 + (short float)(v3 * v2));
  return check_and_update_fw_version_cmd_tlv(a1, a2);
}

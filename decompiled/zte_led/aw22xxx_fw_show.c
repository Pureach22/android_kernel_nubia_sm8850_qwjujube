__int64 __fastcall aw22xxx_fw_show(int a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "firmware name = %s\n", (const char *)&aw22xxx_fw_name);
}

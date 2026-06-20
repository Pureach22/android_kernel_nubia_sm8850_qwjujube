void *__fastcall pld_get_default_fw_files(char *a1)
{
  void *result; // x0

  result = memset(a1 + 21, 0, 0x8E2u);
  strcpy(a1, "peach_v2/athwlan.bin");
  strcpy(a1 + 255, "peach_v2/fakeboar.bin");
  strcpy(a1 + 510, "peach_v2/otp.bin");
  strcpy(a1 + 765, "peach_v2/utf.bin");
  strcpy(a1 + 1020, "peach_v2/fakeboar.bin");
  strcpy(a1 + 1275, "peach_v2/epping.bin");
  strcpy(a1 + 1785, "peach_v2/athsetup.bin");
  return result;
}

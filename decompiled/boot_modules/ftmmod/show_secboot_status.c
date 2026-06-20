__int64 __fastcall show_secboot_status(__int64 a1, __int64 a2, char *a3)
{
  int v4; // w0

  v4 = is_secboot_device();
  return snprintf(a3, 0x1000u, "%d\n", v4);
}

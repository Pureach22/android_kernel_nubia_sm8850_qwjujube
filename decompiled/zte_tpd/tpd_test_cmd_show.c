__int64 __fastcall tpd_test_cmd_show(__int64 a1, char *a2, __int64 a3)
{
  printk(&unk_34878, "tpd_test_cmd_show", a3);
  return snprintf(a2, 0x1000u, "%d,%d,%d,%d", 0, 16, 37, 0);
}

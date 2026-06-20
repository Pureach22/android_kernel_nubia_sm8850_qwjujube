__int64 __fastcall show_permission_status(__int64 a1, __int64 a2, char *a3)
{
  printk(&unk_665D, a2);
  return snprintf(a3, 0x1000u, "%d\n", 0);
}

__int64 __fastcall tpd_set_palm_mode(__int64 a1, unsigned int a2)
{
  *(_DWORD *)(*(_QWORD *)(a1 + 3072) + 1508LL) = a2;
  printk(unk_37B5F, "tpd_set_palm_mode", a2);
  return 0;
}

__int64 __fastcall tpd_get_singleaodgesture(__int64 a1)
{
  __int64 v2; // x2

  v2 = *(unsigned int *)(*(_QWORD *)(a1 + 3072) + 1460LL);
  *(_DWORD *)(a1 + 1104) = v2;
  printk(unk_32825, "tpd_get_singleaodgesture", v2);
  printk(unk_3A057, "tpd_get_singleaodgesture", *(unsigned int *)(a1 + 1104));
  return 0;
}

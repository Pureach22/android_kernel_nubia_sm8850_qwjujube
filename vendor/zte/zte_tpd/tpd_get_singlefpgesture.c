__int64 __fastcall tpd_get_singlefpgesture(__int64 a1)
{
  __int64 v2; // x2

  v2 = *(unsigned int *)(*(_QWORD *)(a1 + 3072) + 1464LL);
  *(_DWORD *)(a1 + 1100) = v2;
  printk(unk_3A696, "tpd_get_singlefpgesture", v2);
  printk(unk_39C51, "tpd_get_singlefpgesture", *(unsigned int *)(a1 + 1100));
  return 0;
}

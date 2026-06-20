__int64 __fastcall tpd_get_singlegamegesture(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 3072);
  *(_DWORD *)(a1 + 1108) = *(_DWORD *)(v1 + 1464);
  printk(unk_32D26, "tpd_get_singlegamegesture", *(unsigned int *)(v1 + 1468));
  printk(unk_3CE17, "tpd_get_singlegamegesture", *(unsigned int *)(a1 + 1108));
  return 0;
}

__int64 __fastcall tpd_set_singlefpgesture(__int64 a1, int a2, __int64 a3)
{
  _DWORD *v3; // x20
  int v4; // w8
  int v5; // w9
  __int64 v6; // x2

  v3 = *(_DWORD **)(a1 + 3072);
  if ( v3[351] == 1 )
  {
    v4 = v3[365];
    v5 = v3[367];
    v6 = a2 > 0;
    v3[366] = v6;
    v3[364] = v4 | v5 | v6;
  }
  else
  {
    printk(&unk_3B5E0, "tpd_set_singlefpgesture", a3);
    v6 = (unsigned int)v3[366];
  }
  printk(&unk_3526D, "tpd_set_singlefpgesture", v6);
  printk(&unk_33365, "tpd_set_singlefpgesture", (unsigned int)v3[365]);
  printk(&unk_35831, "tpd_set_singlefpgesture", (unsigned int)v3[364]);
  return 0;
}

__int64 __fastcall tpd_set_singlegamegesture(__int64 a1, int a2, __int64 a3)
{
  _DWORD *v3; // x20
  int v4; // w8
  __int64 v5; // x2
  _BOOL4 v6; // w9

  v3 = *(_DWORD **)(a1 + 3072);
  if ( v3[351] == 1 )
  {
    v4 = v3[365];
    v5 = (unsigned int)v3[366];
    v6 = a2 > 0;
    v3[367] = v6;
    v3[364] = v4 | v5 | v6;
  }
  else
  {
    printk(unk_3B5E0, "tpd_set_singlegamegesture", a3);
    v5 = (unsigned int)v3[366];
  }
  printk(unk_3526D, "tpd_set_singlegamegesture", v5);
  printk(unk_33365, "tpd_set_singlegamegesture", (unsigned int)v3[365]);
  printk(unk_3C339, "tpd_set_singlegamegesture", (unsigned int)v3[367]);
  printk(unk_35831, "tpd_set_singlegamegesture", (unsigned int)v3[364]);
  return 0;
}

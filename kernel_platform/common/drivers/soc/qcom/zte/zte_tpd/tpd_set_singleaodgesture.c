__int64 __fastcall tpd_set_singleaodgesture(__int64 a1, int a2, __int64 a3)
{
  _DWORD *v3; // x20
  __int64 v4; // x2
  int v5; // w8
  _BOOL4 v6; // w9

  v3 = *(_DWORD **)(a1 + 3072);
  if ( v3[351] == 1 )
  {
    v4 = (unsigned int)v3[366];
    v5 = v3[367];
    v6 = a2 > 0;
    v3[365] = v6;
    v3[364] = v4 | v5 | v6;
  }
  else
  {
    printk(unk_3B5E0, "tpd_set_singleaodgesture", a3);
    v4 = (unsigned int)v3[366];
  }
  printk(unk_3526D, "tpd_set_singleaodgesture", v4);
  printk(unk_33365, "tpd_set_singleaodgesture", (unsigned int)v3[365]);
  printk(unk_35831, "tpd_set_singleaodgesture", (unsigned int)v3[364]);
  return 0;
}

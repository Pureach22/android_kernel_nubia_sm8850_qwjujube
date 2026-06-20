__int64 __fastcall btfm_swr_dai_get_configs(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  int v3; // w21
  __int64 v6; // x23
  unsigned int v7; // w10
  char v8; // w9
  char v9; // w8
  int v10; // w9
  char v11; // w8
  void *v12; // x0
  char v13; // w19

  v3 = a3;
  v6 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  printk(&unk_77ED, "btfm_swr_dai_get_configs");
  *(_BYTE *)a2 = a3;
  v7 = v3 - 3;
  v8 = usecase_codec;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v6 + 20);
  v9 = *(_DWORD *)(v6 + 24);
  *(_BYTE *)(a2 + 10) = v8;
  *(_BYTE *)(a2 + 8) = v9;
  v10 = *(unsigned __int8 *)(v6 + 30);
  *(_BYTE *)(a2 + 9) = v10;
  if ( v10 == 2 )
    v11 = 3;
  else
    v11 = 1;
  *(_BYTE *)(a2 + 11) = 5;
  *(_BYTE *)(a2 + 13) = v11;
  if ( v7 >= 2 )
    v12 = &unk_738E;
  else
    v12 = &unk_73EE;
  if ( v7 >= 2 )
    v13 = 1;
  else
    v13 = 2;
  printk(v12, "btfm_swr_dai_get_configs");
  *(_BYTE *)(a2 + 12) = v13;
  return 1;
}

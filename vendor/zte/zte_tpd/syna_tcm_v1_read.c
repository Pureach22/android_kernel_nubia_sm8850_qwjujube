__int64 __fastcall syna_tcm_v1_read(__int64 a1, unsigned int a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v5; // w3
  __int64 v7; // x0
  __int64 (*v8)(void); // x8
  unsigned int v9; // w0
  __int64 v10; // x2
  void *v12; // x0
  unsigned int v13; // w20
  void *v14; // x0

  if ( !a3 )
  {
    printk(unk_33DE9, "syna_tcm_v1_read", 0);
    return 4294967055LL;
  }
  if ( !a2 )
    return 0;
  if ( a2 > a4 )
  {
    v12 = unk_3B91C;
LABEL_16:
    printk(v12, "syna_tcm_v1_read", a2);
    return 4294967055LL;
  }
  v5 = *(_DWORD *)(a1 + 60);
  if ( v5 && v5 < a2 )
  {
    v12 = unk_33865;
    goto LABEL_16;
  }
  v7 = *(_QWORD *)(a1 + 72);
  if ( !v7 )
  {
    v13 = -241;
    v14 = unk_37DFA;
LABEL_19:
    printk(v14, "syna_tcm_read", a3);
LABEL_21:
    printk(unk_31A6B, "syna_tcm_v1_read", a2);
    return v13;
  }
  v8 = *(__int64 (**)(void))(v7 + 32);
  if ( !v8 )
  {
    v13 = -245;
    v14 = unk_3617E;
    goto LABEL_19;
  }
  /* CFI check removed */
  v9 = v8();
  if ( (v9 & 0x80000000) != 0 )
  {
    v13 = v9;
    goto LABEL_21;
  }
  v10 = *a3;
  if ( (_DWORD)v10 == 165 )
    return 0;
  printk(unk_3849F, "syna_tcm_v1_read", v10);
  return 4294967054LL;
}

__int64 __fastcall syna_tcm_rezero(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x2
  __int64 (*v4)(void); // x8
  unsigned int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 v8; // x20

  if ( a1 )
  {
    v3 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v3 == 1 )
    {
      if ( !a2 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
      {
        v8 = a1;
        printk(&unk_3BA3F, "syna_tcm_rezero", v3);
        a1 = v8;
      }
      v4 = *(__int64 (**)(void))(a1 + 920);
      if ( *((_DWORD *)v4 - 1) != 606091918 )
        __break(0x8228u);
      v5 = v4();
      result = 0;
      if ( (v5 & 0x80000000) != 0 )
      {
        v7 = v5;
        printk(&unk_39AB7, "syna_tcm_rezero", 39);
        return v7;
      }
    }
    else
    {
      printk(&unk_33E1E, "syna_tcm_rezero", v3);
      return 4294967055LL;
    }
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_rezero", a3);
    return 4294967055LL;
  }
  return result;
}

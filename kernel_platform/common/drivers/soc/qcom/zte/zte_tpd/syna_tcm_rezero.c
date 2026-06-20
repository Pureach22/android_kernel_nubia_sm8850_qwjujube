__int64 __fastcall syna_tcm_rezero(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x2
  __int64 (*v4)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int); // x8
  unsigned int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w19
  __int64 v8; // x20

  if ( a1 )
  {
    v3 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v3 == 1 )
    {
      int delay = a2;
      if ( !a2 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
        {
          printk(unk_3BA3F, "syna_tcm_rezero", v3);
          delay = *(_DWORD *)(a1 + 524);
        }
        else
        {
          delay = 0;
        }
      }
      v4 = *(__int64 (**)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int))(a1 + 920);
      /* CFI check removed */
      v5 = v4(a1, 39, 0, 0, 0, delay);
      result = 0;
      if ( (v5 & 0x80000000) != 0 )
      {
        v7 = v5;
        printk(unk_39AB7, "syna_tcm_rezero", 39);
        return v7;
      }
    }
    else
    {
      printk(unk_33E1E, "syna_tcm_rezero", v3);
      return 4294967055LL;
    }
  }
  else
  {
    printk(unk_3365A, "syna_tcm_rezero", a3);
    return 4294967055LL;
  }
  return result;
}

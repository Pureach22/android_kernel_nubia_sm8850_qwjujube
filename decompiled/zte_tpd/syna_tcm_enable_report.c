__int64 __fastcall syna_tcm_enable_report(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  char v4; // w19
  __int64 v5; // x2
  __int64 (*v6)(void); // x9
  unsigned __int8 v7; // w21
  __int64 result; // x0
  unsigned int v9; // w19
  __int64 v10; // x21

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v4 = a3;
    v5 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v5 == 1 )
    {
      if ( !a4 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
      {
        v10 = a1;
        printk(&unk_3BA3F, "syna_tcm_enable_report", v5);
        a1 = v10;
      }
      v6 = *(__int64 (**)(void))(a1 + 920);
      if ( (v4 & 1) != 0 )
        v7 = 5;
      else
        v7 = 6;
      if ( *((_DWORD *)v6 - 1) != 606091918 )
        __break(0x8229u);
      result = v6();
      if ( (result & 0x80000000) != 0 )
      {
        v9 = result;
        printk(&unk_39ED3, "syna_tcm_enable_report", v7);
        result = v9;
      }
    }
    else
    {
      printk(&unk_33E1E, "syna_tcm_enable_report", v5);
      result = 4294967055LL;
    }
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_enable_report", a3);
    result = 4294967055LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

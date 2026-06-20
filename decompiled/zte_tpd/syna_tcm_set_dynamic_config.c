__int64 __fastcall syna_tcm_set_dynamic_config(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x2
  __int64 (*v5)(void); // x9
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w19
  __int64 v9; // x22

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v4 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v4 == 1 )
    {
      if ( !a4 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
      {
        v9 = a1;
        printk(&unk_3BA3F, "syna_tcm_set_dynamic_config", v4);
        a1 = v9;
      }
      v5 = *(__int64 (**)(void))(a1 + 920);
      if ( *((_DWORD *)v5 - 1) != 606091918 )
        __break(0x8229u);
      v6 = v5();
      if ( (v6 & 0x80000000) != 0 )
      {
        v8 = v6;
        printk(&unk_3CD6C, "syna_tcm_set_dynamic_config", 36);
        result = v8;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      printk(&unk_33E1E, "syna_tcm_set_dynamic_config", v4);
      result = 4294967055LL;
    }
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_set_dynamic_config", a3);
    result = 4294967055LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

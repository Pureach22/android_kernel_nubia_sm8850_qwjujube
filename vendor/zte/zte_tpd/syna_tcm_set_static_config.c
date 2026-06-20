__int64 __fastcall syna_tcm_set_static_config(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v4; // w19
  __int64 v5; // x2
  __int64 (*v6)(void); // x8
  unsigned int v7; // w0
  unsigned int v9; // w19
  __int64 v10; // x22

  if ( a1 )
  {
    v4 = a3;
    v5 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v5 == 1 )
    {
      if ( !a4 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
      {
        v10 = a1;
        printk(unk_3BA3F, "syna_tcm_set_static_config", v5);
        a1 = v10;
      }
      if ( *(unsigned __int16 *)(a1 + 180) == v4 )
      {
        v6 = *(__int64 (**)(void))(a1 + 920);
        /* CFI check removed */
        v7 = v6();
        if ( (v7 & 0x80000000) != 0 )
        {
          v9 = v7;
          printk(unk_39AB7, "syna_tcm_set_static_config", 34);
          return v9;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        printk(unk_3501F, "syna_tcm_set_static_config", v4);
        return 4294967055LL;
      }
    }
    else
    {
      printk(unk_33E1E, "syna_tcm_set_static_config", v5);
      return 4294967055LL;
    }
  }
  else
  {
    printk(unk_3365A, "syna_tcm_set_static_config", a3);
    return 4294967055LL;
  }
}

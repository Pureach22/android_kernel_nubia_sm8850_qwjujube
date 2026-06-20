__int64 __fastcall syna_tcm_set_dynamic_config(__int64 a1, int a2, int a3, int a4)
{
  __int64 v4;
  __int64 (*v5)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int);
  unsigned int v6;
  __int64 result;
  unsigned int v8;
  __int64 v9;
  unsigned char buf[3];

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v4 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v4 == 1 )
    {
      int delay = a4;
      if ( !delay )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) == 0 )
        {
          v9 = a1;
          printk(unk_3BA3F, "syna_tcm_set_dynamic_config", v4);
          a1 = v9;
          delay = *(_DWORD *)(a1 + 524);
        }
      }
      
      buf[0] = a2;
      buf[1] = a3 & 0xFF;
      buf[2] = (a3 >> 8) & 0xFF;

      v5 = *(__int64 (**)(__int64, unsigned char, unsigned char *, unsigned int, unsigned char *, int))(a1 + 920);
      /* CFI check removed */
      v6 = v5(a1, 0x24, buf, 3, NULL, delay);
      if ( (v6 & 0x80000000) != 0 )
      {
        v8 = v6;
        printk(unk_3CD6C, "syna_tcm_set_dynamic_config", 36, a2, a3);
        result = v8;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      printk(unk_33E1E, "syna_tcm_set_dynamic_config", v4);
      result = 4294967055LL;
    }
  }
  else
  {
    printk(unk_3365A, "syna_tcm_set_dynamic_config", a3);
    result = 4294967055LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

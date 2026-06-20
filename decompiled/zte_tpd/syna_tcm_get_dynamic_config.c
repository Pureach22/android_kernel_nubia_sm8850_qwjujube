__int64 __fastcall syna_tcm_get_dynamic_config(__int64 a1, char a2, _WORD *a3, unsigned int a4)
{
  __int64 v5; // x2
  unsigned int v7; // w22
  _DWORD *v9; // x8
  unsigned int v10; // w0
  __int64 v11; // x2
  __int64 result; // x0
  unsigned int v13; // w19
  unsigned int v14; // w19
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v5 == 1 )
    {
      v7 = a4;
      if ( !a4 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
        {
          v7 = 0;
        }
        else
        {
          v7 = *(_DWORD *)(a1 + 524);
          printk(&unk_3BA3F, "syna_tcm_get_dynamic_config", v5);
        }
      }
      v9 = *(_DWORD **)(a1 + 920);
      v15[0] = a2;
      if ( *(v9 - 1) != 606091918 )
        __break(0x8228u);
      v10 = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64, _QWORD, _QWORD))v9)(a1, 35, v15, 1, 0, v7);
      if ( (v10 & 0x80000000) != 0 )
      {
        v13 = v10;
        printk(&unk_31B0B, "syna_tcm_get_dynamic_config", 35);
        result = v13;
      }
      else
      {
        v11 = *(unsigned int *)(a1 + 340);
        if ( (unsigned int)v11 <= 1 )
        {
          v14 = v10;
          printk(&unk_37237, "syna_tcm_get_dynamic_config", v11);
          result = v14;
        }
        else
        {
          result = 0;
          *a3 = **(_WORD **)(a1 + 328);
        }
      }
    }
    else
    {
      printk(&unk_33E1E, "syna_tcm_get_dynamic_config", v5);
      result = 4294967055LL;
    }
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_get_dynamic_config", a3);
    result = 4294967055LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

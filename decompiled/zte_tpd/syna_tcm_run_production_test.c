__int64 __fastcall syna_tcm_run_production_test(__int64 a1, char a2, __int64 a3, unsigned int a4)
{
  __int64 v5; // x2
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 result; // x0
  unsigned int v10; // w0
  __int64 v11; // x2
  unsigned int v12; // w19
  char v13; // w22
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_3365A, "syna_tcm_run_production_test", a3);
    result = 4294967055LL;
    goto LABEL_12;
  }
  v5 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v5 != 1 )
  {
    printk(&unk_33E1E, "syna_tcm_run_production_test", v5);
    result = 4294967055LL;
    goto LABEL_12;
  }
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
      v13 = a2;
      printk(&unk_3BA3F, "syna_tcm_run_production_test", v5);
      a2 = v13;
    }
  }
  v8 = *(_DWORD **)(a1 + 920);
  v14[0] = a2;
  if ( *(v8 - 1) != 606091918 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64, _QWORD, _QWORD))v8)(a1, 42, v14, 1, 0, v7);
  if ( (result & 0x80000000) != 0 )
  {
    v12 = result;
    printk(&unk_39F4B, "syna_tcm_run_production_test", v14[0]);
    goto LABEL_17;
  }
  if ( a3 )
  {
    v10 = syna_tcm_buf_copy_2(a3, a1 + 328);
    if ( (v10 & 0x80000000) == 0 )
    {
      result = 0;
      goto LABEL_12;
    }
    v12 = v10;
    printk(&unk_37261, "syna_tcm_run_production_test", v11);
LABEL_17:
    result = v12;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

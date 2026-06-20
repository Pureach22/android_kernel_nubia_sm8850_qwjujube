__int64 __fastcall aw882xx_dsp_noise_en(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 *v5; // x8
  __int64 v6; // x1
  __int64 *v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x1
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a1 + 52);
  v10 = a2 & 1;
  if ( (unsigned int)v3 >= 8 )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    printk(&unk_27130, v6, "aw882xx_dsp_noise_en");
    result = 4294967274LL;
  }
  else
  {
    result = aw882xx_dsp_write_dsp_msg(a1, dword_29ACC[v3], &v10, 4u);
    if ( (_DWORD)result )
    {
      v7 = *(__int64 **)(a1 + 112);
      v8 = result;
      v9 = v7[14];
      if ( !v9 )
        v9 = *v7;
      printk(&unk_25EB6, v9, "aw882xx_dsp_noise_en");
      result = v8;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

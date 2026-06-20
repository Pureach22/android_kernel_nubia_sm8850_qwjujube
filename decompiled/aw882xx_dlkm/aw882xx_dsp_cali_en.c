__int64 __fastcall aw882xx_dsp_cali_en(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 *v4; // x8
  unsigned int v5; // w20
  __int64 v6; // x1
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a2;
  result = aw882xx_dsp_write_dsp_msg(a1, 1, &v7, 4u);
  if ( (_DWORD)result )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = result;
    v6 = v4[14];
    if ( !v6 )
      v6 = *v4;
    printk(&unk_282E9, v6, "aw882xx_dsp_cali_en");
    result = v5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

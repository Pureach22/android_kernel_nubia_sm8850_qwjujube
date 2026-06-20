__int64 __fastcall aw882xx_dsp_read_cali_re(__int64 a1, int *a2)
{
  unsigned int v3; // w8
  __int64 result; // x0
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 *v8; // x8
  unsigned int v9; // w19
  __int64 v10; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 52);
  v11 = 0;
  if ( v3 >= 8 )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    printk(&unk_27130, v7, "aw882xx_dsp_read_cali_re");
    result = 4294967274LL;
  }
  else
  {
    result = aw882xx_dsp_read_dsp_msg(a1, (__int64)a2, (__int64)&v11, 4u);
    if ( (_DWORD)result )
    {
      v8 = *(__int64 **)(a1 + 112);
      v9 = result;
      v10 = v8[14];
      if ( !v10 )
        v10 = *v8;
      printk(&unk_22494, v10, "aw882xx_dsp_read_cali_re");
      result = v9;
    }
    else
    {
      *a2 = (1000 * v11) >> 12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

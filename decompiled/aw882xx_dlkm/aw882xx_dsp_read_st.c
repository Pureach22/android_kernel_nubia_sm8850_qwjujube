__int64 __fastcall aw882xx_dsp_read_st(__int64 a1, int *a2, _DWORD *a3)
{
  __int64 result; // x0
  _QWORD *v7; // x8
  int v8; // w8
  __int64 v9; // x9
  int v10; // w9
  __int64 *v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x1
  _QWORD v14[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v15[1] = 0;
  v14[0] = 0;
  v14[1] = 0;
  result = aw882xx_dsp_read_dsp_msg(a1, (__int64)a2, (__int64)v14, 0x20u);
  if ( (_DWORD)result )
  {
    v11 = *(__int64 **)(a1 + 112);
    v12 = result;
    v13 = v11[14];
    if ( !v13 )
      v13 = *v11;
    printk(&unk_28995, v13, "aw882xx_dsp_read_st");
    result = v12;
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 52) & 1) != 0 )
      v7 = v15;
    else
      v7 = v14;
    v8 = 1000 * *(_DWORD *)v7;
    v9 = 3;
    if ( (*(_DWORD *)(a1 + 52) & 1) == 0 )
      v9 = 1;
    v10 = v14[v9];
    *a2 = v8 >> 12;
    *a3 = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

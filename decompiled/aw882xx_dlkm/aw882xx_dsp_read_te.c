__int64 __fastcall aw882xx_dsp_read_te(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  _QWORD *v5; // x8
  __int64 *v6; // x8
  unsigned int v7; // w19
  __int64 v8; // x1
  __int64 v9; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v11[2]; // [xsp+20h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[1] = 0;
  v11[0] = 0;
  v9 = 0;
  v10[0] = 0;
  result = aw882xx_dsp_read_dsp_msg(a1, (__int64)a2, (__int64)&v9, 0x20u);
  if ( (_DWORD)result )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = result;
    v8 = v6[14];
    if ( !v8 )
      v8 = *v6;
    printk(&unk_22A14, v8, "aw882xx_dsp_read_te");
    result = v7;
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 52) & 1) != 0 )
      v5 = v11;
    else
      v5 = v10;
    *a2 = *(_DWORD *)v5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

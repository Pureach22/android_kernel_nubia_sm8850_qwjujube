__int64 __fastcall aw882xx_dsp_read_f0_q(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 *v7; // x9
  __int64 v8; // x8
  int v9; // w8
  __int64 *v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x1
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14[0] = 0;
  result = aw882xx_dsp_read_dsp_msg(a1, (__int64)a2, (__int64)&v13, 0x10u);
  if ( (_DWORD)result )
  {
    v10 = *(__int64 **)(a1 + 112);
    v11 = result;
    v12 = v10[14];
    if ( !v12 )
      v12 = *v10;
    printk(&unk_25E90, v12, "aw882xx_dsp_read_f0_q");
    result = v11;
  }
  else
  {
    v7 = v14;
    v8 = 12;
    if ( (*(_DWORD *)(a1 + 52) & 1) == 0 )
    {
      v7 = &v13;
      v8 = 4;
    }
    v9 = *(_DWORD *)((char *)&v14[-1] + v8);
    *a2 = *(_DWORD *)v7;
    *a3 = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

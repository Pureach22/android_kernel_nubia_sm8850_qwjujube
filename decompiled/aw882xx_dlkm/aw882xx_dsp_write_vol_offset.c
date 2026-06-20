__int64 __fastcall aw882xx_dsp_write_vol_offset(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 *v4; // x9
  __int64 v5; // x1
  unsigned int v6; // w19
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a2;
  result = aw_write_msg_to_dsp_v_1_0_0_0(a1, 31, &v7, 4u);
  if ( (_DWORD)result )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    v6 = result;
    printk(&unk_2482F, v5, "aw882xx_dsp_write_vol_offset");
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

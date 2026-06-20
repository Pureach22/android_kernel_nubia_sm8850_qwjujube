__int64 __fastcall aw882xx_dsp_get_dc_status(__int64 a1, __int64 a2)
{
  unsigned int dsp_msg; // w0
  unsigned int *v4; // x8
  __int64 result; // x0
  __int64 *v6; // x8
  unsigned int v7; // w20
  __int64 v8; // x1
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  dsp_msg = aw882xx_dsp_read_dsp_msg(a1, a2, (__int64)v9, 8u);
  if ( dsp_msg )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = dsp_msg;
    v8 = v6[14];
    if ( !v8 )
      v8 = *v6;
    printk(&unk_28DFC, v8, "aw882xx_dsp_get_dc_status");
    result = v7;
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 52) & 1) != 0 )
      v4 = (unsigned int *)v9 + 1;
    else
      v4 = (unsigned int *)v9;
    result = *v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall aw882xx_dsp_algo_ver(__int64 a1, char *a2)
{
  unsigned int dsp_msg; // w0
  __int64 v5; // x1
  unsigned int v6; // w20
  __int64 result; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  dsp_msg = aw882xx_dsp_read_dsp_msg(a1, (__int64)a2, (__int64)&v8, 4u);
  if ( (dsp_msg & 0x80000000) != 0 || !v8 )
  {
    result = aw882xx_dsp_read_dsp_msg(a1, v5, (__int64)a2, 0x50u);
  }
  else
  {
    v6 = dsp_msg;
    snprintf(a2, 0x50u, "aw_algo_v%d.%d.%d.%d", HIBYTE(v8), BYTE2(v8), BYTE1(v8), (unsigned __int8)v8);
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

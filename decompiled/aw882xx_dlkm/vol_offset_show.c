__int64 __fastcall vol_offset_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x8
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v6 = 0;
  aw882xx_dsp_read_vol_offset(*(_QWORD *)(v4 + 96), &v6);
  LODWORD(result) = snprintf(a3, 0x1000u, "voltage offset: %d\n", v6);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}

__int64 __fastcall dsp_re_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x8
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v6 = 0;
  if ( (unsigned int)aw882xx_dev_get_cali_re(*(_QWORD *)(v4 + 96), &v6) )
  {
    result = 20;
    strcpy(a3, "read dsp_re failed!\n");
  }
  else
  {
    result = snprintf(a3, 0x1000u, "%d\n", v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

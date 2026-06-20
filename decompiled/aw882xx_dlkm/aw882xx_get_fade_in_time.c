__int64 __fastcall aw882xx_get_fade_in_time(__int64 a1, __int64 a2)
{
  unsigned int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  aw882xx_dev_get_fade_time(&v4, 1);
  *(_QWORD *)(a2 + 72) = v4;
  _ReadStatusReg(SP_EL0);
  return 0;
}

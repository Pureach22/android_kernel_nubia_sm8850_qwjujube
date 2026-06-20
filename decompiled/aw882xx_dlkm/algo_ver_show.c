__int64 __fastcall algo_ver_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL);
  memset(v6, 0, 80);
  if ( (aw882xx_dsp_algo_ver(v4, v6) & 0x80000000) != 0 )
  {
    result = 26;
    strcpy(a3, "read algo version failed!\n");
  }
  else
  {
    result = snprintf(a3, 0x1000u, "%s\n", (const char *)v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall algo_state_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  _QWORD v6[16]; // [xsp+0h] [xbp-80h] BYREF

  v6[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL);
  memset(v6, 0, 120);
  if ( (aw882xx_dsp_read_run_state_avg(v4, v6, 120) & 0x80000000) != 0 )
  {
    result = 28;
    strcpy(a3, "read algo run state failed!\n");
  }
  else
  {
    result = snprintf(a3, 0x1000u, "%s\n", (const char *)v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

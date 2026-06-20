__int64 __fastcall ufs_qcom_cfg_timers(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  char v3; // w20
  __int64 v4; // x23
  __int64 v5; // x22
  unsigned __int64 rate; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x20

  if ( result )
  {
    v2 = result;
    v3 = a2;
    if ( *(unsigned __int8 *)(*(_QWORD *)(result + 184) + 174LL) > 3u
      || (*(_BYTE *)(result + 3000) & 0x10) != 0 && (*(_BYTE *)(result + 212) & 1) == 0
      || (*(_BYTE *)(result + 138) & 0x80) != 0 && (*(_BYTE *)(result + 213) & 8) == 0 )
    {
      v4 = result + 2664;
      v5 = result + 2664;
      do
      {
        v5 = *(_QWORD *)v5;
        if ( v5 == v4 )
        {
          rate = 0;
          goto LABEL_14;
        }
      }
      while ( strcmp(*(const char **)(v5 + 24), "core_clk") );
      if ( (v3 & 1) != 0 )
        rate = *(unsigned int *)(v5 + 32);
      else
        rate = clk_get_rate(*(_QWORD *)(v5 + 16));
LABEL_14:
      v7 = 1000000;
      if ( rate > 0xF4240 )
        v7 = rate;
      v8 = v7 / 0xF4240;
      result = readl((unsigned int *)(*(_QWORD *)v2 + 192LL));
      if ( (_DWORD)result != (_DWORD)v8 )
      {
        writel(v8, (unsigned int *)(*(_QWORD *)v2 + 192LL));
        return readl((unsigned int *)(*(_QWORD *)v2 + 192LL));
      }
    }
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_core_clk_ctrl(0, a2);
  }
  return result;
}

__int64 __fastcall lpass_bt_swr_mclk_enable(_QWORD *a1, char a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v5; // x19
  unsigned int v6; // w21
  __int64 v7; // x20
  unsigned int v8; // w20
  unsigned int v9; // w21
  __int64 v10; // x19

  v2 = a1[24];
  if ( (a2 & 1) != 0 )
  {
    result = clk_prepare(v2);
    if ( (_DWORD)result )
    {
      if ( (result & 0x80000000) != 0 )
      {
LABEL_14:
        v8 = result;
        if ( (unsigned int)__ratelimit(&lpass_bt_swr_mclk_enable__rs, "lpass_bt_swr_mclk_enable") )
          dev_err(*a1, "%s: bt_swr_clk enable failed\n", "lpass_bt_swr_mclk_enable");
        return v8;
      }
    }
    else
    {
      result = clk_enable(v2);
      if ( (_DWORD)result )
      {
        v6 = result;
        clk_unprepare(v2);
        result = v6;
        if ( (v6 & 0x80000000) != 0 )
          goto LABEL_14;
      }
    }
    v7 = a1[25];
    if ( !v7 )
      return result;
    result = clk_prepare(a1[25]);
    if ( (_DWORD)result )
    {
      if ( (result & 0x80000000) == 0 )
        return result;
      goto LABEL_18;
    }
    result = clk_enable(v7);
    if ( (_DWORD)result )
    {
      v9 = result;
      clk_unprepare(v7);
      result = v9;
      if ( (v9 & 0x80000000) != 0 )
      {
LABEL_18:
        v8 = result;
        if ( (unsigned int)__ratelimit(&lpass_bt_swr_mclk_enable__rs_41, "lpass_bt_swr_mclk_enable") )
          dev_err(*a1, "%s: bt_swr_2x_clk enable failed\n", "lpass_bt_swr_mclk_enable");
        v10 = a1[24];
        clk_disable(v10);
        clk_unprepare(v10);
        return v8;
      }
    }
  }
  else
  {
    clk_disable(v2);
    clk_unprepare(v2);
    v5 = a1[25];
    if ( v5 )
    {
      clk_disable(v5);
      clk_unprepare(v5);
    }
    return 0;
  }
  return result;
}

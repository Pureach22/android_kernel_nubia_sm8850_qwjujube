__int64 __fastcall lpass_bt_swrm_clock(_QWORD *a1, char a2)
{
  __int64 v4; // x0
  int v5; // w8
  unsigned int v6; // w20
  __int64 v7; // x21
  int v8; // w8
  int v9; // w8
  unsigned int active; // w0
  __int64 v11; // x20
  __int64 v12; // x20

  mutex_lock(a1 + 7);
  if ( (a2 & 1) != 0 )
  {
    v4 = _pm_runtime_resume(*a1, 4);
    v5 = *((_DWORD *)a1 + 46);
    if ( v5 )
    {
      v6 = 0;
LABEL_4:
      v7 = *a1;
      *((_DWORD *)a1 + 46) = v5 + 1;
LABEL_24:
      *(_QWORD *)(v7 + 520) = ktime_get_mono_fast_ns(v4);
      _pm_runtime_suspend(*a1, 13);
      goto LABEL_25;
    }
    active = msm_cdc_pinctrl_select_active_state(a1[40]);
    if ( (active & 0x80000000) != 0 )
    {
      v6 = active;
      v4 = __ratelimit(&lpass_bt_swrm_clock__rs, "lpass_bt_swrm_clock");
      if ( (_DWORD)v4 )
        v4 = dev_err(*a1, "%s: bt swr pinctrl enable failed\n", "lpass_bt_swrm_clock");
    }
    else
    {
      v4 = lpass_bt_swr_mclk_enable(a1, 1);
      v6 = v4;
      if ( (v4 & 0x80000000) == 0 )
      {
        v5 = *((_DWORD *)a1 + 46);
        goto LABEL_4;
      }
      msm_cdc_pinctrl_select_sleep_state(a1[40]);
      v4 = __ratelimit(&lpass_bt_swrm_clock__rs_34, "lpass_bt_swrm_clock");
      if ( (_DWORD)v4 )
        v4 = dev_err(*a1, "%s: lpass bt swr request clock enable failed\n", "lpass_bt_swrm_clock");
    }
    v7 = *a1;
    goto LABEL_24;
  }
  v8 = *((_DWORD *)a1 + 46);
  if ( v8 <= 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_bt_swrm_clock__rs_36, "lpass_bt_swrm_clock") )
      dev_err(*a1, "%s: clock already disabled\n", "lpass_bt_swrm_clock");
    v6 = 0;
    *((_DWORD *)a1 + 46) = 0;
  }
  else
  {
    v9 = v8 - 1;
    *((_DWORD *)a1 + 46) = v9;
    if ( v9 )
    {
      v6 = 0;
    }
    else
    {
      v11 = a1[24];
      clk_disable(v11);
      clk_unprepare(v11);
      v12 = a1[25];
      if ( v12 )
      {
        clk_disable(a1[25]);
        clk_unprepare(v12);
      }
      v6 = msm_cdc_pinctrl_select_sleep_state(a1[40]);
      if ( (v6 & 0x80000000) != 0 && (unsigned int)__ratelimit(&lpass_bt_swrm_clock__rs_38, "lpass_bt_swrm_clock") )
        dev_err(*a1, "%s: bt swr pinctrl disable failed\n", "lpass_bt_swrm_clock");
    }
  }
LABEL_25:
  mutex_unlock(a1 + 7);
  return v6;
}

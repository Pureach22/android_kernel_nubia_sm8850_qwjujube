__int64 __fastcall lpass_bt_swr_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x4
  unsigned __int64 v13; // x0
  __int64 v14; // x9
  unsigned __int64 v15; // x8
  __int64 v16; // x0
  int v17; // w0
  _QWORD v18[11]; // [xsp+8h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v18[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_kmalloc(a1 + 16, 424, 3520);
  if ( v3 )
  {
    v5 = v3;
    _init_rwsem(v3 + 344, "&(&priv->notifier)->rwsem", &lpass_bt_swr_probe___key);
    *(_QWORD *)(v5 + 408) = 0;
    *(_QWORD *)v5 = v1;
    *(_BYTE *)(v5 + 152) = 1;
    *(_QWORD *)(v5 + 176) = 0;
    *(_QWORD *)(a1 + 168) = v5;
    _mutex_init(v5 + 8, "&priv->vote_lock", &lpass_bt_swr_probe___key_6);
    _mutex_init(v5 + 56, "&priv->swr_clk_lock", &lpass_bt_swr_probe___key_8);
    _mutex_init(v5 + 104, "&priv->ssr_lock", &lpass_bt_swr_probe___key_10);
    v6 = *(_QWORD *)(a1 + 760);
    memset(v18, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v6, "qcom,bt-swr-gpios", 0, 0, 0, v18) )
      v7 = 0;
    else
      v7 = v18[0];
    *(_QWORD *)(v5 + 320) = v7;
    if ( v7 )
    {
      if ( (msm_cdc_pinctrl_get_state() & 0x80000000) != 0 )
      {
        dev_info(v1, "%s: failed to get swr pin state\n", "lpass_bt_swr_probe");
        result = 4294966779LL;
      }
      else
      {
        v8 = devm_clk_get(v1, "lpass_core_hw_vote");
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
          v9 = v8;
        else
          v9 = 0;
        *(_QWORD *)(v5 + 160) = v9;
        v10 = devm_clk_get(v1, "lpass_audio_hw_vote");
        if ( v10 <= 0xFFFFFFFFFFFFF000LL )
          v11 = v10;
        else
          v11 = 0;
        *(_QWORD *)(v5 + 168) = v11;
        v12 = devm_clk_get(v1, "bt_swr_mclk_clk");
        if ( v12 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(v5 + 192) = v12;
          v13 = devm_clk_get(v1, "bt_swr_mclk_clk_2x");
          v14 = v5 + 280;
          *(_QWORD *)(v5 + 264) = 0;
          *(_QWORD *)(v5 + 272) = 0xFFFFFFFE00000LL;
          if ( v13 <= 0xFFFFFFFFFFFFF000LL )
            v15 = v13;
          else
            v15 = 0;
          *(_QWORD *)(v5 + 200) = v15;
          *(_QWORD *)(v5 + 280) = v14;
          *(_QWORD *)(v5 + 288) = v14;
          *(_QWORD *)(v5 + 296) = lpass_bt_swr_add_child_devices;
          *(_QWORD *)(v5 + 248) = lpass_bt_swrm_clock;
          *(_QWORD *)(v5 + 256) = lpass_bt_swr_core_vote;
          *(_QWORD *)(v5 + 216) = v5;
          *(_QWORD *)(v5 + 224) = 0;
          *(_QWORD *)(v5 + 232) = 0;
          *(_QWORD *)(v5 + 240) = 0;
          lpass_bt_priv = v5;
          pm_runtime_set_autosuspend_delay(v1, 100);
          _pm_runtime_use_autosuspend(v1, 1);
          _pm_runtime_set_status(v1, 2);
          *(_WORD *)(a1 + 504) |= 0x100u;
          pm_runtime_enable(v1);
          queue_work_on(32, system_wq, v5 + 272);
          v16 = *(_QWORD *)v5;
          *(_BYTE *)(v5 + 153) = 1;
          v17 = snd_event_client_register(v16, &lpass_bt_swr_ssr_ops, v5);
          if ( v17 )
          {
            dev_err(v1, "%s: Registration with SND event FWK failed ret = %d\n", "lpass_bt_swr_probe", v17);
          }
          else
          {
            snd_event_notify(*(_QWORD *)v5, 1);
            dev_err(v1, "%s: Registered SSR ops\n", "lpass_bt_swr_probe");
          }
          result = 0;
        }
        else
        {
          dev_err(v1, "%s: clk get %s failed %d\n", "lpass_bt_swr_probe", "bt_swr_clk", v12);
          result = 4294967274LL;
        }
      }
    }
    else
    {
      dev_err(v1, "%s: swr_gpios handle not provided!\n", "lpass_bt_swr_probe");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

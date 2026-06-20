__int64 __fastcall msm_common_snd_shutdown(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 pdata; // x0
  __int64 v5; // x23
  __int64 v6; // x20
  const char *v7; // x22
  __int64 result; // x0
  int v9; // w25
  unsigned int v10; // w21
  __int64 v11; // x23
  __int64 v12; // x8
  unsigned int v19; // w11
  size_t v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x2
  __int64 v23; // x2
  void *v24; // x0
  size_t v25; // x0
  unsigned int v26; // w0
  const char *v28; // x1
  unsigned int v30; // w10
  __int64 v31; // x9
  unsigned int v34; // w12
  int v35; // w0
  _QWORD v36[3]; // [xsp+8h] [xbp-18h] BYREF

  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v3 = *(_QWORD *)(v2 + 8);
  pdata = msm_common_get_pdata(v3);
  v5 = *(_QWORD *)(a1 + 192);
  v6 = pdata;
  v7 = *(const char **)(*(_QWORD *)(v2 + 16) + 8LL);
  result = get_mi2s_tdm_auxpcm_intf_index(v7);
  v9 = *(_DWORD *)(v5 + 108);
  v36[0] = 0;
  v36[1] = 0;
  if ( !v6 )
  {
    result = dev_err(*(_QWORD *)(v3 + 72), "%s: pdata is NULL\n", "msm_common_snd_shutdown");
    goto LABEL_47;
  }
  v10 = result;
  if ( (result & 0x80000000) == 0 )
  {
    v11 = v6 + 48LL * (unsigned int)result;
    mutex_lock(v11 + 216);
    v12 = v6 + 584;
    _X9 = (unsigned int *)(v6 + 584 + 4LL * v10);
    __asm { PRFM            #0x11, [X9] }
    do
      v19 = __ldxr(_X9);
    while ( __stxr(v19 - 1, _X9) );
    if ( *(_DWORD *)(v12 + 4LL * v10) )
    {
      if ( (*(_DWORD *)(v12 + 4LL * v10) & 0x80000000) != 0 )
        *(_DWORD *)(v12 + 4LL * v10) = 0;
      goto LABEL_38;
    }
    v20 = strlen(v7);
    if ( strnstr(v7, "TDM", v20) )
    {
      if ( v10 < 7 )
      {
        LODWORD(v36[0]) = dword_14508[v10];
        v21 = audio_prm_set_lpass_clk_cfg(v36, 0);
        if ( (v21 & 0x80000000) == 0 )
          goto LABEL_16;
        v23 = v21;
        v24 = &unk_139EC;
LABEL_34:
        printk(v24, "msm_common_snd_shutdown", v23);
LABEL_16:
        if ( !*(_DWORD *)(v6 + 4LL * v10 + 624) )
          goto LABEL_38;
        if ( v9 > 176399 )
        {
          if ( v9 != 176400 && v9 != 352800 )
          {
LABEL_23:
            if ( v10 == 4 )
              goto LABEL_24;
LABEL_38:
            if ( *(_QWORD *)(v6 + 160 + 8LL * v10) )
            {
              v31 = v6 + 556;
              _X10 = (unsigned int *)(v6 + 556 + 4LL * v10);
              __asm { PRFM            #0x11, [X10] }
              do
                v34 = __ldxr(_X10);
              while ( __stxr(v34 - 1, _X10) );
              if ( *(_DWORD *)(v31 + 4LL * v10) )
              {
                if ( (*(_DWORD *)(v31 + 4LL * v10) & 0x80000000) != 0 )
                  *(_DWORD *)(v31 + 4LL * v10) = 0;
              }
              else
              {
                v35 = msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(v6 + 160 + 8LL * v10));
                if ( v35 )
                  dev_err(*(_QWORD *)(v3 + 72), "%s: pinctrl set actv fail %d\n", "msm_common_snd_shutdown", v35);
              }
            }
            result = mutex_unlock(v11 + 216);
            goto LABEL_47;
          }
        }
        else if ( v9 != 44100 && v9 != 88200 )
        {
          goto LABEL_23;
        }
LABEL_24:
        if ( *(_QWORD *)(v6 + 616) )
        {
          _X8 = (unsigned int *)(v6 + 612);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 - 1, _X8) );
          if ( *(_DWORD *)(v6 + 612) )
          {
            if ( (*(_DWORD *)(v6 + 612) & 0x80000000) != 0 )
              *(_DWORD *)(v6 + 612) = 0;
          }
          else
          {
            digital_cdc_rsc_mgr_hw_vote_disable(*(_QWORD *)(v6 + 616), 0);
          }
        }
        else
        {
          printk(&unk_128BB, "mi2s_tdm_hw_vote_req", v22);
        }
        goto LABEL_38;
      }
      v28 = "get_tdm_clk_id";
    }
    else
    {
      v25 = strlen(v7);
      if ( !strnstr(v7, "MI2S", v25) )
      {
        printk(&unk_1267C, "msm_common_snd_shutdown", v7);
        goto LABEL_16;
      }
      if ( v10 < 7 )
      {
        LODWORD(v36[0]) = dword_14524[v10];
        v26 = audio_prm_set_lpass_clk_cfg(v36, 0);
        if ( (v26 & 0x80000000) == 0 )
          goto LABEL_16;
        v23 = v26;
        v24 = &unk_124B2;
        goto LABEL_34;
      }
      v28 = "get_mi2s_clk_id";
    }
    printk(&unk_12C5D, v28, v10);
    goto LABEL_16;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall msm_common_snd_startup(__int64 a1)
{
  __int64 v1; // x22
  __int64 pdata; // x19
  unsigned int mi2s_tdm_auxpcm_intf_index; // w0
  unsigned int v5; // w20
  __int64 v6; // x21
  __int64 v7; // x20
  unsigned int active; // w0
  unsigned int v10; // w19
  unsigned int v17; // w9

  v1 = *(_QWORD *)(a1 + 16);
  pdata = msm_common_get_pdata(*(_QWORD *)(v1 + 8));
  mi2s_tdm_auxpcm_intf_index = get_mi2s_tdm_auxpcm_intf_index(*(const char **)(*(_QWORD *)(v1 + 16) + 8LL));
  if ( !pdata )
  {
    dev_err(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 72LL), "%s: pdata is NULL\n", "msm_common_snd_startup");
    return (unsigned int)-22;
  }
  v5 = mi2s_tdm_auxpcm_intf_index;
  if ( (*(_WORD *)(*(_QWORD *)(v1 + 16) + 144LL) & 0x80) == 0 )
    snd_soc_set_runtime_hwparams(a1, &dummy_dma_hardware);
  if ( (v5 & 0x80000000) != 0 )
    return 0;
  v6 = pdata + 48LL * v5;
  mutex_lock(v6 + 216);
  if ( *(_QWORD *)(pdata + 8LL * v5 + 160) )
  {
    v7 = pdata + 4LL * v5;
    if ( !*(_DWORD *)(v7 + 556) )
    {
      active = msm_cdc_pinctrl_select_active_state();
      if ( active )
      {
        v10 = active;
        printk(&unk_13396, "msm_common_snd_startup", active);
        goto LABEL_10;
      }
    }
    _X8 = (unsigned int *)(v7 + 556);
    __asm { PRFM            #0x11, [X8] }
    do
      v17 = __ldxr(_X8);
    while ( __stxr(v17 + 1, _X8) );
  }
  v10 = 0;
LABEL_10:
  mutex_unlock(v6 + 216);
  return v10;
}

__int64 __fastcall wcd9378_codec_enable_aux_pa(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned __int64 *v4; // x20
  void (__fastcall *v5)(unsigned __int64, __int64, __int64); // x8
  unsigned __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x19
  void (__fastcall *v10)(unsigned __int64, __int64, __int64); // x8
  unsigned __int64 v11; // x0
  _QWORD *v12; // x0
  __int64 v13; // x1
  unsigned __int64 v14; // x0
  __int64 virq; // x0
  __int64 v16; // x0
  unsigned int v17; // w8
  __int64 result; // x0
  unsigned int v19; // w19
  void (__fastcall *v20)(unsigned __int64, __int64, __int64); // x8
  unsigned __int64 v21; // x0
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x9
  unsigned __int64 v34; // x10

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int64 **)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( (_DWORD)a3 == 8 )
  {
    v9 = v4[2];
    mutex_lock(v4 + 29);
    if ( (v9 & 0x400) != 0 )
    {
      _X8 = v4 + 2;
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr(_X8);
      while ( __stxr(v34 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
      mutex_unlock(v4 + 29);
      if ( (v4[2] & 0x1000) != 0 )
        return 0;
      v20 = (void (__fastcall *)(unsigned __int64, __int64, __int64))v4[404];
      if ( v20 )
      {
        v21 = v4[403];
        if ( *((_DWORD *)v20 - 1) != -17866579 )
          __break(0x8228u);
        v20(v21, 1, 65537);
      }
      v12 = v4 + 51;
      v13 = 14;
    }
    else
    {
      _X8 = v4 + 2;
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
      mutex_unlock(v4 + 29);
      v10 = (void (__fastcall *)(unsigned __int64, __int64, __int64))v4[404];
      if ( v10 )
      {
        v11 = v4[403];
        if ( *((_DWORD *)v10 - 1) != -17866579 )
          __break(0x8228u);
        v10(v11, 1, 131073);
      }
      v12 = v4 + 51;
      v13 = 15;
    }
    wcd_disable_irq(v12, v13);
    return 0;
  }
  if ( (_DWORD)a3 != 1 )
    return 0;
  swr_slvdev_datapath_control(v4[7], *(unsigned __int8 *)(v4[7] + 64), a3);
  v5 = (void (__fastcall *)(unsigned __int64, __int64, __int64))v4[404];
  if ( (v4[2] & 0x400) != 0 )
  {
    if ( v5 )
    {
      v14 = v4[403];
      if ( *((_DWORD *)v5 - 1) != -17866579 )
        __break(0x8228u);
      v5(v14, 1, 0x10000);
    }
    virq = regmap_irq_get_virq(v4[54], 14);
    v16 = irq_to_desc(virq);
    if ( !v16 || *(_DWORD *)(v16 + 136) )
      wcd_enable_irq(v4 + 51, 14);
    _X8 = v4 + 57;
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 | 0x800, _X8) );
  }
  else
  {
    if ( v5 )
    {
      v6 = v4[403];
      if ( *((_DWORD *)v5 - 1) != -17866579 )
        __break(0x8228u);
      v5(v6, 1, 0x20000);
    }
    v7 = regmap_irq_get_virq(v4[54], 15);
    v8 = irq_to_desc(v7);
    if ( !v8 || *(_DWORD *)(v8 + 136) )
      wcd_enable_irq(v4 + 51, 15);
  }
  v17 = wcd9378_pde_act_ps_check(v3 - 208, 1082655744, 0);
  result = 0;
  if ( v17 )
  {
    v19 = v17;
    dev_err(*(_QWORD *)(v3 - 184), "%s: SA sequencer power on failed\n", "wcd9378_codec_enable_aux_pa");
    return v19;
  }
  return result;
}

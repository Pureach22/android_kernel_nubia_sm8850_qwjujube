__int64 __fastcall wcd_mbhc_elec_hs_report_unplug(_QWORD *a1)
{
  _DWORD *v2; // x8
  _DWORD *v3; // x8
  __int64 v4; // x1
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 result; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 (__fastcall *v14)(__int64, __int64, __int64); // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v24; // x9

  if ( (cancel_delayed_work_sync(a1) & 1) != 0 )
  {
    v2 = *(_DWORD **)(a1[15] + 144LL);
    if ( *(v2 - 1) != 1996337026 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v2)(a1, 0);
  }
  v3 = *(_DWORD **)(a1[115] + 32LL);
  if ( v3 )
  {
    if ( *(v3 - 1) != -794314397 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD *))v3)(a1, a1 + 100);
  }
  else
  {
    printk(&unk_E3F3, "wcd_mbhc_elec_hs_report_unplug");
  }
  wcd_mbhc_report_plug((__int64)a1, 1, 4);
  extcon_set_state_sync(a1[121], 23, 1);
  if ( (a1[45] & 1) != 0 )
    wcd_mbhc_set_and_turnoff_hph_padac(a1);
  if ( (mutex_is_locked(a1 + 93) & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
  {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
    __break(0x800u);
  }
  v4 = *(unsigned int *)(a1[99] + 16LL);
  if ( (a1[113] & 2) != 0 )
  {
    v5 = a1[27];
    v6 = *(_DWORD **)(a1[15] + 112LL);
    if ( *(v6 - 1) != 542830841 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v6)(v5, v4, 0);
    _X8 = a1 + 113;
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  wcd_enable_curr_micbias(a1, 3);
  v7 = a1[107];
  v8 = *(unsigned int *)(v7 + 184);
  if ( (_DWORD)v8 )
  {
    snd_soc_component_update_bits(a1[27], v8, *(unsigned __int8 *)(v7 + 188), 0);
    v7 = a1[107];
  }
  v9 = *(unsigned int *)(v7 + 168);
  if ( (_DWORD)v9 )
  {
    snd_soc_component_update_bits(a1[27], v9, *(unsigned __int8 *)(v7 + 172), (unsigned int)(3 << *(_BYTE *)(v7 + 173)));
    v7 = a1[107];
  }
  v10 = *(unsigned int *)(v7 + 72);
  if ( (_DWORD)v10 )
    snd_soc_component_update_bits(a1[27], v10, *(unsigned __int8 *)(v7 + 76), (unsigned int)(1 << *(_BYTE *)(v7 + 77)));
  result = mutex_is_locked(a1 + 93);
  if ( (result & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
  {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    result = _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
    __break(0x800u);
  }
  v12 = *(unsigned int *)(a1[99] + 12LL);
  if ( (a1[113] & 1) == 0 )
  {
    v13 = a1[27];
    v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1[15] + 112LL);
    if ( *((_DWORD *)v14 - 1) != 542830841 )
      __break(0x8228u);
    result = v14(v13, v12, 1);
    _X8 = a1 + 113;
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 | 1, _X8) );
  }
  return result;
}

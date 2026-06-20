__int64 __fastcall wcd_mbhc_adc_detect_plug_type(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  __int64 v4; // x8
  __int64 v5; // x1
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x8
  void (__fastcall *v8)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 216);
  if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd_mbhc_adc_detect_plug_type___already_done & 1) == 0 )
  {
    wcd_mbhc_adc_detect_plug_type___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_adc_detect_plug_type");
    __break(0x800u);
  }
  v3 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 256LL);
  if ( v3 )
  {
    if ( *(v3 - 1) != -1918869124 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v3)(v2, 0);
  }
  v4 = *(_QWORD *)(a1 + 856);
  v5 = *(unsigned int *)(v4 + 760);
  if ( (_DWORD)v5 )
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v5, *(unsigned __int8 *)(v4 + 764), 0);
  v6 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 208LL);
  if ( !v6 )
    return printk(&unk_DD61, "wcd_mbhc_adc_detect_plug_type");
  if ( *((_DWORD *)v6 - 1) != -1208669315 )
    __break(0x8228u);
  v6(v2, 2, 2);
  *(_DWORD *)(a1 + 864) = 0;
  if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd_schedule_hs_detect_plug___already_done & 1) == 0 )
  {
    wcd_schedule_hs_detect_plug___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd_schedule_hs_detect_plug");
    __break(0x800u);
  }
  v7 = *(_QWORD *)(a1 + 120);
  *(_BYTE *)(a1 + 206) = 0;
  v8 = *(void (__fastcall **)(__int64, __int64))(v7 + 144);
  if ( *((_DWORD *)v8 - 1) != 1996337026 )
    __break(0x8228u);
  v8(a1, 1);
  return queue_work_on(32, system_wq, a1 + 800);
}

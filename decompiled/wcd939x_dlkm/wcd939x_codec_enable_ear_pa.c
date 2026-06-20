__int64 __fastcall wcd939x_codec_enable_ear_pa(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  _QWORD *v7; // x20
  void (__fastcall *v8)(__int64, __int64, __int64); // x8
  __int64 v9; // x0
  unsigned int v10; // w20
  void (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x0

  result = 0;
  v5 = *(_QWORD *)(a1 + 40);
  v6 = v5 - 208;
  v7 = *(_QWORD **)(*(_QWORD *)(v5 - 184) + 152LL);
  if ( (int)a3 > 3 )
  {
    if ( (_DWORD)a3 == 4 )
    {
      wcd_disable_irq(v7 + 41, 13);
      v11 = (void (__fastcall *)(__int64, __int64, __int64))v7[394];
      if ( v11 )
      {
        v12 = v7[393];
        if ( *((_DWORD *)v11 - 1) != -17866579 )
          __break(0x8228u);
        v11(v12, 1, 131073);
      }
    }
    else
    {
      if ( (_DWORD)a3 != 8 )
        return result;
      snd_soc_component_update_bits(v5 - 208, 12299, 128, 0);
      usleep_range_state(7000, 7010, 2);
      snd_soc_component_update_bits(v6, 13413, 7, 0);
      wcd_cls_h_fsm(v6, v7 + 28, 2, 1, 6);
    }
  }
  else
  {
    if ( (_DWORD)a3 == 1 )
    {
      v10 = swr_slvdev_datapath_control(v7[5], *(unsigned __int8 *)(v7[5] + 64LL), a3);
      snd_soc_component_update_bits(v6, 13413, 7, 3);
      snd_soc_component_update_bits(v6, 12296, 2, 2);
      snd_soc_component_update_bits(v6, 12299, 128, 128);
      return v10;
    }
    if ( (_DWORD)a3 != 2 )
      return result;
    usleep_range_state(6000, 6010, a3);
    v8 = (void (__fastcall *)(__int64, __int64, __int64))v7[394];
    if ( v8 )
    {
      v9 = v7[393];
      if ( *((_DWORD *)v8 - 1) != -17866579 )
        __break(0x8228u);
      v8(v9, 1, 0x20000);
    }
    wcd_enable_irq(v7 + 41, 13);
  }
  return 0;
}

__int64 __fastcall wcd938x_codec_enable_aux_pa(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x21
  unsigned int v8; // w20
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x0
  int v11; // w8
  unsigned int v12; // w20
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0

  result = 0;
  v5 = *(_QWORD *)(a1 + 40);
  v6 = v5 - 208;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v8 = *(_DWORD *)(v7 + 264);
  if ( (int)a3 <= 3 )
  {
    if ( (_DWORD)a3 == 1 )
    {
      v12 = swr_slvdev_datapath_control(*(_QWORD *)(v7 + 40), *(unsigned __int8 *)(*(_QWORD *)(v7 + 40) + 64LL), a3);
      snd_soc_component_update_bits(v6, 13415, 1, 1);
      return v12;
    }
    if ( (_DWORD)a3 != 2 )
      return result;
    usleep_range_state(1000, 1010, a3);
    if ( v8 <= 8 && ((1 << v8) & 0x1C8) != 0 )
      snd_soc_component_update_bits(v6, 12296, 2, 2);
    v9 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v7 + 3120);
      if ( *((_DWORD *)v9 - 1) != -17866579 )
        __break(0x8228u);
      v9(v10, 1, 0x20000);
    }
    wcd_enable_irq(v7 + 304, 15);
    return 0;
  }
  if ( (_DWORD)a3 == 4 )
  {
    wcd_disable_irq(v7 + 304, 15);
    v13 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v7 + 3120);
      if ( *((_DWORD *)v13 - 1) != -17866579 )
        __break(0x8228u);
      v13(v14, 1, 131073);
    }
    return 0;
  }
  if ( (_DWORD)a3 == 8 )
  {
    usleep_range_state(1000, 1010, 2);
    snd_soc_component_update_bits(v6, 13415, 1, 0);
    wcd_cls_h_fsm(v6, v7 + 224, 2, 8, v8);
    result = 0;
    v11 = *(_DWORD *)(v7 + 3184) - 1;
    *(_DWORD *)(v7 + 3184) = v11;
    if ( !v11 )
    {
      snd_soc_component_update_bits(v6, 12452, 4, 4);
      return 0;
    }
  }
  return result;
}

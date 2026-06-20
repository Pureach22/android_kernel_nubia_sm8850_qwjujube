__int64 __fastcall wcd938x_codec_enable_ear_pa(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x21
  unsigned int v8; // w20
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x0
  unsigned int v11; // w20
  int v12; // w0
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x0
  int v17; // w8
  unsigned __int64 v24; // x10
  unsigned __int64 v27; // x9

  result = 0;
  v5 = *(_QWORD *)(a1 + 40);
  v6 = v5 - 208;
  v7 = *(_QWORD *)(*(_QWORD *)(v5 - 184) + 152LL);
  v8 = *(_DWORD *)(v7 + 264);
  if ( (int)a3 <= 3 )
  {
    if ( (_DWORD)a3 != 1 )
    {
      if ( (_DWORD)a3 != 2 )
        return result;
      usleep_range_state(6000, 6010, a3);
      if ( v8 <= 8 && ((1 << v8) & 0x1C8) != 0 )
        snd_soc_component_update_bits(v6, 12296, 2, 2);
      v9 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
      if ( (*(_BYTE *)(v7 + 3188) & 1) != 0 )
      {
        if ( v9 )
        {
          v16 = *(_QWORD *)(v7 + 3120);
          if ( *((_DWORD *)v9 - 1) != -17866579 )
            __break(0x8228u);
          v9(v16, 1, 0x20000);
        }
        wcd_enable_irq(v7 + 304, 15);
      }
      else
      {
        if ( v9 )
        {
          v10 = *(_QWORD *)(v7 + 3120);
          if ( *((_DWORD *)v9 - 1) != -17866579 )
            __break(0x8228u);
          v9(v10, 1, 0);
        }
        wcd_enable_irq(v7 + 304, 13);
      }
      return 0;
    }
    v11 = swr_slvdev_datapath_control(*(_QWORD *)(v7 + 40), *(unsigned __int8 *)(*(_QWORD *)(v7 + 40) + 64LL), a3);
    v12 = snd_soc_component_read(v6, 13392);
    *(_DWORD *)(v7 + 3188) = v12;
    if ( (v12 & 1) != 0 )
    {
      snd_soc_component_update_bits(v6, 13415, 1, 1);
      if ( (*(_BYTE *)(v7 + 288) & 1) == 0 )
      {
LABEL_21:
        snd_soc_component_update_bits(v6, 12299, 128, 128);
        return v11;
      }
    }
    else
    {
      snd_soc_component_update_bits(v6, 13413, 7, 3);
      _X8 = (unsigned __int64 *)(v7 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x4000, _X8) );
      if ( (*(_BYTE *)(v7 + 288) & 1) == 0 )
        goto LABEL_21;
    }
    return v11;
  }
  if ( (_DWORD)a3 == 4 )
  {
    if ( (*(_BYTE *)(v7 + 3188) & 1) != 0 )
    {
      wcd_disable_irq(v7 + 304, 15);
      v13 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
      if ( !v13 )
        return 0;
      v14 = *(_QWORD *)(v7 + 3120);
      v15 = 131073;
    }
    else
    {
      if ( (*(_QWORD *)(v7 + 352) & 0x2000) != 0 )
        return 0;
      wcd_disable_irq(v7 + 304, 13);
      v13 = *(void (__fastcall **)(__int64, __int64, __int64))(v7 + 3128);
      if ( !v13 )
        return 0;
      v14 = *(_QWORD *)(v7 + 3120);
      v15 = 1;
    }
    if ( *((_DWORD *)v13 - 1) != -17866579 )
      __break(0x8228u);
    v13(v14, 1, v15);
    return 0;
  }
  if ( (_DWORD)a3 != 8 )
    return result;
  if ( (*(_BYTE *)(v7 + 288) & 1) == 0 )
    snd_soc_component_update_bits(v6, 12299, 128, 0);
  usleep_range_state(7000, 7010, 2);
  if ( (*(_BYTE *)(v7 + 3188) & 1) != 0 )
  {
    snd_soc_component_update_bits(v6, 13415, 1, 0);
  }
  else
  {
    snd_soc_component_update_bits(v6, 13413, 7, 0);
    _X8 = (unsigned __int64 *)(v7 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 & 0xFFFFFFFFFFFFBFFFLL, _X8) );
  }
  wcd_cls_h_fsm(v6, v7 + 224, 2, 1, v8);
  v17 = *(_DWORD *)(v7 + 3184) - 1;
  *(_DWORD *)(v7 + 3184) = v17;
  if ( !v17 )
    snd_soc_component_update_bits(v6, 12452, 4, 4);
  return 0;
}

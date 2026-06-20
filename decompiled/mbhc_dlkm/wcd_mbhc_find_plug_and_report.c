__int64 __fastcall wcd_mbhc_find_plug_and_report(__int64 a1, int a2)
{
  __int64 result; // x0
  int v5; // w1
  __int64 v6; // x0
  __int64 v7; // x1
  void (__fastcall *v8)(_QWORD); // x8
  int v9; // w20
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x0
  __int64 (__fastcall *v17)(__int64, __int64, __int64); // x8
  unsigned __int64 v24; // x9

  if ( *(_BYTE *)(a1 + 896) == 1 )
    return printk(&unk_DCC3, "wcd_mbhc_find_plug_and_report");
  result = mutex_is_locked(a1 + 744);
  if ( (result & 1) == 0 && (wcd_mbhc_find_plug_and_report___already_done & 1) == 0 )
  {
    wcd_mbhc_find_plug_and_report___already_done = 1;
    result = _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_find_plug_and_report");
    __break(0x800u);
  }
  v5 = *(unsigned __int8 *)(a1 + 161);
  if ( v5 != a2 )
  {
    if ( a2 <= 2 )
    {
      if ( a2 == 1 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 112) + 84LL) == 1 )
        {
          v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 920) + 24LL);
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != -9629763 )
              __break(0x8228u);
            v8(a1);
          }
        }
        wcd_mbhc_report_plug(a1, 1, 3);
        v6 = *(_QWORD *)(a1 + 968);
        v7 = 20;
        return extcon_set_state_sync(v6, v7, 1);
      }
      if ( a2 == 2 )
      {
        wcd_mbhc_report_plug(a1, 1, 1);
        v6 = *(_QWORD *)(a1 + 968);
        v7 = 21;
        return extcon_set_state_sync(v6, v7, 1);
      }
LABEL_17:
      result = _warn_printk("Unexpected current plug_type %d, plug_type %d\n", v5, a2);
      __break(0x800u);
      return result;
    }
    if ( a2 != 3 )
    {
      if ( a2 == 4 )
      {
        if ( v5 == 2 )
        {
          wcd_mbhc_report_plug(a1, 0, 1);
          extcon_set_state_sync(*(_QWORD *)(a1 + 968), 21, 0);
          v5 = *(unsigned __int8 *)(a1 + 161);
        }
        if ( v5 == 1 )
        {
          wcd_mbhc_report_plug(a1, 0, 3);
          extcon_set_state_sync(*(_QWORD *)(a1 + 968), 20, 0);
        }
        v6 = *(_QWORD *)(a1 + 968);
        v7 = 62;
        return extcon_set_state_sync(v6, v7, 1);
      }
      goto LABEL_17;
    }
    v9 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 112) + 16LL);
    wcd_mbhc_report_plug(a1, 1, 4);
    result = extcon_set_state_sync(*(_QWORD *)(a1 + 968), 23, 1);
    if ( v9 == 1 )
    {
      v10 = *(_QWORD *)(a1 + 856);
      v11 = *(unsigned int *)(v10 + 184);
      if ( (_DWORD)v11 )
      {
        snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v11, *(unsigned __int8 *)(v10 + 188), 0);
        v10 = *(_QWORD *)(a1 + 856);
      }
      v12 = *(unsigned int *)(v10 + 360);
      if ( (_DWORD)v12 )
      {
        snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v12, *(unsigned __int8 *)(v10 + 364), 0);
        v10 = *(_QWORD *)(a1 + 856);
      }
      v13 = *(unsigned int *)(v10 + 72);
      if ( (_DWORD)v13 )
      {
        snd_soc_component_update_bits(
          *(_QWORD *)(a1 + 216),
          v13,
          *(unsigned __int8 *)(v10 + 76),
          (unsigned int)(1 << *(_BYTE *)(v10 + 77)));
        v10 = *(_QWORD *)(a1 + 856);
      }
      v14 = *(unsigned int *)(v10 + 168);
      if ( (_DWORD)v14 )
        snd_soc_component_update_bits(
          *(_QWORD *)(a1 + 216),
          v14,
          *(unsigned __int8 *)(v10 + 172),
          (unsigned int)(3 << *(_BYTE *)(v10 + 173)));
      result = mutex_is_locked(a1 + 744);
      if ( (result & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
      {
        wcd_mbhc_hs_elec_irq___already_done = 1;
        result = _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
        __break(0x800u);
      }
      v15 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
      if ( (*(_QWORD *)(a1 + 904) & 1) == 0 )
      {
        v16 = *(_QWORD *)(a1 + 216);
        v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 112LL);
        if ( *((_DWORD *)v17 - 1) != 542830841 )
          __break(0x8228u);
        result = v17(v16, v15, 1);
        _X8 = (unsigned __int64 *)(a1 + 904);
        __asm { PRFM            #0x11, [X8] }
        do
          v24 = __ldxr(_X8);
        while ( __stxr(v24 | 1, _X8) );
      }
    }
  }
  return result;
}

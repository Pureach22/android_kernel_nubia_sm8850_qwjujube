__int64 __fastcall wcd_mbhc_usbc_ana_event_handler(__int64 a1, unsigned __int64 a2, _BYTE *a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  _DWORD *v11; // x8
  __int64 result; // x0
  __int64 v13; // x8
  char v15; // w8
  __int64 v16; // x20
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  _DWORD *v18; // x8
  void (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x0

  v3 = a1 - 944;
  if ( a1 == 944 )
    return 4294967274LL;
  if ( a2 == 1 )
  {
    if ( !a3 || (*a3 & 1) == 0 )
      wcd_usbss_switch_update(3, 1);
    v5 = a1 - 824;
    v6 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 824) + 128LL);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a1 - 728);
      if ( *((_DWORD *)v6 - 1) != -1918869124 )
        __break(0x8228u);
      v6(v7, 1);
    }
    v8 = *(_QWORD *)(a1 - 88);
    v9 = *(unsigned int *)(v8 + 8);
    if ( (_DWORD)v9 )
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 - 728),
        v9,
        *(unsigned __int8 *)(v8 + 12),
        (unsigned int)(1 << *(_BYTE *)(v8 + 13)));
    v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v5 + 144LL);
    if ( *((_DWORD *)v10 - 1) != 1996337026 )
      __break(0x8228u);
    if ( (v10(v3, 1) & 1) != 0 )
    {
      if ( !*(_BYTE *)(a1 - 783) )
        wcd_mbhc_swch_irq_handler(v3);
      v11 = *(_DWORD **)(*(_QWORD *)v5 + 144LL);
      if ( *(v11 - 1) != 1996337026 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v11)(v3, 0);
    }
    else
    {
      printk(&unk_DE3D, "wcd_mbhc_usbc_ana_event_handler");
    }
    return 0;
  }
  if ( a2 > 2 )
  {
    if ( a2 == 3 )
    {
      v19 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 824) + 328LL);
      if ( v19 )
      {
        v20 = a1 - 944;
        if ( *((_DWORD *)v19 - 1) != -144065355 )
          __break(0x8228u);
        v19(v20);
      }
    }
    return 0;
  }
  v13 = *(_QWORD *)(a1 - 88);
  if ( *(_DWORD *)(v13 + 8) )
  {
    snd_soc_component_read(*(_QWORD *)(a1 - 728));
    v13 = *(_QWORD *)(a1 - 88);
  }
  if ( !*(_DWORD *)(v13 + 40) )
    return 0;
  v15 = snd_soc_component_read(*(_QWORD *)(a1 - 728));
  result = 0;
  if ( !a2
    && !((unsigned __int8)(v15 & *(_BYTE *)(*(_QWORD *)(a1 - 88) + 44LL)) >> *(_BYTE *)(*(_QWORD *)(a1 - 88) + 45LL)) )
  {
    v16 = a1 - 824;
    v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v16 + 144LL);
    if ( *((_DWORD *)v17 - 1) != 1996337026 )
      __break(0x8228u);
    if ( (v17(v3, 1) & 1) != 0 )
    {
      wcd_mbhc_swch_irq_handler(v3);
      v18 = *(_DWORD **)(*(_QWORD *)v16 + 144LL);
      if ( *(v18 - 1) != 1996337026 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v18)(v3, 0);
    }
    else
    {
      printk(&unk_DE3D, "wcd_mbhc_usbc_ana_event_handler");
    }
    wcd_usbss_switch_update(3, 0);
    return 0;
  }
  return result;
}

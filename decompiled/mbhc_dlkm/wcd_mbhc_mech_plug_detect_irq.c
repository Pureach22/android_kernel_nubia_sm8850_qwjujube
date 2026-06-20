__int64 __fastcall wcd_mbhc_mech_plug_detect_irq(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  _DWORD *v5; // x8
  void *v6; // x0

  if ( !a2 )
  {
    v6 = &unk_E323;
LABEL_12:
    printk(v6, "wcd_mbhc_mech_plug_detect_irq");
    return 0;
  }
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 112) + 88LL) )
    return 0;
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 120) + 144LL);
  if ( *((_DWORD *)v4 - 1) != 1996337026 )
    __break(0x8228u);
  if ( (v4(a2, 1) & 1) == 0 )
  {
    v6 = &unk_DE3D;
    goto LABEL_12;
  }
  wcd_mbhc_swch_irq_handler(a2);
  v5 = *(_DWORD **)(*(_QWORD *)(a2 + 120) + 144LL);
  if ( *(v5 - 1) != 1996337026 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v5)(a2, 0);
  return 1;
}

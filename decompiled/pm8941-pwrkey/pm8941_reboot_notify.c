__int64 __fastcall pm8941_reboot_notify(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v4; // x0
  int v6; // w21
  int updated; // w0
  unsigned int v8; // w8
  __int64 v9; // x3
  int v10; // w0
  int v11; // w0

  v2 = *(_DWORD *)(a1 - 8);
  v4 = *(_QWORD *)(a1 - 24);
  if ( v2 )
    v6 = 91;
  else
    v6 = 90;
  updated = regmap_update_bits_base(v4, (unsigned int)(*(_DWORD *)(a1 - 36) + v6), 128, 0, 0, 0, 0);
  if ( updated )
    dev_err(*(_QWORD *)(a1 - 48), "unable to clear ps hold reset enable: %d\n", updated);
  usleep_range_state(100, 1000, 2);
  if ( reboot_mode == 1 )
    v8 = 1;
  else
    v8 = 7;
  if ( (a2 & 0xFFFFFFFFFFFFFFFELL) == 2 )
    v9 = 4;
  else
    v9 = v8;
  v10 = regmap_update_bits_base(*(_QWORD *)(a1 - 24), (unsigned int)(*(_DWORD *)(a1 - 36) + 90), 15, v9, 0, 0, 0);
  if ( v10 )
    dev_err(*(_QWORD *)(a1 - 48), "unable to set ps hold reset type: %d\n", v10);
  v11 = regmap_update_bits_base(*(_QWORD *)(a1 - 24), (unsigned int)(*(_DWORD *)(a1 - 36) + v6), 128, 128, 0, 0, 0);
  if ( v11 )
    dev_err(*(_QWORD *)(a1 - 48), "unable to re-set enable: %d\n", v11);
  return 0;
}

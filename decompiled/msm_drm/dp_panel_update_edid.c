__int64 __fastcall dp_panel_update_edid(__int64 a1, __int64 a2)
{
  unsigned int updated; // w21
  char v5; // w8

  **(_QWORD **)(a1 + 96) = a2;
  sde_parse_edid(*(_QWORD *)(a1 + 96));
  updated = sde_edid_update_modes(*(_QWORD *)(a1 + 944), *(_QWORD *)(a1 + 96));
  v5 = drm_detect_monitor_audio(a2);
  *(_BYTE *)(a1 + 960) = v5 & 1;
  return updated;
}

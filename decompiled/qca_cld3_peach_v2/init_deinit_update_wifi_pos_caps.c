__int64 __fastcall init_deinit_update_wifi_pos_caps(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( (wmi_service_enabled(a1, 273) & 1) != 0 )
    *(_DWORD *)(a2 + 20) |= 0x80000000;
  if ( (wmi_service_enabled(a1, 274) & 1) != 0 )
    *(_DWORD *)(a2 + 24) |= 1u;
  if ( (wmi_service_enabled(a1, 275) & 1) != 0 )
    *(_DWORD *)(a2 + 24) |= 0x200u;
  if ( (wmi_service_enabled(a1, 272) & 1) != 0 )
    *(_DWORD *)(a2 + 24) |= 2u;
  result = wmi_service_enabled(a1, 271);
  if ( (result & 1) != 0 )
    *(_DWORD *)(a2 + 24) |= 4u;
  return result;
}

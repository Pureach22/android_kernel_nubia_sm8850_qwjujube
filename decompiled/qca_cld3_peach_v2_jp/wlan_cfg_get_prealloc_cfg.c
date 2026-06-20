__int64 __fastcall wlan_cfg_get_prealloc_cfg(__int64 result, _DWORD *a2)
{
  __int64 v3; // x20

  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      a2[8] = *(_DWORD *)(cfg_psoc_get_values(result) + 460);
      *a2 = *(_DWORD *)(cfg_psoc_get_values(v3) + 364);
      a2[1] = *(_DWORD *)(cfg_psoc_get_values(v3) + 344);
      a2[2] = *(_DWORD *)(cfg_psoc_get_values(v3) + 432);
      a2[3] = *(_DWORD *)(cfg_psoc_get_values(v3) + 548);
      a2[4] = *(_DWORD *)(cfg_psoc_get_values(v3) + 456);
      a2[5] = *(_DWORD *)(cfg_psoc_get_values(v3) + 300);
      a2[6] = *(_DWORD *)(cfg_psoc_get_values(v3) + 324);
      a2[7] = *(_DWORD *)(cfg_psoc_get_values(v3) + 588);
      a2[9] = *(_DWORD *)(cfg_psoc_get_values(v3) + 488);
      a2[10] = *(_DWORD *)(cfg_psoc_get_values(v3) + 492);
      a2[11] = *(_DWORD *)(cfg_psoc_get_values(v3) + 484);
      a2[12] = *(_DWORD *)(cfg_psoc_get_values(v3) + 540);
      a2[13] = *(_DWORD *)(cfg_psoc_get_values(v3) + 660);
      result = cfg_psoc_get_values(v3);
      a2[14] = *(_DWORD *)(result + 668);
    }
  }
  return result;
}

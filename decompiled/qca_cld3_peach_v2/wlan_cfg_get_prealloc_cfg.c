__int64 __fastcall wlan_cfg_get_prealloc_cfg(__int64 result, _DWORD *a2)
{
  __int64 v3; // x20

  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      a2[8] = *(_DWORD *)(cfg_psoc_get_values(result) + 464);
      *a2 = *(_DWORD *)(cfg_psoc_get_values(v3) + 368);
      a2[1] = *(_DWORD *)(cfg_psoc_get_values(v3) + 348);
      a2[2] = *(_DWORD *)(cfg_psoc_get_values(v3) + 436);
      a2[3] = *(_DWORD *)(cfg_psoc_get_values(v3) + 552);
      a2[4] = *(_DWORD *)(cfg_psoc_get_values(v3) + 460);
      a2[5] = *(_DWORD *)(cfg_psoc_get_values(v3) + 304);
      a2[6] = *(_DWORD *)(cfg_psoc_get_values(v3) + 328);
      a2[7] = *(_DWORD *)(cfg_psoc_get_values(v3) + 592);
      a2[9] = *(_DWORD *)(cfg_psoc_get_values(v3) + 492);
      a2[10] = *(_DWORD *)(cfg_psoc_get_values(v3) + 496);
      a2[11] = *(_DWORD *)(cfg_psoc_get_values(v3) + 488);
      a2[12] = *(_DWORD *)(cfg_psoc_get_values(v3) + 544);
      a2[13] = *(_DWORD *)(cfg_psoc_get_values(v3) + 664);
      result = cfg_psoc_get_values(v3);
      a2[14] = *(_DWORD *)(result + 672);
    }
  }
  return result;
}

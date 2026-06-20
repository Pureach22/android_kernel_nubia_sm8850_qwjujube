__int64 __fastcall cds_cfg_update_ac_specs_params(__int64 result, __int64 a2)
{
  if ( result )
  {
    *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(result + 40) = *(_DWORD *)(a2 + 44);
    *(_WORD *)(result + 44) = *(_WORD *)(a2 + 48);
    *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(result + 52) = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(result + 56) = *(_DWORD *)(a2 + 60);
    *(_DWORD *)(result + 60) = *(_DWORD *)(a2 + 64);
    *(_WORD *)(result + 64) = *(_WORD *)(a2 + 68);
    *(_DWORD *)(result + 68) = *(_DWORD *)(a2 + 72);
    *(_DWORD *)(result + 72) = *(_DWORD *)(a2 + 76);
    *(_DWORD *)(result + 76) = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(result + 80) = *(_DWORD *)(a2 + 84);
    *(_WORD *)(result + 84) = *(_WORD *)(a2 + 88);
    *(_DWORD *)(result + 88) = *(_DWORD *)(a2 + 92);
    *(_DWORD *)(result + 92) = *(_DWORD *)(a2 + 96);
    *(_DWORD *)(result + 96) = *(_DWORD *)(a2 + 100);
    *(_DWORD *)(result + 100) = *(_DWORD *)(a2 + 104);
    *(_WORD *)(result + 104) = *(_WORD *)(a2 + 108);
    *(_DWORD *)(result + 108) = *(_DWORD *)(a2 + 112);
    *(_DWORD *)(result + 112) = *(_DWORD *)(a2 + 116);
  }
  return result;
}

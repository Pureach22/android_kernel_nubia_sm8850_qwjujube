__int64 __fastcall cam_cdm_write_clear_comp_event(__int64 a1, int a2, int a3)
{
  *(_BYTE *)(a1 + 3) = 13;
  *(_DWORD *)(a1 + 4) = a2;
  *(_DWORD *)(a1 + 8) = a3;
  return a1 + 12;
}

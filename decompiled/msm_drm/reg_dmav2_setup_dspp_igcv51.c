unsigned __int64 __fastcall reg_dmav2_setup_dspp_igcv51(int *a1, __int64 a2)
{
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a2 + 160) & 0xFF0F0FFF | 0x105000;
  return reg_dmav2_setup_dspp_igc_common_v5(a1, (_QWORD *)a2, 96);
}

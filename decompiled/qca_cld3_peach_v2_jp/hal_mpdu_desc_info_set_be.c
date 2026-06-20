void __fastcall hal_mpdu_desc_info_set_be(__int64 a1, __int64 a2, _DWORD *a3, __int16 a4)
{
  *(_DWORD *)(a2 + 24) |= (a4 & 0xFFF) << 19;
  *a3 |= 1u;
}

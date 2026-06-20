__int64 __fastcall sub_230AA8(int a1, int a2, int a3)
{
  __int64 v3; // x22
  __int128 v4; // q8
  __int128 v5; // q22

  *(_OWORD *)(v3 + 96) = v4;
  *(_OWORD *)(v3 + 112) = v5;
  return extract_hal_reg_cap_tlv(a1, a2, a3);
}

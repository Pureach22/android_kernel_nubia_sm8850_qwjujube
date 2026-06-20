__int64 __fastcall sub_216ECC(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int128 v4; // q8
  __int128 v5; // q22

  *(_OWORD *)(v3 + 96) = v4;
  *(_OWORD *)(v3 + 112) = v5;
  return wmi_extract_hal_reg_cap(a1, a2, a3);
}

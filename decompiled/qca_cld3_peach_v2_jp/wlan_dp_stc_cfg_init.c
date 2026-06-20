__int64 __fastcall wlan_dp_stc_cfg_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  *(_BYTE *)(a1 + 200) = *(_BYTE *)(cfg_psoc_get_values(a2) + 4153);
  result = cfg_psoc_get_values(a2);
  *(_BYTE *)(a1 + 201) = *(_BYTE *)(result + 4154);
  return result;
}

__int64 __fastcall lim_is_ap_power_type_6g_invalid(__int64 a1)
{
  unsigned __int64 v1; // x8
  bool v2; // cc
  unsigned int v3; // w8
  int v4; // w9

  v1 = *(unsigned __int8 *)(a1 + 10068);
  v2 = v1 > 8;
  v3 = 0xF0u >> v1;
  v4 = v2;
  return (v4 | v3) & 1;
}

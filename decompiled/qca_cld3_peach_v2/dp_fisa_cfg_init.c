__int64 __fastcall dp_fisa_cfg_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  *(_DWORD *)(a1 + 184) = *(unsigned __int8 *)(cfg_psoc_get_values(a2) + 4232);
  *(_BYTE *)(a1 + 194) = *(_BYTE *)(cfg_psoc_get_values(a2) + 4232);
  result = cfg_psoc_get_values(a2);
  *(_BYTE *)(a1 + 195) = *(_BYTE *)(result + 4233);
  return result;
}

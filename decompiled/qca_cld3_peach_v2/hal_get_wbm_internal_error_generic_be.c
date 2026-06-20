__int64 __fastcall hal_get_wbm_internal_error_generic_be(__int64 a1)
{
  return *(_DWORD *)(a1 + 8) >> 31;
}

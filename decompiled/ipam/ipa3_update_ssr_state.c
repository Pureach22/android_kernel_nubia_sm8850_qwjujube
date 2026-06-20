__int64 __fastcall ipa3_update_ssr_state(__int64 result)
{
  *(_DWORD *)(ipa3_ctx + 45216) = result & 1;
  return result;
}

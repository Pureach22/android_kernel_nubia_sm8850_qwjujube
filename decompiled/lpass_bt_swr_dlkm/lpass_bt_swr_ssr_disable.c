__int64 __fastcall lpass_bt_swr_ssr_disable(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( (*(_BYTE *)(a2 + 152) & 1) != 0 )
  {
    mutex_lock(a2 + 104);
    *(_BYTE *)(a2 + 152) = 0;
    mutex_unlock(a2 + 104);
    return swrm_wcd_notify(**(_QWORD **)(a2 + 208), 6, 0);
  }
  else
  {
    result = __ratelimit(&lpass_bt_swr_ssr_disable__rs, "lpass_bt_swr_ssr_disable");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)a2, "%s: already disabled\n", "lpass_bt_swr_ssr_disable");
  }
  return result;
}

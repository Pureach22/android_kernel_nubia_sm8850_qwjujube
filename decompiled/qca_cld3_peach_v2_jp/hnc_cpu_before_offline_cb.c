__int64 __fastcall hnc_cpu_before_offline_cb(__int64 result, unsigned int a2)
{
  if ( a2 <= 0x1F )
  {
    *(_DWORD *)(result + 48LL * a2 + 880) = 1;
    return hif_napi_event(result, 4, ((unsigned __int64)a2 << 16) | 1);
  }
  return result;
}

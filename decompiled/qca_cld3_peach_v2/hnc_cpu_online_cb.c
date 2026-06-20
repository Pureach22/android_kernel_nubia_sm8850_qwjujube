__int64 __fastcall hnc_cpu_online_cb(__int64 result, unsigned int a2)
{
  if ( a2 <= 0x1F )
    *(_DWORD *)(result + 48LL * a2 + 880) = 2;
  return result;
}

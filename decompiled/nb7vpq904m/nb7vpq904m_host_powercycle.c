__int64 __fastcall nb7vpq904m_host_powercycle(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 124) != 1 )
    return 4294967274LL;
  queue_work_on(32, system_wq, a1 + 216);
  return 0;
}

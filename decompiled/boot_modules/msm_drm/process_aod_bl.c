__int64 __fastcall process_aod_bl(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x1

  if ( result && *(_DWORD *)(result + 2552) == 3 && *(_DWORD *)(result + 2324) != a3 )
  {
    v3 = *(_QWORD *)(result + 2536);
    *(_DWORD *)(result + 2324) = a3;
    return queue_work_on(32, v3, result + 2504);
  }
  return result;
}

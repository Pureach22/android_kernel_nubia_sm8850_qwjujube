__int64 __fastcall lim_stop_pmfcomeback_timer(__int64 result)
{
  __int64 v1; // x19

  if ( !*(_DWORD *)(result + 7036) )
  {
    v1 = result;
    result = qdf_mc_timer_stop(result + 7872);
    *(_BYTE *)(v1 + 8049) = 0;
  }
  return result;
}

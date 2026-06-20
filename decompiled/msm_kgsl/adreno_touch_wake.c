__int64 __fastcall adreno_touch_wake(__int64 result)
{
  if ( (*(_BYTE *)(result + 10952) & 1) == 0 && *(_DWORD *)(result + 11120) == 128 )
    return queue_work_on(32, system_wq, result + 20304);
  return result;
}

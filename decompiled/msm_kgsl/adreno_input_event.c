__int64 __fastcall adreno_input_event(__int64 result, int a2)
{
  __int64 v2; // x8

  if ( a2 == 3 )
  {
    v2 = **(_QWORD **)(result + 32);
    if ( (*(_BYTE *)(v2 + 10952) & 1) == 0 && *(_DWORD *)(v2 + 11120) == 128 )
      return queue_work_on(32, system_wq, v2 + 20304);
  }
  return result;
}

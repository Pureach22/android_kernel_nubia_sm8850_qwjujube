__int64 __fastcall kgsl_timer(__int64 result)
{
  if ( *(_DWORD *)(result + 2332) != 16 )
  {
    *(_DWORD *)(result + 2332) = 128;
    return queue_work_on(32, qword_3A900, result - 32);
  }
  return result;
}

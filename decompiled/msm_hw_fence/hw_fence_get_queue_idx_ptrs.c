__int64 __fastcall hw_fence_get_queue_idx_ptrs(__int64 result, __int64 a2, _QWORD *a3, _QWORD *a4, _QWORD *a5)
{
  __int64 v5; // x8
  __int64 v6; // x9

  if ( *(_BYTE *)(result + 33520) == 1 )
  {
    v5 = a2 + 64;
    v6 = a2 + 128;
  }
  else
  {
    v5 = a2 + 48;
    v6 = a2 + 52;
  }
  *a3 = v5;
  *a4 = v6;
  if ( a5 )
    *a5 = a2 + 28;
  return result;
}

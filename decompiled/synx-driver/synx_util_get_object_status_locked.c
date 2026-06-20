__int64 __fastcall synx_util_get_object_status_locked(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  unsigned __int64 v8; // x0

  result = 0;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v8 = *(_QWORD *)(a1 + 64);
    if ( (*(_BYTE *)(a1 + 124) & 0x20) != 0 )
      return _fence_group_state(v8, 1);
    else
      return _fence_state(v8, 1, a3, a4, a5, a6);
  }
  return result;
}

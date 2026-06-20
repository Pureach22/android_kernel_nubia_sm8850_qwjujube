__int64 __fastcall _cam_icp_start_dev_in_acquired(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 result; // x0

  result = cam_context_start_dev_to_hw(a1, a2, a3, a4, a5, a6, a7);
  if ( !(_DWORD)result )
    *(_DWORD *)(a1 + 240) = 3;
  return result;
}

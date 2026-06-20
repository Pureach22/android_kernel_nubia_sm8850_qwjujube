__int64 __fastcall _cam_icp_acquire_dev_in_available(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  result = cam_context_acquire_dev_to_hw(a1, a2);
  if ( !(_DWORD)result )
    *(_DWORD *)(a1 + 240) = 2;
  return result;
}

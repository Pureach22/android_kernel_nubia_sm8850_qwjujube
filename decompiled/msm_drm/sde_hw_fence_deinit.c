unsigned __int64 __fastcall sde_hw_fence_deinit(unsigned __int64 result)
{
  unsigned __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 168);
    if ( result )
    {
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(
            0,
            0,
            0,
            "hwfence deregister ctl_id:%d hw_fence_client_id:%d\n",
            *(_DWORD *)(v1 + 64) - 1,
            *(_DWORD *)(v1 + 164));
          result = *(_QWORD *)(v1 + 168);
        }
        result = synx_uninitialize(result);
        *(_QWORD *)(v1 + 168) = 0;
      }
    }
  }
  return result;
}

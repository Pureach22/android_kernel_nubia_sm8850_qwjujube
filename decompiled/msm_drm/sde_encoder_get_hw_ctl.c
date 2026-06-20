__int64 __fastcall sde_encoder_get_hw_ctl(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x19

  if ( result )
  {
    if ( *(_BYTE *)(result + 5120) == 1 && (v1 = *(_QWORD *)(result + 2744)) != 0 && (v2 = *(_QWORD *)(v1 + 200)) != 0 )
    {
      result = *(_QWORD *)(v2 + 416);
      if ( result )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          v3 = *(_QWORD *)(v2 + 416);
          _drm_dev_dbg(0, 0, 0, "conn hw_ctl idx:%d intf_mode:%d\n", *(_DWORD *)(result + 64), *(_DWORD *)(v2 + 668));
          return v3;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

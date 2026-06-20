__int64 __fastcall cam_icp_ctx_clk_info_init(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 v5; // x25
  __int64 i; // x27
  __int64 v7; // x8
  int v8; // w8
  __int64 v9; // [xsp+8h] [xbp-8h]

  *(_QWORD *)(result + 29248) = 0;
  *(_DWORD *)(result + 29232) = 0;
  *(_DWORD *)(result + 29240) = 0;
  v1 = *(_QWORD *)(result + 16);
  *(_QWORD *)(result + 29256) = 0;
  *(_QWORD *)(result + 29328) = 0;
  *(_QWORD *)(result + 29336) = 0;
  *(_QWORD *)(result + 29344) = 0;
  *(_QWORD *)(result + 29368) = 0;
  *(_QWORD *)(result + 29376) = 0;
  *(_QWORD *)(result + 29384) = 0;
  *(_QWORD *)(result + 29408) = 0;
  *(_QWORD *)(result + 29416) = 0;
  *(_QWORD *)(result + 29424) = 0;
  *(_QWORD *)(result + 29448) = 0;
  *(_QWORD *)(result + 29456) = 0;
  *(_QWORD *)(result + 29464) = 0;
  *(_QWORD *)(result + 29488) = 0;
  *(_QWORD *)(result + 29496) = 0;
  *(_QWORD *)(result + 29504) = 0;
  *(_QWORD *)(result + 29544) = 0;
  *(_QWORD *)(result + 29536) = 0;
  *(_QWORD *)(result + 29528) = 0;
  *(_QWORD *)(result + 29584) = 0;
  *(_QWORD *)(result + 29576) = 0;
  *(_QWORD *)(result + 29568) = 0;
  *(_QWORD *)(result + 29624) = 0;
  *(_QWORD *)(result + 29616) = 0;
  *(_QWORD *)(result + 29608) = 0;
  *(_QWORD *)(result + 29664) = 0;
  *(_QWORD *)(result + 29656) = 0;
  *(_QWORD *)(result + 29648) = 0;
  *(_QWORD *)(result + 29704) = 0;
  *(_QWORD *)(result + 29696) = 0;
  *(_QWORD *)(result + 29688) = 0;
  *(_QWORD *)(result + 29728) = 0;
  *(_QWORD *)(result + 29736) = 0;
  *(_QWORD *)(result + 29744) = 0;
  *(_QWORD *)(result + 29784) = 0;
  *(_QWORD *)(result + 29776) = 0;
  *(_QWORD *)(result + 29768) = 0;
  v2 = **(_QWORD **)(v1 + 16);
  if ( !v2 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_get_supported_clk_rates",
             365,
             "%s Invalid device intf for %s",
             (const char *)(result + 29824),
             *(const char **)v1);
  v3 = *(_QWORD *)(v2 + 112);
  v4 = 0;
  v5 = result + 29264;
  for ( i = v3 + 1480; ; i += 128 )
  {
    v7 = *(unsigned int *)(v3 + 2892);
    if ( (unsigned int)v7 >= 0x20 )
      break;
    v8 = *(_DWORD *)(i + 4 * v7);
    *(_DWORD *)(v5 + 4 * v4) = v8;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      v9 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_get_supported_clk_rates",
        376,
        "%s: clk_info[%d] = %d",
        (const char *)(result + 29824),
        v4,
        v8);
      result = v9;
    }
    if ( ++v4 == 10 )
      return result;
  }
  __break(0x5512u);
  return cam_icp_device_timer_start(result);
}

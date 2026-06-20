__int64 __fastcall hdd_enable_mc_addr_filtering(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = *(_QWORD **)(a1 + 24);
  result = _wlan_hdd_validate_context(
             (__int64)v10,
             (__int64)"hdd_enable_mc_addr_filtering",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( !(_DWORD)result )
  {
    result = hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52824));
    if ( (result & 1) != 0 )
    {
      result = ucfg_pmo_enable_mc_addr_filtering_in_fwr(*v10, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), a2);
      if ( (_DWORD)result )
        return qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: failed to enable mc list; status:%d",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "hdd_enable_mc_addr_filtering",
                 (unsigned int)result);
    }
  }
  return result;
}

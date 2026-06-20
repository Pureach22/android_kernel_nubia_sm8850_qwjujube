__int64 __fastcall host_diag_log_submit(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  size_t v11; // x20
  unsigned __int16 *v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  result = cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 6) == 0 )
  {
    result = nl_srv_is_initialized();
    if ( !(_DWORD)result )
    {
      result = cds_is_multicast_logging();
      if ( (_BYTE)result )
      {
        v11 = *a1;
        result = _qdf_mem_malloc((unsigned __int16)(v11 + 8), "host_diag_log_submit", 124);
        if ( result )
        {
          v12 = (unsigned __int16 *)result;
          *(_WORD *)result = 20560;
          *(_DWORD *)(result + 4) = 1;
          *(_WORD *)(result + 2) = bswap32(v11 + 8) >> 16;
          memcpy((void *)(result + 8), a1, v11);
          ptt_sock_send_msg_to_app(v12, 0, v13, v14, v15, v16, v17, v18, v19, v20, 17, 0xFFFFFFFF);
          return _qdf_mem_free((__int64)v12);
        }
      }
    }
  }
  return result;
}

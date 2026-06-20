__int64 __fastcall sme_send_vendor_btm_params(
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
  __int64 result; // x0

  if ( (unsigned __int8)a2 < 6u )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1912LL) == 1 )
        wlan_roam_update_cfg(*(_QWORD *)(a1 + 21624), a2, 0x31u);
      qdf_mutex_release(a1 + 12848);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid sme session id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_send_vendor_btm_params");
    return 4;
  }
  return result;
}

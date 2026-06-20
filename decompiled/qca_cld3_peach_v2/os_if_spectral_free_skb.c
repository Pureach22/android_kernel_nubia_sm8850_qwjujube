__int64 __fastcall os_if_spectral_free_skb(
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
  const char *v11; // x2
  unsigned int v12; // w1
  __int64 result; // x0
  const char *v14; // x2
  __int64 comp_private_obj; // x0
  __int64 v16; // x20
  __int64 v17; // x0

  if ( !a1 )
  {
    v14 = "%s: PDEV is NULL!";
    return qdf_trace_msg(0x48u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_free_skb");
  }
  if ( a2 >= 3 )
  {
    v11 = "%s: Invalid Spectral message type %u";
    v12 = 2;
    return qdf_trace_msg(0x48u, v12, v11, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_free_skb", a2);
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
  if ( !comp_private_obj )
  {
    v14 = "%s: PDEV SPECTRAL object is NULL!";
    return qdf_trace_msg(0x48u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_free_skb");
  }
  v16 = comp_private_obj + 24;
  v17 = *(_QWORD *)(comp_private_obj + 24 + 8LL * a2);
  if ( !v17 )
  {
    v11 = "%s: Socket buffer is null, msg_type= %u";
    v12 = 4;
    return qdf_trace_msg(0x48u, v12, v11, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_free_skb", a2);
  }
  result = _qdf_nbuf_free(v17);
  *(_QWORD *)(v16 + 8LL * a2) = 0;
  return result;
}

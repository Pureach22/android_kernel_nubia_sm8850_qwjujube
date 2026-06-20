__int64 __fastcall wlan_cfg80211_dealloc_coap_buf_info(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x20
  _QWORD *v11; // x21
  _QWORD *v12; // x22

  if ( result )
  {
    v9 = result;
    v10 = result + 16;
    v11 = *(_QWORD **)(result + 16);
    if ( v11 != (_QWORD *)(result + 16) )
    {
      do
      {
        v12 = (_QWORD *)*v11;
        qdf_list_remove_node(v10, v11);
        _qdf_mem_free(v11[4]);
        result = _qdf_mem_free((__int64)v11);
        v11 = v12;
      }
      while ( v12 != (_QWORD *)v10 );
    }
    if ( *(_DWORD *)(v9 + 32) )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: list length not equal to zero",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "qdf_list_destroy");
  }
  return result;
}

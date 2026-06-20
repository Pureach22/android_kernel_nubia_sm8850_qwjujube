__int64 __fastcall cm_is_ese_connection(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 result; // x0
  __int64 v15; // x21

  v10 = *(_QWORD *)(a1 + 152);
  if ( v10 && (v11 = *(_QWORD *)(v10 + 80)) != 0 )
  {
    result = mlme_get_psoc_ext_obj_fl(v11);
    if ( !result )
      return result;
    if ( *(_BYTE *)(result + 1562) == 1 )
    {
      v15 = result;
      if ( (wlan_crypto_get_param(a1, 7u) & 0x4000) != 0
        || wlan_vdev_is_open_mode(a1) && (a2 & 1) != 0 && (*(_BYTE *)(v15 + 1562) & 1) != 0 )
      {
        return 1;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: psoc not found", a3, a4, a5, a6, a7, a8, a9, a10, "cm_is_ese_connection");
  }
  return 0;
}

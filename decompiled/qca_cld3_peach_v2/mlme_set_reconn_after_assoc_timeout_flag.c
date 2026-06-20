__int64 __fastcall mlme_set_reconn_after_assoc_timeout_flag(__int64 result, __int64 a2, char a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int *v22; // x8

  if ( result )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(result, a2, 7);
    if ( result )
    {
      v12 = result;
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(result, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( ext_hdl )
      {
        v22 = (unsigned int *)(a3 & 1);
        *(_BYTE *)(ext_hdl + 6) = a3 & 1;
      }
      else
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: vdev legacy private object is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "mlme_set_reconn_after_assoc_timeout_flag");
      }
      return wlan_objmgr_vdev_release_ref(v12, 7u, v22, v14, v15, v16, v17, v18, v19, v20, v21);
    }
  }
  return result;
}

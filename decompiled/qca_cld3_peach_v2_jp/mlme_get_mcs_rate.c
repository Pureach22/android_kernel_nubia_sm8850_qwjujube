__int64 __fastcall mlme_get_mcs_rate(
        __int64 a1,
        void *a2,
        unsigned __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 ext_hdl; // x0
  unsigned __int64 v14; // x5
  const char *v15; // x2
  __int64 v17; // x19

  if ( !a1 || !a2 || !a3 )
  {
    v15 = "%s: invalid params";
LABEL_9:
    qdf_trace_msg(0x1Fu, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "mlme_get_mcs_rate");
    return 0;
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !ext_hdl )
  {
    v15 = "%s: vdev legacy private object is NULL";
    goto LABEL_9;
  }
  v14 = *(_QWORD *)(ext_hdl + 23800);
  if ( v14 <= a3 )
  {
    v17 = ext_hdl;
    qdf_mem_copy(a2, (const void *)(ext_hdl + 23808), (unsigned int)v14);
    return *(_QWORD *)(v17 + 23800);
  }
  qdf_trace_msg(0x1Fu, 2u, "%s: Invalid length %zd (<%zd)", a4, a5, a6, a7, a8, a9, a10, a11, "mlme_get_mcs_rate", a3);
  return 0;
}

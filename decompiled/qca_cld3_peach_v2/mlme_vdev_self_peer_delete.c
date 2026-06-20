__int64 __fastcall mlme_vdev_self_peer_delete(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  const char *v10; // x2

  if ( !*(_QWORD *)(a1 + 8) )
  {
    v9 = 4;
    v10 = "%s: Invalid del self peer params";
    goto LABEL_5;
  }
  v9 = wma_vdev_detach();
  if ( v9 )
  {
    v10 = "%s: Failed to detach vdev";
LABEL_5:
    qdf_trace_msg(0x68u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "mlme_vdev_self_peer_delete");
  }
  return v9;
}

__int64 __fastcall wma_is_vdev_up(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0

  context = _cds_get_context(54, (__int64)"wma_is_vdev_up", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
    LOBYTE(context) = wlan_is_vdev_id_up(context[4], a1);
  return (unsigned __int8)context & 1;
}

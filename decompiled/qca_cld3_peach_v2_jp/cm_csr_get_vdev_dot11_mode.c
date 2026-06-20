__int64 __fastcall cm_csr_get_vdev_dot11_mode(
        unsigned int a1,
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
  _QWORD *v11; // x20
  unsigned int v12; // w0

  context = _cds_get_context(52, (__int64)"cm_csr_get_vdev_dot11_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 9;
  v11 = context;
  v12 = csr_translate_to_wni_cfg_dot11_mode(context, *((unsigned int *)context + 4283));
  return csr_get_vdev_dot11_mode(v11, a1, v12);
}

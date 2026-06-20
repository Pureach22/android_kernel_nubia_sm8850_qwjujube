_QWORD *__fastcall wma_get_vdev_address_by_vdev_id(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  const char *v20; // x2

  result = _cds_get_context(54, (__int64)"wma_get_vdev_address_by_vdev_id", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    if ( *((unsigned __int16 *)result + 81) <= (unsigned int)a1 )
    {
      v20 = "%s: Invalid vdev_id %u";
    }
    else
    {
      v19 = *(_QWORD *)(result[65] + 488LL * a1);
      if ( v19 )
        return (_QWORD *)(v19 + 74);
      v20 = "%s: Invalid vdev for vdev_id %u";
    }
    qdf_trace_msg(0x36u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "wma_get_vdev_address_by_vdev_id");
    return nullptr;
  }
  return result;
}

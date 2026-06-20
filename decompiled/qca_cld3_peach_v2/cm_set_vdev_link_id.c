__int64 __fastcall cm_set_vdev_link_id(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 v11; // w20
  __int64 result; // x0

  v11 = *(_BYTE *)(*(_QWORD *)(*((_QWORD *)a2 + 127) + 24LL) + 1919LL);
  result = qdf_trace_msg(
             0x68u,
             8u,
             "%s: vdev %d cm_id 0x%x: setting link ID to %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "cm_set_vdev_link_id",
             *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
             *a2,
             v11);
  *(_BYTE *)(*(_QWORD *)a1 + 93LL) = v11;
  return result;
}

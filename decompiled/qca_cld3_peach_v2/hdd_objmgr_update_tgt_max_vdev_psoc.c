__int64 __fastcall hdd_objmgr_update_tgt_max_vdev_psoc(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( !*(_QWORD *)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Psoc NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_objmgr_update_tgt_max_vdev_psoc",
             v10,
             v11);
  *(_WORD *)(*(_QWORD *)result + 54LL) = a2;
  return result;
}

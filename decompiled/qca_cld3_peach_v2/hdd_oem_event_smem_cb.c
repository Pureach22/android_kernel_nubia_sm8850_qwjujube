_QWORD *__fastcall hdd_oem_event_smem_cb(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _BYTE *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD *v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  context = _cds_get_context(51, (__int64)"hdd_oem_event_smem_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  result = (_QWORD *)qdf_trace_msg(
                       0x33u,
                       8u,
                       "%s: enter",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "hdd_oem_event_smem_cb");
  if ( context )
  {
    result = _cds_get_context(64, (__int64)"hdd_oem_event_smem_cb", v20, v21, v22, v23, v24, v25, v26, v27);
    if ( result )
    {
      if ( *((_QWORD *)a1 + 5) )
      {
        return hdd_copy_file_name_and_oem_data(context, (__int64)a1, v28, v29, v30, v31, v32, v33, v34, v35);
      }
      else
      {
        v36 = result;
        hdd_get_link_info_by_vdev((__int64)context, *a1);
        pld_oem_event_smem_write(v36[5], 1, *((_QWORD *)a1 + 3), *((unsigned int *)a1 + 2));
        return (_QWORD *)qdf_trace_msg(
                           0x33u,
                           8u,
                           "%s: exit",
                           v37,
                           v38,
                           v39,
                           v40,
                           v41,
                           v42,
                           v43,
                           v44,
                           "hdd_oem_event_smem_cb");
      }
    }
  }
  return result;
}

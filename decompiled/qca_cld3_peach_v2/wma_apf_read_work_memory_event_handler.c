__int64 __fastcall wma_apf_read_work_memory_event_handler(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  __int64 v32; // x21
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int memory_resp_event; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  void (__fastcall *v51)(__int64, __int64 *); // x8
  __int64 v52; // x0
  __int64 v53; // [xsp+0h] [xbp-20h] BYREF
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_apf_read_work_memory_event_handler", a4, a5, a6, a7, a8, a9, a10, a11);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: handle:%pK event:%pK len:%u",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wma_apf_read_work_memory_event_handler",
    a1,
    a2,
    a3,
    0,
    0,
    0,
    v54);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_apf_read_work_memory_event_handler") )
    goto LABEL_2;
  v32 = *a1;
  v33 = _wmi_validate_handle(
          v32,
          (__int64)"wma_apf_read_work_memory_event_handler",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30);
  result = 4294967274LL;
  if ( !v33 && context )
  {
    if ( !context[1822] )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Callback not registered",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "wma_apf_read_work_memory_event_handler");
      goto LABEL_2;
    }
    memory_resp_event = wmi_extract_apf_read_memory_resp_event(v32);
    if ( memory_resp_event )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Event extract failure: %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wma_apf_read_work_memory_event_handler",
        memory_resp_event);
LABEL_2:
      result = 4294967274LL;
      goto LABEL_3;
    }
    v51 = (void (__fastcall *)(__int64, __int64 *))context[1822];
    v52 = context[1604];
    if ( *((_DWORD *)v51 - 1) != -2005530453 )
      __break(0x8228u);
    v51(v52, &v53);
    result = 0;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}

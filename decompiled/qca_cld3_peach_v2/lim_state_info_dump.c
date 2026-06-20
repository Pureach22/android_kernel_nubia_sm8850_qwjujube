void __fastcall lim_state_info_dump(
        __int64 *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x22
  unsigned __int16 v23; // w0
  unsigned __int16 v24; // w23
  __int16 v25; // w0
  unsigned __int16 v26; // w23
  __int16 v27; // w0
  unsigned __int16 v28; // w23
  __int16 v29; // w0
  unsigned __int16 v30; // w23
  __int16 v31; // w0

  v11 = *a1;
  context = _cds_get_context(53, (__int64)"lim_state_info_dump", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v22 = context;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: size of buffer: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_state_info_dump",
      *a2);
    scnprintf(v11, *a2, "\n SmeState: %d", *((_DWORD *)v22 + 1014));
    v24 = v23;
    scnprintf(v11 + v23, *a2 - (unsigned __int64)v23, "\n PrevSmeState: %d", *((_DWORD *)v22 + 1004));
    v26 = v25 + v24;
    scnprintf(v11 + v26, *a2 - (unsigned __int64)v26, "\n MlmState: %d", *((_DWORD *)v22 + 1005));
    v28 = v27 + v26;
    scnprintf(v11 + v28, *a2 - (unsigned __int64)v28, "\n PrevMlmState: %d", *((_DWORD *)v22 + 1006));
    v30 = v29 + v28;
    scnprintf(v11 + v30, *a2 - (unsigned __int64)v30, "\n ProcessDefdMsgs: %d", *((unsigned __int8 *)v22 + 8885));
    *a2 -= v31 + v30;
    *a1 += (unsigned __int16)(v31 + v30);
  }
}

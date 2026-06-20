double __fastcall sme_qos_setup_fnp(
        __int64 a1,
        __int64 a2,
        double result,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  unsigned __int64 v11; // x9
  __int64 v12; // x4
  __int64 v14; // x9
  void (__fastcall *v15)(__int64, __int64, __int64, __int64, __int64); // x10
  __int64 v16; // x1
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( !a2 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Entry is NULL", result, a4, a5, a6, a7, a8, a9, a10, "sme_qos_setup_fnp");
    return result;
  }
  v10 = *(_DWORD *)(a2 + 28);
  if ( v10 >= 5 )
    goto LABEL_10;
  if ( *(_DWORD *)(a2 + 20) != 4 )
    return result;
  v11 = *(unsigned __int8 *)(a2 + 17) - 1LL;
  if ( v11 > 2 )
  {
LABEL_10:
    __break(0x5512u);
    return sme_qos_process_buffered_cmd(a1);
  }
  v12 = *(unsigned int *)(a2 + 24);
  v14 = qword_856120 + 3040LL * *(unsigned __int8 *)(a2 + 16) + 728LL * v10 + 76LL * (int)v11;
  v15 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(a2 + 120);
  v16 = *(_QWORD *)(a2 + 112);
  if ( *((_DWORD *)v15 - 1) != -518755401 )
    __break(0x822Au);
  v15(a1, v16, v14 + 16, 6, v12);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Entry with flowID = %d getting notified",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "sme_qos_setup_fnp",
    *(unsigned int *)(a2 + 24));
  return result;
}

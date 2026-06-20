__int64 __fastcall sme_set_cfg_disable_tx(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w22
  const char *v23; // x2
  _DWORD *v24; // x8
  __int64 v25; // x0
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  qdf_trace_msg(0x34u, 8u, "%s: Block Tx %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_cfg_disable_tx", a3);
  if ( *(_QWORD *)(a1 + 14408) )
  {
    if ( a3 )
      v22 = 1;
    else
      v22 = 2;
    if ( a3 )
      v23 = "%s: Blocking the Tx queue";
    else
      v23 = "%s: Enable the Tx queue";
    qdf_trace_msg(0x34u, 8u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "sme_set_cfg_disable_tx");
    v24 = *(_DWORD **)(a1 + 14408);
    v25 = *(_QWORD *)(a1 + 12760);
    if ( *(v24 - 1) != 2083539300 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v24)(v25, a2, v22, 1);
  }
  result = wma_cli_set_command(a2, 166, a3, 1);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: Failed to set firmware, errno %d",
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               "sme_set_cfg_disable_tx",
               (unsigned int)result);
  *(_BYTE *)(a1 + 21710) = a3;
  return result;
}

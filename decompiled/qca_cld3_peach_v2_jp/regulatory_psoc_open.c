__int64 __fastcall regulatory_psoc_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *psoc_tx_ops; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x8
  _QWORD *v20; // x20
  _DWORD *v21; // x8
  _DWORD *v22; // x8
  _DWORD *v23; // x8
  _DWORD *v24; // x8
  _DWORD *v25; // x8
  _DWORD *v26; // x8

  psoc_tx_ops = (_QWORD *)reg_get_psoc_tx_ops(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_tx_ops )
  {
    v19 = (_DWORD *)*psoc_tx_ops;
    v20 = psoc_tx_ops;
    if ( *psoc_tx_ops )
    {
      if ( *(v19 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v19)(a1, 0);
    }
    v21 = (_DWORD *)v20[2];
    if ( v21 )
    {
      if ( *(v21 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v21)(a1, 0);
    }
    v22 = (_DWORD *)v20[7];
    if ( v22 )
    {
      if ( *(v22 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v22)(a1, 0);
    }
    v23 = (_DWORD *)v20[13];
    if ( v23 )
    {
      if ( *(v23 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v23)(a1, 0);
    }
    v24 = (_DWORD *)v20[24];
    if ( v24 )
    {
      if ( *(v24 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v24)(a1, 0);
    }
    v25 = (_DWORD *)v20[21];
    if ( v25 )
    {
      if ( *(v25 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v25)(a1, 0);
    }
    v26 = (_DWORD *)v20[31];
    if ( v26 )
    {
      if ( *(v26 - 1) != -1796695762 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v26)(a1, 0);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: tx_ops is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "regulatory_psoc_open");
    return 16;
  }
}

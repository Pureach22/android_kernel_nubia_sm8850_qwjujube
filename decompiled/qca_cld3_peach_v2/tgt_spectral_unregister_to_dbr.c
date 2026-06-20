__int64 __fastcall tgt_spectral_unregister_to_dbr(
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
  __int64 v9; // x8
  _QWORD *v10; // x20
  __int64 (*v11)(void); // x8
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  _DWORD *v16; // x8

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 || (v10 = *(_QWORD **)(v9 + 2128)) == nullptr )
  {
    qdf_trace_msg(0x56u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_spectral_unregister_to_dbr");
    return 16;
  }
  v11 = (__int64 (*)(void))v10[82];
  if ( !v11 )
    return 16;
  if ( *((_DWORD *)v11 - 1) != -1102235987 )
    __break(0x8228u);
  if ( (v11() & 1) == 0 )
    return 16;
  v13 = (_DWORD *)v10[227];
  if ( v13 )
  {
    if ( *(v13 - 1) != 1845289881 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v13)(a1, 0);
  }
  v14 = (_DWORD *)v10[229];
  v15 = a1;
  if ( v14 )
  {
    if ( *(v14 - 1) != 1845289881 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v14)(a1, 0);
    v15 = a1;
  }
  v16 = (_DWORD *)v10[221];
  if ( v16 )
  {
    if ( *(v16 - 1) != 1845289881 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v16)(v15, 0);
  }
  return 0;
}

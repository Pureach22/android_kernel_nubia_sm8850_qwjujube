__int64 __fastcall wma_get_vht_ch_width(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w8

  context = _cds_get_context(54, (__int64)"wma_get_vht_ch_width", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 1;
  v9 = context[3];
  if ( !v9 )
    return 1;
  v10 = *(_QWORD *)(v9 + 2800);
  if ( !v10 )
    return 1;
  v11 = *(_DWORD *)(v10 + 696);
  if ( (v11 & 8) != 0 )
    return 3;
  if ( (v11 & 4) != 0 )
    return 2;
  return 1;
}

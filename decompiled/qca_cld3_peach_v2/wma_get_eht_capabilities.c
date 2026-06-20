__int64 __fastcall wma_get_eht_capabilities(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  _QWORD *v11; // x20

  context = _cds_get_context(54, (__int64)"wma_get_eht_capabilities", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  v11 = context;
  qdf_mem_copy(a1, (char *)context + 3956, 3u);
  a1[3] = *((_DWORD *)v11 + 992);
  return 0;
}

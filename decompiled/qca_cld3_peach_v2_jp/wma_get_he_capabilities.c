__int64 __fastcall wma_get_he_capabilities(
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
  _DWORD *v11; // x20

  context = _cds_get_context(54, (__int64)"wma_get_he_capabilities", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  v11 = context;
  qdf_mem_copy(a1, context + 486, 3u);
  a1[3] = v11[975];
  a1[4] = v11[976];
  a1[5] = v11[977];
  a1[6] = v11[978];
  qdf_mem_copy(a1 + 7, v11 + 979, 8u);
  return 0;
}

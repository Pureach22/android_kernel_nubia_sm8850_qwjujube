_QWORD *__fastcall sme_vdev_del_resp(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  _QWORD *v11; // x20
  __int64 (__fastcall *v12)(_QWORD); // x8

  result = _cds_get_context(52, (__int64)"sme_vdev_del_resp", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = result;
    result = (_QWORD *)csr_cleanup_vdev_session(result, a1);
    v12 = (__int64 (__fastcall *)(_QWORD))v11[2745];
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != 2029277559 )
        __break(0x8228u);
      return (_QWORD *)v12(a1);
    }
  }
  return result;
}

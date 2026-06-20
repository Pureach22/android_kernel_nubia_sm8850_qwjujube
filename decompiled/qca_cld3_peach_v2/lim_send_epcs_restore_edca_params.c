__int64 __fastcall lim_send_epcs_restore_edca_params(
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
  _QWORD *context; // x0
  _QWORD *v11; // x19
  __int64 session_by_vdev_id; // x0
  __int64 v13; // x20
  char *v14; // x1

  context = _cds_get_context(53, (__int64)"lim_send_epcs_restore_edca_params", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = context;
  session_by_vdev_id = pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
  if ( !session_by_vdev_id )
    return 4;
  v13 = session_by_vdev_id;
  lim_send_edca_params(v11, session_by_vdev_id + 7136, *(unsigned __int8 *)(session_by_vdev_id + 10), 0);
  if ( *((_BYTE *)v11 + 21773) == 1 )
  {
    v14 = (char *)v11 + 21753;
LABEL_8:
    lim_send_edca_params(v11, v14, *(unsigned __int8 *)(v13 + 10), 1);
    return 0;
  }
  if ( *(_BYTE *)(v13 + 10041) == 1 )
  {
    v14 = (char *)(v13 + 10021);
    goto LABEL_8;
  }
  return 0;
}

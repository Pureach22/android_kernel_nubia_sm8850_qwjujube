__int64 __fastcall wma_pre_assoc_req(
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
  _QWORD *v11; // x20

  context = _cds_get_context(54, (__int64)"wma_pre_assoc_req", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = context;
  if ( (unsigned int)wma_update_iface_params(context, a1) )
    return 1;
  else
    return wma_save_bss_params(v11, a1);
}

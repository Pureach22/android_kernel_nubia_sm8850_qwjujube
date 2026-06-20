__int64 __fastcall sde_connector_handle_disp_recovery(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  if ( a3 )
    return sde_kms_handle_recovery(*(_QWORD *)(a3 + 2744), a2, a3, a4, a5, a6, a7, a8);
  else
    return 4294967274LL;
}

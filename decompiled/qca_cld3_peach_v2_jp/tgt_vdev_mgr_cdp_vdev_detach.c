__int64 __fastcall tgt_vdev_mgr_cdp_vdev_detach(
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
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 **v11; // x0
  __int64 v12; // x9
  __int64 (*v13)(void); // x9

  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 504) + 152LL);
  if ( !v9 )
    return 4;
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
    return 4;
  v11 = *(__int64 ***)(v10 + 2808);
  if ( !v11 )
    return 4;
  if ( !*v11 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_vdev_detach");
    return 16;
  }
  v12 = **v11;
  if ( !v12 )
    return 16;
  v13 = *(__int64 (**)(void))(v12 + 24);
  if ( !v13 )
    return 16;
  if ( *((_DWORD *)v13 - 1) != -1818723745 )
    __break(0x8229u);
  return v13();
}

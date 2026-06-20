__int64 __fastcall target_if_get_action_oui_v2_cap(
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

  if ( !a1 )
    return a1 & 1;
  v9 = *(_QWORD *)(a1 + 2800);
  if ( v9 )
  {
    a1 = *(_QWORD *)(v9 + 16);
    if ( a1 )
      LOBYTE(a1) = wmi_service_enabled(a1, 0x152u, a2, a3, a4, a5, a6, a7, a8, a9);
    return a1 & 1;
  }
  return 0;
}

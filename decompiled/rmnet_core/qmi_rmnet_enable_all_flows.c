__int64 __fastcall qmi_rmnet_enable_all_flows(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 i; // x21
  int v5; // w9
  _BOOL4 v6; // w8

  result = rmnet_get_qos_pt(a1);
  if ( result )
  {
    v3 = result;
    raw_spin_lock_bh(result + 332);
    for ( i = *(_QWORD *)(v3 + 56); i != v3 + 56; i = *(_QWORD *)i )
    {
      *(_WORD *)(i + 32) = 0;
      *(_BYTE *)(i + 34) = 0;
      *(_DWORD *)(i + 44) = 0;
      *(_WORD *)(i + 52) = 0;
      qmi_rmnet_watchdog_remove((unsigned __int8 *)i);
      if ( (*(_BYTE *)(i + 54) & 1) == 0 )
      {
        v5 = *(_DWORD *)(i + 24);
        v6 = qmi_rmnet_scale_factor == 1;
        *(_DWORD *)(i + 24) = 1;
        *(_DWORD *)(i + 28) = v6;
        if ( !v5 )
          dfc_bearer_flow_ctl(a1, i, v3);
      }
    }
    return raw_spin_unlock_bh(v3 + 332);
  }
  return result;
}

bool __fastcall qmi_rmnet_all_flows_enabled(__int64 a1)
{
  __int64 qos_pt; // x0
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9
  _BOOL4 v5; // w20

  qos_pt = rmnet_get_qos_pt(a1);
  if ( qos_pt )
  {
    v2 = qos_pt;
    raw_spin_lock_bh(qos_pt + 332);
    v3 = v2 + 56;
    v4 = v2 + 56;
    do
    {
      v4 = *(_QWORD *)v4;
      v5 = v4 == v3;
    }
    while ( v4 != v3 && *(_DWORD *)(v4 + 24) );
    raw_spin_unlock_bh(v2 + 332);
  }
  else
  {
    return 1;
  }
  return v5;
}

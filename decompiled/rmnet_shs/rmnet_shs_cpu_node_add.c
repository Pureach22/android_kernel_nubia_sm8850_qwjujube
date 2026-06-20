__int64 __fastcall rmnet_shs_cpu_node_add(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x2
  unsigned __int64 v3; // x8
  __int64 v5; // x9

  v2 = *a2;
  v3 = a1 + 64;
  if ( *(unsigned __int64 **)(*a2 + 8) != a2 || (unsigned __int64 *)v3 == a2 || v2 == v3 )
  {
    _list_add_valid_or_report(a1 + 64, a2);
    a1 = v5;
  }
  else
  {
    *(_QWORD *)(a1 + 64) = v2;
    *(_QWORD *)(a1 + 72) = a2;
    atomic_store(v3, a2);
    *(_QWORD *)(v2 + 8) = v3;
  }
  return rmnet_shs_change_cpu_num_flows(*(unsigned __int16 *)(a1 + 210), 1);
}

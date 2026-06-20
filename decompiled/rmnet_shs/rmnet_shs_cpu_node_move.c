__int64 __fastcall rmnet_shs_cpu_node_move(__int64 a1, __int64 *a2, unsigned int a3)
{
  _QWORD *v4; // x8
  __int64 *v5; // x9
  __int64 v6; // x10
  __int64 *v7; // x2
  __int64 *v9; // x11
  __int64 v10; // x10
  __int64 v11; // x10

  v4 = *(_QWORD **)(a1 + 72);
  v5 = (__int64 *)(a1 + 64);
  if ( *v4 == a1 + 64 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 64);
    a2 = v9;
    a1 = v10;
  }
  v7 = (__int64 *)*a2;
  if ( *(__int64 **)(*a2 + 8) != a2 || v5 == a2 || v7 == v5 )
  {
    _list_add_valid_or_report(v5, a2);
    a1 = v11;
  }
  else
  {
    v7[1] = (__int64)v5;
    *(_QWORD *)(a1 + 64) = v7;
    *(_QWORD *)(a1 + 72) = a2;
    *a2 = (__int64)v5;
  }
  rmnet_shs_change_cpu_num_flows(*(unsigned __int16 *)(a1 + 210), 1);
  return rmnet_shs_change_cpu_num_flows(a3, 0);
}

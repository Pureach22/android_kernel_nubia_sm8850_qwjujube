__int64 __fastcall rmnet_shs_cpu_node_remove(__int64 a1)
{
  _QWORD *v1; // x9
  __int64 *v2; // x8
  __int64 v3; // x10
  unsigned int v4; // w8
  __int64 v6; // x9

  v1 = *(_QWORD **)(a1 + 72);
  v2 = (__int64 *)(a1 + 64);
  if ( *v1 == a1 + 64 && (v3 = *v2, *(__int64 **)(*v2 + 8) == v2) )
  {
    *(_QWORD *)(v3 + 8) = v1;
    *v1 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 64);
    a1 = v6;
  }
  v4 = *(unsigned __int16 *)(a1 + 210);
  *(_QWORD *)(a1 + 72) = 0xDEAD000000000122LL;
  return rmnet_shs_change_cpu_num_flows(v4, 0);
}

__int64 wlan_get_pkt_stats_free_node()
{
  __int64 *v0; // x10
  __int64 v1; // x0
  __int64 *v2; // x1
  _QWORD *v3; // x9
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *v12; // x8
  __int64 v13; // x10

  v0 = &qword_826C98;
  v2 = (__int64 *)qword_826CA0;
  v1 = qword_826CA8;
  if ( (__int64 *)qword_826CA8 == &qword_826C98
    || qword_826CA0 == qword_826CA8
    || *(__int64 **)qword_826CA0 != &qword_826C98 )
  {
    _list_add_valid_or_report(qword_826CA8, qword_826CA0);
  }
  else
  {
    qword_826CA0 = qword_826CA8;
    *(_QWORD *)qword_826CA8 = &qword_826C98;
    *(_QWORD *)(v1 + 8) = v2;
    *v2 = v1;
  }
  v3 = (_QWORD *)qword_826C88;
  if ( (__int64 *)qword_826C88 == &qword_826C88 )
  {
    if ( (__int64 *)*v0 == v0 )
      return skb_trim(*(_QWORD *)(qword_826CA8 + 16), 0);
    qword_826CA8 = *v0;
    ++dword_826CB0;
    if ( (unsigned __int8)cds_is_multicast_logging() && (dword_826CB0 & 0x3F) == 0 )
      qdf_trace_msg(0x38u, 2u, "%s: drop_count = %u", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_get_pkt_stats_free_node");
    v3 = (_QWORD *)qword_826C98;
  }
  else
  {
    qword_826CA8 = qword_826C88;
  }
  v12 = (_QWORD *)v3[1];
  if ( (_QWORD *)*v12 == v3 && (v13 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v13 + 8) = v12;
    *v12 = v13;
  }
  else
  {
    _list_del_entry_valid_or_report(v3);
  }
  *v3 = v3;
  v3[1] = v3;
  return skb_trim(*(_QWORD *)(qword_826CA8 + 16), 0);
}

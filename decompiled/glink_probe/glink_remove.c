__int64 __fastcall glink_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x20
  _QWORD *v4; // x21
  _UNKNOWN **v5; // x24
  _QWORD *v6; // x8
  _UNKNOWN **v7; // x9

  v1 = *(_QWORD *)(a1 + 760);
  result = of_get_next_available_child(v1, 0);
  if ( result )
  {
    v3 = result;
    do
    {
      v4 = edge_infos;
      if ( edge_infos != (_UNKNOWN *)&edge_infos )
      {
        do
        {
          v5 = (_UNKNOWN **)*v4;
          qcom_unregister_ssr_notifier(v4[12], v4 + 9);
          v6 = (_QWORD *)v4[1];
          if ( (_QWORD *)*v6 == v4 && (v7 = (_UNKNOWN **)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
          {
            v7[1] = v6;
            *v6 = v7;
          }
          else
          {
            _list_del_entry_valid_or_report(v4);
          }
          *v4 = 0xDEAD000000000100LL;
          v4[1] = 0xDEAD000000000122LL;
          v4 = v5;
        }
        while ( v5 != &edge_infos );
      }
      result = of_get_next_available_child(v1, v3);
      v3 = result;
    }
    while ( result );
  }
  return result;
}

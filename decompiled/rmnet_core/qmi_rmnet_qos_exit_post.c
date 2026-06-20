__int64 __fastcall qmi_rmnet_qos_exit_post(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x26
  _QWORD *v5; // x0
  _QWORD *v6; // x9
  _QWORD *v7; // x8
  _QWORD *v8; // x28
  _QWORD *v9; // x0
  _QWORD *v10; // x9
  _QWORD *v11; // x8
  _QWORD *v12; // x28

  result = synchronize_rcu(a1);
  v2 = qos_cleanup_list;
  if ( qos_cleanup_list != (_UNKNOWN *)&qos_cleanup_list )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      v3 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v3 == v2 && (_QWORD *)v4[1] == v2 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      if ( !(unsigned int)rtnl_is_locked(result) && (qmi_rmnet_clean_flow_list___already_done & 1) == 0 )
      {
        qmi_rmnet_clean_flow_list___already_done = 1;
        _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c", 183);
        __break(0x800u);
      }
      v5 = (_QWORD *)v2[5];
      if ( v5 != v2 + 5 )
      {
        do
        {
          v8 = (_QWORD *)*v5;
          v7 = (_QWORD *)v5[1];
          if ( (_QWORD *)*v7 == v5 && (_QWORD *)v8[1] == v5 )
          {
            v8[1] = v7;
            *v7 = v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v5);
            v5 = v6;
          }
          *v5 = 0xDEAD000000000100LL;
          v5[1] = 0xDEAD000000000122LL;
          kfree(v5);
          v5 = v8;
        }
        while ( v8 != v2 + 5 );
      }
      v9 = (_QWORD *)v2[7];
      if ( v9 != v2 + 7 )
      {
        do
        {
          v12 = (_QWORD *)*v9;
          v11 = (_QWORD *)v9[1];
          if ( (_QWORD *)*v11 == v9 && (_QWORD *)v12[1] == v9 )
          {
            v12[1] = v11;
            *v11 = v12;
          }
          else
          {
            _list_del_entry_valid_or_report(v9);
            v9 = v10;
          }
          *v9 = 0xDEAD000000000100LL;
          v9[1] = 0xDEAD000000000122LL;
          kfree(v9);
          v9 = v12;
        }
        while ( v12 != v2 + 7 );
      }
      v2[39] = 0;
      v2[40] = 0;
      v2[37] = 0;
      v2[38] = 0;
      v2[35] = 0;
      v2[36] = 0;
      v2[33] = 0;
      v2[34] = 0;
      v2[31] = 0;
      v2[32] = 0;
      v2[29] = 0;
      v2[30] = 0;
      v2[27] = 0;
      v2[28] = 0;
      v2[25] = 0;
      v2[26] = 0;
      v2[23] = 0;
      v2[24] = 0;
      v2[21] = 0;
      v2[22] = 0;
      v2[19] = 0;
      v2[20] = 0;
      v2[17] = 0;
      v2[18] = 0;
      v2[15] = 0;
      v2[16] = 0;
      v2[13] = 0;
      v2[14] = 0;
      v2[11] = 0;
      v2[12] = 0;
      v2[9] = 0;
      v2[10] = 0;
      result = kfree(v2);
      v2 = v4;
    }
    while ( v4 != &qos_cleanup_list );
  }
  return result;
}

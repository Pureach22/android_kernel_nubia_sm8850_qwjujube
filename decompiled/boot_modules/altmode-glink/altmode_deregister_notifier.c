__int64 __fastcall altmode_deregister_notifier(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  int v5; // w0
  __int64 v6; // x20
  _QWORD *v7; // x0
  _QWORD *v8; // x9
  _QWORD *v9; // x8
  __int64 result; // x0
  unsigned int v11; // w19
  _QWORD *v12; // x9
  _QWORD v13[11]; // [xsp+8h] [xbp-58h] BYREF

  v13[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 744);
    memset(v13, 0, 80);
    v5 = _of_parse_phandle_with_args(v3, "qcom,altmode-dev", "#altmode-cells", 0xFFFFFFFFLL, 0, v13);
    if ( v5 )
    {
      v11 = v5;
      dev_err(a1, "Error parsing qcom,altmode-dev property: %d\n", v5);
      result = v11;
    }
    else
    {
      v6 = v13[0];
      mutex_lock(&notify_lock);
      v7 = probe_notify_list;
      if ( probe_notify_list != (_UNKNOWN *)&probe_notify_list )
      {
        while ( 1 )
        {
          v8 = (_QWORD *)*v7;
          if ( v7[2] == v6 && v7[4] == a2 )
            break;
          v7 = (_QWORD *)*v7;
          if ( v8 == &probe_notify_list )
            goto LABEL_12;
        }
        v9 = (_QWORD *)v7[1];
        if ( (_QWORD *)*v9 == v7 && (_QWORD *)v8[1] == v7 )
        {
          v8[1] = v9;
          *v9 = v8;
        }
        else
        {
          _list_del_entry_valid_or_report();
          v7 = v12;
        }
        *v7 = 0xDEAD000000000100LL;
        v7[1] = 0xDEAD000000000122LL;
        kfree();
      }
LABEL_12:
      mutex_unlock(&notify_lock);
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

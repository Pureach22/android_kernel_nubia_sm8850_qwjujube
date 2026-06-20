__int64 __fastcall altmode_register_notifier(__int64 a1, void (__fastcall *a2)(_QWORD), __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  int v9; // w0
  __int64 v10; // x21
  __int64 device_by_node; // x0
  __int64 v12; // x0
  void *v13; // x2
  unsigned int v14; // w19
  _QWORD v15[11]; // [xsp+8h] [xbp-58h] BYREF

  result = 4294967274LL;
  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && a3 )
  {
    v7 = *(_QWORD *)(a1 + 744);
    v8 = a1;
    memset(v15, 0, 80);
    v9 = _of_parse_phandle_with_args(v7, "qcom,altmode-dev", "#altmode-cells", 0xFFFFFFFFLL, 0, v15);
    if ( v9 )
    {
      v14 = v9;
      dev_err(v8, "Error parsing qcom,altmode-dev property: %d\n", v9);
      result = v14;
    }
    else
    {
      v10 = v15[0];
      mutex_lock(&notify_lock);
      device_by_node = of_find_device_by_node(v10);
      if ( device_by_node && *(_QWORD *)(device_by_node + 168) )
      {
        if ( *((_DWORD *)a2 - 1) != 251140989 )
          __break(0x8233u);
        a2(a3);
      }
      else
      {
        v12 = _kmalloc_cache_noprof(kfree, 3520, 40);
        if ( !v12 )
        {
          mutex_unlock(&notify_lock);
          result = 4294967284LL;
          goto LABEL_18;
        }
        *(_QWORD *)(v12 + 24) = a2;
        *(_QWORD *)(v12 + 32) = a3;
        v13 = probe_notify_list;
        *(_QWORD *)(v12 + 16) = v10;
        if ( v13 == (void *)v12 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)v13) != &probe_notify_list )
        {
          _list_add_valid_or_report();
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)v13) = v12;
          *(_QWORD *)v12 = v13;
          *(_QWORD *)(v12 + 8) = &probe_notify_list;
          probe_notify_list = (_UNKNOWN *)v12;
        }
      }
      mutex_unlock(&notify_lock);
      result = 0;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

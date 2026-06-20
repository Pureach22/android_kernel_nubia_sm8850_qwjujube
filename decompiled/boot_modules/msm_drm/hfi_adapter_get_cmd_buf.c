_QWORD *__fastcall hfi_adapter_get_cmd_buf(__int64 a1)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x10
  __int64 v6; // x2
  _QWORD *v7; // x1

  v2 = (_QWORD *)((__int64 (*)(void))hfi_adapter_get_cmd_buf_helper)();
  if ( v2 )
  {
    v2[15] = v2 + 15;
    v2[16] = v2 + 15;
    mutex_lock(a1 + 16);
    v3 = (_QWORD *)v2[14];
    v4 = v2 + 13;
    if ( (_QWORD *)*v3 == v2 + 13 && (v5 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v2 + 13);
    }
    v6 = a1 + 64;
    v2[13] = v2 + 13;
    v2[14] = v4;
    v7 = *(_QWORD **)(a1 + 72);
    if ( v4 == (_QWORD *)(a1 + 64) || v7 == v4 || *v7 != v6 )
    {
      _list_add_valid_or_report(v4, v7);
    }
    else
    {
      *(_QWORD *)(a1 + 72) = v4;
      v2[13] = v6;
      v2[14] = v7;
      *v7 = v4;
    }
    mutex_unlock(a1 + 16);
  }
  else
  {
    printk(&unk_21CF8B, "hfi_adapter_get_cmd_buf");
  }
  return v2;
}

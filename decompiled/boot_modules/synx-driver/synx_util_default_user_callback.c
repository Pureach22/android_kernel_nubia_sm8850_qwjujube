__int64 __fastcall synx_util_default_user_callback(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x20
  _QWORD *v8; // x0
  __int64 v9; // x2
  _QWORD *v10; // x1
  int v11; // w21

  if ( a3 && (v6 = *(_QWORD *)(a3 + 8)) != 0 )
  {
    if ( (synx_debug & 0x10) != 0 )
    {
      v11 = a2;
      printk(&unk_2563C, "verb", "synx_util_default_user_callback", 1365, *(_QWORD *)(v6 + 104), (unsigned int)result);
      a2 = v11;
    }
    *(_DWORD *)(a3 + 20) = a2;
    mutex_lock(v6 + 128);
    v8 = (_QWORD *)(a3 + 48);
    v9 = v6 + 176;
    v10 = *(_QWORD **)(v6 + 184);
    if ( a3 + 48 == v6 + 176 || v10 == v8 || *v10 != v9 )
    {
      _list_add_valid_or_report(v8, v10);
    }
    else
    {
      *(_QWORD *)(v6 + 184) = v8;
      *(_QWORD *)(a3 + 48) = v9;
      *(_QWORD *)(a3 + 56) = v10;
      *v10 = v8;
    }
    mutex_unlock(v6 + 128);
    return _wake_up(v6 + 192, 3, 0, 0);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return printk(&unk_2A5F2, &unk_29207, "synx_util_default_user_callback", 1372, a5, a6);
  }
  return result;
}

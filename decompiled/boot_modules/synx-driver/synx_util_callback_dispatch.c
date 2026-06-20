unsigned __int64 __fastcall synx_util_callback_dispatch(
        unsigned __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  _QWORD *v6; // x24
  unsigned __int64 v7; // x25
  __int64 v9; // x5
  _QWORD *v10; // x28
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x4
  __int64 v14; // x5

  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = *(_QWORD **)(result + 328);
    v7 = result + 328;
    if ( v6 != (_QWORD *)(result + 328) )
    {
      do
      {
        v9 = *(v6 - 5);
        v10 = (_QWORD *)*v6;
        if ( v9 != -1 )
        {
          if ( (synx_debug & 0x10) != 0 )
            printk(&unk_27236, "verb", "synx_util_callback_dispatch", 1391, v6 - 13, v9);
          timer_delete_sync(v6 - 10);
        }
        v11 = (_QWORD *)v6[1];
        *((_DWORD *)v6 - 22) = a2;
        if ( (_QWORD *)*v11 == v6 && (v12 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
        {
          *(_QWORD *)(v12 + 8) = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *v6 = v6;
        v6[1] = v6;
        result = queue_work_on(32, *(_QWORD *)(synx_dev + 160), v6 - 4);
        if ( (synx_debug & 0x10) != 0 )
          result = printk(&unk_286E1, "verb", "synx_util_callback_dispatch", 1398, v13, v14);
        v6 = v10;
      }
      while ( v10 != (_QWORD *)v7 );
    }
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return printk(&unk_2B3D9, &unk_29207, "synx_util_callback_dispatch", 1381, a5, a6);
  }
  return result;
}

__int64 __fastcall slim_stream_free(_QWORD *a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x0
  __int64 v5; // x9

  if ( a1 )
  {
    v1 = a1[1];
    raw_spin_lock(v1 + 952);
    v3 = (_QWORD *)a1[7];
    v4 = a1 + 6;
    if ( (_QWORD *)*v3 == a1 + 6 && (v5 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report();
    }
    a1[6] = 0xDEAD000000000100LL;
    a1[7] = 0xDEAD000000000122LL;
    raw_spin_unlock(v1 + 952);
    kfree(*a1);
    kfree(a1);
    return 0;
  }
  else
  {
    printk(&unk_87EB, "slim_stream_free");
    return 4294967274LL;
  }
}

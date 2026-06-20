__int64 __fastcall mhi_misc_unregister_controller(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x8
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x0

  v1 = *(_QWORD **)(*(_QWORD *)(result + 16) + 192LL);
  if ( v1 )
  {
    mutex_lock(&unk_21020);
    v2 = (_QWORD *)v1[1];
    if ( (_QWORD *)*v2 == v1 && (v3 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
    {
      *(_QWORD *)(v3 + 8) = v2;
      *v2 = v3;
    }
    else
    {
      _list_del_entry_valid_or_report(v1);
    }
    *v1 = 0xDEAD000000000100LL;
    v1[1] = 0xDEAD000000000122LL;
    mutex_unlock(&unk_21020);
    kfree(v1[19]);
    v4 = v1[12];
    if ( v4 )
    {
      kfree(*(_QWORD *)(v4 + 24));
      v5 = v1[12];
    }
    else
    {
      v5 = 0;
    }
    kfree(v5);
    kfree(v1[13]);
    return kfree(v1);
  }
  return result;
}

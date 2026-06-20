__int64 __fastcall destroy_votable(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  _QWORD *v3; // x10
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x11

  if ( result )
  {
    v1 = (_QWORD *)result;
    v2 = raw_spin_lock_irqsave(&votable_list_slock);
    v3 = (_QWORD *)v1[2];
    v4 = v1 + 1;
    v5 = v2;
    if ( (_QWORD *)*v3 == v1 + 1 && (v6 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v6 + 8) = v3;
      *v3 = v6;
    }
    else
    {
      _list_del_entry_valid_or_report(v1 + 1);
    }
    v1[1] = 0xDEAD000000000100LL;
    v1[2] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(&votable_list_slock, v5);
    kfree(*v1);
    return kfree(v1);
  }
  return result;
}

__int64 __fastcall qcom_sg_detach(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  _QWORD *v3; // x19
  _QWORD *v4; // x8
  _QWORD *v5; // x0
  __int64 v6; // x9

  v2 = *(_QWORD *)(a1 + 112);
  v3 = *(_QWORD **)(a2 + 64);
  mutex_lock(v2 + 24);
  v4 = (_QWORD *)v3[3];
  v5 = v3 + 2;
  if ( (_QWORD *)*v4 == v3 + 2 && (v6 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report();
  }
  v3[2] = 0xDEAD000000000100LL;
  v3[3] = 0xDEAD000000000122LL;
  mutex_unlock(v2 + 24);
  sg_free_table(v3[1]);
  kfree(v3[1]);
  return kfree(v3);
}

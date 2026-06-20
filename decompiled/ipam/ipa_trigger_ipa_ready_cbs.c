void ipa_trigger_ipa_ready_cbs()
{
  _QWORD *v0; // x19
  void (__fastcall *v1)(_QWORD); // x8
  _QWORD *v2; // x23
  __int64 v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // x9

  v0 = *(_QWORD **)(ipa3_ctx + 43640);
  if ( v0 != (_QWORD *)(ipa3_ctx + 43640) )
  {
    do
    {
      v1 = (void (__fastcall *)(_QWORD))v0[2];
      v2 = (_QWORD *)*v0;
      if ( v1 )
      {
        v3 = v0[3];
        if ( *((_DWORD *)v1 - 1) != 251140989 )
          __break(0x8228u);
        v1(v3);
      }
      v4 = (_QWORD *)v0[1];
      if ( (_QWORD *)*v4 == v0 && (v5 = (_QWORD *)*v0, *(_QWORD **)(*v0 + 8LL) == v0) )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *v0 = 0xDEAD000000000100LL;
      v0[1] = 0xDEAD000000000122LL;
      kfree(v0);
      v0 = v2;
    }
    while ( v2 != (_QWORD *)(ipa3_ctx + 43640) );
  }
}

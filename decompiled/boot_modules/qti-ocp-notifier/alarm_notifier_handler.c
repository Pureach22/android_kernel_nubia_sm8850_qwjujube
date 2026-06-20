__int64 __fastcall alarm_notifier_handler(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  if ( !(unsigned int)ocp_notifier_read_entry(a2, (__int64)(a2 + 7), 0, (__int64)&v5)
    && !(unsigned int)ocp_notifier_log_event(
                        a2,
                        (__int64)(a2 + 7),
                        (unsigned __int16 *)&v5,
                        "Regulator alarm during runtime:") )
  {
    v3 = idr_find(a2 + 1, (unsigned __int16)v5);
    if ( v3 )
      regulator_notifier_call_chain(v3, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}

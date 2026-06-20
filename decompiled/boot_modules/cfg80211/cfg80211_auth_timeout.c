__int64 __usercall cfg80211_auth_timeout@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X8>)
{
  __int64 *v4; // x19
  __int64 v5; // x9
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x10
  __int64 v11; // [xsp+8h] [xbp-18h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v4 = *(__int64 **)(a1 + 992);
  v5 = *v4;
  if ( *v4 )
  {
    a4 = a1;
    a3 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v12 = a3;
      v11 = a4;
      v8 = _traceiter_cfg80211_send_auth_timeout(0, a4);
      a4 = v11;
      v5 = 0;
      a3 = v12;
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v8, v9, v12);
        a4 = v11;
        v5 = 0;
        a3 = v12;
      }
    }
  }
  nl80211_send_auth_timeout(v5 - 992, a4, a3, 3264);
  return ((__int64 (__fastcall *)(__int64 *))cfg80211_sme_auth_timeout)(v4);
}

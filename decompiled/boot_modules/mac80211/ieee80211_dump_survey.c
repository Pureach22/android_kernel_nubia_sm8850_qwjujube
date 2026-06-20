__int64 __fastcall ieee80211_dump_survey(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 *v5; // x8
  _DWORD *v6; // x8
  unsigned __int64 StatusReg; // x20
  __int64 survey; // x0
  __int64 v10; // x8
  __int64 v11; // [xsp+0h] [xbp-10h]
  unsigned int v12; // [xsp+Ch] [xbp-4h]

  v5 = *(__int64 **)(a2 + 992);
  if ( v5 )
  {
    v4 = *v5;
    if ( *v5 )
      goto LABEL_3;
  }
  else
  {
    __break(0x800u);
  }
  __break(0x800u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v12 = a3;
    v11 = a4;
    survey = _traceiter_drv_get_survey(0, v4 + 1536, a3);
    a3 = v12;
    a4 = v11;
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
    {
      preempt_schedule_notrace(survey);
      a3 = v12;
      a4 = v11;
    }
  }
LABEL_3:
  v6 = *(_DWORD **)(*(_QWORD *)(v4 + 2000) + 392LL);
  if ( !v6 )
    return 4294967201LL;
  if ( *(v6 - 1) != -1997129224 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v6)(v4 + 1536, a3, a4);
}

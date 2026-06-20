__int64 __fastcall cfg80211_disconnect(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 *v3; // x22
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 result; // x0
  _DWORD *v10; // x8
  unsigned int v11; // w19
  unsigned __int64 StatusReg; // x23
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x8

  v3 = *(__int64 **)(a2 + 992);
  kfree_sensitive(v3[11]);
  v7 = v3[10];
  v3[11] = 0;
  *((_DWORD *)v3 + 25) = 0;
  if ( v7 )
  {
    v8 = *v3;
    if ( *v3 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(v8 - 992) + 352LL) )
      {
        if ( *(_DWORD *)(v7 + 400) < 2u )
        {
          LODWORD(result) = 0;
          goto LABEL_14;
        }
        result = cfg80211_mlme_deauth((__int64 *)(v8 - 992), v3[4], *(int **)(v7 + 16), 0, 0, a3, 0);
        v7 = v3[10];
        if ( v7 )
        {
LABEL_14:
          v11 = result;
          kfree(*(_QWORD *)(v7 + 416));
          kfree(v3[10]);
          result = v11;
          v3[10] = 0;
          if ( (*((_BYTE *)v3 + 164) & 1) != 0 )
            return result;
          goto LABEL_18;
        }
LABEL_17:
        if ( (*((_BYTE *)v3 + 164) & 1) != 0 )
          return result;
        goto LABEL_18;
      }
      result = 4294967201LL;
      if ( (*((_BYTE *)v3 + 164) & 1) != 0 )
        return result;
LABEL_18:
      *((_BYTE *)v3 + 318) = 0;
      return result;
    }
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v13 = _traceiter_rdev_disconnect(0, a1 + 124, a2, a3);
      v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v16;
      if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v13, v14, v15);
    }
LABEL_8:
    v10 = *(_DWORD **)(*a1 + 384);
    if ( *(v10 - 1) != 953464600 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64 *, __int64, _QWORD))v10)(a1 + 124, a2, a3);
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(*a1 + 384) )
  {
    cfg80211_mlme_down(a1, a2);
    result = 0;
    goto LABEL_17;
  }
  if ( *((_BYTE *)v3 + 318) )
    goto LABEL_8;
  result = 0;
  if ( (*((_BYTE *)v3 + 164) & 1) == 0 )
    goto LABEL_18;
  return result;
}

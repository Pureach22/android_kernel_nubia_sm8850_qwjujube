__int64 __fastcall ieee80211_set_wiphy_params(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int16 v3; // w20
  __int64 v4; // x29
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned int v6; // w0
  unsigned int v7; // w20
  __int64 result; // x0
  __int64 v9; // x1
  void (__fastcall *v10)(__int64, __int64); // x21
  __int64 v11; // x1
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v16; // x0
  __int64 v17; // x8

  if ( a1 )
  {
    v2 = a1;
    v3 = a2;
    if ( (a2 & 4) == 0 )
      goto LABEL_11;
    ieee80211_check_fast_xmit_all(a1 + 1536);
    a2 = *(unsigned int *)(v2 + 200);
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
      *(_DWORD *)(v4 - 4) = a2;
      v16 = _traceiter_drv_set_frag_threshold(0, v2 + 1536, *(unsigned int *)(v4 - 4));
      a2 = *(unsigned int *)(v4 - 4);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v16);
        a2 = *(unsigned int *)(v4 - 4);
      }
    }
  }
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 2000) + 248LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -1360243996 )
      __break(0x8228u);
    v6 = v5(v2 + 1536, a2);
  }
  else
  {
    v6 = 0;
  }
  if ( v6 )
  {
    v7 = v6;
    ieee80211_check_fast_xmit_all(v2 + 1536);
    return v7;
  }
LABEL_11:
  if ( (v3 & 0x30) == 0 )
    goto LABEL_27;
  v9 = (v3 & 0x10) != 0 ? *(unsigned __int8 *)(v2 + 208) : 0xFFFFLL;
  v10 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 2000) + 408LL);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -1160620618 )
      __break(0x8235u);
    v10(v2 + 1536, v9);
    result = 0;
  }
  else
  {
    result = 4294967201LL;
  }
  if ( v10 )
  {
LABEL_27:
    if ( (v3 & 8) == 0 )
      goto LABEL_28;
    v11 = *(unsigned int *)(v2 + 204);
    v12 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 2000) + 256LL);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -1360243996 )
        __break(0x8228u);
      result = v12(v2 + 1536, v11);
    }
    else
    {
      result = 0;
    }
    if ( !(_DWORD)result )
    {
LABEL_28:
      if ( (v3 & 1) != 0 )
      {
        v13 = *(unsigned __int8 *)(v2 + 196);
        if ( v13 > 0x1F )
          return 4294967274LL;
        *(_BYTE *)(v2 + 1552) = v13;
      }
      if ( (v3 & 2) != 0 )
      {
        v14 = *(unsigned __int8 *)(v2 + 197);
        if ( v14 > 0x1F )
          return 4294967274LL;
        *(_BYTE *)(v2 + 1551) = v14;
      }
      if ( (v3 & 3) != 0 )
        ieee80211_hw_config(v2 + 1536, 128);
      if ( (v3 & 0x1C0) != 0 )
        ieee80211_txq_set_params(v2 + 1536);
      return 0;
    }
  }
  return result;
}

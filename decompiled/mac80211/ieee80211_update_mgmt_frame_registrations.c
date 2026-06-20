__int64 __usercall ieee80211_update_mgmt_frame_registrations@<X0>(
        __int64 result@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X8>)
{
  _BOOL4 v4; // w19
  __int64 v5; // x29
  unsigned int v6; // w9
  _BOOL4 v7; // w11
  void (__fastcall *v8)(__int64, __int64, __int64, __int64); // x8
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x1
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x3
  __int64 v14; // x8
  __int64 v15; // [xsp+48h] [xbp+28h]

  if ( !result )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      *(_DWORD *)(v5 - 12) = a3;
      v13 = *(unsigned int *)(v5 - 12);
      v15 = a2;
      *(_QWORD *)(v5 - 8) = 0;
      _traceiter_drv_config_iface_filter(0, 1536, a4, v13, 256);
      a3 = *(unsigned int *)(v5 - 12);
      a2 = v15;
      result = *(_QWORD *)(v5 - 8);
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(result);
        a3 = *(unsigned int *)(v5 - 12);
        a2 = v15;
        result = *(_QWORD *)(v5 - 8);
      }
    }
    goto LABEL_14;
  }
  v4 = ((*(_DWORD *)a3 >> 4) & 1) != *(_BYTE *)(result + 2888)
    || ((*(_DWORD *)(a3 + 8) >> 13) & 1) != *(unsigned __int8 *)(result + 2889);
  *(_BYTE *)(result + 2888) = (*(_DWORD *)a3 & 0x10) != 0;
  *(_BYTE *)(result + 2889) = (*(_DWORD *)(a3 + 8) & 0x2000) != 0;
  v6 = *(_DWORD *)(a3 + 4);
  v7 = ((v6 >> 4) & 1) != *(_BYTE *)(a2 + 5864) || ((*(_DWORD *)(a3 + 12) >> 13) & 1) != *(unsigned __int8 *)(a2 + 5865);
  *(_BYTE *)(a2 + 5864) = (*(_DWORD *)(a3 + 4) & 0x10) != 0;
  *(_BYTE *)(a2 + 5865) = (*(_DWORD *)(a3 + 12) & 0x2000) != 0;
  if ( *(_DWORD *)(result + 2852) )
  {
    if ( !v7 || (*(_QWORD *)(a2 + 1616) & 1) == 0 )
    {
LABEL_18:
      if ( v4 )
        return ieee80211_configure_filter(result + 1536);
      return result;
    }
    if ( ((v6 >> 4) & 1) != 0 )
      a3 = 256;
    else
      a3 = 0;
LABEL_14:
    v8 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(result + 2000) + 136LL);
    if ( v8 )
    {
      v9 = result;
      v10 = result + 1536;
      v11 = a2 + 4704;
      if ( *((_DWORD *)v8 - 1) != 1677116977 )
        __break(0x8228u);
      v8(v10, v11, a3, 256);
      result = v9;
    }
    goto LABEL_18;
  }
  return result;
}

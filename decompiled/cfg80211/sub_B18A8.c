// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_B18A8@<X0>(__int64 a1@<X0>, __int16 a2@<W8>)
{
  __int64 v2; // x9
  int v3; // w17
  __int64 v4; // x19
  _QWORD *v5; // x20
  __int64 v6; // x21
  __int64 v7; // x26
  __int64 v8; // x27
  __int64 result; // x0
  unsigned int v10; // [xsp-74h] [xbp-74h]

  if ( (v3 & 0x40000) == 0 )
    return ieee80211_hdrlen(a1);
  if ( v2 )
  {
    a2 |= 0x400u;
    *(_WORD *)(v6 + 60) = a2;
  }
  if ( v5[44] )
  {
    a2 |= 0x800u;
    *(_WORD *)(v6 + 60) = a2;
  }
  if ( v5[48] )
  {
    a2 |= 0x1000u;
    *(_WORD *)(v6 + 60) = a2;
  }
  if ( v5[52] )
  {
    a2 |= 0x2000u;
    *(_WORD *)(v6 + 60) = a2;
  }
  if ( v5[56] )
    *(_WORD *)(v6 + 60) = a2 | 0x4000;
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, __int64, _QWORD))perf_trace_run_bpf_submit)(
             v6,
             68,
             v10,
             v4,
             1,
             v8 + v7,
             0);
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall trace_event_raw_event_cfg80211_mlo_reconf_add_done(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        const void *a4,
        size_t a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v9 & 0x2C0) == 0 || (v9 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      *(_DWORD *)(result + 32) = ((_DWORD)a5 << 16) | 0x24;
      v11 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v11;
      LODWORD(v11) = *(_DWORD *)(a2 + 224);
      *(_WORD *)(result + 28) = a3;
      *(_DWORD *)(result + 24) = v11;
      memcpy((void *)(result + 36), a4, a5);
      result = trace_event_buffer_commit(v12);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

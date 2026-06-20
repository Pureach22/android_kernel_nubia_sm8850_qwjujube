void __fastcall trace_event_raw_event_cfg80211_pmsr_report(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        int *a5)
{
  __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x24
  __int64 v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w8
  int v16; // w9
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 && (_trace_trigger_soft_disabled(a1) & 1) != 0 )
    goto LABEL_17;
  v10 = trace_event_buffer_reserve(v17);
  if ( !v10 )
    goto LABEL_17;
  v11 = *(const char **)(a2 + 504);
  v12 = v10;
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v13 = strnlen(v11, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v12 + 8, v11);
      v15 = 0;
      if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
        v15 = *(_DWORD *)(a3 + 40);
      *(_DWORD *)(v12 + 40) = v15;
      *(_QWORD *)(v12 + 48) = a4;
      if ( a5 )
      {
        v16 = *a5;
        *(_WORD *)(v12 + 60) = *((_WORD *)a5 + 2);
        *(_DWORD *)(v12 + 56) = v16;
      }
      else
      {
        *(_WORD *)(v12 + 60) = 0;
        *(_DWORD *)(v12 + 56) = 0;
      }
      trace_event_buffer_commit(v17);
LABEL_17:
      _ReadStatusReg(SP_EL0);
      JUMPOUT(0xA8C44);
    }
  }
  _fortify_panic(7, 32);
  JUMPOUT(0xA8C80);
}

void __fastcall perf_trace_cfg80211_stop_iface(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x23
  __int64 v5; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v7; // x0
  _QWORD *v8; // x9
  __int64 v9; // x21
  const char *v10; // x23
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  int v14; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v16; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v5 = *(_QWORD *)(a1 + 104);
  v14 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    v7 = perf_trace_buf_alloc(44, v15, &v14);
    if ( v7 )
    {
      v8 = (_QWORD *)v15[0];
      v9 = v7;
      *(_QWORD *)(v15[0] + 232LL) = &v16;
      v8[33] = 5;
      v8[31] = &v13;
      v8[32] = v3;
      v10 = *(const char **)(a2 + 504);
      if ( !v10 )
        v10 = *(const char **)(a2 + 392);
      v11 = strnlen(v10, 0x20u);
      if ( v11 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v11 == 32 )
          v12 = 32;
        else
          v12 = v11 + 1;
        if ( v12 < 0x21 )
        {
          sized_strscpy(v9 + 8, v10);
          JUMPOUT(0xA8A98);
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0xA8B28);
    }
  }
  JUMPOUT(0xA8AD4);
}

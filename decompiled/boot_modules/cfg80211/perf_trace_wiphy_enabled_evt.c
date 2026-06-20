__int64 __fastcall perf_trace_wiphy_enabled_evt(__int64 result, __int64 a2, char a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v6; // x19
  __int64 v8; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v10; // x9
  __int64 v11; // x21
  const char *v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x2
  __int64 v16; // x5
  __int64 v17; // x0
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v21; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v6 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v8 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v8) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(44, v20, &v19);
  if ( !result )
    goto LABEL_12;
  v10 = (_QWORD *)v20[0];
  v11 = result;
  *(_QWORD *)(v20[0] + 232LL) = &v21;
  v10[33] = 5;
  v10[31] = &v18;
  v10[32] = v4;
  v12 = *(const char **)(a2 + 504);
  if ( !v12 )
    v12 = *(const char **)(a2 + 392);
  v13 = strnlen(v12, 0x20u);
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
      sized_strscpy(v11 + 8, v12);
      v15 = v19;
      v16 = v20[0];
      *(_BYTE *)(v11 + 40) = a3 & 1;
      result = perf_trace_run_bpf_submit(v11, 44, v15, v6, 1, v16, StatusReg + v8, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v17 = _fortify_panic(7, 32);
  return trace_event_raw_event_rdev_add_virtual_intf(v17);
}

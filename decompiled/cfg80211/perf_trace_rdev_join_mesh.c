void __fastcall perf_trace_rdev_join_mesh(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x24
  __int64 v5; // x25
  unsigned __int64 StatusReg; // x26
  _QWORD *v7; // x9
  const char *v8; // x24
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v5 = *(_QWORD *)(a1 + 104);
  v10 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( (*(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5)) && perf_trace_buf_alloc(124, v11, &v10) )
  {
    v7 = (_QWORD *)v11[0];
    *(_QWORD *)(v11[0] + 232LL) = &vars0;
    v7[33] = 5;
    v7[31] = &v9;
    v7[32] = v3;
    v8 = *(const char **)(a2 + 504);
    if ( !v8 )
      v8 = *(const char **)(a2 + 392);
    strnlen(v8, 0x20u);
    JUMPOUT(0x94368);
  }
  JUMPOUT(0x9448C);
}

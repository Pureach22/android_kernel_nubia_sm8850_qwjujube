void __fastcall perf_trace_api_request_smps(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w0
  __int64 v5; // x28
  unsigned __int64 StatusReg; // x20
  int v7; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v7 = 0;
  v4 = strlen((const char *)(a3 + 1640));
  v5 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v5) )
  {
    if ( perf_trace_buf_alloc(((v4 + 84) & 0xFFFFFFF8) - 4, v8, &v7) )
      JUMPOUT(0x9BA54);
  }
  JUMPOUT(0x9BB28);
}

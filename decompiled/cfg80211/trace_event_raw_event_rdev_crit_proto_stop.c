__int64 __fastcall trace_event_raw_event_rdev_crit_proto_stop(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  const char *v7; // x22
  __int64 v8; // x20
  size_t v9; // x0
  unsigned __int64 v10; // x2
  int v11; // w8
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v5 & 0x2C0) != 0 && (v5 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v12);
  if ( !result )
    goto LABEL_14;
  v7 = *(const char **)(a2 + 504);
  v8 = result;
  if ( !v7 )
    v7 = *(const char **)(a2 + 392);
  v9 = strnlen(v7, 0x20u);
  if ( v9 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_19;
  }
  if ( v9 == 32 )
    v10 = 32;
  else
    v10 = v9 + 1;
  if ( v10 >= 0x21 )
  {
LABEL_19:
    _fortify_panic(7, 32);
    JUMPOUT(0x3B1AB34);
  }
  sized_strscpy(v8 + 8, v7);
  v11 = 0;
  if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
    v11 = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(v8 + 40) = v11;
  result = trace_event_buffer_commit(v12);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}

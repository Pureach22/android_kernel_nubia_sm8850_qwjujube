__int64 __fastcall trace_event_raw_event_iommu_tlbi(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  const char **v4; // x23
  const char *v5; // x21
  const char *v6; // x8
  const char *v7; // x0
  int v8; // w20
  __int64 result; // x0
  __int64 v10; // x9
  int v11; // w8
  __int64 v12; // x19
  __int64 v13; // x20
  const char *v14; // x1
  __int64 v15; // x20
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v3 & 0x2C0) == 0
    || (v3 & 0x100) != 0
    || (v15 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v15, (result & 1) == 0) )
  {
    v4 = *(const char ***)(a2 + 8);
    v5 = v4[14];
    v6 = v5;
    if ( !v5 )
      v6 = *v4;
    if ( v6 )
      v7 = v6;
    else
      v7 = "(null)";
    v8 = strlen(v7) + 1;
    if ( !v5 )
      v5 = *v4;
    result = trace_event_buffer_reserve(v16, a1, v8 + 12LL);
    if ( result )
    {
      v10 = (unsigned __int16)v8;
      v11 = (v8 << 16) | 0xC;
      v12 = result + 12;
      v13 = (unsigned __int16)v8 - 1LL;
      if ( v5 )
        v14 = v5;
      else
        v14 = "(null)";
      *(_DWORD *)(result + 8) = v11;
      memcpy((void *)(result + 12), v14, v10 - 1);
      *(_BYTE *)(v12 + v13) = 0;
      result = trace_event_buffer_commit(v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

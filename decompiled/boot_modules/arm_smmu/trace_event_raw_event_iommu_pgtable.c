__int64 __fastcall trace_event_raw_event_iommu_pgtable(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  const char **v10; // x26
  const char *v11; // x24
  const char *v12; // x8
  const char *v13; // x0
  int v14; // w23
  __int64 result; // x0
  __int64 v16; // x9
  int v17; // w8
  __int64 v18; // x22
  __int64 v19; // x23
  const char *v20; // x1
  _QWORD *v21; // x24
  __int64 v22; // x23
  _QWORD v23[7]; // [xsp+8h] [xbp-38h] BYREF

  v23[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v23, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v22 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v22, (result & 1) == 0) )
  {
    v10 = *(const char ***)(a2 + 8);
    v11 = v10[14];
    v12 = v11;
    if ( !v11 )
      v12 = *v10;
    if ( v12 )
      v13 = v12;
    else
      v13 = "(null)";
    v14 = strlen(v13) + 1;
    if ( !v11 )
      v11 = *v10;
    result = trace_event_buffer_reserve(v23, a1, v14 + 40LL);
    if ( result )
    {
      v16 = (unsigned __int16)v14;
      v17 = (v14 << 16) | 0x28;
      v18 = result + 40;
      v19 = (unsigned __int16)v14 - 1LL;
      if ( v11 )
        v20 = v11;
      else
        v20 = "(null)";
      v21 = (_QWORD *)result;
      *(_DWORD *)(result + 8) = v17;
      memcpy((void *)(result + 40), v20, v16 - 1);
      *(_BYTE *)(v18 + v19) = 0;
      v21[2] = a3;
      v21[3] = a4;
      v21[4] = a5;
      result = trace_event_buffer_commit(v23);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

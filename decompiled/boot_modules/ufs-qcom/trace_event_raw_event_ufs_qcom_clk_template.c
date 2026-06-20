__int64 __fastcall trace_event_raw_event_ufs_qcom_clk_template(__int64 a1, const char *a2, int a3, char a4, int a5)
{
  __int64 v9; // x8
  const char *v10; // x23
  int v11; // w24
  __int64 result; // x0
  char v13; // w25
  int v14; // w8
  __int64 v15; // x21
  size_t v16; // x22
  __int64 v17; // x24
  const char *v18; // x23
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v9 & 0x2C0) == 0
    || (v9 & 0x100) != 0
    || (v18 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v18, (result & 1) == 0) )
  {
    if ( a2 )
      v10 = a2;
    else
      v10 = "(null)";
    v11 = strlen(v10) + 1;
    result = trace_event_buffer_reserve(v19, a1, v11 + 24LL);
    if ( result )
    {
      v13 = a4 & 1;
      v14 = (v11 << 16) | 0x18;
      v15 = result + 24;
      v16 = (unsigned __int16)v11 - 1LL;
      v17 = result;
      *(_DWORD *)(result + 8) = v14;
      memcpy((void *)(result + 24), v10, v16);
      *(_BYTE *)(v15 + v16) = 0;
      *(_DWORD *)(v17 + 12) = a3;
      *(_BYTE *)(v17 + 16) = v13;
      *(_DWORD *)(v17 + 20) = a5;
      result = trace_event_buffer_commit(v19);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

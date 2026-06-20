__int64 __fastcall trace_event_raw_event_spi_log_info(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v5; // x8
  const char *v6; // x21
  int v7; // w22
  __int64 result; // x0
  __int64 v9; // x20
  __int64 v10; // x23
  unsigned int v11; // w8
  size_t v12; // x22
  const char *v13; // x2
  __int64 *v14; // x8
  char *v15; // x0
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x12
  const char *v20; // x21
  _QWORD arg[4]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v22[7]; // [xsp+28h] [xbp-38h] BYREF

  v22[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v22, 0, 48);
  if ( (v5 & 0x2C0) == 0
    || (v5 & 0x100) != 0
    || (v20 = a2, result = _trace_trigger_soft_disabled(a1), a2 = v20, (result & 1) == 0) )
  {
    v6 = a2 ? a2 : "(null)";
    v7 = strlen(v6);
    result = trace_event_buffer_reserve(v22, a1, v7 + 257 + 16LL);
    if ( result )
    {
      v9 = result + 16;
      v10 = result;
      v11 = (v7 << 16) + 65552;
      *(_DWORD *)(result + 8) = v11;
      *(_DWORD *)(result + 12) = (v7 + 17) | 0x1000000;
      v12 = HIWORD(v11) - 1LL;
      memcpy((void *)(result + 16), v6, v12);
      *(_BYTE *)(v9 + v12) = 0;
      v13 = *(const char **)a3;
      v14 = *(__int64 **)(a3 + 8);
      v15 = (char *)(v10 + *(unsigned __int16 *)(v10 + 12));
      v17 = v14[2];
      v16 = v14[3];
      v19 = *v14;
      v18 = v14[1];
      arg[2] = v17;
      arg[3] = v16;
      arg[0] = v19;
      arg[1] = v18;
      if ( vsnprintf(v15, 0x100u, v13, arg) >= 256 )
        __break(0x800u);
      result = trace_event_buffer_commit(v22);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

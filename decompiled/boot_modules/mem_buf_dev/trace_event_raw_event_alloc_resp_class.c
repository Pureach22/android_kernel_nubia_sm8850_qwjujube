__int64 __fastcall trace_event_raw_event_alloc_resp_class(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x23
  size_t v6; // x22
  const char *v7; // x0
  size_t v8; // x0
  size_t v9; // x21
  unsigned __int64 v10; // x24
  const char *v11; // x22
  __int64 result; // x0
  __int64 v13; // x20
  __int64 v14; // x23
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v4 & 0x2C0) != 0 && (v4 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_13;
  }
  v5 = (unsigned int)a2[1];
  if ( (unsigned int)v5 > 3 )
  {
    v7 = "(null)";
    v6 = 7;
  }
  else
  {
    v6 = qword_14B00[v5];
    v7 = (&off_14170)[v5];
  }
  v8 = strnlen(v7, v6);
  v9 = v8;
  if ( v8 > v6 )
  {
    _fortify_panic(2, v6, v8 + 1);
LABEL_18:
    _fortify_panic(4, v6, v9 + 1);
  }
  if ( v8 >= v6 )
    goto LABEL_18;
  if ( (unsigned int)v5 > 3 )
  {
    v11 = "(null)";
    v10 = 7;
  }
  else
  {
    v10 = qword_14B00[v5];
    v11 = (&off_14170)[v5];
  }
  result = trace_event_buffer_reserve(v19, a1, v8 + 25);
  if ( result )
  {
    *(_DWORD *)(result + 12) = ((_DWORD)v9 << 16) + 65560;
    *(_DWORD *)(result + 8) = *a2;
    if ( v10 < v9 )
    {
      _fortify_panic(16, -1, v9);
      __asm { STLLRB          WZR, [X28] }
      JUMPOUT(0x10F08);
    }
    v13 = result + 24;
    v14 = result;
    memcpy((void *)(result + 24), v11, v9);
    *(_BYTE *)(v13 + v9) = 0;
    *(_DWORD *)(v14 + 16) = a2[3];
    *(_DWORD *)(v14 + 20) = a2[4];
    result = trace_event_buffer_commit(v19);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

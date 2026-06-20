size_t __fastcall perf_trace_rdev_add_virtual_intf(__int64 a1, __int64 a2, const char *a3, int a4)
{
  __int64 v4; // x30
  __int64 v6; // x25
  const char *v9; // x21
  size_t result; // x0
  __int64 v11; // x27
  unsigned __int64 StatusReg; // x28
  int v13; // w26
  unsigned int v14; // w22
  _QWORD *v15; // x9
  size_t v16; // x23
  const char *v17; // x25
  size_t v18; // x0
  unsigned __int64 v19; // x2
  int v20; // w8
  void *v21; // x24
  size_t v22; // x25
  __int64 v23; // x2
  __int64 v24; // x5
  __int64 v25; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v6 = v4;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v9 = a3;
  else
    v9 = "<noname>";
  v27[0] = 0;
  v26 = 0;
  result = strlen(v9);
  v11 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v13 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v14 = ((result + 60) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v14, v27, &v26);
    if ( result )
    {
      v15 = (_QWORD *)v27[0];
      *(_QWORD *)(v27[0] + 232LL) = &vars0;
      v16 = result;
      v15[31] = &v25;
      v15[32] = v6;
      v15[33] = 5;
      *(_DWORD *)(result + 40) = (v13 << 16) + 65584;
      v17 = *(const char **)(a2 + 504);
      if ( !v17 )
        v17 = *(const char **)(a2 + 392);
      v18 = strnlen(v17, 0x20u);
      if ( v18 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v18 == 32 )
          v19 = 32;
        else
          v19 = v18 + 1;
        if ( v19 < 0x21 )
        {
          sized_strscpy(v16 + 8, v17);
          v20 = *(_DWORD *)(v16 + 40);
          v21 = (void *)(v16 + (unsigned __int16)v20);
          v22 = HIWORD(v20) - 1LL;
          memcpy(v21, v9, v22);
          *((_BYTE *)v21 + v22) = 0;
          v23 = v26;
          v24 = v27[0];
          *(_DWORD *)(v16 + 44) = a4;
          result = perf_trace_run_bpf_submit(v16, v14, v23, a1, 1, v24, StatusReg + v11, 0);
          goto LABEL_15;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x3B0C308);
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}

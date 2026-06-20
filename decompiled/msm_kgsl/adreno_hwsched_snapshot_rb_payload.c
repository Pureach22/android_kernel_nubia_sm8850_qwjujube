__int64 __fastcall adreno_hwsched_snapshot_rb_payload(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v6; // x26
  int v7; // w24
  __int64 v8; // x21
  __int64 v9; // x21
  __int64 v10; // x23
  const void *v11; // x0
  const void *v12; // x25
  int v13; // w0
  __int64 result; // x0
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 v20; // [xsp+10h] [xbp-20h] BYREF
  char s[8]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a2[11];
  v7 = adreno_hwsched_parse_payload(a3, 4);
  *(_QWORD *)s = 0;
  v22 = 0;
  v8 = (unsigned int)adreno_hwsched_parse_payload(a3, 7);
  v9 = v8 | (adreno_hwsched_parse_payload(a3, 8) << 32);
  if ( a2[12] >= 8u
    && (v10 = (unsigned int)(4 * v7),
        (v11 = (const void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))adreno_hwsched_get_rb_hostptr)(
                               a1,
                               v9,
                               (unsigned int)v10)) != nullptr)
    && a2[12] - 8LL >= (unsigned __int64)(v10 + 44)
    && (v12 = v11, v6 != -52)
    && (memcpy((void *)(v6 + 52), v11, (unsigned int)(4 * v7)), (_DWORD)v10) )
  {
    if ( *(_BYTE *)(a1 + 14152) == 1 )
    {
      v19 = 0;
      v20 = 0;
      adreno_readreg64(a1, 0, 1u, &v20);
      adreno_readreg64(a1, 2u, 3u, &v19);
      if ( v20 == v9 || v19 == v9 )
        adreno_snapshot_dump_all_ibs(a1, v12, a2);
    }
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = v7 & 0x3FFFFFFF;
    *(_DWORD *)(v6 + 24) = adreno_hwsched_parse_payload(a3, 2);
    v13 = adreno_hwsched_parse_payload(a3, 3);
    *(_DWORD *)(v6 + 16) = v7 & 0x3FFFFFFF;
    *(_DWORD *)(v6 + 20) = v13;
    *(_DWORD *)(v6 + 28) = v7 & 0x3FFFFFFF;
    *(_DWORD *)(v6 + 32) = adreno_hwsched_parse_payload(a3, 5);
    *(_DWORD *)(v6 + 36) = adreno_hwsched_parse_payload(a3, 6);
    *(_QWORD *)(v6 + 40) = v9;
    result = adreno_hwsched_parse_payload(a3, 1);
    v15 = (unsigned int)(v10 + 52);
    *(_DWORD *)(v6 + 48) = result;
    *(_DWORD *)v6 = 50506701;
    *(_DWORD *)(v6 + 4) = v15;
    v16 = a2[10];
    v17 = a2[11] + v15;
    v18 = a2[12];
    a2[11] = v17;
    a2[12] = v18 - *(unsigned int *)(v6 + 4);
    a2[10] = v16 + *(unsigned int *)(v6 + 4);
  }
  else
  {
    snprintf(s, 0x10u, "RB addr:0x%llx", v9);
    result = __ratelimit(&adreno_hwsched_snapshot_rb_payload__rs, "adreno_hwsched_snapshot_rb_payload");
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", s);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall print_fault_syncobj(__int64 result, int a2, int a3)
{
  _QWORD *v3; // x26
  _QWORD *v4; // x27
  _QWORD *v6; // x20
  __int64 v8; // x28
  unsigned int v9; // w23
  _QWORD *v10; // x24
  char v11; // w0
  __int64 v12; // x22
  char v13; // w25
  _DWORD *v14; // x8
  _QWORD v15[5]; // [xsp+8h] [xbp-28h] BYREF

  v15[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(result + 22768);
  v4 = (_QWORD *)(result + 22768);
  if ( v3 != (_QWORD *)(result + 22768) )
  {
    v6 = (_QWORD *)result;
    do
    {
      v8 = *(v3 - 1);
      if ( *(_DWORD *)(v8 + 16) == 4
        && *(_DWORD *)(*(_QWORD *)(v8 + 8) + 4LL) == a2
        && *(_DWORD *)(v8 + 20) == a3
        && *(_DWORD *)(v8 + 136) )
      {
        v9 = 0;
        do
        {
          v10 = *(_QWORD **)(*(_QWORD *)(v8 + 144) + 16LL * (int)v9);
          v11 = is_kgsl_fence(v10);
          v12 = v10[6];
          v13 = v11;
          strcpy((char *)v15, "unknown");
          memset(&v15[1], 0, 24);
          v14 = *(_DWORD **)(v10[1] + 64LL);
          if ( v14 )
          {
            if ( *(v14 - 1) != -938580849 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, _QWORD *, __int64))v14)(v10, v15, 32);
          }
          result = dev_err(
                     *v6,
                     "dma fence[%d] signaled:%d kgsl:%d ctx:%llu seqno:%llu value:%s\n",
                     v9++,
                     v12 & 1,
                     v13 & 1,
                     v10[4],
                     v10[5],
                     (const char *)v15);
        }
        while ( v9 < *(_DWORD *)(v8 + 136) );
      }
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != v4 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

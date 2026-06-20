void __fastcall perf_trace_rdev_assoc_ml_reconf(__int64 a1, __int64 a2, __int64 a3, __int64 *a4, __int16 a5)
{
  __int64 v5; // x30
  __int64 v6; // x25
  __int64 v11; // x26
  unsigned __int64 StatusReg; // x27
  __int64 v13; // x0
  _QWORD *v14; // x9
  __int64 v15; // x21
  const char *v16; // x25
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v24; // [xsp+20h] [xbp+0h] BYREF

  v6 = v5;
  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  v11 = *(_QWORD *)(a1 + 104);
  v22 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v11) )
  {
    v13 = perf_trace_buf_alloc(68, v23, &v22);
    if ( v13 )
    {
      v14 = (_QWORD *)v23[0];
      v15 = v13;
      *(_QWORD *)(v23[0] + 232LL) = &v24;
      v14[33] = 5;
      v14[31] = &v21;
      v14[32] = v6;
      v16 = *(const char **)(a2 + 504);
      if ( !v16 )
        v16 = *(const char **)(a2 + 392);
      v17 = strnlen(v16, 0x20u);
      if ( v17 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v17 == 32 )
          v18 = 32;
        else
          v18 = v17 + 1;
        if ( v18 < 0x21 )
        {
          sized_strscpy(v15 + 8, v16);
          v19 = *(_QWORD *)(a3 + 304);
          *(_QWORD *)(v15 + 40) = *(_QWORD *)(a3 + 296);
          *(_QWORD *)(v15 + 48) = v19;
          LODWORD(v19) = *(_DWORD *)(a3 + 224);
          *(_WORD *)(v15 + 60) = 0;
          *(_WORD *)(v15 + 62) = a5;
          *(_DWORD *)(v15 + 56) = v19;
          if ( a4 )
          {
            v20 = *a4;
            if ( *a4 )
            {
              LOWORD(v20) = 1;
              *(_WORD *)(v15 + 60) = 1;
            }
            if ( a4[4] )
            {
              LOWORD(v20) = v20 | 2;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[8] )
            {
              LOWORD(v20) = v20 | 4;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[12] )
            {
              LOWORD(v20) = v20 | 8;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[16] )
            {
              LOWORD(v20) = v20 | 0x10;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[20] )
            {
              LOWORD(v20) = v20 | 0x20;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[24] )
            {
              LOWORD(v20) = v20 | 0x40;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[28] )
            {
              LOWORD(v20) = v20 | 0x80;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[32] )
            {
              LOWORD(v20) = v20 | 0x100;
              *(_WORD *)(v15 + 60) = v20;
            }
            if ( a4[36] )
              *(_WORD *)(v15 + 60) = v20 | 0x200;
            JUMPOUT(0xAA538);
          }
          JUMPOUT(0xAA584);
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0xAA600);
    }
  }
  JUMPOUT(0xAA5A8);
}

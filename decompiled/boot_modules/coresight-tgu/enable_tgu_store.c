__int64 __fastcall enable_tgu_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  int v14; // w12
  int v15; // w11
  int v16; // w8
  int v17; // w9
  int v18; // w12
  int v19; // w13
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x10
  unsigned int v32; // w8
  unsigned int v39; // w10
  _QWORD v40[2]; // [xsp+0h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v40[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v40) )
  {
    a4 = -22;
  }
  else
  {
    v8 = *(_QWORD *)(v6 + 8);
    v9 = _pm_runtime_resume(v8, 4);
    if ( v9 < 0 )
    {
      v32 = *(_DWORD *)(v8 + 480);
      do
      {
        if ( !v32 )
          break;
        _X12 = (unsigned int *)(v8 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v39 = __ldxr(_X12);
          if ( v39 != v32 )
            break;
          if ( !__stlxr(v32 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v39 == v32;
        v32 = v39;
      }
      while ( !_ZF );
      a4 = v9;
    }
    else
    {
      raw_spin_lock(v6 + 32);
      *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = -978530731;
      __dsb(0xFu);
      v10 = v40[0];
      **(_DWORD **)v6 = 0;
      if ( v10 )
      {
        if ( *(int *)(v6 + 96) >= 1 )
        {
          v11 = 0;
          v12 = 0;
          do
          {
            ++v12;
            v13 = *(_QWORD *)(v6 + 56) + v11;
            v11 += 16;
            *(_DWORD *)(*(_QWORD *)v6 + *(_QWORD *)v13) = *(_DWORD *)(v13 + 8);
          }
          while ( v12 < *(int *)(v6 + 96) );
        }
        v14 = *(_DWORD *)(v6 + 40);
        if ( (v14 & 0x80000000) == 0 )
        {
          v15 = *(_DWORD *)(v6 + 36);
          v16 = 0;
          v17 = 80;
          do
          {
            if ( (v15 & 0x80000000) == 0 )
            {
              v18 = 0;
              v19 = v17;
              do
              {
                ++v18;
                *(_DWORD *)(*(_QWORD *)v6 + v19) = 0x1000000;
                v19 += 472;
                v15 = *(_DWORD *)(v6 + 36);
              }
              while ( v18 <= v15 );
              v14 = *(_DWORD *)(v6 + 40);
            }
            ++v16;
            v17 += 4;
          }
          while ( v16 <= v14 );
        }
        if ( *(int *)(v6 + 100) >= 1 )
        {
          v20 = 0;
          v21 = 0;
          do
          {
            ++v21;
            v22 = *(_QWORD *)(v6 + 64) + v20;
            v20 += 16;
            *(_DWORD *)(*(_QWORD *)v6 + *(_QWORD *)v22) = *(_DWORD *)(v22 + 8);
          }
          while ( v21 < *(int *)(v6 + 100) );
        }
        if ( *(int *)(v6 + 104) >= 1 )
        {
          v23 = 0;
          v24 = 0;
          do
          {
            ++v24;
            v25 = *(_QWORD *)(v6 + 72) + v23;
            v23 += 16;
            *(_DWORD *)(*(_QWORD *)v6 + *(_QWORD *)v25) = *(_DWORD *)(v25 + 8);
          }
          while ( v24 < *(int *)(v6 + 104) );
        }
        if ( *(int *)(v6 + 108) >= 1 )
        {
          v26 = 0;
          v27 = 0;
          do
          {
            ++v27;
            v28 = *(_QWORD *)(v6 + 80) + v26;
            v26 += 16;
            *(_DWORD *)(*(_QWORD *)v6 + *(_QWORD *)v28) = *(_DWORD *)(v28 + 8);
          }
          while ( v27 < *(int *)(v6 + 108) );
        }
        if ( *(int *)(v6 + 112) >= 1 )
        {
          v29 = 0;
          v30 = 0;
          do
          {
            ++v30;
            v31 = *(_QWORD *)(v6 + 88) + v29;
            v29 += 16;
            *(_DWORD *)(*(_QWORD *)v6 + *(_QWORD *)v31) = *(_DWORD *)(v31 + 8);
          }
          while ( v30 < *(int *)(v6 + 112) );
        }
        **(_DWORD **)v6 = 1;
        *(_BYTE *)(v6 + 116) = 1;
      }
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = 0;
      raw_spin_unlock(v6 + 32);
      if ( !v40[0] )
        _pm_runtime_idle(*(_QWORD *)(v6 + 8), 4);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}

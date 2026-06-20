__int64 __fastcall arm_smmu_enable_s1_translation(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v3; // x21
  __int64 v4; // x23
  unsigned int v5; // w0
  unsigned int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w13
  int v9; // w10
  unsigned int v10; // w3
  __int64 v11; // x9
  __int64 v12; // x1
  _DWORD *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x22
  unsigned int v16; // w22
  unsigned int v18; // w8
  unsigned int v25; // w10

  v1 = a1 - 104;
  v3 = *(_QWORD **)(a1 - 184);
  mutex_lock(a1 - 104);
  if ( *(_QWORD *)(a1 - 184) )
  {
    if ( *(_BYTE *)(a1 - 46) == 1 )
    {
      v4 = *v3;
      if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 && (v5 = _pm_runtime_resume(*v3, 4), (v5 & 0x80000000) != 0) )
      {
        v18 = *(_DWORD *)(v4 + 480);
        v16 = v5;
        do
        {
          if ( !v18 )
            break;
          _X12 = (unsigned int *)(v4 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v25 = __ldxr(_X12);
            if ( v25 != v18 )
              break;
            if ( !__stlxr(v18 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v25 == v18;
          v18 = v25;
        }
        while ( !_ZF );
      }
      else
      {
        v6 = *(unsigned __int16 *)(a1 - 128);
        v7 = *(unsigned __int8 *)(a1 - 136);
        v8 = v6 | 0x4000;
        if ( *(_DWORD *)(a1 - 124) )
          v9 = 4166;
        else
          v9 = 70;
        *(_WORD *)(a1 - 128) = v8;
        v10 = (v9 | (v8 >> 14)) & 0xF0FFFFFF
            | ((v6 & 3) << 26)
            | (v6 >> 3) & 0x100
            | (v6 >> 5) & 0x80
            | (v6 >> 8) & 0x20
            | (((v6 >> 2) & 3) << 24)
            | (v6 << 18) & 0xC00000
            | (v6 << 14) & 0x100000
            | (v6 << 9) & 0xF0000;
        *(_DWORD *)(v3[10] + 48LL * v7 + 32) = v10;
        v11 = v3[6];
        v12 = *((_DWORD *)v3 + 6) + v7;
        if ( v11 && (v13 = *(_DWORD **)(v11 + 8)) != nullptr )
        {
          if ( *(v13 - 1) != -1008624849 )
            __break(0x8228u);
          v14 = ((__int64 (__fastcall *)(_QWORD *, __int64, _QWORD))v13)(v3, v12, 0);
        }
        else
        {
          v14 = writel_relaxed_0(v10, (unsigned int *)(v3[1] + (int)((_DWORD)v12 << *((_DWORD *)v3 + 7))));
        }
        if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
        {
          v15 = *v3;
          *(_QWORD *)(v15 + 520) = ktime_get_mono_fast_ns(v14);
          _pm_runtime_suspend(*v3, 13);
        }
        v16 = 0;
        *(_BYTE *)(a1 - 46) = 0;
      }
    }
    else
    {
      v16 = 0;
    }
  }
  else
  {
    v16 = -1;
  }
  mutex_unlock(v1);
  return v16;
}

__int64 __fastcall _arm_smmu_sid_switch(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 **v4; // x23
  __int64 *v5; // x19
  __int64 v7; // x20
  int v8; // w20
  _QWORD **v9; // x23
  bool v10; // w22
  int v11; // w1
  __int64 v12; // x25
  __int64 v13; // x8
  void (__fastcall *v14)(_QWORD); // x9
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned int v17; // w9
  __int64 v18; // x3
  __int64 v19; // x10
  unsigned int v20; // w9
  __int64 v21; // x2
  _DWORD *v22; // x8
  unsigned __int16 *v23; // x8
  __int64 v24; // x3
  __int64 v25; // x8
  __int64 v26; // x2
  _DWORD *v27; // x8
  __int64 v28; // x0
  __int64 v29; // x20
  unsigned int v31; // w8
  unsigned int v38; // w10

  v2 = *(_QWORD *)(a1 + 824);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 56);
    if ( v3 )
    {
      v4 = *(__int64 ***)(v2 + 72);
      if ( v4 )
      {
        v5 = *v4;
        v7 = **v4;
        if ( (*(_WORD *)(v7 + 488) & 7) == 0 && (_pm_runtime_resume(**v4, 4) & 0x80000000) != 0 )
        {
          v31 = *(_DWORD *)(v7 + 480);
          do
          {
            if ( !v31 )
              break;
            _X12 = (unsigned int *)(v7 + 480);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v38 = __ldxr(_X12);
              if ( v38 != v31 )
                break;
              if ( !__stlxr(v31 - 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v38 == v31;
            v31 = v38;
          }
          while ( !_ZF );
        }
        mutex_lock(v5 + 15);
        if ( !a2 && *(_DWORD *)(v3 + 12) )
          arm_smmu_write_context_bank((__int64)v5, *(unsigned __int8 *)(v5[14] + 24LL * *((__int16 *)v4 + 4) + 20));
        if ( *(_DWORD *)(v3 + 12) )
        {
          v8 = 0;
          v9 = v4 + 1;
          v10 = a2 == 0;
          while ( 1 )
          {
            v11 = *((__int16 *)v9 + v8);
            v12 = *((__int16 *)v9 + v8);
            *(_BYTE *)(v5[13] + 8 * v12 + 4) = v10;
            v13 = v5[6];
            if ( v13 )
            {
              v14 = *(void (__fastcall **)(_QWORD))(v13 + 136);
              if ( v14 )
                break;
            }
            v16 = v5[14] + 24LL * v11;
            v17 = ((*(_DWORD *)(v16 + 12) & 3) << 16) & 0xFCFFFFFF
                | ((*(_DWORD *)(v16 + 16) & 3) << 24)
                | *(unsigned __int8 *)(v16 + 20);
            v18 = v17 | 0x300;
            if ( (*((_BYTE *)v5 + 33) & 0x10) != 0 )
            {
              v19 = v5[13];
              if ( v19 )
              {
                v20 = v17 | 0x700;
                if ( *(_BYTE *)(v19 + 8 * v12 + 4) )
                  v18 = v20;
                else
                  v18 = (unsigned int)v18;
              }
            }
            v21 = 4 * v12 + 3072;
            if ( v13 )
            {
              v22 = *(_DWORD **)(v13 + 8);
              if ( v22 )
              {
                if ( *(v22 - 1) != -1008624849 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v22)(v5, 0, v21, v18);
                v15 = v5[13];
                if ( !v15 )
                  goto LABEL_12;
LABEL_27:
                v23 = (unsigned __int16 *)(v15 + 8 * v12);
                v24 = v23[1] | (*v23 << 16);
                if ( (*((_BYTE *)v5 + 33) & 0x10) == 0 )
                {
                  if ( *((_BYTE *)v23 + 4) )
                    v24 = (unsigned int)v24 | 0x80000000;
                  else
                    v24 = (unsigned int)v24;
                }
                v25 = v5[6];
                v26 = 4 * v12 + 2048;
                if ( v25 && (v27 = *(_DWORD **)(v25 + 8)) != nullptr )
                {
                  if ( *(v27 - 1) != -1008624849 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v27)(v5, 0, v26, v24);
                }
                else
                {
                  writel_relaxed_0(v24, (unsigned int *)(v5[1] + v26));
                }
                goto LABEL_12;
              }
            }
            writel_relaxed_0(v18, (unsigned int *)(v5[1] + v21));
            v15 = v5[13];
            if ( v15 )
              goto LABEL_27;
LABEL_12:
            if ( (unsigned int)++v8 >= *(_DWORD *)(v3 + 12) )
              goto LABEL_40;
          }
          if ( *((_DWORD *)v14 - 1) != -1998289792 )
            __break(0x8229u);
          v14(v5);
          v15 = v5[13];
          if ( !v15 )
            goto LABEL_12;
          goto LABEL_27;
        }
LABEL_40:
        v28 = mutex_unlock(v5 + 15);
        __dsb(0xEu);
        if ( (*(_WORD *)(*v5 + 488) & 7) == 0 )
        {
          v29 = *v5;
          *(_QWORD *)(v29 + 520) = ktime_get_mono_fast_ns(v28);
          _pm_runtime_suspend(*v5, 13);
        }
      }
    }
  }
  return 0;
}

__int64 __fastcall gen8_perfcounter_update(__int64 a1, int *a2, char a3, int a4, char a5)
{
  int v5; // w10
  __int64 v8; // x22
  int v12; // w26
  int v13; // w21
  int v14; // w11
  unsigned __int64 v15; // x27
  int v21; // w28
  __int64 (*v22)(void); // x8
  unsigned int v23; // w26
  int v24; // w28
  unsigned __int16 v25; // w8
  unsigned int v26; // w11
  unsigned int v27; // w8
  int v28; // w9
  unsigned int v29; // w11
  _DWORD *v30; // x12
  int v31; // w8
  bool v32; // w21
  __int64 v33; // x8
  unsigned int v34; // w20
  __int64 v35; // x8
  __int16 v36; // w9
  int v37; // w11
  unsigned int v38; // w10
  int v39; // w11
  unsigned int v40; // w10
  int v41; // w11
  int v42; // w9
  int v43; // w9
  unsigned int v44; // w10
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v48; // x9
  int v50; // [xsp+4h] [xbp-Ch]
  unsigned __int64 v51; // [xsp+8h] [xbp-8h]

  v5 = *(unsigned __int16 *)(a1 + 24548);
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL);
  v12 = *(unsigned __int8 *)(v8 + 12);
  v13 = *(unsigned __int8 *)(v8 + 13);
  v14 = *(unsigned __int16 *)(v8 + 14);
  v50 = v14;
  if ( !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 304LL) )
  {
    v51 = 0;
LABEL_7:
    v23 = 3 * v5 + 2 * (v13 + v12);
    if ( (a5 & 2) != 0 )
    {
      v25 = v14 - v5;
      v24 = v5;
      v26 = (unsigned __int16)(v14 - v5);
      if ( v26 >= 3 )
      {
        v27 = v26 + 2 * v25;
        v28 = -v23;
        v29 = v26 - 2;
        v30 = (_DWORD *)(v8 + 4LL * v23 + 20);
        v31 = v27 + v23 - 6;
        do
        {
          if ( *v30 == a2[6] && *(v30 - 1) == a4 )
          {
            v23 = -v28;
            v32 = v28 == 1;
            goto LABEL_23;
          }
          --v29;
          v28 -= 3;
          v30 += 3;
        }
        while ( v29 );
        v32 = 1;
        v23 = v31;
LABEL_23:
        if ( (unsigned int)kgsl_hwlock(v8) )
        {
          kgsl_hwunlock(v8);
          v34 = -16;
LABEL_44:
          v45 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 312LL);
          if ( v45 )
          {
            if ( *((_DWORD *)v45 - 1) != 994519391 )
              __break(0x8228u);
            v46 = v45(a1);
            StatusReg = _ReadStatusReg(SP_EL0);
            v48 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v48;
            if ( !v48 || !*(_QWORD *)(StatusReg + 16) )
              preempt_schedule(v46);
            _WriteStatusReg(DAIF, v51);
          }
          return v34;
        }
        v35 = v8 + 16;
        if ( v32 )
        {
          if ( v50 == v24 )
            *(_WORD *)(v8 + 14) = *(_WORD *)(a1 + 24548) + 2;
          if ( (a5 & 2) != 0 )
          {
            *(_DWORD *)(v35 + 4LL * v23) = a4;
            v36 = *(_WORD *)(v8 + 14);
            *(_DWORD *)(v35 + 4LL * (v23 + 1)) = a2[6];
            v37 = *a2;
            *(_WORD *)(v8 + 14) = v36 + 1;
            *(_DWORD *)(v35 + 4LL * (v23 + 2)) = v37;
            v38 = v23 + 3;
            if ( a2[10]
              && (*(_DWORD *)(v35 + 4LL * v38) = a4,
                  *(_DWORD *)(v35 + 4LL * (v23 + 4)) = a2[10],
                  v39 = *a2,
                  *(_WORD *)(v8 + 14) = v36 + 2,
                  *(_DWORD *)(v35 + 4LL * (v23 + 5)) = v39,
                  v38 = v23 + 6,
                  a2[11]) )
            {
              *(_DWORD *)(v35 + 4LL * v38) = a4;
              *(_DWORD *)(v35 + 4LL * (v23 + 7)) = a2[11];
              v40 = v23 + 8;
              v23 += 9;
              v41 = *a2;
              *(_WORD *)(v8 + 14) = v36 + 3;
              *(_DWORD *)(v35 + 4LL * v40) = v41;
            }
            else
            {
              v23 = v38;
            }
          }
          *(_DWORD *)(v35 + 4LL * (v23 + 1)) = 1120;
          v43 = 1;
          *(_DWORD *)(v35 + 4LL * (v23 + 2)) = 1;
          v44 = v23 + 5;
          *(_DWORD *)(v35 + 4LL * v23) = 0;
          *(_DWORD *)(v35 + 4LL * (v23 + 3)) = 0;
          *(_DWORD *)(v35 + 4LL * (v23 + 4)) = 1280;
        }
        else
        {
          v42 = *a2;
          *(_DWORD *)(v35 + 4LL * (v23 + 2)) = *a2;
          if ( !a2[10] )
            goto LABEL_38;
          *(_DWORD *)(v35 + 4LL * (v23 + 5)) = v42;
          if ( !a2[11] )
            goto LABEL_38;
          v43 = *a2;
          v44 = v23 + 8;
        }
        *(_DWORD *)(v35 + 4LL * v44) = v43;
LABEL_38:
        kgsl_hwunlock(v8);
LABEL_39:
        if ( (a3 & 1) != 0 )
        {
          kgsl_regmap_write(a1 + 13200, (unsigned int)*a2);
          if ( a2[10] )
          {
            kgsl_regmap_write(a1 + 13200, (unsigned int)*a2);
            if ( a2[11] )
              kgsl_regmap_write(a1 + 13200, (unsigned int)*a2);
          }
        }
        v34 = 0;
        goto LABEL_44;
      }
    }
    else
    {
      if ( v14 != v5 )
        goto LABEL_39;
      v24 = v5;
    }
    v32 = 1;
    goto LABEL_23;
  }
  v51 = _ReadStatusReg(DAIF);
  v15 = _ReadStatusReg(SP_EL0);
  __asm { MSR             DAIFSet, #3 }
  v21 = v5;
  ++*(_DWORD *)(v15 + 16);
  v22 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 304LL);
  if ( *((_DWORD *)v22 - 1) != -1780529452 )
    __break(0x8228u);
  if ( (v22() & 1) != 0 )
  {
    v14 = v50;
    v5 = v21;
    goto LABEL_7;
  }
  v33 = *(_QWORD *)(v15 + 16) - 1LL;
  *(_DWORD *)(v15 + 16) = v33;
  if ( !v33 || !*(_QWORD *)(v15 + 16) )
    ((void (*)(void))preempt_schedule)();
  _WriteStatusReg(DAIF, v51);
  if ( (unsigned int)__ratelimit(&gen8_perfcounter_update__rs, "gen8_perfcounter_update") )
    dev_err(*(_QWORD *)a1, "Timed out waiting to acquire CP semaphore: status=0x%08x\n", 0);
  return (unsigned int)-16;
}

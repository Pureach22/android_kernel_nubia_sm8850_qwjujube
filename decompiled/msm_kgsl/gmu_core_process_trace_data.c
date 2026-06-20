__int64 __fastcall gmu_core_process_trace_data(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  _DWORD *v5; // x22
  int v6; // w19
  __int64 result; // x0
  __int64 v8; // x0
  unsigned int *v9; // x24
  unsigned int v10; // w23
  int v11; // w3
  int v12; // w4
  unsigned int v13; // w8
  int v14; // w3
  unsigned int v15; // w4
  unsigned int v16; // w2
  __int64 v17; // x8
  __int64 v18; // x8
  int v19; // w11
  __int64 v20; // x10
  unsigned __int64 StatusReg; // x19
  __int64 v22; // x0
  __int64 v23; // x8
  char s[8]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v25; // [xsp+40h] [xbp-80h]
  __int64 v26; // [xsp+48h] [xbp-78h]
  __int64 v27; // [xsp+50h] [xbp-70h]
  __int64 v28; // [xsp+58h] [xbp-68h]
  __int64 v29; // [xsp+60h] [xbp-60h]
  __int64 v30; // [xsp+68h] [xbp-58h]
  __int64 v31; // [xsp+70h] [xbp-50h]
  __int64 v32; // [xsp+78h] [xbp-48h]
  __int64 v33; // [xsp+80h] [xbp-40h]
  __int64 v34; // [xsp+88h] [xbp-38h]
  __int64 v35; // [xsp+90h] [xbp-30h]
  __int64 v36; // [xsp+98h] [xbp-28h]
  __int64 v37; // [xsp+A0h] [xbp-20h]
  __int64 v38; // [xsp+A8h] [xbp-18h]
  __int64 v39; // [xsp+B0h] [xbp-10h]
  __int64 v40; // [xsp+B8h] [xbp-8h]

  v4 = a3;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD **)(*(_QWORD *)a3 + 8LL);
  v6 = readl_3(v5 + 4);
  result = readl_3(v5 + 5);
  if ( v6 != (_DWORD)result )
  {
    if ( *(_BYTE *)(v4 + 10) == 1 )
    {
      v8 = (unsigned int)v5[5];
LABEL_37:
      result = writel(v8, v5 + 4);
      goto LABEL_38;
    }
    v9 = &v5[v5[6] + v6];
    v10 = *v9;
    if ( (*v9 & 0x80000000) == 0 )
    {
      v38 = 0;
      v39 = 0;
      v36 = 0;
      v37 = 0;
      v34 = 0;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v30 = 0;
      v31 = 0;
      v28 = 0;
      v29 = 0;
      v26 = 0;
      v27 = 0;
      v11 = v5[4];
      *(_QWORD *)s = 0;
      v25 = 0;
      snprintf(s, 0x80u, "Invalid trace packet found at read index: %d resetting trace header\n", v11);
      if ( (unsigned int)__ratelimit(&gmu_core_process_trace_data__rs, "gmu_core_process_trace_data") )
        dev_err(*(_QWORD *)a1, "%s\n", s);
LABEL_7:
      result = writel((unsigned int)v5[5], v5 + 4);
      *(_BYTE *)(v4 + 10) = 1;
      goto LABEL_38;
    }
    if ( (v10 & 0x40000000) == 0 )
    {
      v12 = *(unsigned __int16 *)(v4 + 8);
      v13 = (unsigned __int16)(v10 - v12);
      if ( v13 >= 2 )
      {
        v38 = 0;
        v39 = 0;
        v36 = 0;
        v37 = 0;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v30 = 0;
        v31 = 0;
        v28 = 0;
        v29 = 0;
        v26 = 0;
        v27 = 0;
        *(_QWORD *)s = 0;
        v25 = 0;
        snprintf(s, 0x80u, "%d GMU trace packets dropped from sequence number: %d\n", v13 - 1, v12);
      }
      *(_WORD *)(v4 + 8) = v10;
      v14 = v9[1];
      if ( v14 <= 4 )
      {
        if ( v14 > 2 || v14 == 1 || v14 == 2 )
          goto LABEL_36;
LABEL_35:
        v30 = 0;
        v31 = 0;
        v28 = 0;
        v29 = 0;
        v26 = 0;
        v27 = 0;
        *(_QWORD *)s = 0;
        v25 = 0;
        snprintf(s, 0x40u, "Unsupported GMU trace id %d\n", v14);
        goto LABEL_36;
      }
      if ( v14 > 6 )
      {
        if ( v14 != 7 )
        {
          if ( v14 == 8 )
            goto LABEL_36;
          goto LABEL_35;
        }
        kgsl_pwrctrl_busy_time(a1, *((_QWORD *)v9 + 2), *((_QWORD *)v9 + 3), *((_QWORD *)v9 + 1));
        *(_QWORD *)s = *((_QWORD *)v9 + 3);
        v25 = *((_QWORD *)v9 + 5);
        v26 = *((_QWORD *)v9 + 4);
        v17 = *(unsigned int *)(a1 + 10040);
        if ( (unsigned int)v17 < 0x20 )
        {
          v18 = a1 + 8 * v17;
          v19 = *(_DWORD *)(a1 + 10048);
          v20 = *(_QWORD *)(v18 + 10648);
          *(_QWORD *)(v18 + 10088) += *((_QWORD *)v9 + 3);
          *(_QWORD *)(v18 + 10648) = v20 + *((_QWORD *)v9 + 2);
          if ( v19 )
            *(_QWORD *)(a1 + 10344) += *((_QWORD *)v9 + 3);
          *(_DWORD *)(a1 + 11064) = *((unsigned __int16 *)v9 + 24);
          goto LABEL_36;
        }
      }
      else
      {
        if ( v14 != 5 )
        {
          *(_DWORD *)(a1 + 10936) = v9[5];
          *(_QWORD *)(a1 + 10384) = v9[6];
          goto LABEL_36;
        }
        v15 = v9[5];
        if ( v15 == *(_DWORD *)(a1 + 10068) )
        {
          v15 = *(_DWORD *)(a1 + 10040);
          v9[5] = v15;
        }
        v16 = v9[4];
        if ( *(_DWORD *)(a1 + 10040) == v16 || v16 <= 0x1F && v15 < 0x20 && (v4 = v9[10], v9[4] <= 0x1F) )
        {
          *(_DWORD *)(a1 + 10040) = v9[4];
          *(_DWORD *)(a1 + 10044) = v9[5];
          goto LABEL_36;
        }
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v22 = _traceiter_kgsl_msg(0, s);
        v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v23;
        if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v22);
      }
      goto LABEL_7;
    }
LABEL_36:
    v8 = ((HIWORD(v10) & 0xFFF) + v6) % v5[7];
    goto LABEL_37;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}

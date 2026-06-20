__int64 __fastcall hif_affinity_mgr_affine_irq(__int64 result)
{
  __int64 v1; // x23
  unsigned __int64 StatusReg; // x20
  unsigned int v3; // w8
  __int64 v4; // x21
  __int64 v5; // x26
  signed int v6; // w9
  __int64 v7; // x27
  signed int v8; // w28
  __int64 v9; // x22
  unsigned int v10; // w23
  __int64 v11; // x0
  int v12; // w24
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  __int64 v18; // x11
  unsigned int *v19; // x28
  __int64 v20; // x27
  unsigned __int64 v21; // x25
  unsigned int v22; // w19
  __int64 v23; // x22
  unsigned int v24; // w23
  __int64 v25; // x0
  int v26; // w24
  __int64 v27; // x0
  __int64 v28; // x24
  __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  __int64 v32; // [xsp+8h] [xbp-68h]
  __int64 v33; // [xsp+10h] [xbp-60h]
  __int64 v34; // [xsp+18h] [xbp-58h]
  char v35; // [xsp+24h] [xbp-4Ch]
  __int64 v36; // [xsp+28h] [xbp-48h]
  __int64 v37; // [xsp+30h] [xbp-40h] BYREF
  __int64 v38; // [xsp+38h] [xbp-38h] BYREF
  __int64 v39; // [xsp+40h] [xbp-30h] BYREF
  __int16 v40; // [xsp+48h] [xbp-28h]
  __int64 v41; // [xsp+50h] [xbp-20h] BYREF
  __int64 v42; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v43[2]; // [xsp+60h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 4196) == 1 )
  {
    v1 = result;
    v40 = 0;
    v39 = 0;
    v38 = 0;
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    result = qdf_walt_get_cpus_taken();
    v3 = *(_DWORD *)(v1 + 656);
    v4 = result;
    v36 = v1;
    v37 = result;
    if ( v3 )
    {
      v5 = *(_QWORD *)(v1 + 27400);
      v6 = 0;
      v7 = v1 + 4208;
      v35 = 0;
      while ( 1 )
      {
        v8 = v6;
        if ( (*(_BYTE *)(v5 + 32LL * v6) & 8) == 0 )
        {
          if ( (unsigned int)v6 >= 0xD )
            goto LABEL_42;
          v9 = v7 + 48LL * v6;
          qdf_cpumask_copy(&v38, v9);
          v41 = v38;
          v42 = v4;
          result = hif_affinity_mgr_check_update_mask(v1, v7 + 48LL * v8, v4, &v41, StatusReg);
          if ( !(_DWORD)result )
          {
            v10 = *(_DWORD *)(v9 + 44);
            irq_modify_status(v10, 0x2000, 0);
            v11 = _irq_apply_affinity_hint(v10, &v41, 1);
            v12 = qdf_status_from_os_return(v11);
            v13 = v10;
            v1 = v36;
            result = irq_modify_status(v13, 0, 0x2000);
            if ( !v12 )
            {
              qdf_cpumask_copy(v9 + 16, &v42);
              qdf_cpumask_copy(v7 + 48LL * v8, &v41);
              v14 = v42;
              *(_QWORD *)(v9 + 24) = StatusReg;
              v43[0] = v14;
              result = qdf_cpumask_equal(v43, v9 + 16);
              if ( (result & 1) != 0
                || ((v15 = StatusReg - *(_QWORD *)(v9 + 32), 10 * v15 >= v15)
                  ? (v16 = 10 * v15 / 0xC0)
                  : (v16 = 10 * (v15 / 0xC0)),
                    v16 >= *(_QWORD *)(v36 + 4200)) )
              {
                *(_QWORD *)(v9 + 32) = StatusReg;
              }
              v35 = 1;
            }
          }
          v3 = *(_DWORD *)(v1 + 656);
        }
        v6 = v8 + 1;
        if ( v8 + 1 >= v3 )
          goto LABEL_19;
      }
    }
    v35 = 0;
LABEL_19:
    v17 = *(unsigned int *)(v1 + 27264);
    if ( (_DWORD)v17 )
    {
      v18 = 0;
      v33 = v1 + 27120;
      v32 = v1 + 4828;
      while ( 1 )
      {
        v34 = v18;
        if ( v18 == 18 )
          break;
        v19 = *(unsigned int **)(v33 + 8 * v18);
        if ( v19[4] )
        {
          v20 = v32;
          v21 = 0;
          do
          {
            if ( v21 > 0x19 )
              goto LABEL_42;
            v22 = v19[58];
            if ( v22 > 0x11 )
              goto LABEL_42;
            v23 = v20 + 1200LL * v22 - 44;
            qdf_cpumask_copy(&v38, v23);
            v41 = v38;
            v42 = v4;
            result = hif_affinity_mgr_check_update_mask(v1, v23, v4, &v41, StatusReg);
            if ( !(_DWORD)result )
            {
              v24 = *(_DWORD *)(v20 + 1200LL * v22);
              irq_modify_status(v24, 0x2000, 0);
              v25 = _irq_apply_affinity_hint(v24, &v41, 1);
              v26 = qdf_status_from_os_return(v25);
              v27 = v24;
              v1 = v36;
              result = irq_modify_status(v27, 0, 0x2000);
              if ( !v26 )
              {
                v28 = v20 + 1200LL * v22;
                qdf_cpumask_copy(v28 - 28, &v42);
                qdf_cpumask_copy(v23, &v41);
                v29 = v42;
                v1 = v36;
                *(_QWORD *)(v28 - 20) = StatusReg;
                v43[0] = v29;
                result = qdf_cpumask_equal(v43, v28 - 28);
                if ( (result & 1) != 0
                  || ((v30 = StatusReg - *(_QWORD *)(v20 + 1200LL * v22 - 12), 10 * v30 >= v30)
                    ? (v31 = 10 * v30 / 0xC0)
                    : (v31 = 10 * (v30 / 0xC0)),
                      v31 >= *(_QWORD *)(v36 + 4200)) )
                {
                  *(_QWORD *)(v20 + 1200LL * v22 - 12) = StatusReg;
                }
                v19[732] = -1;
                v35 = 1;
              }
            }
            ++v21;
            v20 += 48;
          }
          while ( v21 < v19[4] );
          v18 = v34;
          v17 = *(unsigned int *)(v1 + 27264);
        }
        if ( ++v18 >= v17 )
          goto LABEL_39;
      }
LABEL_42:
      __break(0x5512u);
    }
LABEL_39:
    if ( (v35 & 1) != 0 )
    {
      qdf_thread_cpumap_print_to_pagebuf(0, &v39, &v37);
      result = qdf_trace_msg(61, 5, "%s: Audio taken CPU mask: %s", "hif_affinity_mgr_affine_irq", (const char *)&v39);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

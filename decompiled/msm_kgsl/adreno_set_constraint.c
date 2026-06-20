__int64 __fastcall adreno_set_constraint(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x22
  unsigned int v4; // w20
  int v5; // w8
  __int64 v6; // x8
  unsigned int *v7; // x21
  __int64 v8; // x19
  unsigned int v9; // w3
  unsigned int v10; // w8
  __int64 v11; // x2
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x8
  void (*v15)(void); // x9
  unsigned int *v16; // x20
  __int64 v17; // x19
  int v19; // w3
  __int64 v20; // x1
  unsigned int v21; // w0
  __int64 v22; // x10
  unsigned int v23; // w0
  __int64 v24; // x10
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v3 = a1 + 12288;
  v4 = -22;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)a3;
  if ( *(int *)a3 > 1 )
  {
    if ( v5 == 2 )
    {
      a2[58] = 2;
      goto LABEL_32;
    }
    if ( v5 != 3 )
      goto LABEL_34;
    v14 = *(_QWORD *)(a3 + 16);
    v25 = 0;
    if ( v14 != 4 )
      goto LABEL_22;
    v7 = a2;
    v8 = a1;
    if ( inline_copy_from_user((int)&v25, *(_QWORD *)(a3 + 8), 4u) )
      goto LABEL_20;
    if ( *(_DWORD *)(v8 + 13100) )
    {
LABEL_39:
      v19 = v25;
      if ( v25 >= 2 )
      {
        v19 = 1;
        v25 = 1;
      }
      v20 = v7[1];
      v7[58] = 3;
      v7[59] = v19;
      trace_kgsl_user_pwrlevel_constraint(v8, v20, 3);
      a2 = v7;
      a1 = v8;
      goto LABEL_32;
    }
    rt_mutex_lock(v8 + 11088);
    if ( *(_BYTE *)(v3 + 1128) != 1 || *(_DWORD *)(v8 + 13100) )
    {
LABEL_38:
      rt_mutex_unlock(v8 + 11088);
      goto LABEL_39;
    }
    *(_DWORD *)(v8 + 13096) = 0;
    *(_QWORD *)(v8 + 13088) = 0;
    v21 = qcom_dcvs_register_voter("kgsl-l3", 2, 0);
    if ( v21 )
    {
      v4 = v21;
      if ( (register_l3_voter___print_once & 1) == 0 )
      {
        v22 = *(_QWORD *)(v8 + 11168);
        register_l3_voter___print_once = 1;
        dev_err(v22 + 16, "Unable to register l3 dcvs voter: %d\n", v21);
      }
    }
    else
    {
      v23 = qcom_dcvs_hw_minmax_get(2, v8 + 13092, v8 + 13096);
      if ( !v23 )
      {
        *(_DWORD *)(v8 + 13100) = 3;
        goto LABEL_38;
      }
      v4 = v23;
      if ( (register_l3_voter___print_once_128 & 1) == 0 )
      {
        v24 = *(_QWORD *)(v8 + 11168);
        register_l3_voter___print_once_128 = 1;
        dev_err(v24 + 16, "Unable to get min/max for l3 dcvs: %d\n", v23);
      }
      qcom_dcvs_unregister_voter("kgsl-l3", 2, 0);
      *(_QWORD *)(v8 + 13088) = 0;
      *(_DWORD *)(v8 + 13096) = 0;
    }
    rt_mutex_unlock(v8 + 11088);
    a1 = v8;
    goto LABEL_21;
  }
  if ( v5 )
  {
    if ( v5 != 1 )
      goto LABEL_34;
    v6 = *(_QWORD *)(a3 + 16);
    v25 = 0;
    if ( v6 != 4 )
      goto LABEL_22;
    v7 = a2;
    v8 = a1;
    if ( !inline_copy_from_user((int)&v25, *(_QWORD *)(a3 + 8), 4u) )
    {
      v9 = v25;
      a1 = v8;
      a2 = v7;
      if ( *(_BYTE *)(v3 + 1944) )
        v10 = 1;
      else
        v10 = 100;
      if ( v25 > v10 )
      {
LABEL_22:
        if ( v4 )
          goto LABEL_34;
        goto LABEL_32;
      }
      v11 = 1;
      v7[52] = 1;
      v7[53] = v9;
      v12 = v7[1];
      if ( (*(_BYTE *)(v3 + 1944) & 1) == 0 )
      {
        v13 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 14264) + 40LL)
                                                                           + 160LL)
                                                               + 64LL);
        if ( v13 )
        {
          if ( *((_DWORD *)v13 - 1) != -1013493491 )
            __break(0x8228u);
          v13(v8, v12, 4);
          v11 = v7[52];
          v12 = v7[1];
        }
      }
      trace_kgsl_user_pwrlevel_constraint(v8, v12, v11);
      a1 = v8;
      v4 = 0;
LABEL_21:
      a2 = v7;
      goto LABEL_22;
    }
LABEL_20:
    v4 = -14;
    a1 = v8;
    goto LABEL_21;
  }
  if ( a2[52] == 1 )
  {
    a2[52] = 0;
    if ( (*(_BYTE *)(a1 + 14232) & 1) == 0 )
    {
      v15 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL) + 64LL);
      if ( v15 )
      {
        v16 = a2;
        v17 = a1;
        if ( *((_DWORD *)v15 - 1) != -1013493491 )
          __break(0x8229u);
        v15();
        a2 = v16;
        a1 = v17;
      }
    }
  }
  else
  {
    a2[52] = 0;
  }
LABEL_32:
  v4 = 0;
  if ( a2[1] == *(_DWORD *)(a1 + 10432) )
    *(_DWORD *)(a1 + 10416) = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v4;
}

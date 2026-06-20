// positive sp value has been detected, the output may be wrong!
unsigned __int64 __usercall sub_59598@<X0>(
        unsigned __int64 result@<X0>,
        __int64 **a2@<X8>,
        __int64 a3,
        int a4,
        __int64 a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // x9
  __int64 v8; // x10
  _DWORD *v9; // x11
  int v10; // w12
  _DWORD *v11; // x13
  __int64 v12; // x14
  _DWORD *v13; // x15
  __int64 v14; // x16
  _DWORD *v15; // x17
  const char *v16; // x19
  __int64 **v17; // x20
  __int64 v18; // x1
  __int64 *v19; // x1
  __int64 *v20; // x1
  __int64 *v21; // x1
  unsigned __int64 v22; // x1
  __int64 *i; // x8
  __int64 *v24; // x8
  char *v25; // x6
  __int64 v26; // x19
  __int64 v27; // x21
  __int64 v28; // x7
  _QWORD *v29; // x3
  __int64 *v30; // x4
  int *v31; // x5
  int v32; // w3
  __int64 v33; // x11
  __int64 *k; // x8
  __int64 v35; // x11
  int v36; // w11
  __int64 *j; // x8
  __int64 v38; // x12
  __int64 *m; // x19

  if ( ((unsigned int)v11 & 0x1000000) == 0 )
    return enable_load_sync(result);
  while ( 1 )
  {
    a2[59][18] = v14;
    a2[59][20] = v14;
    a2[59][22] = v14;
    a2[59][24] = v14;
    a2[59][38] = v14;
    *v9 = v14;
    *v11 = v14;
    *v13 = v14;
    *v15 = v14;
    a2[59][41] = v14;
    *(_DWORD *)((char *)&unk_4 + (_QWORD)v9) = v14;
    *(_DWORD *)((char *)&unk_4 + (_QWORD)v11) = v14;
    *(_DWORD *)((char *)&unk_4 + (_QWORD)v13) = v14;
    *(_DWORD *)((char *)&unk_4 + (_QWORD)v15) = v14;
    a2[59][44] = v14;
    *(_DWORD *)((char *)&unk_8 + (_QWORD)v9) = v14;
    *(_DWORD *)((char *)&unk_8 + (_QWORD)v11) = v14;
    *(_DWORD *)((char *)&unk_8 + (_QWORD)v13) = v14;
    *(_DWORD *)((char *)&unk_8 + (_QWORD)v15) = v14;
    a2[59][47] = v14;
    *(_DWORD *)((char *)&_ksymtab_core_ctl_notifier_unregister + (_QWORD)v9) = v14;
    *(_DWORD *)((char *)&_ksymtab_core_ctl_notifier_unregister + (_QWORD)v11) = v14;
    *(_DWORD *)((char *)&_ksymtab_core_ctl_notifier_unregister + (_QWORD)v13) = v14;
    *(_DWORD *)((char *)&_ksymtab_core_ctl_notifier_unregister + (_QWORD)v15) = v14;
    a2[59][50] = v14;
    v22 = result;
    *(_DWORD *)((char *)&unk_10 + (_QWORD)v9) = v14;
    *(_DWORD *)((char *)&unk_10 + (_QWORD)v11) = v14;
    *(_DWORD *)((char *)&unk_10 + (_QWORD)v13) = v14;
    *(_DWORD *)((char *)&unk_10 + (_QWORD)v15) = v14;
    a2 = (__int64 **)*a2;
    if ( a2 == v17 )
      break;
    result += 416LL;
    if ( v22 == 2080 )
      goto LABEL_45;
    a2[59] = (__int64 *)(v7 + v22);
    if ( v22 > 0x67F )
      goto LABEL_46;
    *(_DWORD *)(v7 + v22) = v10;
    *((_DWORD *)a2[59] + 1) = 0;
    a2[59][2] = v12;
    *((_DWORD *)a2[59] + 6) = 0;
    v18 = *((unsigned int *)a2 + 6);
    if ( (unsigned int)v18 > 3 )
    {
LABEL_45:
      __break(0x5512u);
LABEL_46:
      __break(1u);
      JUMPOUT(0x5B77C);
    }
    *(_DWORD *)(v8 + 4 * v18 + 16) = v14;
    v19 = a2[59];
    v19[35] = 0;
    v19[36] = 0;
    v19[33] = 0;
    v19[34] = 0;
    v19[31] = 0;
    v19[32] = 0;
    v19[29] = 0;
    v19[30] = 0;
    v19[27] = 0;
    v19[28] = 0;
    v19[26] = 0;
    v20 = a2[59];
    v20[24] = 0;
    v20[25] = 0;
    v20[22] = 0;
    v20[23] = 0;
    v20[20] = 0;
    v20[21] = 0;
    v20[18] = 0;
    v20[19] = 0;
    v20[16] = 0;
    v20[17] = 0;
    v20[14] = 0;
    v20[15] = 0;
    v20[12] = 0;
    v20[13] = 0;
    v20[10] = 0;
    v20[11] = 0;
    v20[8] = 0;
    v20[9] = 0;
    v20[6] = 0;
    v20[7] = 0;
    v20[4] = 0;
    v20[5] = 0;
    v21 = a2[59];
    v21[50] = 0;
    v21[51] = 0;
    v21[48] = 0;
    v21[49] = 0;
    v21[46] = 0;
    v21[47] = 0;
    v21[44] = 0;
    v21[45] = 0;
    v21[42] = 0;
    v21[43] = 0;
    v21[40] = 0;
    v21[41] = 0;
    v21[38] = 0;
    v21[39] = 0;
    v21[37] = 0;
    a2[59][4] = v14;
    a2[59][6] = v14;
    a2[59][8] = v14;
    a2[59][10] = v14;
    a2[59][12] = v14;
    a2[59][14] = v14;
    a2[59][16] = v14;
  }
  if ( !v16 )
    goto LABEL_42;
  result = strcmp(v16, "SUN");
  if ( !(_DWORD)result
    || (result = strcmp(v16, "SUNP"), !(_DWORD)result)
    || (result = strcmp(v16, "CANOE"), !(_DWORD)result)
    || (result = strcmp(v16, "ALOR_INTERPOSER"), !(_DWORD)result) )
  {
    v24 = *v17;
    if ( *v17 == (__int64 *)v17 )
      goto LABEL_42;
    result = 31;
    v22 = 0xB400000078LL;
    while ( 1 )
    {
      v32 = *((_DWORD *)v24 + 6);
      if ( v32 == 1 )
      {
        v25 = (char *)&qword_68974 + 4;
        v26 = 220;
        v27 = 260;
        *(_QWORD *)(v24[59] + 32) = 3513600;
        v28 = 7004160;
        *(_QWORD *)(v24[59] + 72) = 1000000000;
        *(_QWORD *)(v24[59] + 88) = 1000000000;
        *(_QWORD *)(v24[59] + 104) = 300000000;
        *(_DWORD *)v24[59] |= 0x3FEu;
        v29 = v24 + 59;
        sysctl_ipc_levels_cluster1 = 0x104000000DCLL;
        qword_68974 = 0x14000000118LL;
        v30 = &qword_68974;
        dword_6897C = 400;
        v31 = &dword_6897C;
      }
      else
      {
        if ( v32 )
          goto LABEL_22;
        v25 = (char *)&qword_68960 + 4;
        v26 = 120;
        v27 = 180;
        *(_QWORD *)(v24[59] + 32) = 2400000;
        v28 = 5806080;
        *(_QWORD *)(v24[59] + 72) = 1000000000;
        *(_QWORD *)(v24[59] + 88) = 1000000000;
        *(_QWORD *)(v24[59] + 104) = 300000000;
        *(_DWORD *)v24[59] |= 0x3FEu;
        v29 = v24 + 59;
        sysctl_ipc_levels_cluster0 = 0xB400000078LL;
        qword_68960 = 0x104000000DCLL;
        v30 = &qword_68960;
        dword_68968 = 300;
        v31 = &dword_68968;
      }
      *(_QWORD *)(*v29 + 296LL) = v26;
      *(_QWORD *)(*v29 + 320LL) = v27;
      *(_QWORD *)(*v29 + 344LL) = *(unsigned int *)v30;
      *(_QWORD *)(*v29 + 368LL) = *(unsigned int *)v25;
      *(_QWORD *)(*v29 + 392LL) = (unsigned int)*v31;
      *(_DWORD *)(*v29 + 24LL) = 31;
      *(_QWORD *)(*v29 + 16LL) = v28;
LABEL_22:
      v24 = (__int64 *)*v24;
      if ( v24 == (__int64 *)v17 )
        goto LABEL_42;
    }
  }
  result = strcmp(v16, "ALOR");
  if ( (_DWORD)result )
  {
    result = strcmp(v16, "TUNA");
    if ( (_DWORD)result )
    {
      result = strcmp(v16, "KERA");
      if ( !(_DWORD)result )
      {
        for ( i = *v17; i != (__int64 *)v17; i = (__int64 *)*i )
        {
          v33 = *((unsigned int *)i + 6);
          if ( (unsigned int)v33 <= 2 )
          {
            *(_QWORD *)(i[59] + 32) = qword_6BD28[v33];
            *(_QWORD *)(i[59] + 72) = 1000000000;
            *(_QWORD *)(i[59] + 88) = 1000000000;
            *(_QWORD *)(i[59] + 104) = 1000000000;
            *(_DWORD *)i[59] |= 0x1FEu;
          }
        }
      }
    }
    else
    {
      for ( j = *v17; j != (__int64 *)v17; j = (__int64 *)*j )
      {
        v38 = *((unsigned int *)j + 6);
        if ( (unsigned int)v38 <= 3 )
        {
          *(_QWORD *)(j[59] + 32) = qword_6C748[v38];
          *(_QWORD *)(j[59] + 72) = 1000000000;
          *(_QWORD *)(j[59] + 88) = 1000000000;
          *(_QWORD *)(j[59] + 104) = 300000000;
          *(_DWORD *)j[59] |= 0x1FEu;
        }
      }
    }
    goto LABEL_42;
  }
  for ( k = *v17; k != (__int64 *)v17; k = (__int64 *)*k )
  {
    v36 = *((_DWORD *)k + 6);
    if ( v36 )
    {
      if ( v36 != 1 )
        continue;
      v35 = 3513600;
    }
    else
    {
      v35 = 2400000;
    }
    *(_QWORD *)(k[59] + 32) = v35;
    *(_QWORD *)(k[59] + 72) = 1000000000;
    *(_QWORD *)(k[59] + 88) = 1000000000;
    *(_QWORD *)(k[59] + 104) = 300000000;
    *(_DWORD *)k[59] |= 0x3FEu;
  }
LABEL_42:
  smart_freq_init_done = 1;
  for ( m = *v17; m != (__int64 *)v17; m = (__int64 *)*m )
    result = ((__int64 (__fastcall *)(__int64 *, unsigned __int64))update_smart_freq_capacities_one_cluster)(m - 1, v22);
  return result;
}

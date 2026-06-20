__int64 __fastcall update_cluster_load_subtractions(char *a1, unsigned int a2, __int64 a3, char a4)
{
  char *v6; // x9
  __int64 v7; // x21
  __int64 v8; // x25
  char *v9; // x24
  unsigned __int64 v10; // x14
  __int64 v11; // x8
  char *v12; // x9
  char *v13; // x11
  unsigned __int64 v14; // x14
  char *v15; // x15
  __int64 v16; // x16
  char *v17; // x0
  char *v18; // x0
  unsigned __int64 v19; // x17
  unsigned __int64 v20; // t1
  _BOOL4 v21; // w17
  unsigned __int64 v22; // x1
  char *v23; // x16
  char *v24; // x16
  __int64 v25; // x17
  __int64 v26; // x16
  char *v27; // x0
  char *v28; // x0
  unsigned __int64 v29; // x17
  unsigned __int64 v30; // t1
  _BOOL4 v31; // w17
  unsigned __int64 v32; // x1
  char *v33; // x16
  __int64 v34; // x15
  __int64 v35; // x16
  char *v36; // x15
  __int64 result; // x0
  unsigned __int64 v44; // x10
  unsigned __int64 v45[2]; // [xsp+0h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0x20 )
    goto LABEL_31;
  v6 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + a2);
  v7 = *((_QWORD *)v6 + 1);
  v8 = *((unsigned int *)v6 + 18);
  if ( a1 == (char *)&init_task )
    v9 = (char *)&vendor_data_pad;
  else
    v9 = a1 + 5184;
  v45[0] = *(_QWORD *)(v7 + 24);
  _X9 = v45;
  __asm { PRFM            #0x11, [X9,#0x30+var_30] }
  do
    v44 = __ldxr(v45);
  while ( __stxr(v44 & ~(1LL << a2), v45) );
  raw_spin_lock(v7);
  v10 = LODWORD(v45[0]);
  if ( LODWORD(v45[0]) )
  {
    v11 = a3 - v8;
    v12 = v9 + 68;
    v13 = v9 + 100;
    while ( 1 )
    {
      v14 = __clz(__rbit64(v10));
      if ( v14 > 7 )
        break;
      v15 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v14);
      if ( *(_DWORD *)&v12[4 * v14] )
      {
        v16 = *((unsigned int *)v15 + 908);
        if ( (unsigned int)v16 >= 0x20 )
          break;
        v17 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v16);
        v20 = *((_QWORD *)v17 + 26);
        v18 = v17 + 208;
        v19 = v20;
        if ( v20 == a3 )
        {
          v21 = 0;
        }
        else
        {
          v22 = *(_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v16) + 232);
          if ( v22 == a3 )
          {
            v21 = 1;
          }
          else
          {
            v21 = v22 < v19;
            v23 = &v18[24 * v21];
            *(_QWORD *)v23 = a3;
            *((_QWORD *)v23 + 1) = 0;
            *((_QWORD *)v23 + 2) = 0;
            v16 = *((unsigned int *)v15 + 908);
            if ( (unsigned int)v16 >= 0x20 )
              break;
          }
        }
        v24 = (char *)&walt_rq + 24 * v21 + *((_QWORD *)&_per_cpu_offset + v16);
        v25 = *(unsigned int *)&v12[4 * v14];
        *((_QWORD *)v24 + 27) += v25;
        if ( (a4 & 1) != 0 )
          *((_QWORD *)v24 + 28) += v25;
        *(_DWORD *)&v12[4 * v14] = 0;
      }
      if ( *(_DWORD *)&v13[4 * v14] )
      {
        v26 = *((unsigned int *)v15 + 908);
        if ( (unsigned int)v26 >= 0x20 )
          break;
        v27 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v26);
        v30 = *((_QWORD *)v27 + 26);
        v28 = v27 + 208;
        v29 = v30;
        if ( v30 == v11 )
        {
          v31 = 0;
        }
        else
        {
          v32 = *(_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v26) + 232);
          if ( v32 == v11 )
          {
            v31 = 1;
          }
          else
          {
            v31 = v32 < v29;
            v33 = &v28[24 * v31];
            *(_QWORD *)v33 = v11;
            *((_QWORD *)v33 + 1) = 0;
            *((_QWORD *)v33 + 2) = 0;
            v26 = *((unsigned int *)v15 + 908);
            if ( (unsigned int)v26 >= 0x20 )
              break;
          }
        }
        v34 = *((_QWORD *)&_per_cpu_offset + v26);
        v35 = *(unsigned int *)&v13[4 * v14];
        v36 = (char *)&walt_rq + 24 * v31 + v34;
        *((_QWORD *)v36 + 27) += v35;
        if ( (a4 & 1) != 0 )
          *((_QWORD *)v36 + 28) += v35;
        *(_DWORD *)&v13[4 * v14] = 0;
      }
      v10 = (unsigned int)(-2LL << v14) & v45[0];
      if ( !(_DWORD)v10 )
        goto LABEL_30;
    }
LABEL_31:
    __break(0x5512u);
  }
LABEL_30:
  result = raw_spin_unlock(v7);
  _ReadStatusReg(SP_EL0);
  return result;
}

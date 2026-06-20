__int64 __usercall get_cluster_ipc_level_freq@<X0>(
        unsigned int a1@<W0>,
        __int64 a2@<X1>,
        unsigned int a3@<W2>,
        unsigned int a4@<W3>,
        unsigned int a5@<W4>,
        __int64 a6@<X5>,
        __int64 a7@<X6>,
        unsigned int a8@<W7>,
        unsigned int *a9@<X8>)
{
  __int64 v9; // x9
  __int64 v10; // x10
  char v11; // w16
  char v12; // w0
  bool v13; // nf
  bool v14; // vf
  bool v15; // cf
  unsigned __int64 v16; // x16
  unsigned __int64 v17; // x16
  __int64 v18; // x17
  unsigned __int64 StatusReg; // x19
  __int64 v21; // x0
  __int64 v22; // x9
  unsigned int *v23; // [xsp+28h] [xbp+18h]

  if ( a1 >= 0x20 )
    goto LABEL_18;
  if ( smart_freq_init_done != 1 )
    return 0;
  a9 = (unsigned int *)&_per_cpu_offset;
  a8 = a1;
  v9 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a1) + 8];
  v10 = *(_QWORD *)(v9 + 480);
  if ( !*(_DWORD *)(v10 + 24) )
    return 0;
  a6 = a2;
  v11 = 0;
  a3 = 0;
  a4 = 0;
  do
  {
    v16 = (unsigned int)(-1LL << v11) & *(_DWORD *)(v9 + 24);
    if ( !(_DWORD)v16 )
      break;
    v17 = __clz(__rbit64(v16));
    v18 = *((_QWORD *)&_per_cpu_offset + v17);
    if ( (unsigned __int64)(a6 - *(_QWORD *)((char *)&last_ipc_update + v18)) <= 0x7A11FF )
    {
      LODWORD(a2) = *(_DWORD *)((char *)&ipc_level + v18);
      v12 = 0;
    }
    else
    {
      LODWORD(a2) = 0;
      v12 = 1;
    }
    v14 = __OFSUB__((_DWORD)a2, a4);
    v13 = (int)(a2 - a4) < 0;
    tickless_mode[v18] = v12;
    if ( (int)a2 > (int)a4 )
      a4 = a2;
    if ( v13 == v14 )
      a3 = v17;
    v15 = v17 >= 0x1F;
    v11 = v17 + 1;
  }
  while ( !v15 );
  *(_DWORD *)(v10 + 8) = a4;
  if ( a4 > 4 )
  {
LABEL_18:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v23 = a9;
      v21 = _traceiter_ipc_freq(0, a2, a3, a4, a5, a6, a7, a8, v9);
      a9 = v23;
      v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v22;
      if ( !v22 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v21);
        a9 = v23;
      }
    }
  }
  else
  {
    a9 = (unsigned int *)(v10 + 24LL * a4 + 304);
  }
  return *a9;
}

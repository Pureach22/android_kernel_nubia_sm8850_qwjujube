__int64 __usercall ufs_qcom_resume@<X0>(__int64 a1@<X0>, int a2@<W1>, int a3@<W8>)
{
  int v3; // w9
  int v4; // w10
  unsigned int v5; // w19
  unsigned int v6; // w20
  __int64 v7; // x21
  __int64 v8; // x29
  __int64 v9; // x21
  __int64 v10; // x20
  _QWORD *v12; // x22
  _QWORD *v13; // x22
  int v14; // w0
  __int64 result; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v21; // x8
  __int64 v22; // x23
  __int64 (__fastcall *v23)(__int64, __int64, _QWORD, __int64, __int64, __int64, _QWORD, _QWORD); // x8
  __int64 v24; // x0
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // t1
  __int64 v29; // x8

  if ( !a1 )
  {
    __break(0x800u);
    *(_DWORD *)(v8 + 24) = a3;
    *(_DWORD *)(v8 + 28) = v3;
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(unsigned int *)(StatusReg + 40);
    *(_DWORD *)(v8 - 4) = v4;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v21 >> 3) & 0x1FFFFFF8)) >> v21) & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v22 = qword_17798;
      if ( qword_17798 )
      {
        do
        {
          v23 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64, __int64, __int64, _QWORD, _QWORD))v22;
          v24 = *(_QWORD *)(v22 + 8);
          v25 = *(unsigned int *)(v8 + 24);
          v26 = *(unsigned int *)(v8 + 28);
          v27 = *(unsigned int *)(v8 - 4);
          if ( *(_DWORD *)(*(_QWORD *)v22 - 4LL) != -291122989 )
            __break(0x8228u);
          a1 = v23(v24, v7, v5, v25, v26, v27, v6, 0);
          v28 = *(_QWORD *)(v22 + 24);
          v22 += 24;
        }
        while ( v28 );
      }
      v29 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v29;
      if ( !v29 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(a1);
    }
    return 0;
  }
  v9 = *(_QWORD *)(a1 + 184);
  v10 = a1;
  v12 = *(_QWORD **)(v9 + 392);
  if ( v12
    && (*(_DWORD *)(a1 + 88) > 3u || *(_DWORD *)(a1 + 92) >= 4u)
    && (*((_BYTE *)v12 + 17) & 1) == 0
    && ((int)regulator_count_voltages(*v12) < 1 || !(unsigned int)regulator_set_load(*v12, *((unsigned int *)v12 + 5)))
    && !(unsigned int)regulator_enable(*v12) )
  {
    *((_BYTE *)v12 + 17) = 1;
  }
  v13 = *(_QWORD **)(v9 + 400);
  if ( v13
    && (*((_BYTE *)v13 + 17) & 1) == 0
    && ((int)regulator_count_voltages(*v13) < 1 || !(unsigned int)regulator_set_load(*v13, *((unsigned int *)v13 + 5)))
    && !(unsigned int)regulator_enable(*v13) )
  {
    *((_BYTE *)v13 + 17) = 1;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v9 + 16) + 3001LL) & 1) != 0 )
  {
    v14 = qcom_ice_resume(*(_QWORD *)(v9 + 152));
    if ( v14 )
    {
      dev_warn(
        *(_QWORD *)(*(_QWORD *)(v9 + 16) + 64LL),
        "ICE could not be resumed err=%d. Disabling inline encryption support.\n",
        v14);
      *(_DWORD *)(*(_QWORD *)(v9 + 16) + 3000LL) &= ~0x100u;
    }
  }
  result = ufs_qcom_enable_lane_clks(v9);
  if ( !(_DWORD)result )
  {
    v16 = *(_QWORD *)(*(_QWORD *)(v10 + 64) + 592LL);
    if ( v16 )
    {
      if ( v16 <= 0xFFFFFFFFFFFFF000LL )
      {
        v17 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v10 + 184) + 8LL) + 96LL);
        if ( v17 )
        {
          if ( v17 <= 0xFFFFFFFFFFFFF000LL )
          {
            v18 = *(_QWORD *)(v17 + 592);
            if ( v18 )
            {
              if ( v18 <= 0xFFFFFFFFFFFFF000LL )
              {
                *(_DWORD *)(v16 + 520) &= ~4u;
                *(_DWORD *)(v18 + 520) &= ~4u;
              }
            }
          }
        }
      }
    }
    v19 = *(_QWORD *)(v9 + 656);
    if ( v19 )
    {
      if ( *(_BYTE *)(v9 + 664) == 1 )
        ipc_log_string(
          v19,
          ",%d,$,%d,%d,%d,%d,%d,%d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40),
          a2,
          *(_DWORD *)(v10 + 88),
          *(_DWORD *)(v10 + 92),
          *(_DWORD *)(v10 + 84),
          *(_DWORD *)(v10 + 80),
          0);
    }
    return 0;
  }
  return result;
}

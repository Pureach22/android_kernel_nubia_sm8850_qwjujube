__int64 __fastcall vote(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  __int64 v4; // x20
  _BYTE *v5; // x23
  char v6; // w25
  unsigned int v7; // w22
  unsigned int v8; // w21
  unsigned int v10; // w22
  __int64 v11; // x8
  __int64 v12; // x0
  int v13; // w8
  unsigned int v14; // w9
  signed int v15; // w8
  signed int v16; // w10
  bool v17; // cc
  signed int v18; // w10
  bool v19; // cc
  signed int v20; // w10
  bool v21; // cc
  signed int v22; // w10
  bool v23; // cc
  signed int v24; // w10
  bool v25; // cc
  signed int v26; // w10
  bool v27; // cc
  signed int v28; // w10
  bool v29; // cc
  signed int v30; // w10
  bool v31; // cc
  signed int v32; // w10
  bool v33; // cc
  signed int v34; // w10
  bool v35; // cc
  signed int v36; // w10
  bool v37; // cc
  signed int v38; // w10
  bool v39; // cc
  signed int v40; // w10
  bool v41; // cc
  signed int v42; // w10
  bool v43; // cc
  int v44; // w2
  unsigned int v45; // w8
  __int64 (__fastcall *v46)(__int64, __int64); // x8
  __int64 v47; // x1
  unsigned __int64 StatusReg; // x24
  __int64 v50; // x0
  __int64 v51; // x8

  v7 = -22;
  if ( !a1 )
    return v7;
  v8 = a2;
  if ( (a2 & 0x80000000) != 0 )
    return v7;
  if ( *(_DWORD *)(a1 + 92) == 2 )
    v10 = a3 & 1;
  else
    v10 = a4;
  if ( (unsigned int)a2 >= 8 )
    goto LABEL_139;
  v5 = (_BYTE *)(a1 + 24);
  v11 = a1 + 24 + 8LL * (unsigned int)a2;
  if ( *(_BYTE *)v11 == (a3 & 1) && *(_DWORD *)(v11 + 4) == v10 )
  {
    if ( (*(_BYTE *)(a1 + 128) & 1) != 0 )
      return 0;
  }
  else
  {
    *(_BYTE *)v11 = a3 & 1;
    *(_DWORD *)(v11 + 4) = v10;
  }
  v6 = a3;
  v12 = raw_spin_lock_irqsave(a1 + 104);
  a2 = *(_QWORD *)a1;
  v4 = v12;
  while ( 1 )
  {
    v13 = *(_DWORD *)(a1 + 92);
    if ( v13 == 2 )
    {
      v45 = *(_DWORD *)(a1 + 88);
      if ( (int)v45 < 1 )
      {
        v44 = 0;
        goto LABEL_129;
      }
      v44 = (unsigned __int8)*v5;
      if ( v45 == 1 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 32);
      if ( v45 < 3 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 40);
      if ( v45 == 3 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 48);
      if ( v45 < 5 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 56);
      if ( v45 == 5 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 64);
      if ( v45 < 7 )
        goto LABEL_129;
      v44 |= *(unsigned __int8 *)(a1 + 72);
      if ( v45 == 7 )
        goto LABEL_129;
      if ( v45 <= 8 )
      {
        v44 |= *(unsigned __int8 *)(a1 + 80);
        goto LABEL_129;
      }
      goto LABEL_139;
    }
    if ( v13 == 1 )
    {
      v14 = *(_DWORD *)(a1 + 88);
      if ( (int)v14 < 1 )
        goto LABEL_127;
      v15 = 0x80000000;
      v8 = -22;
      if ( (*v5 & 1) != 0 )
      {
        v15 = *(_DWORD *)(a1 + 28);
        if ( v15 == 0x80000000 )
          v8 = -22;
        else
          v8 = 0;
      }
      if ( v14 == 1 )
        break;
      if ( *(_BYTE *)(a1 + 32) == 1 )
      {
        v30 = *(_DWORD *)(a1 + 36);
        v31 = v15 < v30;
        if ( v15 <= v30 )
          v15 = *(_DWORD *)(a1 + 36);
        if ( v31 )
          v8 = 1;
      }
      if ( v14 < 3 )
        break;
      if ( *(_BYTE *)(a1 + 40) == 1 )
      {
        v32 = *(_DWORD *)(a1 + 44);
        v33 = v15 < v32;
        if ( v15 <= v32 )
          v15 = *(_DWORD *)(a1 + 44);
        if ( v33 )
          v8 = 2;
      }
      if ( v14 == 3 )
        break;
      if ( *(_BYTE *)(a1 + 48) == 1 )
      {
        v34 = *(_DWORD *)(a1 + 52);
        v35 = v15 < v34;
        if ( v15 <= v34 )
          v15 = *(_DWORD *)(a1 + 52);
        if ( v35 )
          v8 = 3;
      }
      if ( v14 < 5 )
        break;
      if ( *(_BYTE *)(a1 + 56) == 1 )
      {
        v36 = *(_DWORD *)(a1 + 60);
        v37 = v15 < v36;
        if ( v15 <= v36 )
          v15 = *(_DWORD *)(a1 + 60);
        if ( v37 )
          v8 = 4;
      }
      if ( v14 == 5 )
        break;
      if ( *(_BYTE *)(a1 + 64) == 1 )
      {
        v38 = *(_DWORD *)(a1 + 68);
        v39 = v15 < v38;
        if ( v15 <= v38 )
          v15 = *(_DWORD *)(a1 + 68);
        if ( v39 )
          v8 = 5;
      }
      if ( v14 < 7 )
        break;
      if ( *(_BYTE *)(a1 + 72) == 1 )
      {
        v40 = *(_DWORD *)(a1 + 76);
        v41 = v15 < v40;
        if ( v15 <= v40 )
          v15 = *(_DWORD *)(a1 + 76);
        if ( v41 )
          v8 = 6;
      }
      if ( v14 == 7 )
        break;
      if ( *(_BYTE *)(a1 + 80) == 1 )
      {
        v42 = *(_DWORD *)(a1 + 84);
        v43 = v15 < v42;
        if ( v15 <= v42 )
          v15 = *(_DWORD *)(a1 + 84);
        if ( v43 )
          v8 = 7;
      }
      goto LABEL_112;
    }
    if ( v13 )
    {
      v7 = -22;
      goto LABEL_137;
    }
    v14 = *(_DWORD *)(a1 + 88);
    if ( (int)v14 < 1 )
    {
LABEL_127:
      v8 = -22;
      v44 = -22;
      goto LABEL_129;
    }
    v15 = 0x7FFFFFFF;
    v8 = -22;
    if ( (*v5 & 1) != 0 )
    {
      v15 = *(_DWORD *)(a1 + 28);
      if ( v15 == 0x7FFFFFFF )
        v8 = -22;
      else
        v8 = 0;
    }
    if ( v14 == 1 )
      break;
    if ( *(_BYTE *)(a1 + 32) == 1 )
    {
      v16 = *(_DWORD *)(a1 + 36);
      v17 = v15 <= v16;
      if ( v15 >= v16 )
        v15 = *(_DWORD *)(a1 + 36);
      if ( !v17 )
        v8 = 1;
    }
    if ( v14 < 3 )
      break;
    if ( *(_BYTE *)(a1 + 40) == 1 )
    {
      v18 = *(_DWORD *)(a1 + 44);
      v19 = v15 <= v18;
      if ( v15 >= v18 )
        v15 = *(_DWORD *)(a1 + 44);
      if ( !v19 )
        v8 = 2;
    }
    if ( v14 == 3 )
      break;
    if ( *(_BYTE *)(a1 + 48) == 1 )
    {
      v20 = *(_DWORD *)(a1 + 52);
      v21 = v15 <= v20;
      if ( v15 >= v20 )
        v15 = *(_DWORD *)(a1 + 52);
      if ( !v21 )
        v8 = 3;
    }
    if ( v14 < 5 )
      break;
    if ( *(_BYTE *)(a1 + 56) == 1 )
    {
      v22 = *(_DWORD *)(a1 + 60);
      v23 = v15 <= v22;
      if ( v15 >= v22 )
        v15 = *(_DWORD *)(a1 + 60);
      if ( !v23 )
        v8 = 4;
    }
    if ( v14 == 5 )
      break;
    if ( *(_BYTE *)(a1 + 64) == 1 )
    {
      v24 = *(_DWORD *)(a1 + 68);
      v25 = v15 <= v24;
      if ( v15 >= v24 )
        v15 = *(_DWORD *)(a1 + 68);
      if ( !v25 )
        v8 = 5;
    }
    if ( v14 < 7 )
      break;
    if ( *(_BYTE *)(a1 + 72) == 1 )
    {
      v26 = *(_DWORD *)(a1 + 76);
      v27 = v15 <= v26;
      if ( v15 >= v26 )
        v15 = *(_DWORD *)(a1 + 76);
      if ( !v27 )
        v8 = 6;
    }
    if ( v14 == 7 )
      break;
    if ( *(_BYTE *)(a1 + 80) == 1 )
    {
      v28 = *(_DWORD *)(a1 + 84);
      v29 = v15 <= v28;
      if ( v15 >= v28 )
        v15 = *(_DWORD *)(a1 + 84);
      if ( !v29 )
        v8 = 7;
    }
LABEL_112:
    if ( v14 <= 8 )
      break;
LABEL_139:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v50 = _traceiter_sched_client_vote(0, a2, v8, v6 & 1, v10);
      v51 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v51;
      if ( !v51 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v50);
    }
  }
  if ( v8 == -22 )
    v44 = -22;
  else
    v44 = v15;
LABEL_129:
  if ( *(_BYTE *)(a1 + 128) == 1 && v44 == *(_DWORD *)(a1 + 100)
    || (*(_DWORD *)(a1 + 96) = v8,
        *(_DWORD *)(a1 + 100) = v44,
        (v46 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 120)) == nullptr) )
  {
    v7 = 0;
  }
  else
  {
    v47 = *(_QWORD *)(a1 + 112);
    if ( *((_DWORD *)v46 - 1) != -1953655469 )
      __break(0x8228u);
    v7 = v46(a1, v47);
  }
  *(_BYTE *)(a1 + 128) = 1;
LABEL_137:
  raw_spin_unlock_irqrestore(a1 + 104, v4);
  return v7;
}

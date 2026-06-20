__int64 __fastcall hdd_adapter_iterate(
        __int64 (__fastcall *a1)(__int64, __int64),
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x22
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x25
  unsigned __int64 v20; // x28
  __int64 v21; // x0
  __int64 v22; // x23
  _DWORD *v23; // x24
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned int *v26; // x8
  unsigned int v27; // w10
  __int64 v28; // x8
  __int64 v29; // x9
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  unsigned int *v32; // x9
  unsigned int v33; // w12
  __int64 v34; // x9
  unsigned int v36; // w22
  unsigned int v37; // [xsp+Ch] [xbp-154h]
  __int64 v38; // [xsp+10h] [xbp-150h] BYREF
  _QWORD s[41]; // [xsp+18h] [xbp-148h] BYREF

  s[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_adapter_iterate", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v37 = 16;
    goto LABEL_43;
  }
  v13 = context;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(context + 4);
  }
  else
  {
    raw_spin_lock_bh(context + 4);
    v13[5] |= 1uLL;
  }
  memset(s, 0, 0x138u);
  v38 = 0;
  LODWORD(v15) = 0;
  if ( !(unsigned int)qdf_list_peek_front(v13 + 6, &v38) )
  {
    v16 = v38 - 8;
    if ( v38 != 8 )
    {
      v17 = 0;
      do
      {
        if ( v17 == 39 )
        {
LABEL_46:
          __break(0x5512u);
LABEL_47:
          __break(1u);
        }
        if ( (v17 & 0x1FFFFFFFFFFFFFFFLL) == 0x27 )
          goto LABEL_47;
        s[v17] = v16;
        v15 = v17 + 1;
        v38 = 0;
        if ( (unsigned int)qdf_list_peek_next(v13 + 6, (_QWORD *)(v16 + 8), &v38) )
          break;
        v17 = v15;
        v16 = v38 - 8;
      }
      while ( v38 != 8 );
    }
  }
  v18 = v13[5];
  if ( (v18 & 1) != 0 )
  {
    v13[5] = v18 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 4);
    if ( (_DWORD)v15 )
      goto LABEL_15;
LABEL_42:
    v37 = 0;
    goto LABEL_43;
  }
  raw_spin_unlock(v13 + 4);
  if ( !(_DWORD)v15 )
    goto LABEL_42;
LABEL_15:
  v19 = 0;
  v37 = 0;
  v20 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v19 == 39 )
      goto LABEL_46;
    if ( (v19 & 0x1FFFFFFFFFFFFFFFLL) == 0x27 )
      goto LABEL_47;
    v21 = hdd_adapter_get_by_reference(v13, s[v19]);
    if ( v21 )
      break;
    v37 = 16;
LABEL_17:
    if ( ++v19 == (unsigned int)v15 )
      goto LABEL_43;
  }
  v22 = v21;
  if ( (*(_QWORD *)(v21 + 1640) & 1) == 0 || (v23 = (_DWORD *)(v21 + 52832), v21 == -52832) )
  {
LABEL_28:
    v24 = *(_QWORD *)(v22 + 32);
    if ( v24 )
    {
      ++*(_DWORD *)(v20 + 16);
      v25 = *(_QWORD *)(v24 + 1320);
      v26 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v25);
      do
        v27 = __ldxr(v26);
      while ( __stxr(v27 - 1, v26) );
      v28 = *(_QWORD *)(v20 + 16) - 1LL;
      *(_DWORD *)(v20 + 16) = v28;
      if ( !v28 || !*(_QWORD *)(v20 + 16) )
        preempt_schedule_notrace(v21);
    }
    goto LABEL_17;
  }
  while ( 1 )
  {
    if ( *((_DWORD *)a1 - 1) != -459219669 )
      __break(0x8234u);
    v21 = a1(v22 + 52832, a2);
    if ( (_DWORD)v21 )
      break;
    if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v23 - *v23 - 52832) >> 4))
      || (*(_QWORD *)(v22 + 1640) & 1) == 0 )
    {
      goto LABEL_28;
    }
  }
  v29 = *(_QWORD *)(v22 + 32);
  if ( !v29 )
    goto LABEL_39;
  v30 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v30 + 16);
  v31 = *(_QWORD *)(v29 + 1320);
  v32 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v31);
  do
    v33 = __ldxr(v32);
  while ( __stxr(v33 - 1, v32) );
  v34 = *(_QWORD *)(v30 + 16) - 1LL;
  *(_DWORD *)(v30 + 16) = v34;
  if ( v34 && *(_QWORD *)(v30 + 16) )
  {
LABEL_39:
    v37 = v21;
  }
  else
  {
    v36 = v21;
    preempt_schedule_notrace(v21);
    v37 = v36;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v37;
}

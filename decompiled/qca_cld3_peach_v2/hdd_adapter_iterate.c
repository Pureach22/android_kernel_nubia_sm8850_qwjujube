__int64 __fastcall hdd_adapter_iterate(
        _DWORD *a1,
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
  unsigned int v20; // w24
  __int64 v21; // x0
  __int64 v22; // x23
  _DWORD *v23; // x24
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned int *v29; // x8
  unsigned int v30; // w10
  __int64 v31; // x8
  __int64 v32; // x9
  unsigned __int64 v33; // x8
  __int64 v34; // x9
  unsigned int *v35; // x9
  unsigned int v36; // w12
  __int64 v37; // x9
  unsigned __int64 v39; // [xsp+8h] [xbp-168h]
  unsigned int v40; // [xsp+1Ch] [xbp-154h]
  __int64 v41; // [xsp+20h] [xbp-150h] BYREF
  _QWORD s[41]; // [xsp+28h] [xbp-148h] BYREF

  s[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_adapter_iterate", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v20 = 16;
    goto LABEL_54;
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
  v41 = 0;
  LODWORD(v15) = 0;
  if ( !(unsigned int)qdf_list_peek_front(v13 + 6, &v41) )
  {
    v16 = v41 - 8;
    if ( v41 != 8 )
    {
      v17 = 0;
      while ( 1 )
      {
        if ( v17 == 39 )
          goto LABEL_58;
        if ( (v17 & 0x1FFFFFFFFFFFFFFFLL) == 0x27 )
          break;
        s[v17] = v16;
        v15 = v17 + 1;
        v41 = 0;
        if ( !(unsigned int)qdf_list_peek_next(v13 + 6, (_QWORD *)(v16 + 8), &v41) )
        {
          v17 = v15;
          v16 = v41 - 8;
          if ( v41 != 8 )
            continue;
        }
        goto LABEL_13;
      }
LABEL_57:
      __break(1u);
LABEL_58:
      __break(0x5512u);
    }
  }
LABEL_13:
  v18 = v13[5];
  if ( (v18 & 1) != 0 )
  {
    v13[5] = v18 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 4);
    if ( (_DWORD)v15 )
      goto LABEL_15;
LABEL_53:
    v20 = 0;
    goto LABEL_54;
  }
  raw_spin_unlock(v13 + 4);
  if ( !(_DWORD)v15 )
    goto LABEL_53;
LABEL_15:
  v19 = 0;
  v20 = 0;
  v39 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v19 == 39 )
      goto LABEL_58;
    if ( (v19 & 0x1FFFFFFFFFFFFFFFLL) == 0x27 )
      goto LABEL_57;
    v21 = hdd_adapter_get_by_reference(v13, s[v19]);
    if ( v21 )
      break;
    v20 = 16;
LABEL_17:
    if ( ++v19 == (unsigned int)v15 )
      goto LABEL_54;
  }
  v40 = v20;
  v22 = v21;
  if ( (*(_QWORD *)(v21 + 1640) & 1) == 0 || (v23 = (_DWORD *)(v21 + 52840), v21 == -52840) )
  {
    if ( (*(_QWORD *)(v21 + 1640) & 2) == 0 || (v23 = (_DWORD *)(v21 + 58928), v21 == -58928) )
    {
      if ( (*(_QWORD *)(v21 + 1640) & 4) == 0 || (v23 = (_DWORD *)(v21 + 65016), v21 == -65016) )
      {
LABEL_37:
        v27 = *(_QWORD *)(v22 + 32);
        if ( v27 )
        {
          ++*(_DWORD *)(v39 + 16);
          v28 = *(_QWORD *)(v27 + 1320);
          v29 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v28);
          do
            v30 = __ldxr(v29);
          while ( __stxr(v30 - 1, v29) );
          v31 = *(_QWORD *)(v39 + 16) - 1LL;
          *(_DWORD *)(v39 + 16) = v31;
          v20 = v40;
          if ( !v31 || !*(_QWORD *)(v39 + 16) )
            preempt_schedule_notrace(v21);
        }
        else
        {
          v20 = v40;
        }
        goto LABEL_17;
      }
    }
  }
  while ( 1 )
  {
    if ( *(a1 - 1) != -459219669 )
      __break(0x8234u);
    v21 = ((__int64 (__fastcall *)(_DWORD *, __int64))a1)(v23, a2);
    if ( (_DWORD)v21 )
      break;
    if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1) <= 2u )
    {
      v24 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v23 - *v23 - 52840) >> 3) + 1);
      v23 = nullptr;
      v25 = v22 + 52840 + 6088LL * (unsigned int)v24;
      do
      {
        if ( v23 )
          break;
        v26 = *(_QWORD *)(v22 + 1640) >> v24++;
        v23 = (_DWORD *)((v26 << 63 >> 63) & v25);
        v25 += 6088;
      }
      while ( v24 != 3 );
      if ( v23 )
        continue;
    }
    goto LABEL_37;
  }
  v32 = *(_QWORD *)(v22 + 32);
  if ( !v32 )
    goto LABEL_50;
  v33 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v33 + 16);
  v34 = *(_QWORD *)(v32 + 1320);
  v35 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v34);
  do
    v36 = __ldxr(v35);
  while ( __stxr(v36 - 1, v35) );
  v37 = *(_QWORD *)(v33 + 16) - 1LL;
  *(_DWORD *)(v33 + 16) = v37;
  if ( v37 && *(_QWORD *)(v33 + 16) )
  {
LABEL_50:
    v20 = v21;
  }
  else
  {
    v20 = v21;
    preempt_schedule_notrace(v21);
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v20;
}

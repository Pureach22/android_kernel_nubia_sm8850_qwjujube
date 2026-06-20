__int64 __fastcall ieee80211_get_key(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        __int64 a6,
        __int64 a7,
        __int64 (__fastcall *a8)(__int64, __int64 *))
{
  __int64 v12; // x22
  __int64 lock; // x0
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x1
  __int64 *v19; // x8
  unsigned int v20; // w24
  int v21; // w9
  __int64 *v22; // x22
  __int64 v23; // x21
  _DWORD *v24; // x8
  __int64 v25; // x1
  __int64 v26; // x8
  unsigned __int64 v27; // x9
  _QWORD *v28; // x8
  int v29; // w9
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x10
  __int64 v34; // x21
  _DWORD *v35; // x8
  __int64 v36; // x1
  unsigned __int64 StatusReg; // x23
  __int64 key_seq; // x0
  __int64 v39; // x8
  __int64 v40; // [xsp+0h] [xbp-50h] BYREF
  _DWORD *v41; // [xsp+8h] [xbp-48h]
  __int64 v42; // [xsp+10h] [xbp-40h]
  __int64 v43; // [xsp+18h] [xbp-38h]
  __int64 v44; // [xsp+20h] [xbp-30h]
  _DWORD v45[2]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v46[2]; // [xsp+30h] [xbp-20h] BYREF
  int v47; // [xsp+40h] [xbp-10h]
  __int64 v48; // [xsp+48h] [xbp-8h]

  v12 = a4;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v45, 0, 6);
  v43 = 0;
  v44 = 0;
  v41 = nullptr;
  v42 = 0;
  v40 = 0;
  v47 = 0;
  v46[0] = 0;
  v46[1] = 0;
  lock = _rcu_read_lock(a1, a2);
  if ( (a3 & 0x80000000) != 0 )
  {
    v16 = a2 + 6304;
    if ( a6 )
      goto LABEL_5;
  }
  else
  {
    if ( a3 >= 0xF )
      goto LABEL_55;
    v16 = *(_QWORD *)(a2 + 8LL * a3 + 7256);
    if ( !v16 )
      goto LABEL_34;
    if ( a6 )
    {
LABEL_5:
      lock = sta_info_get_bss(a2 + 2688, a6);
      if ( lock )
      {
        if ( (a3 & 0x80000000) != 0 )
        {
          v17 = lock + 1640;
        }
        else
        {
          v17 = *(_QWORD *)(lock + 8LL * a3 + 2568);
          if ( !v17 )
            goto LABEL_34;
        }
        if ( (unsigned __int8)v12 <= 3u && (a5 & 1) != 0 )
        {
          v19 = (__int64 *)(lock + 8LL * (unsigned __int8)v12 + 88);
        }
        else
        {
          v20 = -2;
          if ( (unsigned __int8)v12 > 7u || (a5 & 1) != 0 )
            goto LABEL_41;
          v19 = (__int64 *)(v17 + 8LL * (unsigned __int8)v12 + 40);
        }
        goto LABEL_23;
      }
LABEL_34:
      v20 = -2;
      goto LABEL_41;
    }
  }
  if ( (unsigned __int8)v12 <= 3u && (a5 & 1) != 0 )
    goto LABEL_15;
  if ( (unsigned __int8)v12 > 7u )
  {
LABEL_55:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      key_seq = _traceiter_drv_get_key_seq(0, a2, v12);
      v39 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v39;
      if ( !v39 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(key_seq);
    }
    goto LABEL_33;
  }
  v18 = *(_QWORD *)(v16 + 8LL * (unsigned __int8)v12 + 48);
  if ( (unsigned __int8)v12 <= 3u && !v18 )
  {
LABEL_15:
    v19 = (__int64 *)(a2 + 8LL * (unsigned __int8)v12 + 4584);
LABEL_23:
    v18 = *v19;
  }
  if ( !v18 )
    goto LABEL_34;
  v21 = *(_DWORD *)(v18 + 544);
  v22 = (__int64 *)(v18 + 536);
  LODWORD(v43) = 0;
  v44 = 0;
  v41 = nullptr;
  v42 = 0;
  v40 = 0;
  HIDWORD(v43) = v21;
  if ( (unsigned int)(v21 - 1027074) <= 0xB )
  {
    if ( ((1 << (v21 - 2)) & 0xFD4) != 0 )
    {
      if ( (*(_BYTE *)(v18 + 40) & 1) == 0 || (*(_WORD *)(v18 + 552) & 2) != 0 )
      {
        v26 = *v22;
        v27 = (unsigned __int64)*v22 >> 8;
        LOBYTE(v45[0]) = *v22;
        BYTE1(v45[0]) = v27;
        BYTE2(v45[0]) = BYTE2(v26);
        HIBYTE(v45[0]) = BYTE3(v26);
        LOWORD(v45[1]) = WORD2(v26);
        goto LABEL_36;
      }
      v23 = *(_QWORD *)(a2 + 4304);
      v24 = *(_DWORD **)(*(_QWORD *)(v23 + 464) + 240LL);
      if ( v24 )
      {
        v25 = v18 + 536;
        if ( *(v24 - 1) != -111748570 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD *))v24)(v23, v25, v46);
      }
LABEL_33:
      v45[0] = v46[0];
      LOWORD(v45[1]) = WORD2(v46[0]);
LABEL_36:
      v28 = v45;
      v29 = 6;
      goto LABEL_37;
    }
    if ( v21 == 1027074 )
    {
      v31 = *(_QWORD *)(v18 + 536);
      v32 = v31 >> 16;
      v33 = v31 >> 8;
      if ( (*(_BYTE *)(v18 + 40) & 1) != 0 && (*(_WORD *)(v18 + 552) & 2) == 0 )
      {
        drv_get_key_seq(*(_QWORD *)(a2 + 4304));
        LOBYTE(v31) = BYTE4(v46[0]);
        LODWORD(v32) = v46[0];
        LODWORD(v33) = HIBYTE(WORD2(v46[0]));
      }
      LOBYTE(v45[0]) = v31;
      BYTE1(v45[0]) = v33;
      *(_DWORD *)((char *)v45 + 2) = v32;
      v41 = v45;
      HIDWORD(v42) = 6;
      goto LABEL_38;
    }
  }
  if ( (*(_BYTE *)(v18 + 40) & 1) == 0 )
    goto LABEL_38;
  if ( (*(_WORD *)(v18 + 552) & 2) != 0 )
  {
    __break(0x800u);
    goto LABEL_38;
  }
  v34 = *(_QWORD *)(a2 + 4304);
  v35 = *(_DWORD **)(*(_QWORD *)(v34 + 464) + 240LL);
  if ( v35 )
  {
    v36 = v18 + 536;
    if ( *(v35 - 1) != -111748570 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD *))v35)(v34, v36, v46);
  }
  v29 = (unsigned __int8)v47;
  v28 = v46;
LABEL_37:
  v41 = v28;
  HIDWORD(v42) = v29;
LABEL_38:
  if ( *((_DWORD *)a8 - 1) != -867534714 )
    __break(0x8233u);
  lock = a8(a7, &v40);
  v20 = 0;
LABEL_41:
  _rcu_read_unlock(lock);
  _ReadStatusReg(SP_EL0);
  return v20;
}

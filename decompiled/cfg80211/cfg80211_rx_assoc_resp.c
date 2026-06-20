__int64 __fastcall cfg80211_rx_assoc_resp(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x21
  __int64 v4; // x23
  __int64 *v5; // x22
  __int64 v6; // x20
  __int64 v7; // x9
  __int64 v8; // x10
  int v9; // w12
  __int64 v10; // x11
  __int64 v11; // x8
  _DWORD **v12; // x9
  __int64 v13; // x8
  __int64 v14; // x11
  __int64 v15; // x12
  int v16; // w10
  char v17; // w10
  _DWORD *v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  int **v21; // x10
  char v22; // w12
  _QWORD *v23; // x15
  int v24; // w16
  int *v25; // x13
  int *v26; // x14
  __int64 v27; // x15
  __int64 v28; // x16
  __int64 v29; // x15
  int v30; // w14
  char v31; // w14
  _DWORD *v32; // x13
  __int64 v33; // x13
  int v34; // w24
  __int64 result; // x0
  __int64 v36; // x21
  __int64 v37; // x1
  __int64 v38; // x8
  unsigned int v45; // w8
  unsigned int v46; // w8
  unsigned int v49; // w8
  unsigned int v50; // w8
  unsigned __int64 StatusReg; // x24
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x2
  __int64 v55; // x8
  _QWORD s[75]; // [xsp+8h] [xbp-258h] BYREF

  s[74] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 **)(a1 + 992);
  v6 = *v5;
  if ( *v5 )
  {
    v3 = a1;
    v2 = a2;
    v4 = *a2;
    memset(s, 0, 0x250u);
    v7 = v2[2];
    v8 = v2[3];
    v9 = *((unsigned __int16 *)v2 + 32);
    v10 = v2[5];
    LODWORD(s[0]) = *(unsigned __int16 *)(v4 + 26);
    v11 = v2[1];
    s[1] = v7;
    s[2] = v8;
    LOWORD(s[17]) = v9;
    s[3] = v4 + 30;
    s[4] = v11 - 30;
    v12 = (_DWORD **)v2[7];
    v13 = v4 + 28;
    s[12] = v10;
    s[16] = v12;
    if ( v9 )
    {
      if ( v10 && v12 )
      {
        v14 = v2[7] + 72LL;
        s[14] = v2 + 6;
        s[15] = v14;
        goto LABEL_9;
      }
      __break(0x800u);
    }
    if ( !v12 )
    {
LABEL_20:
      v20 = 0;
      v4 = v6 - 992;
      v21 = (int **)&s[18];
      v22 = 1;
      while ( 1 )
      {
        v23 = &v2[v20];
        v24 = LOWORD(v2[v20 + 11]);
        v25 = (int *)v2[v20 + 10];
        v26 = (int *)&v2[v20 + 9];
        *((_WORD *)v21 + 12) = v24;
        v21[2] = v25;
        if ( v24 )
        {
          if ( s[12] && v25 )
          {
            v27 = v23[10] + 72LL;
            *v21 = v26;
            v21[1] = (int *)v27;
            goto LABEL_29;
          }
          __break(0x800u);
        }
        if ( v25 )
        {
          v28 = s[12];
          v29 = v23[10] + 72LL;
          *v21 = v26;
          v21[1] = (int *)v29;
          if ( v28 )
          {
LABEL_29:
            v30 = *v26;
            if ( (v30 & 1) != 0 || !(v30 | WORD2(v2[v20 + 9])) )
            {
              v31 = 0;
              __break(0x800u);
              v32 = *(_DWORD **)v25;
              if ( !v32 )
                goto LABEL_57;
            }
            else
            {
              v31 = 0;
              v32 = *(_DWORD **)v25;
              if ( !v32 )
                goto LABEL_57;
            }
          }
          else
          {
            v31 = 1;
            v32 = *(_DWORD **)v25;
            if ( !v32 )
              goto LABEL_57;
          }
          if ( *v32 == 4 )
          {
            __break(0x800u);
            v33 = v2[1] - 28LL;
            s[3] = v13;
            s[4] = v33;
          }
          if ( (v31 & 1) == 0 )
            LOWORD(s[13]) |= 1LL << v22;
        }
        v20 += 3;
        ++v22;
        v21 += 4;
        if ( v20 == 42 )
          goto LABEL_40;
      }
    }
    v15 = v2[7] + 72LL;
    s[14] = v2 + 6;
    s[15] = v15;
    if ( !v10 )
    {
      v17 = 1;
      v18 = *v12;
      if ( !v18 )
      {
LABEL_57:
        __break(0x800u);
        goto LABEL_58;
      }
      goto LABEL_16;
    }
LABEL_9:
    v16 = *((_DWORD *)v2 + 12);
    if ( (v16 & 1) != 0 || !(v16 | *((unsigned __int16 *)v2 + 26)) )
    {
      v17 = 0;
      __break(0x800u);
      v18 = *v12;
      if ( !v18 )
        goto LABEL_57;
    }
    else
    {
      v17 = 0;
      v18 = *v12;
      if ( !v18 )
        goto LABEL_57;
    }
LABEL_16:
    if ( *v18 == 4 )
    {
      v19 = v2[1] - 28LL;
      s[3] = v4 + 28;
      s[4] = v19;
    }
    if ( (v17 & 1) == 0 )
      LOWORD(s[13]) = 1;
    goto LABEL_20;
  }
LABEL_58:
  __break(0x800u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v52 = _traceiter_cfg80211_send_rx_assoc(0, v3, v2);
    v55 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v55;
    if ( !v55 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v52, v53, v54);
  }
LABEL_40:
  v34 = s[0];
  result = ((__int64 (__fastcall *)(__int64 *, _QWORD))cfg80211_sme_rx_assoc_resp)(v5, LODWORD(s[0]));
  if ( (result & 1) != 0 )
  {
    v36 = 7;
    while ( 1 )
    {
      v37 = v2[v36];
      if ( !v37 )
        goto LABEL_43;
      _X9 = (unsigned int *)(v37 - 32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v45 = __ldxr(_X9);
        v46 = v45 - 1;
      }
      while ( __stlxr(v46, _X9) );
      __dmb(0xBu);
      if ( (v46 & 0x80000000) != 0 )
      {
        __break(0x800u);
        v38 = *(_QWORD *)(v37 + 40);
        if ( v38 )
        {
LABEL_47:
          _X9 = (unsigned int *)(v38 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v49 = __ldxr(_X9);
            v50 = v49 - 1;
          }
          while ( __stlxr(v50, _X9) );
          __dmb(0xBu);
          if ( (v50 & 0x80000000) != 0 )
            __break(0x800u);
        }
      }
      else
      {
        v38 = *(_QWORD *)(v37 + 40);
        if ( v38 )
          goto LABEL_47;
      }
      result = cfg80211_put_bss(v6, v37);
LABEL_43:
      v36 += 3;
      if ( v36 == 52 )
        goto LABEL_56;
    }
  }
  nl80211_send_rx_assoc(v4, v3, v2);
  result = _cfg80211_connect_result(v3, s, v34 == 0);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}

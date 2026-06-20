__int64 __fastcall ieee80211_tx_frags(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  __int64 *v5; // x23
  __int64 v10; // x25
  __int64 v11; // x24
  __int64 v12; // x26
  __int64 *v13; // x27
  unsigned __int64 v14; // x28
  __int64 v15; // x0
  __int64 v16; // x8
  int v17; // w8
  __int64 v18; // x8
  _QWORD *v19; // x9
  _DWORD *v20; // x8
  __int64 *v21; // x8
  _QWORD *v22; // x11
  __int64 *v23; // x10
  __int64 v24; // x12
  __int64 *v25; // x8
  __int64 *v26; // x11
  __int64 v27; // x9
  _QWORD *v28; // x10
  __int64 result; // x0
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(__int64 **)a4;
  v30[0] = 0;
  if ( v5 == (__int64 *)a4 )
  {
    result = 1;
    goto LABEL_24;
  }
  v10 = a1 + 480;
  v11 = a1 + 2000;
  if ( a3 )
    v12 = a3 + 2688;
  else
    v12 = 0;
  while ( 1 )
  {
    v13 = (__int64 *)*v5;
    v14 = ((unsigned __int64)*((unsigned int *)v5 + 11) >> 17) & 0xF;
    v15 = raw_spin_lock_irqsave(a1 + 1312);
    v16 = *(_QWORD *)(v10 + 8 * v14);
    if ( v16 )
      break;
    if ( (a5 & 1) == 0
      && *(_QWORD *)(v11 + 24LL * (unsigned int)v14) != v11 + 24LL * (unsigned int)v14
      && (*((_BYTE *)v5 + 41) & 0x20) == 0 )
    {
      goto LABEL_20;
    }
LABEL_12:
    raw_spin_unlock_irqrestore(a1 + 1312, v15);
    v5[8] = a2;
    v17 = *(_DWORD *)(a4 + 16);
    v30[0] = v12;
    *(_DWORD *)(a4 + 16) = v17 - 1;
    v18 = *v5;
    v19 = (_QWORD *)v5[1];
    *v5 = 0;
    v5[1] = 0;
    *(_QWORD *)(v18 + 8) = v19;
    *v19 = v18;
    v20 = **(_DWORD ***)(a1 + 464);
    if ( *(v20 - 1) != 638598288 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *, __int64 *))v20)(a1, v30, v5);
    result = 1;
    v5 = v13;
    if ( v13 == (__int64 *)a4 )
      goto LABEL_24;
  }
  if ( (*((_BYTE *)v5 + 41) & 0x20) != 0 )
  {
    if ( (v16 & 0xFFFFFFFFFFFFFFBFLL) != 0 )
    {
      raw_spin_unlock_irqrestore(a1 + 1312, v15);
      ieee80211_purge_tx_queue(a1, a4);
      result = 1;
      goto LABEL_24;
    }
    goto LABEL_12;
  }
  if ( (a5 & 1) != 0 )
  {
    v21 = *(__int64 **)a4;
    if ( *(_QWORD *)a4 == a4 )
      goto LABEL_23;
    v22 = *(_QWORD **)(a4 + 8);
    v23 = (__int64 *)(v11 + 24LL * (unsigned int)v14);
    v24 = *v23;
    v21[1] = (__int64)v23;
    *v23 = (__int64)v21;
    *v22 = v24;
    *(_QWORD *)(v24 + 8) = v22;
    goto LABEL_22;
  }
LABEL_20:
  v25 = *(__int64 **)a4;
  if ( *(_QWORD *)a4 == a4 )
    goto LABEL_23;
  v26 = *(__int64 **)(a4 + 8);
  v27 = v11 + 24LL * (unsigned int)v14;
  v28 = *(_QWORD **)(v27 + 8);
  v25[1] = (__int64)v28;
  *v28 = v25;
  *v26 = v27;
  *(_QWORD *)(v27 + 8) = v26;
LABEL_22:
  *(_DWORD *)(v11 + 24LL * (unsigned int)v14 + 16) += *(_DWORD *)(a4 + 16);
  *(_QWORD *)a4 = a4;
  *(_QWORD *)(a4 + 8) = a4;
  *(_DWORD *)(a4 + 16) = 0;
LABEL_23:
  raw_spin_unlock_irqrestore(a1 + 1312, v15);
  result = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall _qcom_glink_send(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 v7; // x20
  unsigned __int64 v8; // x24
  __int64 v9; // x8
  __int64 v10; // x27
  __int64 next; // x0
  __int64 v12; // x23
  unsigned __int64 v13; // x8
  int v14; // w3
  __int64 v15; // x8
  unsigned int v16; // w0
  unsigned __int64 i; // x27
  __int64 v18; // x0
  int v19; // w23
  __int64 v20; // x23
  unsigned __int64 v21; // x28
  int v22; // w3
  int v23; // w9
  int v24; // w10
  __int16 v25; // w9
  __int64 v26; // x27
  __int64 v27; // x9
  __int64 result; // x0
  unsigned int v29; // w20
  int v30; // w8
  bool v31; // nf
  __int64 v32; // [xsp+10h] [xbp-60h]
  int v34; // [xsp+24h] [xbp-4Ch] BYREF
  _QWORD v35[5]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v36; // [xsp+50h] [xbp-20h] BYREF
  __int64 v37; // [xsp+58h] [xbp-18h] BYREF
  __int64 v38; // [xsp+60h] [xbp-10h]
  __int64 v39; // [xsp+68h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 112);
  v34 = 0;
  v37 = 0;
  v38 = 0;
  if ( *(_BYTE *)(v7 + 216) == 1 )
  {
    v8 = a3;
    v9 = 0;
    if ( !a3 )
    {
LABEL_54:
      result = 0;
      goto LABEL_61;
    }
  }
  else
  {
    v8 = a3;
    while ( 1 )
    {
      v10 = raw_spin_lock_irqsave(a1 + 144);
      v34 = 0;
      next = idr_get_next(a1 + 176, &v34);
      if ( next )
        break;
LABEL_16:
      raw_spin_unlock_irqrestore(a1 + 144, v10);
      if ( (a4 & 1) == 0 )
      {
        result = 4294967280LL;
        goto LABEL_61;
      }
      v36 = 7;
      mutex_lock(a1 + 344);
      *(_DWORD *)(a1 + 392) = -1;
      *(_BYTE *)(a1 + 396) = 0;
      v14 = *(_DWORD *)(a1 + 136);
      v15 = *(_QWORD *)(a1 + 112);
      HIDWORD(v36) = a3;
      WORD1(v36) = v14;
      if ( v15 )
        ipc_log_string(
          *(_QWORD *)(v15 + 256),
          "%s[%d:%d] %s: size:%zd\n",
          *(const char **)(a1 + 128),
          v14,
          *(_DWORD *)(a1 + 140),
          "qcom_glink_request_intent",
          a3);
      v16 = qcom_glink_tx(v7, (__int64)&v36, 8, 0, 0, 1);
      if ( v16 )
      {
        v29 = v16;
LABEL_60:
        mutex_unlock(a1 + 344);
        result = v29;
        goto LABEL_61;
      }
      if ( ((*(_DWORD *)(a1 + 392) & 0x80000000) != 0 || (*(_BYTE *)(a1 + 396) & 1) == 0)
        && (*(_BYTE *)(v7 + 249) & 1) == 0 )
      {
        memset(v35, 0, sizeof(v35));
        init_wait_entry(v35, 0);
        for ( i = 2500; ; i = schedule_timeout() )
        {
          prepare_to_wait_event(a1 + 400, v35, 2);
          if ( (*(_DWORD *)(a1 + 392) & 0x80000000) == 0 && *(_BYTE *)(a1 + 396) == 1 )
            break;
          if ( (*(_BYTE *)(v7 + 249) & (i == 0)) != 0 )
            v18 = 1;
          else
            v18 = i;
          if ( (*(_BYTE *)(v7 + 249) & 1) != 0 || !v18 )
          {
            v19 = v18;
            goto LABEL_36;
          }
        }
        v19 = i <= 1 ? 1 : i;
LABEL_36:
        finish_wait(a1 + 400, v35);
        if ( !v19 )
        {
          dev_err(
            *(_QWORD *)v7,
            "%s: intent request ack timed out (%d)\n",
            *(const char **)(a1 + 128),
            *(_DWORD *)(a1 + 428));
          v30 = *(_DWORD *)(a1 + 428) + 1;
          v31 = *(_DWORD *)(a1 + 428) - 1 < 0;
          *(_DWORD *)(a1 + 428) = v30;
          if ( v31 == __OFSUB__(v30, 2) )
            ipc_log_string(
              *(_QWORD *)(v7 + 256),
              "[%s]: WARN at line %d: remoteproc:%s channel:%s unresponsive\n",
              "qcom_glink_request_intent",
              1956,
              *(const char **)(v7 + 8),
              *(const char **)(a1 + 128));
          v29 = -110;
          goto LABEL_60;
        }
      }
      if ( !*(_DWORD *)(a1 + 392) )
      {
        v29 = -125;
        goto LABEL_60;
      }
      mutex_unlock(a1 + 344);
    }
    v12 = 0;
    while ( 1 )
    {
      v13 = *(_QWORD *)(next + 16);
      if ( v13 >= a3 && (*(_BYTE *)(next + 25) & 1) == 0 )
      {
        if ( v12 )
        {
          if ( *(_QWORD *)(v12 + 16) <= v13 )
            next = v12;
          v13 = *(_QWORD *)(next + 16);
        }
        v12 = next;
        if ( v13 == a3 )
          break;
      }
      ++v34;
      next = idr_get_next(a1 + 176, &v34);
      if ( !next )
      {
        next = v12;
        if ( !v12 )
          goto LABEL_16;
        break;
      }
    }
    v20 = next;
    *(_BYTE *)(next + 25) = 1;
    raw_spin_unlock_irqrestore(a1 + 144, v10);
    v9 = v20;
    v34 = *(_DWORD *)(v20 + 8);
    if ( !a3 )
      goto LABEL_54;
  }
  v21 = 0;
  v32 = v9;
  while ( 1 )
  {
    v22 = *(_DWORD *)(a1 + 136);
    if ( a3 - (int)v21 >= 0x2000 )
      v23 = 0x2000;
    else
      v23 = a3 - v21;
    WORD1(v37) = *(_DWORD *)(a1 + 136);
    if ( (a4 & 1) != 0 )
      v24 = v23;
    else
      v24 = a3 - v21;
    if ( v21 )
      v25 = 12;
    else
      v25 = 9;
    v26 = v24;
    LOWORD(v37) = v25;
    v27 = *(_QWORD *)(a1 + 112);
    HIDWORD(v37) = v34;
    LODWORD(v38) = v24;
    HIDWORD(v38) = a3 - v21 - v24;
    if ( v27 )
      ipc_log_string(
        *(_QWORD *)(v27 + 256),
        "%s[%d:%d] %s: iid:%d chunk_size:%d left_size:%d\n",
        *(const char **)(a1 + 128),
        v22,
        *(_DWORD *)(a1 + 140),
        "__qcom_glink_send",
        v34,
        v24,
        a3 - v21 - v24);
    result = qcom_glink_tx(v7, (__int64)&v37, 16, a2 + v21, v26, a4 & 1);
    if ( (_DWORD)result )
      break;
    v21 += v26;
    if ( v21 >= v8 )
      goto LABEL_54;
  }
  if ( v32 )
    *(_BYTE *)(v32 + 25) = 0;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}

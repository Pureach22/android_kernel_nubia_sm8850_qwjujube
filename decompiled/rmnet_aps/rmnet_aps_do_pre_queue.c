__int64 __fastcall rmnet_aps_do_pre_queue(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  __int64 v6; // x9
  __int64 *v7; // x9
  __int64 *v8; // x10
  __int64 *v9; // x24
  __int64 v10; // x20
  _QWORD *v11; // x20
  _QWORD *v12; // x21
  _QWORD *v13; // t1
  int v14; // w8
  char v15; // w9
  int v16; // w9
  __int64 v17; // x23
  int v18; // w10
  int v19; // w9
  int v20; // w9
  __int64 v21; // x9
  _QWORD v22[5]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 3176) )
    result = ktime_get_with_offset(1);
  else
    result = 0;
  *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 16LL) = result;
  if ( !rmnet_aps_flow_cnt )
    goto LABEL_62;
  if ( !aps_user_cookie )
  {
    v10 = *(_QWORD *)(a1 + 3184);
    if ( !v10 )
      goto LABEL_62;
    v23 = 0;
    v13 = *(_QWORD **)(v10 + 16);
    v11 = (_QWORD *)(v10 + 16);
    v12 = v13;
    memset(v22, 0, sizeof(v22));
    if ( v13 == v11 )
      goto LABEL_62;
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      v17 = v12[7];
      if ( v17 )
      {
        v18 = *(_DWORD *)(v17 + 28);
        if ( v18 != 10 )
        {
          if ( v18 == 2 && *(_WORD *)(a2 + 180) != 8 )
            goto LABEL_59;
LABEL_25:
          if ( (v15 & 1) == 0 )
          {
            result = aps_dissect_skb(a2, (__int64)v22);
            if ( (_DWORD)result || BYTE1(v22[0]) )
              goto LABEL_62;
            v14 = BYTE3(v22[0]);
          }
          v19 = *(unsigned __int8 *)(v17 + 74);
          if ( *(_BYTE *)(v17 + 74) )
          {
            if ( v19 == 253 )
            {
              if ( v14 != 6 && v14 != 17 )
                goto LABEL_58;
LABEL_37:
              if ( *(_WORD *)(v17 + 66)
                && (*(unsigned __int16 *)(v17 + 66) > (unsigned int)HIWORD(v22[4])
                 || *(unsigned __int16 *)(v17 + 110) < (unsigned int)HIWORD(v22[4]))
                || *(_WORD *)(v17 + 64)
                && (*(unsigned __int16 *)(v17 + 64) > (unsigned int)WORD2(v22[4])
                 || *(unsigned __int16 *)(v17 + 108) < (unsigned int)WORD2(v22[4])) )
              {
                goto LABEL_58;
              }
LABEL_43:
              v20 = *(_DWORD *)(v17 + 28);
              if ( v20 == 10 )
              {
                if ( ((*(_BYTE *)(v17 + 75) & 2) == 0
                   || ((*(_OWORD *)((char *)&v22[2] + 4) ^ *(_OWORD *)(v17 + 48)) & *(_OWORD *)(v17 + 92)) == 0)
                  && ((*(_BYTE *)(v17 + 75) & 1) == 0
                   || ((*(_OWORD *)((char *)v22 + 4) ^ *(_OWORD *)(v17 + 32)) & *(_OWORD *)(v17 + 76)) == 0)
                  && (!*(_BYTE *)(v17 + 72)
                   || *(unsigned __int8 *)(v17 + 72) == (unsigned __int8)(*(_BYTE *)(v17 + 73) & BYTE4(v23))) )
                {
                  v16 = *(_DWORD *)(v17 + 68);
                  if ( !v16 || v16 == (_DWORD)v23 )
                  {
LABEL_63:
                    v9 = v12 - 2;
                    if ( v12 != qword_10 )
                    {
LABEL_61:
                      raw_spin_lock_bh(&rmnet_aps_lock);
                      *(_DWORD *)(a2 + 144) = *((_DWORD *)v9 + 20);
                      v21 = v9[12];
                      v9[11] = jiffies + *((unsigned int *)v9 + 21);
                      v9[12] = v21 + *(unsigned int *)(a2 + 112);
                      raw_spin_unlock_bh(&rmnet_aps_lock);
                      result = queue_delayed_work_on(32, system_wq, &rmnet_aps_rate_work, 750);
                    }
                    goto LABEL_62;
                  }
                }
              }
              else if ( v20 == 2
                     && ((*(_BYTE *)(v17 + 75) & 2) == 0
                      || ((HIDWORD(v22[2]) ^ *(_DWORD *)(v17 + 48)) & *(_DWORD *)(v17 + 92)) == 0)
                     && ((*(_BYTE *)(v17 + 75) & 1) == 0
                      || ((HIDWORD(v22[0]) ^ *(_DWORD *)(v17 + 32)) & *(_DWORD *)(v17 + 76)) == 0)
                     && (!*(_BYTE *)(v17 + 72)
                      || *(unsigned __int8 *)(v17 + 72) == (unsigned __int8)(*(_BYTE *)(v17 + 73) & BYTE4(v23))) )
              {
                goto LABEL_63;
              }
              goto LABEL_58;
            }
            if ( v19 != v14 )
            {
LABEL_58:
              v15 = 1;
              goto LABEL_59;
            }
          }
          if ( v14 == 17 || v14 == 6 )
            goto LABEL_37;
          goto LABEL_43;
        }
        if ( *(unsigned __int16 *)(a2 + 180) == 56710 )
          goto LABEL_25;
      }
LABEL_59:
      v12 = (_QWORD *)*v12;
      if ( v12 == v11 )
        goto LABEL_62;
    }
  }
  v5 = *(_DWORD *)(a2 + 144);
  if ( (unsigned __int16)aps_user_cookie == HIWORD(v5) )
  {
    v6 = *(_QWORD *)(a1 + 3184);
    if ( v6 )
    {
      v7 = (__int64 *)(v6 + 16);
      v8 = v7;
      while ( 1 )
      {
        v8 = (__int64 *)*v8;
        if ( v8 == v7 )
          break;
        if ( *((_DWORD *)v8 + 9) == v5 )
        {
          v9 = v8 - 2;
          if ( v8 != qword_10 )
            goto LABEL_61;
          break;
        }
      }
    }
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}

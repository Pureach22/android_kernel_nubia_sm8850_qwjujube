__int64 __fastcall rmnet_aps_genl_flow_hdlr(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned __int64 v7; // x0
  __int64 v8; // x1
  int v9; // w21
  __int64 result; // x0
  _UNKNOWN ***v11; // x0
  __int64 v12; // x9
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x11
  __int64 v16; // x8
  __int64 v17; // x12
  _UNKNOWN **v18; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x9
  unsigned int *v21; // x9
  unsigned int v22; // w12
  __int64 v23; // x9
  unsigned __int64 v24; // [xsp+0h] [xbp-30h] BYREF
  int v25; // [xsp+8h] [xbp-28h]
  __int64 v26; // [xsp+10h] [xbp-20h] BYREF
  __int64 v27; // [xsp+18h] [xbp-18h]
  int v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = a2[4];
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v3 = *(_QWORD *)(v2 + 8);
    if ( v3 )
    {
      if ( (int)nla_memcpy(&v26, v3, 20) >= 1 )
      {
        mutex_lock(&rmnet_aps_mutex);
        if ( rmnet_aps_active == 1 )
        {
          if ( (unsigned int)(v26 - 2) >= 3 )
          {
            if ( (_DWORD)v26 == 1 )
            {
              aps_client_genl_info = *a2;
              v11 = (_UNKNOWN ***)aps_flow_list;
              v12 = a2[4];
              v13 = a2[1];
              v14 = a2[2];
              qword_8D18 = a2[3];
              qword_8D20 = v12;
              qword_8D08 = v13;
              qword_8D10 = v14;
              v15 = a2[8];
              v17 = a2[5];
              v16 = a2[6];
              qword_8D38 = a2[7];
              qword_8D40 = v15;
              qword_8D28 = v17;
              qword_8D30 = v16;
              if ( aps_flow_list != (_UNKNOWN *)&aps_flow_list )
              {
                do
                {
                  v18 = *v11;
                  rmnet_aps_remove_flow(v11 - 4);
                  v11 = (_UNKNOWN ***)v18;
                }
                while ( v18 != &aps_flow_list );
              }
              v9 = 0;
              aps_user_cookie = WORD2(v26);
              goto LABEL_16;
            }
          }
          else if ( HIDWORD(v27) )
          {
            v5 = dev_get_by_index(&init_net);
            if ( v5 )
            {
              v6 = v5;
              v7 = strncmp((const char *)(v5 + 296), "rmnet_data", 0xAu);
              if ( (_DWORD)v7 )
              {
LABEL_9:
                v9 = -22;
LABEL_24:
                StatusReg = _ReadStatusReg(SP_EL0);
                ++*(_DWORD *)(StatusReg + 16);
                v20 = *(_QWORD *)(v6 + 1320);
                v21 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v20);
                do
                  v22 = __ldxr(v21);
                while ( __stxr(v22 - 1, v21) );
                v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
                *(_DWORD *)(StatusReg + 16) = v23;
                if ( !v23 || !*(_QWORD *)(StatusReg + 16) )
                  preempt_schedule_notrace(v7, v8);
                goto LABEL_16;
              }
              v7 = *(_QWORD *)(v6 + 3184);
              if ( v7 || (_DWORD)v26 != 2 )
              {
                if ( !v7 )
                  goto LABEL_9;
              }
              else
              {
                v7 = _kmalloc_cache_noprof(raw_spin_unlock_bh, 3520, 32);
                if ( !v7 )
                  goto LABEL_9;
                *(_QWORD *)(v7 + 16) = v7 + 16;
                *(_QWORD *)(v7 + 24) = v7 + 16;
                atomic_store(v7, (unsigned __int64 *)(v6 + 3184));
              }
              v7 = rmnet_aps_change_flow(v7 + 16, &v26);
              v9 = v7;
              goto LABEL_24;
            }
          }
        }
        v9 = -22;
LABEL_16:
        mutex_unlock(&rmnet_aps_mutex);
        v24 = __PAIR64__(v9, v26);
        v25 = HIDWORD(v26);
        result = rmnet_aps_send_msg(a2, 1, 2, 12, &v24, 3264);
        goto LABEL_17;
      }
    }
  }
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

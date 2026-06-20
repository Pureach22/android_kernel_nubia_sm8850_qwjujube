__int64 __fastcall mlo_mgr_ml_peer_exist_on_diff_ml_ctx(unsigned __int8 *a1, unsigned __int8 *a2)
{
  __int64 mlo_ctx; // x19
  __int64 result; // x0
  int v6; // w8
  int v7; // w0
  _QWORD *v8; // x21
  int v10; // w0
  _QWORD *v11; // x24
  int v12; // w23
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  _QWORD v34[3]; // [xsp+8h] [xbp-18h] BYREF

  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  result = 0;
  if ( a1 && mlo_ctx )
  {
    if ( *(_DWORD *)a1 | *((unsigned __int16 *)a1 + 2) )
    {
      qdf_mutex_acquire(mlo_ctx);
      v6 = *(_DWORD *)(mlo_ctx + 208);
      if ( v6 )
      {
        v34[0] = 0;
        v7 = qdf_list_peek_front((_QWORD *)(mlo_ctx + 192), v34);
        v6 = 0;
        if ( !v7 )
        {
          v8 = (_QWORD *)v34[0];
          if ( v34[0] )
          {
            while ( 1 )
            {
              qdf_mutex_acquire((__int64)(v8 + 207));
              if ( *(_DWORD *)((char *)&off_10 + (_QWORD)v8 + 1) == *(_DWORD *)a1
                && *(unsigned __int16 *)((char *)&off_10 + (_QWORD)v8 + 5) == *((unsigned __int16 *)a1 + 2) )
              {
                break;
              }
              qdf_mutex_acquire((__int64)(v8 + 198));
              if ( mlo_get_mlpeer(v8, a1) )
              {
                if ( a2 )
                {
                  v15 = *(__int64 *)((char *)&off_18 + (_QWORD)v8);
                  LODWORD(a2) = v15 && *a2 == *(unsigned __int8 *)(v15 + 168)
                             || (v16 = *(__int64 *)((char *)&off_20 + (_QWORD)v8)) != 0
                             && *a2 == *(unsigned __int8 *)(v16 + 168);
                }
                qdf_mutex_release((__int64)(v8 + 198));
                qdf_mutex_release((__int64)(v8 + 207));
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: MLD ID %d ML Peer exists with mac %02x:%02x:%02x:**:**:%02x",
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  "mlo_mgr_ml_peer_exist_on_diff_ml_ctx",
                  *((unsigned __int8 *)&off_10 + (_QWORD)v8),
                  *a1,
                  a1[1],
                  a1[2],
                  a1[5]);
                if ( !(_DWORD)a2 )
                  goto LABEL_33;
LABEL_30:
                v6 = 0;
                goto LABEL_34;
              }
              qdf_mutex_release((__int64)(v8 + 198));
              v34[0] = 0;
              v10 = qdf_list_peek_next((_QWORD *)(mlo_ctx + 192), v8, v34);
              v11 = (_QWORD *)v34[0];
              v12 = v10;
              qdf_mutex_release((__int64)(v8 + 207));
              v6 = 0;
              if ( !v12 )
              {
                v8 = v11;
                if ( v11 )
                  continue;
              }
              goto LABEL_34;
            }
            if ( a2 )
            {
              v13 = *(__int64 *)((char *)&off_18 + (_QWORD)v8);
              LOBYTE(a2) = v13 && *a2 == *(unsigned __int8 *)(v13 + 168)
                        || (v14 = *(__int64 *)((char *)&off_20 + (_QWORD)v8)) != 0
                        && *a2 == *(unsigned __int8 *)(v14 + 168);
            }
            qdf_mutex_release((__int64)(v8 + 207));
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: MLD ID %d exists with mac %02x:%02x:%02x:**:**:%02x",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "mlo_mgr_ml_peer_exist_on_diff_ml_ctx",
              *((unsigned __int8 *)&off_10 + (_QWORD)v8),
              *a1,
              a1[1],
              a1[2],
              a1[5]);
            if ( ((unsigned __int8)a2 & 1) != 0 )
              goto LABEL_30;
LABEL_33:
            v6 = 1;
          }
        }
      }
LABEL_34:
      v33 = v6;
      qdf_mutex_release(mlo_ctx);
      result = v33;
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

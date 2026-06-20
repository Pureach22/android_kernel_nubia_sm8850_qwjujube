__int64 __fastcall rmnet_aps_genl_filter_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x1
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  unsigned int *v11; // x9
  unsigned int v12; // w12
  __int64 v13; // x9
  int v14; // w20
  __int64 result; // x0
  __int64 v16; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x9
  unsigned int *v19; // x9
  unsigned int v20; // w12
  __int64 v21; // x9
  _DWORD v22[3]; // [xsp+Ch] [xbp-94h] BYREF
  __int64 v23; // [xsp+18h] [xbp-88h] BYREF
  __int64 v24; // [xsp+20h] [xbp-80h]
  __int64 v25; // [xsp+28h] [xbp-78h]
  __int64 v26; // [xsp+30h] [xbp-70h]
  __int64 v27; // [xsp+38h] [xbp-68h]
  __int64 v28; // [xsp+40h] [xbp-60h]
  __int64 v29; // [xsp+48h] [xbp-58h]
  __int64 v30; // [xsp+50h] [xbp-50h]
  __int64 v31; // [xsp+58h] [xbp-48h]
  __int64 v32; // [xsp+60h] [xbp-40h]
  __int64 v33; // [xsp+68h] [xbp-38h]
  __int64 v34; // [xsp+70h] [xbp-30h]
  __int64 v35; // [xsp+78h] [xbp-28h]
  __int64 v36; // [xsp+80h] [xbp-20h]
  __int64 v37; // [xsp+88h] [xbp-18h]
  __int64 v38; // [xsp+90h] [xbp-10h]
  __int64 v39; // [xsp+98h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v2 = *(_QWORD *)(a2 + 32);
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v23 = 0;
    v3 = *(_QWORD *)(v2 + 40);
    if ( v3 )
    {
      if ( (int)nla_memcpy(&v23, v3, 128) >= 1 )
      {
        mutex_lock(&rmnet_aps_mutex);
        if ( rmnet_aps_active == 1 && (_DWORD)v24 && (v5 = dev_get_by_index(&init_net)) != 0 )
        {
          v6 = v5;
          v7 = strncmp((const char *)(v5 + 296), "rmnet_data", 0xAu);
          if ( !(_DWORD)v7 )
          {
            if ( (_DWORD)v23 == 6 && (v16 = *(_QWORD *)(v6 + 3184)) != 0 )
            {
              v7 = rmnet_aps_change_filter(v16 + 16, &v23);
              v14 = v7;
            }
            else
            {
              v14 = -22;
            }
            StatusReg = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(StatusReg + 16);
            v18 = *(_QWORD *)(v6 + 1320);
            v19 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v18);
            do
              v20 = __ldxr(v19);
            while ( __stxr(v20 - 1, v19) );
            v21 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v21;
            if ( v21 && *(_QWORD *)(StatusReg + 16) )
              goto LABEL_15;
            goto LABEL_27;
          }
          v9 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v9 + 16);
          v10 = *(_QWORD *)(v6 + 1320);
          v11 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v10);
          do
            v12 = __ldxr(v11);
          while ( __stxr(v12 - 1, v11) );
          v13 = *(_QWORD *)(v9 + 16) - 1LL;
          *(_DWORD *)(v9 + 16) = v13;
          if ( !v13 )
          {
            v14 = -22;
LABEL_27:
            preempt_schedule_notrace(v7, v8);
            goto LABEL_15;
          }
          v14 = -22;
          if ( !*(_QWORD *)(v9 + 16) )
            goto LABEL_27;
        }
        else
        {
          v14 = -22;
        }
LABEL_15:
        mutex_unlock(&rmnet_aps_mutex);
        v22[0] = v23;
        v22[1] = v14;
        v22[2] = HIDWORD(v23);
        result = rmnet_aps_send_msg(a2, 3u, 6u, 0xCu, (__int64)v22, 0xCC0u);
        goto LABEL_16;
      }
    }
  }
  result = 4294967274LL;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}

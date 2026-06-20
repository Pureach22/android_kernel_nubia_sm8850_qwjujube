__int64 __fastcall _cam_req_mgr_notify_frame_skip(__int64 result, int a2)
{
  unsigned int v2; // w6
  __int64 v3; // x8
  __int64 v4; // x19
  _DWORD *v5; // x21
  __int64 v7; // x24
  __int64 v8; // x9
  unsigned int v9; // w9
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x25
  __int64 v12; // x26
  int v13; // w27
  __int64 v14; // x21
  int v15; // w7
  unsigned int *v16; // x8
  __int64 v17; // x10
  unsigned int v18; // w9
  __int64 v19; // x10
  int v20; // w11
  int v21; // t1
  unsigned int v22; // w6
  __int64 v23; // x8
  unsigned int v24; // w9
  __int64 v25; // x9
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 (__fastcall *v28)(unsigned __int64 *, __int64); // x8
  unsigned __int64 v29; // [xsp+20h] [xbp-70h] BYREF
  __int64 v30; // [xsp+28h] [xbp-68h]
  __int64 v31; // [xsp+30h] [xbp-60h]
  __int64 v32; // [xsp+38h] [xbp-58h]
  __int64 v33; // [xsp+40h] [xbp-50h]
  __int64 v34; // [xsp+48h] [xbp-48h]
  __int64 v35; // [xsp+50h] [xbp-40h]
  unsigned __int64 v36; // [xsp+58h] [xbp-38h] BYREF
  __int64 v37; // [xsp+60h] [xbp-30h]
  __int64 v38; // [xsp+68h] [xbp-28h]
  __int64 v39; // [xsp+70h] [xbp-20h]
  __int64 v40; // [xsp+78h] [xbp-18h]
  __int64 v41; // [xsp+80h] [xbp-10h]
  __int64 v42; // [xsp+88h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(result + 8);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  if ( v2 <= 2 )
  {
    v3 = *(unsigned int *)(result + 4);
    v4 = result;
    if ( (int)v3 < 1 )
      goto LABEL_43;
    v5 = *(_DWORD **)(result + 40);
    v7 = result + 144;
    while ( 1 )
    {
      if ( v5[71] == 1 )
      {
        v8 = *((_QWORD *)v5 + 38);
        if ( v8 )
        {
          if ( *(_QWORD *)(v8 + 40) )
            break;
        }
      }
      --v3;
      v5 += 80;
      if ( !v3 )
        goto LABEL_13;
    }
    v9 = *(_DWORD *)result;
    v30 = *(_QWORD *)(v7 + 24LL * *(int *)(*((_QWORD *)v5 + 2) + 4LL) + 8);
    v29 = __PAIR64__(*v5, v9);
    HIDWORD(v31) = 9;
    raw_spin_lock_bh(result + 33216);
    LOBYTE(v32) = *(_DWORD *)(v4 + 33152) == 3;
    raw_spin_unlock_bh(v4 + 33216);
    v10 = *(__int64 (__fastcall **)(_QWORD))(*((_QWORD *)v5 + 38) + 40LL);
    if ( *((_DWORD *)v10 - 1) != -662406558 )
      __break(0x8228u);
    result = v10(&v29);
    if ( (_DWORD)result )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 16,
                 1,
                 "__cam_req_mgr_notify_frame_skip",
                 448,
                 "Failed to send FRAME_SKIP_AVALIABLE on link 0x%x dev 0x%x",
                 *(_DWORD *)v4,
                 *v5);
      goto LABEL_43;
    }
    LOBYTE(v3) = v32;
    if ( *(int *)(v4 + 4) <= 0 )
      goto LABEL_43;
LABEL_13:
    v11 = 0;
    v12 = 0;
    v13 = v3 & 1;
    while ( 1 )
    {
      v14 = *(_QWORD *)(v4 + 40);
      v15 = *(_DWORD *)(v14 + v11 + 288);
      if ( v15 >= 3 )
      {
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   16,
                   2,
                   "__cam_req_mgr_notify_frame_skip",
                   461,
                   "pd %d greater than max",
                   v15);
        goto LABEL_15;
      }
      v16 = (unsigned int *)(v7 + 24LL * v15);
      if ( *v16 >= 0x31 )
        goto LABEL_44;
      v17 = *(_QWORD *)(v14 + v11 + 16) + 48LL * *v16;
      v18 = *(_DWORD *)(v14 + v11);
      v21 = *(_DWORD *)(v17 + 64);
      v19 = v17 + 64;
      v20 = v21;
      if ( v21 )
      {
        if ( v18 == *(_DWORD *)(v19 + 4) )
          goto LABEL_20;
        if ( v20 != 1 )
        {
          if ( v18 == *(_DWORD *)(v19 + 8) )
            goto LABEL_20;
          if ( v20 != 2 )
          {
            if ( v18 == *(_DWORD *)(v19 + 12) )
              goto LABEL_20;
            if ( v20 != 3 )
            {
              if ( v18 == *(_DWORD *)(v19 + 16) )
              {
LABEL_20:
                if ( a2 == 2 )
                {
                  if ( *(_BYTE *)(v19 + 20) != 1 )
                    goto LABEL_15;
                }
                else if ( a2 == 1 && (*(_BYTE *)(v19 + 20) & 1) != 0 )
                {
                  goto LABEL_15;
                }
                goto LABEL_33;
              }
              if ( v20 != 4 )
                goto LABEL_44;
            }
          }
        }
      }
LABEL_33:
      v22 = *(_DWORD *)v4;
      v23 = *((_QWORD *)v16 + 1);
      LODWORD(v39) = 0;
      HIDWORD(v39) = a2;
      v36 = __PAIR64__(v18, v22);
      v24 = *(_DWORD *)(v4 + 8);
      v37 = v23;
      if ( v24 > 2 )
LABEL_44:
        __break(0x5512u);
      BYTE3(v41) = v13;
      v25 = *(_QWORD *)(v7 + 24LL * v24 + 8);
      v26 = debug_mdl & 0x1000010;
      v38 = v25;
      if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   v26,
                   4,
                   "__cam_req_mgr_notify_frame_skip",
                   505,
                   "Notify_frame_skip: link: 0x%x pd %d req_id %lld last_applied %lld frame_duration_changing:%d",
                   v22,
                   v15,
                   v23,
                   v25,
                   v13);
      v27 = *(_QWORD *)(v14 + v11 + 304);
      if ( v27 )
      {
        v28 = *(__int64 (__fastcall **)(unsigned __int64 *, __int64))(v27 + 24);
        if ( v28 )
        {
          if ( *((_DWORD *)v28 - 1) != 1415584157 )
            __break(0x8228u);
          result = v28(&v36, v26);
        }
      }
LABEL_15:
      ++v12;
      v11 += 320;
      if ( v12 >= *(int *)(v4 + 4) )
        goto LABEL_43;
    }
  }
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             16,
             1,
             "__cam_req_mgr_notify_frame_skip",
             429,
             "link->max_delay is out of bounds: %d",
             v2);
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}

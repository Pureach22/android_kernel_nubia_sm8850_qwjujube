__int64 __fastcall _cam_req_mgr_check_link_is_ready(unsigned int *a1, unsigned int a2, char a3)
{
  unsigned int *v5; // x25
  __int64 v6; // x9
  __int64 v7; // x11
  int v8; // w9
  unsigned int v9; // w10
  __int64 v10; // x21
  __int64 v11; // x20
  _BYTE *v12; // x20
  int v13; // t1
  __int64 result; // x0
  int v15; // w27
  unsigned __int64 v16; // x28
  __int64 v17; // x20
  __int64 v18; // x26
  __int64 v19; // x21
  __int64 v20; // x23
  __int64 v21; // x0
  unsigned int v22; // [xsp+20h] [xbp-40h] BYREF
  __int128 v23; // [xsp+24h] [xbp-3Ch]
  unsigned int v24; // [xsp+34h] [xbp-2Ch]
  __int64 v25; // [xsp+38h] [xbp-28h]
  unsigned int *v26; // [xsp+40h] [xbp-20h]
  __int64 v27; // [xsp+48h] [xbp-18h]
  __int64 v28; // [xsp+50h] [xbp-10h]
  __int64 v29; // [xsp+58h] [xbp-8h]

  v5 = a1 + 0x2000;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_QWORD *)a1 + 6);
  if ( (a3 & 1) == 0 )
  {
    *((_QWORD *)a1 + 16) = 0;
    *((_QWORD *)a1 + 17) = 0;
    *((_QWORD *)a1 + 14) = 0;
    *((_QWORD *)a1 + 15) = 0;
    *((_QWORD *)a1 + 12) = 0;
    *((_QWORD *)a1 + 13) = 0;
    *((_QWORD *)a1 + 10) = 0;
    *((_QWORD *)a1 + 11) = 0;
    *((_QWORD *)a1 + 9) = 0;
  }
  v7 = *((_QWORD *)a1 + 7);
  v27 = v6;
  v28 = 0;
  v8 = *((unsigned __int8 *)a1 + 33277);
  v22 = a2;
  v25 = v7;
  v26 = a1 + 18;
  v9 = a1[8314];
  v23 = 0u;
  v24 = 0;
  v28 = a3 & 1;
  HIDWORD(v28) = v9;
  if ( v8 == 1 )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_check_link_is_ready",
        1633,
        "Set initial_skip to false for link %x",
        *a1);
    *((_BYTE *)v5 + 509) = 0;
  }
  if ( a2 >= 0x31 )
    __break(0x5512u);
  v10 = *((_QWORD *)a1 + 6);
  if ( (unsigned int)_cam_req_mgr_traverse(&v22) || (_DWORD)v23 != a1[8] )
  {
    if ( (int)a1[1] >= 1 )
    {
      v15 = HIDWORD(v23);
      v16 = v24;
      v17 = *(_QWORD *)((char *)&v23 + 4);
      v18 = 0;
      v19 = 288;
      do
      {
        v20 = *((_QWORD *)a1 + 5);
        if ( *(_DWORD *)(v20 + v19) == v15 && ((v16 >> *(_QWORD *)(v20 + v19 - 280)) & 1) == 0 )
        {
          if ( *((_BYTE *)v5 + 592) == 1 )
          {
            if ( (unsigned int)__ratelimit(&_cam_req_mgr_find_dev_name__rs, "__cam_req_mgr_find_dev_name") )
              v21 = 3;
            else
              v21 = 2;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, __int64, unsigned int))cam_print_log)(
              v21,
              16,
              3,
              "__cam_req_mgr_find_dev_name",
              294,
              "WQ congestion, Skip Frame: req: %lld not ready on link: 0x%x for pd: %d dev: %s open_req count: %u",
              v17,
              *a1,
              v15,
              v20 + v19 - 260,
              v5[122]);
          }
          else
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int, __int64, unsigned int))cam_print_log)(
              3,
              16,
              3,
              "__cam_req_mgr_find_dev_name",
              299,
              "Skip Frame: req: %lld not ready on link: 0x%x for pd: %d dev: %s open_req count: %u",
              v17,
              *a1,
              v15,
              v20 + v19 - 260,
              v5[122]);
          }
        }
        ++v18;
        v19 += 320;
      }
      while ( v18 < (int)a1[1] );
    }
    goto LABEL_29;
  }
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_check_link_is_ready",
      1650,
      "READY: link_hdl= %x idx= %d, req_id= %lld :%lld :%lld",
      *a1,
      a2,
      *((_QWORD *)a1 + 16),
      *((_QWORD *)a1 + 13),
      *((_QWORD *)a1 + 10));
  if ( *(_BYTE *)(g_crm_core_dev + 66) == 1 )
  {
    v11 = v10 + 8 + 72LL * a2;
    v13 = *(unsigned __int8 *)(v11 + 69);
    v12 = (_BYTE *)(v11 + 69);
    if ( v13 == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        2,
        "__cam_req_mgr_check_link_is_ready",
        1655,
        "Simulate Skip on link: 0x%x req_id= %lld :%lld :%lld",
        *a1,
        *((_QWORD *)a1 + 16),
        *((_QWORD *)a1 + 13),
        *((_QWORD *)a1 + 10));
      *v12 = 0;
LABEL_29:
      result = 4294967285LL;
      goto LABEL_30;
    }
  }
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}

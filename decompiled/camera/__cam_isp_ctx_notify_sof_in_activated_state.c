__int64 __fastcall _cam_isp_ctx_notify_sof_in_activated_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v4; // x21
  __int64 result; // x0
  _QWORD *v6; // x20
  __int64 v7; // x6
  __int64 v8; // x7
  int v9; // w9
  const char *v10; // x5
  __int64 v11; // x1
  __int64 v12; // x4
  __int64 v13; // x24
  int v14; // w8
  __int64 v15; // x8
  __int64 *v16; // x10
  __int64 (__fastcall *v17)(__int64, __int64 *); // x8
  __int64 v18; // x0
  unsigned int v19; // w0
  unsigned int v20; // w19
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x6
  unsigned int v23; // w10
  __int64 v24; // x7
  _QWORD *v25; // x22
  _QWORD *v26; // x23
  _QWORD *v27; // t1
  unsigned __int64 v29; // x20
  unsigned __int64 v30; // x22
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x2
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x9
  int v42; // [xsp+8h] [xbp-98h]
  unsigned __int64 v43; // [xsp+18h] [xbp-88h]
  _QWORD v44[2]; // [xsp+20h] [xbp-80h] BYREF
  __int64 v45; // [xsp+30h] [xbp-70h]
  __int64 v46; // [xsp+38h] [xbp-68h]
  __int64 v47; // [xsp+40h] [xbp-60h]
  __int64 v48; // [xsp+48h] [xbp-58h]
  __int64 v49; // [xsp+50h] [xbp-50h]
  __int64 v50; // [xsp+58h] [xbp-48h]
  __int64 v51; // [xsp+60h] [xbp-40h]
  __int64 v52; // [xsp+68h] [xbp-38h]
  __int64 v53; // [xsp+70h] [xbp-30h]
  __int64 v54; // [xsp+78h] [xbp-28h]
  __int64 v55; // [xsp+80h] [xbp-20h] BYREF
  __int64 v56; // [xsp+88h] [xbp-18h]
  _QWORD *v57; // [xsp+90h] [xbp-10h]
  __int64 v58; // [xsp+98h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v56 = 0;
  v57 = nullptr;
  v55 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v44[0] = 0;
  v44[1] = 0;
  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_notify_sof_in_activated_state",
      3714,
      "invalid event data");
    result = 4294967274LL;
    goto LABEL_60;
  }
  v4 = a1 + 37296;
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(a2 + 8);
  if ( *(_BYTE *)(a2 + 24) == 1 )
  {
    if ( *(_QWORD *)a2 == *(_QWORD *)(a1 + 37304) )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_notify_sof_in_activated_state",
          3730,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          *(_QWORD *)a2 / 0x3B9ACA00uLL,
          *(_QWORD *)a2 % 0x3B9ACA00uLL,
          *(_QWORD *)(a1 + 37312) / 0x3B9ACA00uLL,
          *(_QWORD *)(a1 + 37312) % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts(a1, *(_QWORD *)a2, *(_QWORD *)(a2 + 16));
    }
  }
  if ( *(_DWORD *)(a1 + 24) )
  {
    v6 = *(_QWORD **)(v2 + 128);
    if ( v6 == (_QWORD *)(v2 + 128) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_notify_sof_in_activated_state",
        3737,
        "No available active req in bubble, ctx %u, link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      *(_DWORD *)(a1 + 24) = 0;
      result = 4294967274LL;
      *(_DWORD *)(v4 + 80) = 0;
      goto LABEL_60;
    }
    v7 = *(_QWORD *)(v4 + 72);
    if ( v7 == *(_QWORD *)(v4 + 8) )
    {
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_42;
      v8 = *(unsigned int *)(v2 + 32);
      v9 = *(_DWORD *)(v2 + 64);
      v10 = "Tasklet delay detected! Bubble frame check skipped, sof_timestamp: %lld, ctx %u, link: 0x%x";
      v11 = debug_mdl & 8;
      v12 = 3748;
    }
    else
    {
      v13 = v6[4];
      v14 = *(_DWORD *)(v4 + 80);
      if ( v14 && (*(_BYTE *)(v13 + 4504) & 1) != 0 )
      {
        v15 = *(_QWORD *)v4;
        v16 = *(__int64 **)(v2 + 208);
        LODWORD(v44[0]) = 6;
        LODWORD(v56) = 0;
        v55 = v15;
        v17 = (__int64 (__fastcall *)(__int64, __int64 *))v16[12];
        v57 = v44;
        v18 = *v16;
        if ( *((_DWORD *)v17 - 1) != 1863972096 )
          __break(0x8228u);
        v19 = v17(v18, &v55);
        if ( v19 )
        {
          v20 = v19;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_notify_sof_in_activated_state",
            3768,
            "HW command failed, ctx %u, link: 0x%x",
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
          result = v20;
          goto LABEL_60;
        }
        v21 = v45;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v43 = v45;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_notify_sof_in_activated_state",
            3774,
            "last_cdm_done req: %d, ctx %u, link: 0x%x",
            v45,
            *(_DWORD *)(v2 + 32),
            *(_DWORD *)(v2 + 64));
          v21 = v43;
        }
        v22 = v6[3];
        v23 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
        if ( v21 >= v22 )
        {
          if ( v23 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_notify_sof_in_activated_state",
              3779,
              "invalid sof event data CDM cb detected for req: %lld, possible buf_done delay, waiting for buf_done, ctx %u, link: 0x%x",
              v22,
              *(_DWORD *)(v2 + 32),
              *(_DWORD *)(v2 + 64));
          *(_DWORD *)(v4 + 80) = 0;
        }
        else
        {
          if ( v23 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_notify_sof_in_activated_state",
              3784,
              "CDM callback not happened for req: %lld, possible CDM stuck or workqueue delay, ctx %u, link: 0x%x",
              v22,
              *(_DWORD *)(v2 + 32),
              *(_DWORD *)(v2 + 64));
          *(_QWORD *)(v13 + 52) = 0;
          *(_DWORD *)(v4 + 80) = 0;
          *(_WORD *)(v13 + 4504) = 256;
          _list_del_entry(v6);
          *v6 = v6;
          v6[1] = v6;
          _list_add(v6, (_QWORD *)(v2 + 144), *(_QWORD *)(v2 + 144));
          *(_DWORD *)(a1 + 24) = 0;
          v24 = (unsigned int)(*(_DWORD *)(v4 + 24) - 1);
          *(_DWORD *)(v4 + 24) = v24;
          if ( (debug_mdl & 0x1000008) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD, _DWORD))cam_print_log)(
              3,
              debug_mdl & 0x1000008,
              4,
              "__cam_isp_ctx_notify_sof_in_activated_state",
              3797,
              "Move active req: %lld to pending list(cnt = %d) [bubble re-apply], ctx %u link: 0x%x",
              v6[3],
              v24,
              *(_DWORD *)(v2 + 32),
              *(_DWORD *)(v2 + 64));
        }
        goto LABEL_42;
      }
      if ( (*(_BYTE *)(v13 + 4504) & 1) != 0 )
      {
        v8 = (unsigned int)(v14 + 1);
        *(_DWORD *)(v4 + 80) = v8;
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_42;
        v7 = v6[3];
        v9 = *(_DWORD *)(v2 + 32);
        v10 = "Waiting on bufdone for bubble req: %lld, since frame_cnt = %lld, ctx %u link: 0x%x";
        v11 = debug_mdl & 8;
        v12 = 3804;
        v42 = *(_DWORD *)(v2 + 64);
      }
      else
      {
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_42;
        v7 = v6[3];
        v8 = *(unsigned int *)(v2 + 32);
        v9 = *(_DWORD *)(v2 + 64);
        v10 = "Delayed bufdone for req: %lld, ctx %u link: 0x%x";
        v11 = debug_mdl & 8;
        v12 = 3807;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int))cam_print_log)(
      3,
      v11,
      4,
      "__cam_isp_ctx_notify_sof_in_activated_state",
      v12,
      v10,
      v7,
      v8,
      v9,
      v42);
  }
LABEL_42:
  if ( *(int *)(v4 + 24) <= 2 )
  {
    _cam_isp_ctx_notify_trigger_util(1, a1);
    v27 = *(_QWORD **)(v2 + 128);
    v25 = (_QWORD *)(v2 + 128);
    v26 = v27;
    if ( v27 == v25 )
    {
LABEL_52:
      v29 = 0;
    }
    else
    {
      _X8 = (unsigned __int64 *)(a1 + 42128);
      while ( 1 )
      {
        if ( (*(_BYTE *)(v26[4] + 4504LL) & 1) == 0 )
        {
          v29 = v26[3];
          if ( v29 > *(_QWORD *)(v4 + 32) )
            break;
        }
        v26 = (_QWORD *)*v26;
        if ( v26 == v25 )
          goto LABEL_52;
      }
      if ( a1 )
      {
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v40 = __ldxr(_X8);
          v41 = v40 + 1;
        }
        while ( __stlxr(v41, _X8) );
        __dmb(0xBu);
        v30 = v41 & 7;
        v31 = ktime_get_with_offset(1);
        v32 = a1 + (v30 << 6);
        if ( v26 )
        {
          v33 = v26[4];
          *(_QWORD *)(v32 + 43184) = v26[3];
          *(_QWORD *)(v33 + 4472) = v31;
        }
        else
        {
          *(_QWORD *)(v32 + 43184) = 0;
        }
        *(_QWORD *)(v32 + 43192) = v31;
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_ctx_update_event_record",
          98,
          "Invalid Args");
      }
    }
    if ( *(_DWORD *)(a1 + 20) == 3 )
      v34 = 0;
    else
      v34 = v29;
    if ( v34 )
      *(_QWORD *)(v4 + 32) = v34;
    _cam_isp_ctx_update_state_monitor_array(a1, 4, v34);
  }
  result = 0;
  *(_QWORD *)(v4 + 72) = *(_QWORD *)(v4 + 8);
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}

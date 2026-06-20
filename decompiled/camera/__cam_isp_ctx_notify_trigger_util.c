__int64 __fastcall _cam_isp_ctx_notify_trigger_util(int a1, __int64 *a2)
{
  __int64 *v2; // x22
  __int64 v3; // x7
  __int64 v4; // x21
  unsigned int v5; // w19
  int v6; // w10
  const char *v7; // x6
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x4
  int v11; // w8
  int v12; // w11
  int v13; // w10
  __int64 v14; // x9
  __int64 v16; // x7
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x0
  const char *v22; // x6
  const char *v24; // x6
  int v25; // [xsp+8h] [xbp-58h]
  __int64 v26; // [xsp+10h] [xbp-50h]
  _DWORD v27[2]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v28; // [xsp+28h] [xbp-38h]
  __int64 v29; // [xsp+30h] [xbp-30h]
  __int64 v30; // [xsp+38h] [xbp-28h]
  __int64 v31; // [xsp+40h] [xbp-20h]
  __int64 v32; // [xsp+48h] [xbp-18h]
  __int64 v33; // [xsp+50h] [xbp-10h]
  __int64 v34; // [xsp+58h] [xbp-8h]

  v2 = a2 + 4663;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((unsigned int *)a2 + 9336);
  v4 = *a2;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( ((unsigned int)v3 & a1) != 0 )
  {
    if ( *((_DWORD *)a2 + 11393) )
    {
      v5 = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v3 = *(unsigned int *)(v4 + 32);
        v6 = *(_DWORD *)(v4 + 64);
        if ( a1 == 1 )
          v7 = "SOF";
        else
          v7 = "EOF";
        v8 = "Internal recovery in progress skip notifying %s trigger point in ctx: %u on link: 0x%x";
        v9 = debug_mdl & 8;
        v10 = 846;
LABEL_15:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int, int, __int64))cam_print_log)(
          3,
          v9,
          4,
          "__cam_isp_ctx_notify_trigger_util",
          v10,
          v8,
          v7,
          v3,
          v6,
          v25,
          v26);
        v5 = 0;
      }
    }
    else
    {
      v12 = *(_DWORD *)(v4 + 60);
      v11 = *(_DWORD *)(v4 + 64);
      v13 = *((_DWORD *)a2 + 11400);
      v14 = a2[4674];
      v16 = a2[1];
      LODWORD(v29) = a1;
      v27[0] = v11;
      v27[1] = v12;
      v18 = *v2;
      v19 = a2[4664];
      LODWORD(v32) = v13;
      v28 = v16;
      v30 = v18;
      v31 = v14;
      v33 = v19;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        if ( a1 == 1 )
          v24 = "SOF";
        else
          v24 = "EOF";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_notify_trigger_util",
          863,
          "Notify CRM %s on frame: %llu ctx: %u link: 0x%x last_buf_done_req: %lld",
          v24,
          v16,
          *(_DWORD *)(v4 + 32),
          v11,
          v14);
      }
      v20 = **(__int64 (__fastcall ***)(_QWORD))(v4 + 216);
      if ( *((_DWORD *)v20 - 1) != -2043465336 )
        __break(0x8228u);
      v5 = v20(v27);
      if ( v5 )
      {
        if ( (unsigned int)__ratelimit(&_cam_isp_ctx_notify_trigger_util__rs, "__cam_isp_ctx_notify_trigger_util") )
          v21 = 3;
        else
          v21 = 2;
        if ( a1 == 1 )
          v22 = "SOF";
        else
          v22 = "EOF";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v21,
          8,
          1,
          "__cam_isp_ctx_notify_trigger_util",
          871,
          "Failed to notify CRM %s on frame: %llu ctx: %u link: 0x%x last_buf_done_req: %lld rc: %d",
          v22,
          a2[1],
          *(_DWORD *)(v4 + 32),
          *(_DWORD *)(v4 + 64),
          v2[11],
          v5);
      }
    }
  }
  else
  {
    v5 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v6 = *(_DWORD *)(v4 + 32);
      if ( a1 == 1 )
        v7 = "SOF";
      else
        v7 = "EOF";
      v26 = a2[4674];
      v8 = "%s trigger point not subscribed for in mask: %u in ctx: %u on link: 0x%x last_bufdone: %lld";
      v25 = *(_DWORD *)(v4 + 64);
      v9 = debug_mdl & 8;
      v10 = 837;
      goto LABEL_15;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}

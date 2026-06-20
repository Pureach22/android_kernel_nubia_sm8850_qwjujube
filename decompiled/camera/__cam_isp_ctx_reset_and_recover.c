__int64 __fastcall _cam_isp_ctx_reset_and_recover(__int64 a1)
{
  __int64 v2; // x21
  _QWORD *v3; // x20
  __int64 result; // x0
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 *v7; // x10
  _DWORD *v8; // x8
  __int64 v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x7
  int v12; // w8
  const char *v13; // x5
  unsigned int v14; // w19
  __int64 v15; // x4
  __int64 v16; // x8
  __int64 *v17; // x10
  __int64 (__fastcall *v18)(__int64, __int64 *); // x8
  __int64 v19; // x0
  unsigned int v20; // w0
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 *v23; // x8
  __int64 (__fastcall *v24)(__int64, __int64 *); // x9
  __int64 v25; // x0
  unsigned int v26; // w0
  unsigned int v27; // w20
  const char *v28; // x9
  _QWORD v29[12]; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v30; // [xsp+80h] [xbp-80h] BYREF
  __int64 v31; // [xsp+88h] [xbp-78h]
  _QWORD *v32; // [xsp+90h] [xbp-70h]
  __int64 v33; // [xsp+98h] [xbp-68h] BYREF
  __int64 v34; // [xsp+A0h] [xbp-60h]
  __int64 v35; // [xsp+A8h] [xbp-58h]
  __int64 v36; // [xsp+B0h] [xbp-50h]
  __int64 v37; // [xsp+B8h] [xbp-48h]
  __int64 v38; // [xsp+C0h] [xbp-40h]
  __int64 v39; // [xsp+C8h] [xbp-38h]
  __int64 v40; // [xsp+D0h] [xbp-30h]
  __int64 v41; // [xsp+D8h] [xbp-28h]
  _QWORD v42[2]; // [xsp+E0h] [xbp-20h] BYREF
  _QWORD v43[2]; // [xsp+F0h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v43[0] = 0x10100000001LL;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v3 = (_QWORD *)(v2 + 37296);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v33 = 0;
  v31 = 0;
  memset(v29, 0, sizeof(v29));
  raw_spin_lock_bh(a1 + 120);
  if ( !*(_DWORD *)(v2 + 37320) )
  {
    if ( *(_DWORD *)(a1 + 240) != 5 )
    {
      raw_spin_unlock_bh(a1 + 120);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_reset_and_recover",
        9880,
        "In wrong state %d, for recovery ctx: %u in link: 0x%x recovery req: %lld",
        *(_DWORD *)(a1 + 240),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64),
        *(_QWORD *)(v2 + 37360));
      result = 4294967274LL;
      goto LABEL_22;
    }
    if ( *(_QWORD *)(a1 + 144) == a1 + 144 )
    {
      raw_spin_unlock_bh(a1 + 120);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_reset_and_recover",
        9890,
        "Failed to reset and recover last_applied_req: %llu in ctx: %u on link: 0x%x",
        *(_QWORD *)(v2 + 37352),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      result = 4294967282LL;
      goto LABEL_22;
    }
    if ( !*v3 )
    {
      raw_spin_unlock_bh(a1 + 120);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_reset_and_recover",
        9899,
        "Invalid hw context pointer ctx: %u on link: 0x%x",
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      result = 4294967282LL;
      goto LABEL_22;
    }
    *(_DWORD *)(v2 + 20) = 6;
    *(_DWORD *)(v2 + 45564) = 0;
    v5 = *(_QWORD *)(a1 + 144);
    raw_spin_unlock_bh(a1 + 120);
    v6 = *(_QWORD *)(v5 + 32);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "__cam_isp_ctx_reset_and_recover",
      9916,
      "Trigger Halt, Reset & Resume for req: %llu ctx: %u in state: %d link: 0x%x",
      *(_QWORD *)(v5 + 24),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 240),
      *(_DWORD *)(a1 + 64));
    v7 = *(__int64 **)(a1 + 208);
    v42[0] = *v3;
    v42[1] = v43;
    v8 = (_DWORD *)v7[6];
    v9 = *v7;
    if ( *(v8 - 1) != 1863972096 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(__int64, _QWORD *))v8)(v9, v42);
    if ( v10 )
    {
      v11 = *(unsigned int *)(a1 + 32);
      v12 = *(_DWORD *)(a1 + 64);
      v13 = "Failed to stop HW rc: %d ctx: %u link: 0x%x";
      v14 = v10;
      v15 = 9927;
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_reset_and_recover",
          9931,
          "Stop HW success ctx: %u link: 0x%x",
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
      v16 = *v3;
      v17 = *(__int64 **)(a1 + 208);
      LODWORD(v29[0]) = 2;
      LODWORD(v31) = 0;
      v30 = v16;
      v18 = (__int64 (__fastcall *)(__int64, __int64 *))v17[12];
      v32 = v29;
      v19 = *v17;
      if ( *((_DWORD *)v18 - 1) != 1863972096 )
        __break(0x8228u);
      v20 = v18(v19, &v30);
      if ( !v20 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_reset_and_recover",
            9955,
            "Resume call success ctx: %u on link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
        v21 = *v3;
        v39 = *(_QWORD *)(v5 + 24);
        v22 = *(_QWORD *)(v6 + 8);
        v33 = v21;
        v35 = v22;
        LODWORD(v22) = *(_DWORD *)(v6 + 16);
        v38 = v6 + 80;
        WORD2(v40) = 1;
        LODWORD(v40) = 1;
        LOWORD(v41) = 257;
        LODWORD(v34) = v22;
        *(_DWORD *)(v2 + 45572) = 0;
        *(_DWORD *)(v2 + 24) = 0;
        LODWORD(v22) = *(unsigned __int8 *)(v2 + 45736);
        *(_QWORD *)(v2 + 37376) = 0;
        *(_DWORD *)(v2 + 37388) = 0;
        *(_BYTE *)(v2 + 45746) = 0;
        *(_DWORD *)(v2 + 20) = v22;
        v23 = *(__int64 **)(a1 + 208);
        v24 = (__int64 (__fastcall *)(__int64, __int64 *))v23[5];
        v25 = *v23;
        if ( *((_DWORD *)v24 - 1) != 1863972096 )
          __break(0x8229u);
        v26 = v24(v25, &v33);
        if ( v26 )
        {
          v27 = v26;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_reset_and_recover",
            9976,
            "Start HW failed, ctx: %u link: 0x%x",
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          result = v27;
          *(_DWORD *)(a1 + 240) = 3;
          goto LABEL_22;
        }
        *(_DWORD *)(v6 + 4448) = 2;
        _cam_isp_ctx_notify_v4l2_error_event(7u, 0, *(_QWORD *)(v5 + 24), (_DWORD *)a1);
        v28 = "N";
        if ( *(_BYTE *)(v6 + 4368) )
          v28 = "Y";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, const char *, _DWORD))cam_print_log)(
          3,
          8,
          3,
          "__cam_isp_ctx_reset_and_recover",
          9991,
          "Internal Start HW success ctx %u on link: 0x%x for req: %llu MUP: [en: %s val: %u]",
          *(unsigned int *)(a1 + 32),
          *(unsigned int *)(a1 + 64),
          *(_QWORD *)(v5 + 24),
          v28,
          *(_DWORD *)(v6 + 4360));
        goto LABEL_3;
      }
      v11 = *(unsigned int *)(a1 + 32);
      v12 = *(_DWORD *)(a1 + 64);
      v13 = "Failed to resume HW rc: %d ctx: %u link: 0x%x";
      v14 = v20;
      v15 = 9951;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_reset_and_recover",
      v15,
      v13,
      v14,
      v11,
      v12);
    result = v14;
    goto LABEL_22;
  }
  raw_spin_unlock_bh(a1 + 120);
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _QWORD))cam_print_log)(
    3,
    8,
    2,
    "__cam_isp_ctx_reset_and_recover",
    9871,
    "Active list not empty: %u in ctx: %u on link: 0x%x, retry recovery for req: %lld after buf_done",
    *(unsigned int *)(v2 + 37320),
    *(unsigned int *)(a1 + 32),
    *(_DWORD *)(a1 + 64),
    *(_QWORD *)(v2 + 37360));
LABEL_3:
  result = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}

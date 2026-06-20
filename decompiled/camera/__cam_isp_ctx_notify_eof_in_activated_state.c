__int64 __fastcall _cam_isp_ctx_notify_eof_in_activated_state(__int64 a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x9
  __int64 v4; // x0
  unsigned int (*v5)(void); // x8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x10
  _QWORD *v11; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x11
  __int64 v16; // x10
  __int64 v17; // x8
  unsigned int v18; // w20
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x9
  __int64 v27; // [xsp+48h] [xbp-A8h] BYREF
  __int64 v28; // [xsp+50h] [xbp-A0h]
  __int64 v29; // [xsp+58h] [xbp-98h]
  __int64 v30; // [xsp+60h] [xbp-90h]
  __int64 v31; // [xsp+68h] [xbp-88h]
  _QWORD v32[2]; // [xsp+70h] [xbp-80h] BYREF
  __int64 v33; // [xsp+80h] [xbp-70h]
  __int64 v34; // [xsp+88h] [xbp-68h]
  __int64 v35; // [xsp+90h] [xbp-60h]
  __int64 v36; // [xsp+98h] [xbp-58h]
  __int64 v37; // [xsp+A0h] [xbp-50h]
  __int64 v38; // [xsp+A8h] [xbp-48h]
  __int64 v39; // [xsp+B0h] [xbp-40h]
  __int64 v40; // [xsp+B8h] [xbp-38h]
  __int64 v41; // [xsp+C0h] [xbp-30h]
  __int64 v42; // [xsp+C8h] [xbp-28h]
  __int64 v43; // [xsp+D0h] [xbp-20h]
  __int64 v44; // [xsp+D8h] [xbp-18h]
  _QWORD *v45; // [xsp+E0h] [xbp-10h]
  __int64 v46; // [xsp+E8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)a1;
  v44 = 0;
  v45 = v32;
  v32[0] = 0;
  v32[1] = 0;
  v3 = v2[26];
  LODWORD(v32[0]) = 6;
  v4 = v2[33];
  v41 = 0;
  v42 = 0;
  v5 = *(unsigned int (**)(void))(v3 + 96);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  v43 = v4;
  if ( *((_DWORD *)v5 - 1) != 1863972096 )
    __break(0x8228u);
  if ( v5() )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_notify_eof_in_activated_state",
      3859,
      "ctx:%u link: 0x%x Failed to get timestamp from HW",
      *((_DWORD *)v2 + 8),
      *((_DWORD *)v2 + 16));
    v6 = 0;
  }
  else
  {
    v7 = v39;
    v8 = v40;
    v9 = v41;
    v10 = v42;
    v6 = v33;
    v2[65] = v39;
    v2[66] = v8;
    v2[67] = v9;
    v2[68] = v10;
    time64_to_tm(v7, 0, &v27);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_get_cdm_done_timestamp",
        1622,
        "last_cdm_done req: %lld ctx: %u link: 0x%x TAI time[%d-%d %d:%d:%d.%lld] Boot time[%lld:%09lld]",
        v6,
        *((_DWORD *)v2 + 8),
        *((_DWORD *)v2 + 16),
        v29 + 1,
        HIDWORD(v28),
        v28,
        HIDWORD(v27),
        v27,
        v40 / 1000000,
        v41,
        v42);
  }
  v11 = *(_QWORD **)a1;
  _X10 = (unsigned __int64 *)(a1 + 37400);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v25 = __ldxr(_X10);
    v26 = v25 + 1;
  }
  while ( __stlxr(v26, _X10) );
  __dmb(0xBu);
  v13 = a1 + 56 * (v26 % 0x54) + 37408;
  v14 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)v13 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(v13 + 4) = 11;
  *(_QWORD *)(v13 + 8) = v6;
  *(_QWORD *)(v13 + 16) = v14;
  v15 = v11[66];
  *(_QWORD *)(v13 + 24) = v11[65];
  *(_QWORD *)(v13 + 32) = v15;
  v16 = v11[67];
  v17 = v11[68];
  *(_QWORD *)(v13 + 40) = v16;
  *(_QWORD *)(v13 + 48) = v17;
  v18 = _cam_isp_ctx_notify_trigger_util(2, a1);
  _cam_isp_ctx_update_state_monitor_array(a1, 6, 0);
  _ReadStatusReg(SP_EL0);
  return v18;
}

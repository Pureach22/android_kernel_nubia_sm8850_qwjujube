__int64 __fastcall _cam_isp_ctx_release_hw_in_top_state(__int64 a1)
{
  __int64 v2; // x21
  __int64 *v3; // x9
  _DWORD *v4; // x8
  __int64 v5; // x0
  _QWORD *v6; // x0
  int v7; // w9
  _QWORD *v8; // x0
  unsigned int v9; // w20
  _QWORD v11[4]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v12[3]; // [xsp+28h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 256);
  v12[0] = 0;
  v12[1] = 0;
  if ( *(_QWORD *)(v2 + 37296) )
  {
    v3 = *(__int64 **)(a1 + 208);
    v12[0] = *(_QWORD *)(v2 + 37296);
    v4 = (_DWORD *)v3[4];
    v5 = *v3;
    if ( *(v4 - 1) != 1863972096 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v4)(v5, v12);
    *(_QWORD *)(v2 + 37296) = 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_hw_in_top_state",
      7769,
      "No hw resources acquired for ctx[%u], link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  *(_DWORD *)(a1 + 464) = 0;
  *(_WORD *)(v2 + 45743) = 0;
  v6 = *(_QWORD **)(v2 + 45672);
  *(_BYTE *)(v2 + 45747) = 0;
  *(_DWORD *)(v2 + 37320) = 0;
  *(_WORD *)(v2 + 45740) = 0;
  *(_DWORD *)(v2 + 45756) = 0;
  *(_BYTE *)(v2 + 45745) = 0;
  *(_WORD *)(v2 + 45748) = 0;
  *(_BYTE *)(v2 + 45752) = 0;
  *(_BYTE *)(v2 + 45754) = 0;
  *(_QWORD *)(v2 + 37392) = 0;
  v7 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(v2 + 8) = 0;
  *(_QWORD *)(v2 + 37328) = 0;
  *(_QWORD *)(v2 + 37336) = 0;
  if ( v7 == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v8 = *(_QWORD **)(v2 + 45680);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  *(_QWORD *)(v2 + 45672) = 0;
  *(_QWORD *)(v2 + 45680) = 0;
  *(_QWORD *)(v2 + 37400) = -1;
  *(_QWORD *)(v2 + 45232) = -1;
  *(_QWORD *)(v2 + 42112) = -1;
  *(_QWORD *)(v2 + 42120) = -1;
  *(_QWORD *)(v2 + 42128) = -1;
  *(_QWORD *)(v2 + 42136) = -1;
  *(_QWORD *)(v2 + 42144) = -1;
  *(_QWORD *)(v2 + 42152) = -1;
  if ( *(_QWORD *)(a1 + 128) != a1 + 128 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_release_hw_in_top_state",
      7805,
      "Active list is not empty, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  memset(v11, 0, sizeof(v11));
  v11[0] = __PAIR64__(*(_DWORD *)(a1 + 60), *(_DWORD *)(a1 + 64));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_release_hw_in_top_state",
      7814,
      "try to flush pending list, ctx_idx: %u, link: 0x%x",
      *(unsigned int *)(a1 + 32));
  raw_spin_lock_bh(a1 + 120);
  v9 = _cam_isp_ctx_flush_req(a1, a1 + 144, v11);
  raw_spin_unlock_bh(a1 + 120);
  _cam_isp_ctx_free_mem_hw_entries(a1);
  cam_req_mgr_workq_destroy((_QWORD *)(v2 + 45592));
  *(_DWORD *)(a1 + 240) = 2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_release_hw_in_top_state",
      7824,
      "Release device success[%u] link: 0x%x next state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
  _ReadStatusReg(SP_EL0);
  return v9;
}

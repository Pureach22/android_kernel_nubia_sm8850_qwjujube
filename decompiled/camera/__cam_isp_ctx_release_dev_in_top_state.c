__int64 __fastcall _cam_isp_ctx_release_dev_in_top_state(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  _QWORD *v4; // x22
  __int64 *v5; // x9
  _DWORD *v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w20
  _QWORD v10[4]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v11[3]; // [xsp+28h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 256);
  v11[0] = 0;
  v11[1] = 0;
  v4 = (_QWORD *)(v3 + 37296);
  if ( a2 && *v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_dev_in_top_state",
      7841,
      "releasing hw, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    _cam_isp_ctx_release_hw_in_top_state(a1);
  }
  if ( *v4 )
  {
    v5 = *(__int64 **)(a1 + 208);
    v11[0] = *v4;
    v6 = (_DWORD *)v5[4];
    v7 = *v5;
    if ( *(v6 - 1) != 1863972096 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v6)(v7, v11);
    *v4 = 0;
  }
  cam_common_release_evt_params((_QWORD *)*(unsigned int *)(a1 + 60));
  *(_QWORD *)(v3 + 45640) = 0;
  *(_QWORD *)(v3 + 45648) = 0;
  *(_QWORD *)(v3 + 45624) = 0;
  *(_QWORD *)(v3 + 45632) = 0;
  *(_DWORD *)(a1 + 64) = -1;
  *(_QWORD *)(a1 + 56) = -1;
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 464) = 0;
  *(_QWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 37320) = 0;
  *(_DWORD *)(v3 + 45756) = 0;
  *(_BYTE *)(v3 + 45754) = 0;
  *(_QWORD *)(v3 + 37392) = 0;
  *(_DWORD *)(v3 + 45616) = 0;
  *(_QWORD *)(v3 + 37328) = 0;
  *(_QWORD *)(v3 + 37336) = 0;
  *(_DWORD *)(v3 + 45736) = 0;
  *(_WORD *)(v3 + 45740) = 0;
  *(_QWORD *)(v3 + 37400) = -1;
  *(_QWORD *)(v3 + 45232) = -1;
  *(_QWORD *)(v3 + 42112) = -1;
  *(_QWORD *)(v3 + 42120) = -1;
  *(_QWORD *)(v3 + 42128) = -1;
  *(_QWORD *)(v3 + 42136) = -1;
  *(_QWORD *)(v3 + 42144) = -1;
  *(_QWORD *)(v3 + 42152) = -1;
  if ( *(_QWORD *)(a1 + 128) != a1 + 128 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_dev_in_top_state",
      7885,
      "Active list is not empty, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  memset(v10, 0, sizeof(v10));
  v10[0] = __PAIR64__(*(_DWORD *)(a1 + 60), *(_DWORD *)(a1 + 64));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_release_dev_in_top_state",
      7894,
      "try to flush pending list, ctx_idx: %u, link: 0x%x",
      *(unsigned int *)(a1 + 32));
  raw_spin_lock_bh(a1 + 120);
  v8 = _cam_isp_ctx_flush_req(a1, a1 + 144, v10);
  raw_spin_unlock_bh(a1 + 120);
  _cam_isp_ctx_free_mem_hw_entries(a1);
  *(_DWORD *)(a1 + 240) = 1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_release_dev_in_top_state",
      7904,
      "Release device success[%u] link: 0x%x next state %d",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 240));
  _ReadStatusReg(SP_EL0);
  return v8;
}

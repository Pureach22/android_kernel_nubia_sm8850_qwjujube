__int64 __fastcall sme_set_he_testbed_def(
        _QWORD *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w20
  __int64 v12; // x0
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // [xsp+0h] [xbp-10h] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v10 = a2;
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0x10000001DLL;
  if ( a2 <= 5u && a1[2162] + 96LL * a2 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: set HE testbed defaults",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_set_he_testbed_def",
      v39,
      v40);
    *(_QWORD *)(a1[1] + 1309LL) &= ~1uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x4000000000uLL;
    ucfg_twt_cfg_set_requestor(a1[2703], 0);
    *(_QWORD *)(a1[1] + 1309LL) &= ~2uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x100000uLL;
    *(_BYTE *)(a1[1] + 3756LL) = 1;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x80000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x2000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x20000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x10000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x40000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFFFFFFFFF1FFLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFFFFFFFF8FFFLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFFFFFFFFFE7FLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFE3FFFFFFFFFFFLL;
    *(_QWORD *)(a1[1] + 1309LL) = *(_QWORD *)(a1[1] + 1309LL) & 0xFFFFFFFFFFFFF3FFLL | 0x800;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x40000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x4000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~4uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x200000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x100000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x400000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x80000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x1000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x2000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x80000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x100000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFFFFC7FFFFFFLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFFFE3FFFFFFFLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x20000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x1000000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x2000000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x4000000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x8000000000000000LL;
    *(_BYTE *)(a1[1] + 1325LL) &= ~1u;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x10000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= 0xFFFFFFFFFFFF8FFFLL;
    *(_QWORD *)(a1[1] + 1309LL) &= 0xFFFFF8FFFFFFFFFFLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x400000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x800000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x1000000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x200000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x400000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x800000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x1000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x100000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= 0xFFFFFF1FFFFFFFFFLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x10000000000uLL;
    *(_QWORD *)(a1[1] + 1317LL) &= ~0x20000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= 0xE1FFFFFFFFFFFFFFLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x4000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) |= 0x8000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x10000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x20000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x40000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x80000000000000uLL;
    *(_QWORD *)(a1[1] + 1309LL) &= ~0x100000000000000uLL;
    csr_update_session_he_cap(a1);
    qdf_mem_copy((char *)a1 + 21788, (const void *)(a1[1] + 1308LL), 0x3Cu);
    v12 = a1[2703];
    *(_QWORD *)((char *)a1 + 21789) &= ~0x8000000000000uLL;
    ucfg_mlme_set_channel_bonding_24ghz(v12, 0);
    qdf_mem_copy(a1 + 2731, (const void *)(a1[1] + 1308LL), 0x3Cu);
    v13 = wlan_mlme_set_enable_bcast_probe_rsp(a1[2703], 0);
    if ( v13 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Failed not set enable bcast probe resp info, %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_set_he_testbed_def",
        v13);
    if ( (unsigned int)wma_form_unit_test_cmd_and_send(v10, 77, 2, &v39) )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: prevent pm cmd send failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "sme_set_he_testbed_def");
    result = wma_cli_set_command(v10, 108, 0, 1);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x34u,
                 2u,
                 "%s: Failed to set enable bcast probe resp in FW, %d",
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 "sme_set_he_testbed_def",
                 (unsigned int)result);
    *(_BYTE *)(a1[1] + 3544LL) = 1;
    *(_DWORD *)(a1[1] + 3504LL) = 0;
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               8u,
               "%s: No session for id %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sme_set_he_testbed_def",
               a2,
               v39,
               v40);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

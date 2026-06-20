__int64 __fastcall lim_initialize(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x21
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  void *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  _QWORD v32[7]; // [xsp+8h] [xbp-38h] BYREF

  v2 = a1 + 8688;
  v3 = (_DWORD *)(a1 + 4009);
  v32[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 12368) = 255;
  *(_QWORD *)(a1 + 11376) = 0;
  *(_DWORD *)(a1 + 11392) = 0;
  *(_DWORD *)(a1 + 12408) = 0;
  *(_BYTE *)(a1 + 12432) = 0;
  *(_BYTE *)(a1 + 11388) = 0;
  qdf_mem_set((void *)(a1 + 11396), 6u, 0);
  *(_DWORD *)(a1 + 11404) = 0;
  qdf_mem_set((void *)(a1 + 11408), 0x10u, 0);
  *(_QWORD *)(a1 + 11424) = 0;
  qdf_mem_set((void *)(a1 + 11440), 0x180u, 0);
  qdf_mem_set((void *)(a1 + 11824), 0x180u, 0);
  *(_QWORD *)(a1 + 12376) = 0;
  *(_BYTE *)(v2 + 3696) = 0;
  qdf_mem_set((void *)(a1 + 4848), 0xB4u, 0);
  qdf_mem_set((void *)(a1 + 8696), 0xB4u, 0);
  *(_WORD *)(v2 + 188) = 0;
  qdf_mem_set((void *)(a1 + 8880), 4u, 0);
  *(_WORD *)(v2 + 196) = 256;
  *(_QWORD *)(a1 + 8888) = "__lim_init_vars";
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v4, v5, v6, v7, v8, v9, v10, v11);
  v12 = *(unsigned __int8 *)(v2 + 197);
  memset(v32, 0, 48);
  if ( v12 )
  {
    if ( *(_WORD *)v2 )
    {
      LOWORD(v32[0]) = 5119;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x35u,
                           0x35u,
                           53,
                           (unsigned __int16 *)v32,
                           0x4DAu,
                           (__int64)"lim_post_msg_api") )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v32[0]));
    }
  }
  *(_WORD *)(v2 + 208) = 0;
  *(_BYTE *)(v2 + 210) = 0;
  *(_QWORD *)(a1 + 8904) = 0;
  *(_QWORD *)(a1 + 8912) = 0;
  qdf_mem_set((void *)(a1 + 8920), 0x98Du, 0);
  qdf_mem_set((void *)(a1 + 11365), 2u, 0);
  *(_DWORD *)(a1 + 4016) = 0;
  *v3 = 0;
  qdf_trace(53, 0, 255, 1);
  *(_QWORD *)(a1 + 4020) = 1;
  *(_DWORD *)(a1 + 4056) = 0;
  qdf_mem_set((void *)(a1 + 4064), 0x184u, 0);
  qdf_mem_set((void *)(a1 + 4452), 0x184u, 0);
  *(_DWORD *)(a1 + 4840) = 0;
  *(_WORD *)(a1 + 3994) = 0;
  qdf_mem_set((void *)(a1 + 3996), 6u, 0);
  qdf_mem_set((void *)(a1 + 4002), 6u, 0);
  v21 = *(unsigned __int16 *)(a1 + 3992);
  v22 = *(void **)(a1 + 12264);
  *(_BYTE *)(a1 + 4008) = 0;
  qdf_mem_set(v22, (unsigned int)(10792 * v21), 0);
  *(_BYTE *)(v2 + 3521) = 0;
  *(_DWORD *)(a1 + 12211) = 0;
  *(_DWORD *)(a1 + 12214) = 0;
  *(_QWORD *)(a1 + 12220) = 0;
  *(_BYTE *)(a1 + 12228) = 0;
  *(_QWORD *)(a1 + 12232) = 0;
  *(_BYTE *)(a1 + 12240) = 0;
  rrm_initialize(a1);
  if ( (unsigned int)qdf_mutex_create(a1 + 12280) )
  {
    qdf_trace_msg(0x35u, 2u, "%s: lim lock init failed!", v23, v24, v25, v26, v27, v28, v29, v30, "lim_initialize");
    result = 16;
  }
  else
  {
    *(_QWORD *)(a1 + 12344) = a1 + 12344;
    *(_QWORD *)(a1 + 12352) = a1 + 12344;
    *(_QWORD *)(a1 + 12360) = 0;
    lim_admit_control_init(a1);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

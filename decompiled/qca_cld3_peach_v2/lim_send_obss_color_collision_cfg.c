__int64 __fastcall lim_send_obss_color_collision_cfg(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x19
  int v26; // w8
  __int64 v27; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = nullptr;
  if ( a2 )
  {
    v11 = a2 + 0x2000;
    v12 = *(unsigned __int8 *)(a2 + 8676);
    v13 = *(unsigned __int8 *)(a2 + 10020);
    if ( (_DWORD)v12 == 1 && (v13 & 1) != 0 )
    {
      result = _qdf_mem_malloc(0x1Cu, "lim_send_obss_color_collision_cfg", 11968);
      if ( result )
      {
        v25 = (_DWORD *)result;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: %d: sending event:%d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "lim_send_obss_color_collision_cfg",
          *(unsigned __int8 *)(a2 + 10),
          a3);
        qdf_mem_set(v25, 0x1Cu, 0);
        v26 = *(unsigned __int8 *)(a2 + 10);
        v25[2] = a3;
        *v25 = v26;
        LOBYTE(v26) = *(_BYTE *)(v11 + 553);
        *((_QWORD *)v25 + 2) = 0xC80001D4C0LL;
        v25[3] = v26 & 0x3F;
        if ( a3 == 2 )
          v25[6] = 50000;
        LODWORD(v27) = 4524;
        v28 = v25;
        result = scheduler_post_message_debug(
                   0x35u,
                   0x36u,
                   54,
                   (unsigned __int16 *)&v27,
                   0x2EDCu,
                   (__int64)"lim_send_obss_color_collision_cfg");
        if ( (_DWORD)result )
          result = _qdf_mem_free((__int64)v25);
        else
          *(_DWORD *)(a2 + 10016) = a3;
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: %d: obss color det not enabled, he_cap:%d, sup:%d:%d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_send_obss_color_collision_cfg",
                 *(unsigned __int8 *)(a2 + 10),
                 v12,
                 v13,
                 *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2810LL));
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Invalid session",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_send_obss_color_collision_cfg");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

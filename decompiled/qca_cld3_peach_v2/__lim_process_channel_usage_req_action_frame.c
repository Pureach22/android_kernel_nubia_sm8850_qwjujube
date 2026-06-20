__int64 __fastcall _lim_process_channel_usage_req_action_frame(
        __int64 result,
        __int64 a2,
        __int64 a3,
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
  unsigned __int8 *v12; // x24
  unsigned int v14; // w22
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w9
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  __int16 v37; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a3 + 7036) == 3 )
  {
    v12 = *(unsigned __int8 **)(a2 + 16);
    v11 = *(_QWORD *)(a2 + 24);
    v14 = *(_DWORD *)(a2 + 40);
    v15 = result;
    v37 = 0;
    if ( dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, result, v12 + 10, &v37, a3 + 360) )
    {
      qdf_mem_set((void *)(a3 + 13304), 0x1B4u, 0);
      result = dot11f_unpack_channel_usage_req(v15, v11, v14, a3 + 13304, 0);
      if ( (result & 0x10000000) != 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Error parsing channel usage req action frame (0x%08x, %d bytes):",
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "__lim_process_channel_usage_req_action_frame",
                   (unsigned int)result,
                   v14);
      }
      else
      {
        if ( (_DWORD)result )
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: There were warnings while unpacking channel usage req action frame  (0x%08x, %d bytes):",
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     "__lim_process_channel_usage_req_action_frame",
                     (unsigned int)result,
                     v14);
        v32 = *(unsigned __int8 *)(a3 + 13308);
        *(_BYTE *)(a3 + 13288) |= 2u;
        if ( v32 == 4 )
          result = lim_send_channel_usage_resp_action_frame(v15, a3, v12 + 10);
      }
    }
    else
    {
      if ( v12 == (unsigned __int8 *)-10LL )
      {
        v35 = 0;
        v33 = 0;
        v34 = 0;
        v36 = 0;
      }
      else
      {
        v33 = v12[10];
        v34 = v12[11];
        v35 = v12[12];
        v36 = v12[15];
      }
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Entry not found %02x:%02x:%02x:**:**:%02x",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "__lim_process_channel_usage_req_action_frame",
                 v33,
                 v34,
                 v35,
                 v36);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

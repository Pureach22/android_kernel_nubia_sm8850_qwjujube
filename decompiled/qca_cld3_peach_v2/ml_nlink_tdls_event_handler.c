__int64 __fastcall ml_nlink_tdls_event_handler(
        __int64 a1,
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
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w4
  const char *v24; // x2
  __int64 result; // x0
  __int64 v26; // x23
  int v27; // w22
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h]
  __int64 v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 1360);
  LOWORD(v32) = 0;
  v30 = 0;
  v31 = 0;
  if ( v14 && *(_QWORD *)(v14 + 2224) )
  {
    qdf_mutex_acquire(v14 + 1656);
    qdf_mem_copy(&v30, (const void *)(*(_QWORD *)(v14 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v14 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ml_nlink_get_curr_force_state",
      v30,
      v31,
      v32,
      v33);
  }
  v23 = *(_DWORD *)(a3 + 8);
  if ( v23 == 5 )
  {
    if ( (*(_DWORD *)a3 & WORD1(v30)) == 0 )
    {
      if ( (*(_DWORD *)a3 & (unsigned __int16)v30) == 0 )
      {
        v24 = "%s: link_bitmap 0x%x already no force, 0x%x";
        goto LABEL_29;
      }
      v26 = *(_QWORD *)(a2 + 1360);
      if ( v26 && *(_QWORD *)(v26 + 2224) )
      {
        qdf_mutex_acquire(v26 + 1656);
        v27 = *(unsigned __int16 *)(*(_QWORD *)(v26 + 2224) + 1416LL);
        qdf_mutex_release(v26 + 1656);
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: mlo_ctx or sta_ctx null",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "ml_nlink_get_force_link_request",
          v30);
        v27 = 0;
      }
      if ( (*(_DWORD *)a3 & v27) != 0 )
      {
        v24 = "%s: link_bitmap 0x%x active hold by vendor cmd, 0x%x";
        goto LABEL_29;
      }
      goto LABEL_21;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link_bitmap 0x%x can't be no_force due to concurrency, 0x%x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ml_nlink_tdls_event_handler");
    result = 4;
  }
  else
  {
    if ( v23 == 1 )
    {
      if ( (*(_DWORD *)a3 & ~(unsigned __int16)v30) == 0 )
      {
        v24 = "%s: link_bitmap 0x%x already active, 0x%x";
LABEL_29:
        qdf_trace_msg(0x8Fu, 8u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "ml_nlink_tdls_event_handler", v30);
        result = 0;
        goto LABEL_30;
      }
      if ( ((WORD2(v31) | WORD1(v30)) & *(_DWORD *)a3) != 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: link_bitmap 0x%x can't be active due to concurrency, 0x%x 0x%x",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "ml_nlink_tdls_event_handler");
        result = 4;
        goto LABEL_30;
      }
LABEL_21:
      if ( a1 && (v28 = *(_QWORD *)(a1 + 2800)) != 0 && (v29 = *(_QWORD *)(v28 + 16)) != 0 )
      {
        if ( (wmi_service_enabled(v29, 0x129u, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
        {
          result = policy_mgr_mlo_sta_set_nlink(
                     a1,
                     *(unsigned __int8 *)(a2 + 168),
                     *(_DWORD *)(a3 + 12),
                     *(_DWORD *)(a3 + 8),
                     0,
                     *(_DWORD *)a3,
                     0,
                     0);
          goto LABEL_30;
        }
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Invalid WMI handle",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "ml_is_nlink_service_supported",
          v30);
      }
      result = policy_mgr_mlo_sta_set_link(
                 a1,
                 *(unsigned int *)(a3 + 12),
                 *(unsigned int *)(a3 + 8),
                 *(unsigned __int8 *)(a3 + 4),
                 a3 + 5);
      goto LABEL_30;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unhandled for tdls force mode %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ml_nlink_tdls_event_handler");
    result = 4;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}

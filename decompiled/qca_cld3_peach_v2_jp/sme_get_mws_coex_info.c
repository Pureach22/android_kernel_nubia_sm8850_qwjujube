__int64 __fastcall sme_get_mws_coex_info(__int64 a1, int a2, int a3, __int64 a4, __int64 a5)
{
  _DWORD *v10; // x0
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  const char *v22; // x2
  __int64 result; // x0
  int v24; // w21
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v10 = (_DWORD *)_qdf_mem_malloc(8u, "sme_get_mws_coex_info", 16951);
  if ( v10 )
  {
    *v10 = a2;
    v10[1] = a3;
    v11 = (__int64)v10;
    *(_QWORD *)(a1 + 14528) = a4;
    *(_QWORD *)(a1 + 14520) = a5;
    v12 = qdf_mutex_acquire(a1 + 12776);
    if ( v12 )
    {
      v21 = v12;
      v22 = "%s: sme_acquire_global_lock failed";
    }
    else
    {
      v26 = v11;
      LOWORD(v25) = 4290;
      v24 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)&v25,
              0x4246u,
              (__int64)"sme_get_mws_coex_info");
      qdf_mutex_release(a1 + 12776);
      if ( !v24 )
      {
        result = 0;
        goto LABEL_8;
      }
      v21 = 16;
      v22 = "%s: post MWS coex info req failed";
    }
    qdf_trace_msg(0x34u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "sme_get_mws_coex_info");
    _qdf_mem_free(v11);
    result = v21;
  }
  else
  {
    result = 2;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}

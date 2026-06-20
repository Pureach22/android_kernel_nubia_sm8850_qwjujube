__int64 __fastcall sme_get_roam_scan_stats(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  int v10; // w0
  int v11; // w21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20
  __int64 result; // x0
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v8 = _qdf_mem_malloc(0x18u, "sme_get_roam_scan_stats", 16380);
  if ( v8 )
  {
    *(_DWORD *)v8 = a4;
    v9 = v8;
    *(_QWORD *)(v8 + 8) = a2;
    *(_QWORD *)(v8 + 16) = a3;
    v10 = qdf_mutex_acquire(a1 + 12848);
    if ( !v10 )
    {
      v23 = v9;
      LODWORD(v22) = 4527;
      v11 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)&v22,
              0x400Cu,
              (__int64)"sme_get_roam_scan_stats");
      qdf_mutex_release(a1 + 12848);
      if ( !v11 )
      {
        result = 0;
        goto LABEL_7;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: post roam scan stats req failed",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sme_get_roam_scan_stats");
      v10 = 16;
    }
    v20 = v10;
    _qdf_mem_free(v9);
    result = v20;
  }
  else
  {
    result = 2;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}

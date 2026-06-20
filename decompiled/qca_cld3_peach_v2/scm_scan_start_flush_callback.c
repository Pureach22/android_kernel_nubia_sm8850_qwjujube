__int64 __fastcall scm_scan_start_flush_callback(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  int v10; // w8
  int v11; // w9
  double v12; // d0
  unsigned int *v13; // x8
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 result; // x0
  int v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+Ch] [xbp-34h]
  int v27; // [xsp+14h] [xbp-2Ch]
  int v28; // [xsp+18h] [xbp-28h]
  int v29; // [xsp+1Ch] [xbp-24h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v9 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    v31 = 0;
    v32 = 0;
    v30 = 0;
    v27 = 0;
    v26 = 0x200000001LL;
    v10 = *(_DWORD *)(v9 + 16);
    v28 = *(_DWORD *)(v9 + 12);
    v11 = *(_DWORD *)(v9 + 8);
    v25 = v10;
    v31 = v9;
    v29 = v11;
    v12 = ((double (__fastcall *)(_QWORD, int *))scm_scan_post_event)(*(_QWORD *)v9, &v25);
    wlan_objmgr_vdev_release_ref(*(_QWORD *)v9, 0xCu, v13, v12, v14, v15, v16, v17, v18, v19, v20);
    v21 = *(_QWORD *)(v9 + 2032);
    if ( v21 )
    {
      *(_QWORD *)(v9 + 2032) = 0;
      *(_DWORD *)(v9 + 2024) = 0;
      _qdf_mem_free(v21);
    }
    v22 = *(_QWORD *)(v9 + 2048);
    if ( v22 )
    {
      *(_DWORD *)(v9 + 2040) = 0;
      *(_QWORD *)(v9 + 2048) = 0;
      _qdf_mem_free(v22);
    }
    v23 = *(_QWORD *)(v9 + 2064);
    if ( v23 )
    {
      *(_DWORD *)(v9 + 2056) = 0;
      *(_QWORD *)(v9 + 2064) = 0;
      _qdf_mem_free(v23);
    }
    _qdf_mem_free(v9);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: msg or msg->bodyptr is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "scm_scan_start_flush_callback");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

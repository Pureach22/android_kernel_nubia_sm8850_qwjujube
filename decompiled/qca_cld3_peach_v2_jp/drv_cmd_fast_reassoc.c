__int64 __fastcall drv_cmd_fast_reassoc(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v4; // w8
  const char *v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x3
  const char *v26; // x2
  unsigned int v27; // w1
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v38; // [xsp+10h] [xbp-20h] BYREF
  int v39; // [xsp+18h] [xbp-18h] BYREF
  __int16 v40; // [xsp+1Ch] [xbp-14h]
  int v41; // [xsp+20h] [xbp-10h] BYREF
  __int16 v42; // [xsp+24h] [xbp-Ch]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v37 = 0;
  v42 = 0;
  v4 = *(_DWORD *)(v3 + 40);
  v41 = 0;
  v40 = 0;
  v39 = 0;
  if ( v4 )
  {
    v5 = qdf_opmode_str(v4);
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Unsupported in mode %s(%d)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_fast_reassoc",
      v5,
      *(unsigned int *)(v3 + 40));
  }
  else
  {
    v14 = *(_QWORD *)(v3 + 24);
    if ( hdd_cm_is_vdev_associated(a1) )
    {
      v25 = *(_QWORD *)(v14 + 8);
      v38 = a3;
      if ( !(unsigned int)hdd_parse_bssid_and_chan(&v38, &v41, &v37, v25) )
      {
        qdf_mem_copy(&v39, &v41, 6u);
        ucfg_wlan_cm_roam_invoke(
          *(_QWORD *)(v14 + 8),
          *((unsigned __int8 *)a1 + 8),
          (unsigned __int8 *)&v39,
          v37,
          1u,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36);
        result = 0;
        goto LABEL_9;
      }
      v26 = "%s: Failed to parse reassoc command data";
      v27 = 2;
    }
    else
    {
      v26 = "%s: Not associated!";
      v27 = 3;
    }
    qdf_trace_msg(0x33u, v27, v26, v17, v18, v19, v20, v21, v22, v23, v24, "drv_cmd_fast_reassoc");
  }
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

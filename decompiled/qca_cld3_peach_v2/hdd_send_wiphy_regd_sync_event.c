__int64 __fastcall hdd_send_wiphy_regd_sync_event(__int64 a1, char a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int64 v41; // x24
  int *v42; // x25
  unsigned __int16 *v43; // x26
  int v44; // w13
  int v45; // w8
  unsigned int v46; // t1
  int v47; // w10
  __int64 v48; // x0
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // [xsp+0h] [xbp-2F0h]
  __int64 v59; // [xsp+8h] [xbp-2E8h]
  _DWORD s[180]; // [xsp+10h] [xbp-2E0h] BYREF
  __int64 v61; // [xsp+2E0h] [xbp-10h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 )
  {
    v12 = "%s: hdd_ctx is NULL";
    goto LABEL_5;
  }
  if ( (unsigned int)ucfg_reg_get_regd_rules(*(_QWORD *)(a1 + 8), s, v4, v5, v6, v7, v8, v9, v10, v11) )
  {
    v12 = "%s: could not get reg rules";
LABEL_5:
    result = qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_send_wiphy_regd_sync_event");
    goto LABEL_6;
  }
  if ( LOBYTE(s[2]) )
  {
    result = _qdf_mem_malloc(96LL * LOBYTE(s[2]) + 32, "hdd_send_wiphy_regd_sync_event", 1540);
    if ( result )
    {
      v14 = result;
      *(_DWORD *)(result + 16) = LOBYTE(s[2]);
      qdf_mem_copy((void *)(result + 20), s, 3u);
      if ( (unsigned int)(s[1] - 1) >= 3 )
        v23 = 0;
      else
        v23 = s[1];
      *(_DWORD *)(v14 + 24) = v23;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Regulatory Domain %s",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_send_wiphy_regd_sync_event",
        v14 + 20);
      v32 = qdf_trace_msg(
              0x33u,
              8u,
              "%s: start freq\tend freq\t@ max_bw\tant_gain\tpwr\tflags",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "hdd_send_wiphy_regd_sync_event");
      if ( LOBYTE(s[2]) )
      {
        v41 = 0;
        v42 = (int *)(v14 + 112);
        v43 = (unsigned __int16 *)&s[4] + 1;
        do
        {
          if ( v41 == 10 )
            __break(0x5512u);
          v44 = *v42;
          *(v42 - 21) = 1000 * *(v43 - 4);
          *(v42 - 20) = 1000 * *(v43 - 3);
          *(v42 - 19) = 1000 * *(v43 - 2);
          *(v42 - 18) = 100 * *((unsigned __int8 *)v43 - 1);
          v45 = 100 * *((unsigned __int8 *)v43 - 2);
          *(v42 - 17) = v45;
          v46 = *v43;
          v43 += 7;
          v47 = v44 | (v46 << 6) & 0x80 | (2 * v46) & 0x10 | (v46 >> 6) & 8;
          *v42 = v47 | (v46 >> 6) & 1 | 0x800;
          v42 += 24;
          LODWORD(v59) = v47 | (v46 >> 6) & 1 | 0x800;
          LODWORD(v58) = v45;
          v32 = qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: %d KHz\t%d KHz\t@ %d KHz\t%d\t\t%d\t%d",
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  "hdd_send_wiphy_regd_sync_event",
                  v58,
                  v59);
          ++v41;
        }
        while ( v41 < LOBYTE(s[2]) );
      }
      if ( (a2 & 1) != 0 )
      {
        rtnl_lock(v32);
        v48 = *(_QWORD *)(a1 + 24);
        if ( v48 )
        {
          mutex_lock(v48);
          v48 = *(_QWORD *)(a1 + 24);
        }
        regulatory_set_wiphy_regd_sync(v48, v14);
        v49 = *(_QWORD *)(a1 + 24);
        if ( v49 )
          v49 = mutex_unlock(v49);
        rtnl_unlock(v49);
      }
      else
      {
        regulatory_set_wiphy_regd(*(_QWORD *)(a1 + 24), v14);
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: regd sync event sent with reg rules info",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "hdd_send_wiphy_regd_sync_event");
      result = _qdf_mem_free(v14);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: no reg rules %d",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "hdd_send_wiphy_regd_sync_event",
               0);
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}

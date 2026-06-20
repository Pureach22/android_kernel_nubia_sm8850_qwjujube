__int64 __fastcall lim_process_assoc_req_frame(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x20
  int v17; // w25
  __int64 v18; // x26
  int v19; // w8
  int v20; // w9
  int v21; // w10
  int v22; // w11
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _DWORD *v32; // x8
  const char *v33; // x2
  __int64 v34; // x0
  __int64 v35; // x2
  __int64 v36; // x3
  unsigned __int8 *v37; // x26
  const char *v38; // x4
  __int64 v39; // x6
  __int64 v40; // x7
  int v41; // w8
  int v42; // w9
  __int64 v43; // x4
  __int64 v44; // x6
  __int64 v45; // x7
  int v46; // w8
  int v47; // w9
  int v48; // w10
  int v49; // w9
  int v50; // w10
  const char *v51; // x2
  __int64 v52; // x5
  __int64 v53; // x2
  __int64 v54; // x4
  unsigned __int8 *v55; // x5
  _BOOL8 v56; // x6
  int v57; // w9
  _BOOL8 v58; // x7
  bool v59; // zf
  char v60; // w8
  __int64 v61; // [xsp+0h] [xbp-30h]
  __int64 v62; // [xsp+8h] [xbp-28h]
  __int64 v63; // [xsp+10h] [xbp-20h]
  __int16 v64; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  v16 = *(_QWORD *)(a2 + 16);
  v17 = *(_DWORD *)(a2 + 40);
  v18 = jiffies;
  if ( lim_process_assoc_req_frame___last_ticks - jiffies + 125 < 0 )
  {
    if ( v16 == -10 )
    {
      v21 = 0;
      v19 = 0;
      v20 = 0;
      v22 = 0;
    }
    else
    {
      v19 = *(unsigned __int8 *)(v16 + 10);
      v20 = *(unsigned __int8 *)(v16 + 11);
      v21 = *(unsigned __int8 *)(v16 + 12);
      v22 = *(unsigned __int8 *)(v16 + 15);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "Assoc req RX: subtype %d vdev %d sys role %d lim state %d rssi %d from %02x:%02x:%02x:**:**:%02x",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      (unsigned __int8)a3,
      *(unsigned __int8 *)(a4 + 10),
      *(unsigned int *)(a4 + 88),
      *(unsigned int *)(a4 + 72),
      *(unsigned int *)(a2 + 8),
      v19,
      v20,
      v21,
      v22);
    lim_process_assoc_req_frame___last_ticks = v18;
  }
  result = (__int64)lim_check_assoc_req(a1, a3, (unsigned __int8 *)(v16 + 10), a4, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !(_DWORD)result )
  {
    v32 = *(_DWORD **)(a4 + 16);
    if ( !v32 )
    {
      v33 = "%s: vdev is NULL";
      goto LABEL_11;
    }
    if ( v32[334] )
    {
      v33 = "%s: SAP is suspended, reject peer assoc";
LABEL_11:
      result = qdf_trace_msg(0x35u, 2u, v33, v24, v25, v26, v27, v28, v29, v30, v31, "lim_process_assoc_req_frame");
      goto LABEL_12;
    }
    if ( v32[5] != 3 || v32[6] != 19 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: SAP is not up, drop ASSOC REQ on sessionid: %d",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "lim_process_assoc_req_frame",
                 *(unsigned __int16 *)(a4 + 8));
      goto LABEL_12;
    }
    v34 = dph_lookup_hash_entry(
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            a1,
            (unsigned __int8 *)(v16 + 10),
            &v64,
            a4 + 360);
    if ( v34 )
    {
      if ( (*(_WORD *)v34 & 0x400) == 0 )
      {
        if ( (*(_WORD *)v16 & 0x800) != 0 )
        {
          v43 = *(unsigned __int16 *)(a4 + 8);
          v44 = *(unsigned int *)(a4 + 88);
          if ( v16 == -10 )
          {
            v47 = 0;
            v45 = 0;
            v46 = 0;
            v48 = 0;
          }
          else
          {
            v45 = *(unsigned __int8 *)(v16 + 10);
            v46 = *(unsigned __int8 *)(v16 + 11);
            v47 = *(unsigned __int8 *)(v16 + 12);
            v48 = *(unsigned __int8 *)(v16 + 15);
          }
          v51 = "%s: STA is initiating Assoc Req after ACK lost. Do not process sessionid: %d sys sub_type=%d for role=%d"
                " from: %02x:%02x:%02x:**:**:%02x";
          v52 = (unsigned __int8)a3;
          LODWORD(v63) = v48;
          LODWORD(v62) = v47;
        }
        else
        {
          v35 = *(unsigned __int16 *)(v34 + 336);
          v36 = v34 + 338;
          if ( (unsigned __int8)a3 == 1 )
          {
            lim_send_assoc_rsp_mgmt_frame(a1, 12, v35, v36, 1, v34, a4, 0, v34 + 944);
            v33 = "%s: Rejecting reassoc req from STA";
            goto LABEL_11;
          }
          lim_send_assoc_rsp_mgmt_frame(a1, 0, v35, v36, a3, v34, a4, 0, v34 + 944);
          v43 = *(unsigned __int16 *)(a4 + 8);
          v44 = *(unsigned int *)(a4 + 88);
          if ( v16 == -10 )
          {
            v49 = 0;
            v45 = 0;
            v46 = 0;
            v50 = 0;
          }
          else
          {
            v45 = *(unsigned __int8 *)(v16 + 10);
            v46 = *(unsigned __int8 *)(v16 + 11);
            v49 = *(unsigned __int8 *)(v16 + 12);
            v50 = *(unsigned __int8 *)(v16 + 15);
          }
          v51 = "%s: DUT already received an assoc request frame and STA is sending another assoc req.So, do not Process "
                "sessionid: %d sys sub_type: %d for role: %d from: %02x:%02x:%02x:**:**:%02x";
          LODWORD(v63) = v50;
          LODWORD(v62) = v49;
          v52 = (unsigned __int8)a3;
        }
        LODWORD(v61) = v46;
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   v51,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "lim_process_assoc_req_frame",
                   v43,
                   v52,
                   v44,
                   v45,
                   v61,
                   v62,
                   v63);
        goto LABEL_12;
      }
      if ( !*(_BYTE *)(v34 + 641) )
      {
        v33 = "%s: Drop duplicate assoc_req before 4-way HS";
        goto LABEL_11;
      }
    }
    if ( (*(_BYTE *)(v16 + 10) & 1) != 0 )
    {
      if ( (_BYTE)a3 )
        v38 = "ReAssoc";
      else
        v38 = "Assoc";
      if ( v16 == -10 )
        v39 = 0;
      else
        v39 = *(unsigned __int8 *)(v16 + 10);
      if ( v16 == -10 )
      {
        v41 = 0;
        v40 = 0;
        v42 = 0;
      }
      else
      {
        v40 = *(unsigned __int8 *)(v16 + 11);
        v41 = *(unsigned __int8 *)(v16 + 12);
        v42 = *(unsigned __int8 *)(v16 + 15);
      }
      LODWORD(v62) = v42;
      LODWORD(v61) = v41;
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Rcvd: %s Req, sessionid: %d from a BC/MC address%02x:%02x:%02x:**:**:%02x",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "lim_process_assoc_req_frame",
                 v38,
                 *(unsigned __int16 *)(a4 + 8),
                 v39,
                 v40,
                 v61,
                 v62);
    }
    else
    {
      result = lim_chk_sa_da(a1, v16, a4, a3);
      if ( (result & 1) != 0 )
      {
        result = lim_mismatch_bssid_da(v16);
        if ( (result & 1) == 0 )
        {
          result = _qdf_mem_malloc(0xE20u, "lim_process_assoc_req_frame", 3177);
          if ( result )
          {
            v37 = (unsigned __int8 *)result;
            if ( (lim_alloc_assoc_req_frm_buf(result, *(_QWORD *)(a2 + 56), *(_DWORD *)(a2 + 36), v17) & 1) != 0
              && (result = lim_proc_assoc_req_frm_cmn(a1, a3, a4, (unsigned __int8 *)(v16 + 10), (__int64)v37, 0),
                  !(_DWORD)result) )
            {
              if ( (unsigned __int8)a3 == 1 )
              {
                v54 = v37[10];
                v53 = v16 + 16;
                v55 = v37 + 11;
                v56 = v37[3160] != 0;
                v57 = v37[3480];
                v58 = v37[3296] != 0;
                v59 = v37[3372] == 0;
                LOBYTE(v63) = 1;
              }
              else
              {
                if ( (_BYTE)a3 )
                  goto LABEL_12;
                v53 = v16 + 16;
                v54 = v37[10];
                v55 = v37 + 11;
                v56 = v37[3160] != 0;
                v57 = v37[3480];
                v58 = v37[3296] != 0;
                v59 = v37[3372] == 0;
                LOBYTE(v63) = 0;
              }
              v60 = !v59;
              LOBYTE(v62) = v57 != 0;
              LOBYTE(v61) = v60;
              result = lim_cp_stats_cstats_log_assoc_req_evt(a4, 1, v53, v16 + 10, v54, v55, v56, v58, v61, v62, v63);
            }
            else
            {
              lim_free_assoc_req_frm_buf((__int64)v37);
              result = _qdf_mem_free((__int64)v37);
            }
          }
        }
      }
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

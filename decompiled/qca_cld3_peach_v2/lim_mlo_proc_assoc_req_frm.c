__int64 __fastcall lim_mlo_proc_assoc_req_frm(
        __int64 a1,
        __int64 a2,
        const void *a3,
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
  _QWORD *context; // x0
  unsigned __int8 v17; // w1
  __int64 v18; // x19
  __int64 session_by_vdev_id; // x0
  unsigned int v20; // w27
  const void *v21; // x1
  int v22; // w28
  const char *v23; // x2
  __int64 result; // x0
  unsigned __int16 *v25; // x22
  unsigned __int8 v26; // w8
  int v27; // w22
  unsigned int v28; // t1
  int v29; // w24
  __int64 v30; // x25
  int v31; // w21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x20
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w9
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w19
  int v62; // w9
  __int64 v63; // x8
  int v64; // w9
  __int64 v65; // [xsp+8h] [xbp-18h] BYREF
  int v66; // [xsp+10h] [xbp-10h] BYREF
  __int16 v67; // [xsp+14h] [xbp-Ch]
  __int64 v68; // [xsp+18h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v66 = 0;
  v65 = 0;
  if ( !a1 )
  {
    v23 = "%s: vdev is null";
LABEL_18:
    qdf_trace_msg(0x35u, 2u, v23, a5, a6, a7, a8, a9, a10, a11, a12, "lim_mlo_proc_assoc_req_frm");
LABEL_19:
    result = 4;
    goto LABEL_20;
  }
  if ( !a2 )
  {
    v23 = "%s: ml_peer is null";
    goto LABEL_18;
  }
  if ( !a3 )
  {
    v23 = "%s: link addr is null";
    goto LABEL_18;
  }
  if ( !a4 )
  {
    v23 = "%s: assoq req buf is null";
    goto LABEL_18;
  }
  context = _cds_get_context(53, (__int64)"lim_mlo_proc_assoc_req_frm", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
  {
    v23 = "%s: mac ctx is null";
    goto LABEL_18;
  }
  v17 = *(_BYTE *)(a1 + 168);
  v18 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, v17, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !session_by_vdev_id )
  {
    v23 = "%s: session is NULL";
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(a4 + 68) & 4) == 0 )
  {
    v20 = *(_DWORD *)(a4 + 112);
    if ( v20 >= 0x19 )
    {
      v21 = a3;
      v22 = 0;
      goto LABEL_22;
    }
    goto LABEL_17;
  }
  v22 = *(unsigned __int16 *)(a4 + 66);
  v20 = *(_DWORD *)(a4 + 112);
  if ( v20 + v22 <= 0x18 )
  {
LABEL_17:
    v23 = "%s: invalid buf";
    goto LABEL_18;
  }
  v21 = a3;
LABEL_22:
  v25 = *(unsigned __int16 **)(a4 + 224);
  v28 = *v25;
  v27 = (_DWORD)v25 + 24;
  v26 = v28;
  if ( ((v28 >> 2) & 3) != 0 )
  {
LABEL_23:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: invalid mgt_type %d, sub_type %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_mlo_proc_assoc_req_frm");
    goto LABEL_19;
  }
  v29 = v26 >> 4;
  if ( v26 >> 4 )
  {
    if ( v29 != 2 )
      goto LABEL_23;
    v30 = session_by_vdev_id;
    v31 = 1;
  }
  else
  {
    v30 = session_by_vdev_id;
    v31 = 0;
  }
  qdf_mem_copy(&v66, v21, 6u);
  result = (__int64)lim_check_assoc_req(v18, v31, (unsigned __int8 *)&v66, v30, v32, v33, v34, v35, v36, v37, v38, v39);
  if ( !(_DWORD)result )
  {
    v40 = _qdf_mem_malloc(0xEB8u, "lim_mlo_proc_assoc_req_frm", 747);
    if ( v40 )
    {
      v41 = v40;
      v42 = skb_copy(a4, 2080);
      *(_QWORD *)(v41 + 3272) = v42;
      if ( v42 )
      {
        if ( (*(_BYTE *)(v42 + 68) & 4) != 0 )
          v51 = *(unsigned __int16 *)(v42 + 66);
        else
          v51 = 0;
        v52 = util_gen_link_assoc_req(
                v27,
                v20 + v22 - 24,
                v29 != 0,
                0,
                *(_DWORD *)(v30 + 24),
                *(_QWORD *)(v42 + 224),
                *(_DWORD *)(v42 + 112) + v51,
                (__int64)&v65);
        if ( v52 )
        {
          v61 = v52;
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Partner Assoc Req frame gen error. source addr:%02x:%02x:%02x:**:**:%02x",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_mlo_proc_assoc_req_frm",
            (unsigned __int8)v66,
            BYTE1(v66),
            BYTE2(v66),
            HIBYTE(v67));
        }
        else
        {
          v62 = v65;
          *(_DWORD *)(*(_QWORD *)(v41 + 3272) + 112LL) = v65;
          v63 = *(_QWORD *)(*(_QWORD *)(v41 + 3272) + 224LL);
          *(_DWORD *)(v41 + 3280) = v62 - 24;
          *(_QWORD *)(v41 + 3288) = v63 + 24;
          v64 = *(_DWORD *)(a2 + 104);
          *(_WORD *)(v41 + 3760) = *(_WORD *)(a2 + 108);
          *(_DWORD *)(v41 + 3756) = v64;
          result = lim_proc_assoc_req_frm_cmn(v18, v31, v30, (unsigned __int8 *)&v66, v41, *(_WORD *)(a2 + 184));
          if ( !(_DWORD)result )
            goto LABEL_20;
          v61 = result;
        }
        lim_free_assoc_req_frm_buf(v41);
        _qdf_mem_free(v41);
        result = v61;
        goto LABEL_20;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: partner link assoc request buf clone failed",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "lim_mlo_proc_assoc_req_frm");
      _qdf_mem_free(v41);
      result = 2;
    }
    else
    {
      result = 2;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}

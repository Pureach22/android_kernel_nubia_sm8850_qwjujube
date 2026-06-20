__int64 __fastcall lim_process_set_pdev_IEs(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  int v13; // w23
  int v14; // w24
  __int64 v15; // x21
  _BYTE *v16; // x0
  unsigned __int8 *ie_ptr_from_eid; // x0
  __int16 v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  const char *v28; // x3
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  int v38; // w22
  int v39; // w23
  __int64 v40; // x20
  _BYTE *v41; // x0
  unsigned __int8 *v42; // x0
  __int16 v43; // w9
  char v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int j; // w24
  _BYTE *v54; // x0
  int i; // w25
  _BYTE *v56; // x0
  __int64 v57; // [xsp+8h] [xbp-38h] BYREF
  __int64 v58; // [xsp+10h] [xbp-30h]
  __int64 v59; // [xsp+18h] [xbp-28h]
  __int64 v60; // [xsp+20h] [xbp-20h]
  __int64 v61; // [xsp+28h] [xbp-18h]
  __int64 v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v27 = "%s: NULL ht_vht_cfg";
    v28 = "lim_process_set_pdev_IEs";
LABEL_10:
    result = qdf_trace_msg(0x35u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, v28);
    goto LABEL_22;
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: rcvd set pdev ht vht ie req with nss = %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_set_pdev_IEs",
             (unsigned int)a2[2]);
  v13 = *((unsigned __int8 *)a2 + 8);
  v14 = a2[1];
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  if ( v13 )
  {
    result = _qdf_mem_malloc(0x10u, "lim_set_pdev_ht_ie", 9402);
    if ( result )
    {
      v15 = result;
      *(_BYTE *)result = v14;
      *(_WORD *)(result + 1) = 257;
      *(_BYTE *)(result + 3) = 28;
      v16 = (_BYTE *)_qdf_mem_malloc(0x1Cu, "lim_set_pdev_ht_ie", 9410);
      *(_QWORD *)(v15 + 8) = v16;
      if ( !v16 )
      {
LABEL_8:
        result = _qdf_mem_free(v15);
        goto LABEL_13;
      }
      *v16 = 45;
      *(_BYTE *)(*(_QWORD *)(v15 + 8) + 1LL) = *(_BYTE *)(v15 + 3) - 2;
      lim_set_ht_caps(a1, *(_QWORD *)(v15 + 8), *(unsigned __int8 *)(v15 + 3));
      ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x2Du, *(unsigned __int8 **)(v15 + 8), *(unsigned __int8 *)(v15 + 3));
      if ( ie_ptr_from_eid )
      {
        v18 = *((_WORD *)ie_ptr_from_eid + 1);
        ie_ptr_from_eid[6] = 0;
        *((_WORD *)ie_ptr_from_eid + 1) = v18 & 0xFF7F;
        LOWORD(v57) = 4473;
        v58 = v15;
        HIDWORD(v57) = 0;
        result = wma_post_ctrl_msg(a1, &v57);
        if ( (_DWORD)result )
        {
LABEL_7:
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: wma_post_ctrl_msg() return failure",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "lim_set_pdev_ht_ie");
          _qdf_mem_free(*(_QWORD *)(v15 + 8));
          goto LABEL_8;
        }
        if ( v13 != 1 )
        {
          for ( i = 1; v13 != i; ++i )
          {
            result = _qdf_mem_malloc(0x10u, "lim_set_pdev_ht_ie", 9402);
            if ( !result )
              break;
            v15 = result;
            *(_BYTE *)result = v14;
            *(_BYTE *)(result + 2) = i + 1;
            *(_BYTE *)(result + 1) = 1;
            *(_BYTE *)(result + 3) = 28;
            v56 = (_BYTE *)_qdf_mem_malloc(0x1Cu, "lim_set_pdev_ht_ie", 9410);
            *(_QWORD *)(v15 + 8) = v56;
            if ( !v56 )
              goto LABEL_8;
            *v56 = 45;
            *(_BYTE *)(*(_QWORD *)(v15 + 8) + 1LL) = *(_BYTE *)(v15 + 3) - 2;
            lim_set_ht_caps(a1, *(_QWORD *)(v15 + 8), *(unsigned __int8 *)(v15 + 3));
            LOWORD(v57) = 4473;
            v58 = v15;
            HIDWORD(v57) = 0;
            result = wma_post_ctrl_msg(a1, &v57);
            if ( (_DWORD)result )
              goto LABEL_7;
          }
        }
      }
      else
      {
        _qdf_mem_free(*(_QWORD *)(v15 + 8));
        _qdf_mem_free(v15);
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: failed to get IE ptr",
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   "lim_set_pdev_ht_ie");
      }
    }
  }
LABEL_13:
  v37 = a2[3];
  if ( (unsigned int)(v37 - 8) >= 6 && v37 )
    goto LABEL_22;
  v38 = *((unsigned __int8 *)a2 + 8);
  v39 = a2[1];
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  if ( !v38 )
    goto LABEL_22;
  result = _qdf_mem_malloc(0x10u, "lim_set_pdev_vht_ie", 9471);
  if ( !result )
    goto LABEL_22;
  v40 = result;
  *(_BYTE *)result = v39;
  *(_WORD *)(result + 1) = 258;
  *(_BYTE *)(result + 3) = 14;
  v41 = (_BYTE *)_qdf_mem_malloc(0xEu, "lim_set_pdev_vht_ie", 9480);
  *(_QWORD *)(v40 + 8) = v41;
  if ( !v41 )
  {
LABEL_20:
    result = _qdf_mem_free(v40);
    goto LABEL_22;
  }
  *v41 = -65;
  *(_BYTE *)(*(_QWORD *)(v40 + 8) + 1LL) = *(_BYTE *)(v40 + 3) - 2;
  lim_set_vht_caps(a1, *(_QWORD *)(v40 + 8), *(unsigned __int8 *)(v40 + 3));
  v42 = wlan_get_ie_ptr_from_eid(0xBFu, *(unsigned __int8 **)(v40 + 8), *(unsigned __int8 *)(v40 + 3));
  if ( !v42 )
  {
    _qdf_mem_free(*(_QWORD *)(v40 + 8));
    _qdf_mem_free(v40);
    v27 = "%s: failed to get IE ptr";
    v28 = "lim_set_pdev_vht_ie";
    goto LABEL_10;
  }
  v43 = (unsigned __int8)*((_WORD *)v42 + 3) | 0xFFFC;
  *(_DWORD *)(v42 + 2) &= ~0x80u;
  v44 = *((_WORD *)v42 + 5);
  *((_WORD *)v42 + 3) = v43;
  *((_WORD *)v42 + 4) = 390;
  *((_WORD *)v42 + 5) = *(_WORD *)&v44 | 0xFFFC;
  *((_WORD *)v42 + 6) = 390;
  LOWORD(v57) = 4473;
  v58 = v40;
  HIDWORD(v57) = 0;
  result = wma_post_ctrl_msg(a1, &v57);
  if ( (_DWORD)result )
  {
LABEL_19:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: wma_post_ctrl_msg failure",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_set_pdev_vht_ie");
    _qdf_mem_free(*(_QWORD *)(v40 + 8));
    goto LABEL_20;
  }
  if ( v38 != 1 )
  {
    for ( j = 1; v38 != j; ++j )
    {
      result = _qdf_mem_malloc(0x10u, "lim_set_pdev_vht_ie", 9471);
      if ( !result )
        break;
      v40 = result;
      *(_BYTE *)result = v39;
      *(_BYTE *)(result + 2) = j + 1;
      *(_BYTE *)(result + 1) = 2;
      *(_BYTE *)(result + 3) = 14;
      v54 = (_BYTE *)_qdf_mem_malloc(0xEu, "lim_set_pdev_vht_ie", 9480);
      *(_QWORD *)(v40 + 8) = v54;
      if ( !v54 )
        goto LABEL_20;
      *v54 = -65;
      *(_BYTE *)(*(_QWORD *)(v40 + 8) + 1LL) = *(_BYTE *)(v40 + 3) - 2;
      lim_set_vht_caps(a1, *(_QWORD *)(v40 + 8), *(unsigned __int8 *)(v40 + 3));
      LOWORD(v57) = 4473;
      v58 = v40;
      HIDWORD(v57) = 0;
      result = wma_post_ctrl_msg(a1, &v57);
      if ( (_DWORD)result )
        goto LABEL_19;
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}

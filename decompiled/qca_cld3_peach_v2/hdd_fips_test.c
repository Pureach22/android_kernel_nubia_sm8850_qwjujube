__int64 __fastcall hdd_fips_test(__int64 a1, __int64 a2, __int64 *a3, unsigned int *a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w5
  const char *v35; // x2
  __int64 v36; // x4
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  __int64 v47; // x24
  unsigned int v48; // w9
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int v66; // w19
  unsigned int v67; // w19
  int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  const char *v77; // x2
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  size_t v86; // x2
  __int64 v87; // x22
  unsigned __int16 v88; // w23
  __int64 *v89[2]; // [xsp+0h] [xbp-10h] BYREF

  v89[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v89[0] = nullptr;
  result = _osif_vdev_sync_op_start(a1, v89, (__int64)"hdd_fips_test");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v8, v9, v10, v11, v12, v13, v14, v15, "__hdd_fips_test", a1 + 296);
    v16 = *(_QWORD *)(a1 + 2712);
    v25 = _wlan_hdd_validate_context(v16, (__int64)"__hdd_fips_test", v17, v18, v19, v20, v21, v22, v23, v24);
    if ( v25 )
    {
LABEL_19:
      v67 = v25;
      _osif_vdev_sync_op_stop((__int64)v89[0], (__int64)"hdd_fips_test");
      result = v67;
      goto LABEL_20;
    }
    v34 = *((unsigned __int16 *)a3 + 4);
    if ( v34 <= 0x2F )
    {
      v35 = "%s: Request len %u is too small";
      v36 = *((unsigned __int16 *)a3 + 4);
LABEL_17:
      qdf_trace_msg(0x33u, 8u, v35, v26, v27, v28, v29, v30, v31, v32, v33, "hdd_fips_validate_request", v36);
      goto LABEL_18;
    }
    v36 = a4[2];
    if ( (_DWORD)v36 != 16 && (_DWORD)v36 != 32 )
    {
      v35 = "%s: Invalid key len %u";
      goto LABEL_17;
    }
    if ( v34 - 48 != a4[11] )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Unexpected data_len %u for request_len %u",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_fips_validate_request");
LABEL_18:
      v25 = -22;
      goto LABEL_19;
    }
    v36 = a4[1];
    if ( (unsigned int)v36 >= 2 )
    {
      v35 = "%s: Invalid mode %u";
      goto LABEL_17;
    }
    v36 = *a4;
    if ( (unsigned int)v36 >= 2 )
    {
      v35 = "%s: Invalid operation %u";
      goto LABEL_17;
    }
    v37 = osif_request_alloc(&_hdd_fips_test_params);
    if ( !v37 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Request allocation failure",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__hdd_fips_test");
      v25 = -12;
      goto LABEL_19;
    }
    v46 = v37;
    v47 = osif_request_priv(v37);
    *(_QWORD *)(v47 + 8) = a4 + 3;
    v48 = a4[2];
    *(_QWORD *)(v47 + 24) = a4 + 12;
    *(_DWORD *)(v47 + 16) = v48;
    *(_DWORD *)(v47 + 32) = a4[11];
    *(_DWORD *)(v47 + 36) = a4[1];
    *(_DWORD *)(v47 + 40) = *a4;
    *(_DWORD *)(v47 + 44) = 1;
    v49 = osif_request_cookie(v46);
    if ( (unsigned int)sme_fips_request(
                         v50,
                         v51,
                         v52,
                         v53,
                         v54,
                         v55,
                         v56,
                         v57,
                         *(_QWORD *)(v16 + 16),
                         v47 + 8,
                         (__int64)hdd_fips_cb,
                         v49) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to post fips message",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "__hdd_fips_test");
      v66 = -22;
    }
    else
    {
      v68 = osif_request_wait_for_response(v46);
      if ( v68 )
      {
        v66 = v68;
        v77 = "%s: Target response timed out";
      }
      else
      {
        if ( !*(_DWORD *)v47 )
        {
          if ( *(_DWORD *)(v47 + 56) == *(_DWORD *)(v47 + 32) )
          {
            *a4 = 0;
            v86 = *(unsigned int *)(v47 + 56);
            a4[1] = v86;
            qdf_mem_copy(a4 + 2, *(const void **)(v47 + 64), v86);
            v87 = *a3;
            v88 = *((_WORD *)a4 + 2) + 8;
            *((_WORD *)a3 + 4) = v88;
            _check_object_size(a4, v88, 1);
            if ( inline_copy_to_user_1(v87, a4, v88) )
              v66 = -14;
            else
              v66 = 0;
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Data length mismatch, got %u, expected %u",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "__hdd_fips_test");
            v66 = -22;
          }
          goto LABEL_27;
        }
        v66 = *(_DWORD *)v47;
        v77 = "%s: Target response processing failed";
      }
      qdf_trace_msg(0x33u, 2u, v77, v69, v70, v71, v72, v73, v74, v75, v76, "__hdd_fips_test");
    }
LABEL_27:
    osif_request_put(v46);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v78, v79, v80, v81, v82, v83, v84, v85, "__hdd_fips_test");
    v25 = v66;
    goto LABEL_19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}

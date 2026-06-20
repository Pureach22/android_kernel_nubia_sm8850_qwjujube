__int64 __fastcall os_if_fwol_get_elna_bypass(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int elna_bypass; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w21
  unsigned int v33; // w21
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int *v43; // x21
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v53; // [xsp+0h] [xbp-10h] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v53) = *(_BYTE *)(a1 + 104);
  v4 = osif_request_alloc(os_if_fwol_get_elna_bypass_params);
  if ( v4 )
  {
    v13 = v4;
    v14 = osif_request_cookie(v4);
    elna_bypass = ucfg_fwol_get_elna_bypass(
                    a1,
                    (__int64)&v53,
                    (__int64)os_if_fwol_get_elna_bypass_callback,
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22);
    if ( elna_bypass )
    {
      v32 = elna_bypass;
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Failed to get ELNA BYPASS, %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "os_if_fwol_get_elna_bypass",
        elna_bypass,
        v53,
        v54);
      v33 = qdf_status_to_os_return(v32);
    }
    else
    {
      v34 = osif_request_wait_for_response(v13);
      if ( v34 )
      {
        v33 = v34;
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Operation timed out",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "os_if_fwol_get_elna_bypass",
          v53,
          v54);
      }
      else
      {
        v43 = (unsigned int *)osif_request_priv(v13);
        BYTE4(v53) = *v43;
        if ( (unsigned int)nla_put(a2, 59, 1, (char *)&v53 + 4) )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: put fail with elna_mode:%d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "os_if_fwol_get_elna_bypass",
            *v43,
            v53,
            v54);
          v33 = -22;
        }
        else
        {
          v33 = 0;
        }
      }
    }
    osif_request_put(v13);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Request allocation failure",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "os_if_fwol_get_elna_bypass",
      v53,
      v54);
    v33 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v33;
}

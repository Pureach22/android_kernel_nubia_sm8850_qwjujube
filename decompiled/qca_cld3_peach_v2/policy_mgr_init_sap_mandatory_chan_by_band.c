__int64 __fastcall policy_mgr_init_sap_mandatory_chan_by_band(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 result; // x0
  const char *v15; // x2
  unsigned int v16; // w8
  unsigned __int64 v17; // x22
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  const char *v30; // x2
  __int64 i; // x26
  unsigned int v32; // w24
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x9
  unsigned int v44; // w20
  __int64 v45; // x23
  unsigned int v46; // w22
  __int64 v47; // x21
  unsigned int v48; // w24
  int *v49; // x25
  int v50; // t1
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w0
  unsigned __int64 j; // x20
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  int v78; // w9
  unsigned int v79; // [xsp+4h] [xbp-34Ch] BYREF
  _WORD v80[2]; // [xsp+8h] [xbp-348h] BYREF
  __int16 v81; // [xsp+Ch] [xbp-344h] BYREF
  _BYTE v82[4]; // [xsp+10h] [xbp-340h] BYREF
  unsigned int v83; // [xsp+14h] [xbp-33Ch] BYREF
  _DWORD s[102]; // [xsp+18h] [xbp-338h] BYREF
  _DWORD v85[102]; // [xsp+1B0h] [xbp-1A0h] BYREF
  __int64 v86; // [xsp+348h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v79 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v15 = "%s: Invalid Context";
    goto LABEL_5;
  }
  v13 = comp_private_obj;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: band mask 0x%x",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "policy_mgr_init_sap_mandatory_chan_by_band",
    a2);
  result = policy_mgr_get_valid_chans(a1, s, &v79);
  if ( (_DWORD)result )
  {
    v15 = "%s: Error in getting valid channels";
LABEL_5:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v15,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "policy_mgr_init_sap_mandatory_chan_by_band");
    goto LABEL_6;
  }
  v16 = v79;
  *(_DWORD *)(v13 + 960) = 0;
  if ( v16 )
  {
    v17 = 0;
    do
    {
      result = wlan_reg_is_24ghz_ch_freq(s[v17]);
      if ( (result & 1) != 0 )
      {
        v18 = *(unsigned int *)(v13 + 960);
        v19 = s[v17];
        *(_DWORD *)(v13 + 960) = v18 + 1;
        if ( (unsigned int)v18 > 0x65 )
LABEL_54:
          __break(0x5512u);
        *(_DWORD *)(v13 + 552 + 4 * v18) = v19;
      }
      if ( v17 > 0x64 )
        break;
      ++v17;
    }
    while ( v17 < v79 );
  }
  if ( (a2 & 2) != 0 )
  {
    for ( i = 0; i != 4; ++i )
    {
      v32 = sap_mand_5g_freq_list[i];
      result = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
      if ( result )
      {
        v41 = *(unsigned int *)(result + 960);
        if ( !(_DWORD)v41 )
        {
          v43 = 0;
LABEL_31:
          *(_DWORD *)(result + 960) = v41 + 1;
          *(_DWORD *)(result + 4 * v43 + 552) = v32;
          continue;
        }
        v42 = 0;
        do
        {
          if ( v42 == 408 )
            goto LABEL_54;
          if ( *(_DWORD *)(result + 552 + v42) == v32 )
            goto LABEL_21;
          v42 += 4;
        }
        while ( 4 * v41 != v42 );
        v43 = *(unsigned int *)(result + 960);
        if ( (unsigned int)v41 < 0x66 )
          goto LABEL_31;
        result = qdf_trace_msg(
                   0x4Fu,
                   2u,
                   "%s: mand list overflow (%u)",
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   "policy_mgr_add_sap_mandatory_chan",
                   v32);
      }
      else
      {
        result = qdf_trace_msg(
                   0x4Fu,
                   2u,
                   "%s: Invalid Context",
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   "policy_mgr_add_sap_mandatory_chan");
      }
LABEL_21:
      ;
    }
  }
  if ( (a2 & 4) != 0 )
  {
    memset(v85, 0, sizeof(v85));
    v83 = 0;
    v82[0] = 0;
    v81 = 0;
    v80[0] = 0;
    v20 = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
    if ( v20 )
    {
      v29 = v20;
      result = policy_mgr_get_valid_chans(a1, v85, &v83);
      if ( !(_DWORD)result )
      {
        if ( v83 )
        {
          for ( j = 0; j < v83; ++j )
          {
            if ( *(_DWORD *)(v29 + 960) >= 0x66u )
              break;
            result = wlan_reg_is_6ghz_chan_freq(v85[j]);
            if ( (result & 1) != 0 )
            {
              result = wlan_reg_is_6ghz_psc_chan_freq(v85[j], v61, v62, v63, v64, v65, v66, v67, v68);
              if ( (result & 1) != 0 )
              {
                result = wlan_reg_get_6g_chan_ap_power(
                           *(_QWORD *)(v29 + 8),
                           v85[j],
                           v82,
                           &v81,
                           v80,
                           0,
                           v69,
                           v70,
                           v71,
                           v72,
                           v73,
                           v74,
                           v75,
                           v76);
                if ( !(_DWORD)result )
                {
                  if ( v81 )
                  {
                    v77 = *(unsigned int *)(v29 + 960);
                    v78 = v85[j];
                    *(_DWORD *)(v29 + 960) = v77 + 1;
                    if ( (unsigned int)v77 > 0x65 )
                      goto LABEL_54;
                    *(_DWORD *)(v29 + 552 + 4 * v77) = v78;
                  }
                }
              }
            }
            if ( j > 0x64 )
              break;
          }
        }
        goto LABEL_34;
      }
      v30 = "%s: Error in getting valid channels";
    }
    else
    {
      v30 = "%s: Invalid Context";
    }
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v30,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "policy_mgr_add_sap_mandatory_6ghz_chan");
  }
LABEL_34:
  v44 = *(_DWORD *)(v13 + 960);
  if ( v44 )
  {
    if ( v44 >= 0x66 )
      v45 = 102;
    else
      v45 = v44;
    v46 = (6 * v45) | 1;
    result = _qdf_mem_malloc(v46, "policy_mgr_dump_sap_mandatory", 5938);
    if ( result )
    {
      v47 = result;
      v48 = 0;
      v49 = (int *)(v13 + 552);
      do
      {
        v50 = *v49++;
        v51 = scnprintf(v47 + v48, v46 - v48, " %d", v50);
        --v45;
        v48 += v59;
      }
      while ( v45 );
      qdf_trace_msg(0x4Fu, 8u, "Mandatory SAP fav freq(%d):%s", v51, v52, v53, v54, v55, v56, v57, v58, v44, v47);
      result = _qdf_mem_free(v47);
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}

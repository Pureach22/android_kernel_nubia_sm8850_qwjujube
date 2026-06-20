__int64 __fastcall dp_soc_init_be(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 result; // x0
  unsigned int (*v104)(void); // x8
  __int64 v105; // x0
  _DWORD v106[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v107; // [xsp+8h] [xbp-8h]

  v107 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  wlan_minidump_log(a4, a5, a6, a7, a8, a9, a10, a11, a1, 22528, *(_QWORD *)(a1 + 16));
  *(_QWORD *)(a1 + 64) = a3;
  if ( !a3 )
  {
    result = 0;
    *(_QWORD *)(a1 + 1128) = 0;
    goto LABEL_17;
  }
  v22 = *(_QWORD *)(a3 + 2560);
  *(_QWORD *)(a1 + 1128) = v22;
  if ( !v22 )
    goto LABEL_15;
  if ( (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 22624, v14, v15, v16, v17, v18, v19, v20, v21)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 22704, v23, v24, v25, v26, v27, v28, v29, v30)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 22784, v31, v32, v33, v34, v35, v36, v37, v38)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 22864, v39, v40, v41, v42, v43, v44, v45, v46)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 22944, v47, v48, v49, v50, v51, v52, v53, v54)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 23024, v55, v56, v57, v58, v59, v60, v61, v62)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 23104, v63, v64, v65, v66, v67, v68, v69, v70)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 23184, v71, v72, v73, v74, v75, v76, v77, v78)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 23264, v79, v80, v81, v82, v83, v84, v85, v86)
    || (unsigned int)dp_hw_cookie_conversion_init(a1, a1 + 23344, v87, v88, v89, v90, v91, v92, v93, v94)
    || (unsigned int)dp_tx_init_bank_profiles(a1) )
  {
    goto LABEL_14;
  }
  v104 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
  if ( !v104 )
    goto LABEL_22;
  if ( *((_DWORD *)v104 - 1) != 1696218653 )
    __break(0x8228u);
  if ( v104() != 5 )
  {
LABEL_22:
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 768LL) & 1) != 0 )
    {
      v105 = *(_QWORD *)(a1 + 1128);
      v106[0] = *(_DWORD *)(a1 + 22616);
      v106[1] = 903940515;
      hal_cookie_conversion_reg_cfg_be(v105, v106);
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: INI skip HW CC register setting",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "dp_cc_reg_cfg_init");
    }
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))dp_soc_init)(a1, a2, a3);
  if ( !result )
  {
LABEL_14:
    dp_soc_deinit_be(a1);
LABEL_15:
    result = 0;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall reg_set_country(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  unsigned int v12; // w20
  __int64 psoc_tx_ops; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8
  const char *v24; // x2
  __int64 psoc_obj; // x0
  __int64 v26; // x20
  __int64 v27; // x24
  __int64 is_country_code_valid; // x0
  __int64 v29; // x1
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  bool v46; // zf
  __int64 v47; // x9
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  void (__fastcall *v57)(__int64, char *); // x8
  __int64 result; // x0
  unsigned int v59; // w1
  int v60; // w8
  __int64 v61; // [xsp+0h] [xbp-10h] BYREF
  __int64 v62; // [xsp+8h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v61) = 0;
  LOBYTE(v61) = 0;
  if ( !a1 )
  {
    v24 = "%s: pdev is NULL";
LABEL_32:
    v59 = 2;
LABEL_33:
    qdf_trace_msg(0x51u, v59, v24, a3, a4, a5, a6, a7, a8, a9, a10, "reg_set_country", v61, v62);
    result = 4;
    goto LABEL_34;
  }
  if ( !a2 )
  {
    v24 = "%s: country code is NULL";
    goto LABEL_32;
  }
  v11 = *(_QWORD *)(a1 + 80);
  v12 = *(unsigned __int8 *)(a1 + 40);
  psoc_tx_ops = reg_get_psoc_tx_ops(v11, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !psoc_tx_ops )
    goto LABEL_30;
  v23 = *(_DWORD **)(psoc_tx_ops + 128);
  if ( v23 )
  {
    if ( *(v23 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))v23)(v11, v12, &v61);
  }
  else
  {
    LOBYTE(v61) = v12;
  }
  psoc_obj = reg_get_psoc_obj(v11, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !psoc_obj )
  {
    v24 = "%s: psoc reg component is NULL";
    goto LABEL_32;
  }
  v26 = psoc_obj;
  v27 = psoc_obj + 90112;
  if ( !(unsigned int)qdf_mem_cmp((const void *)(psoc_obj + 91099), a2, 2u) )
  {
    v60 = *(_DWORD *)(v27 + 1000);
    if ( v60 == 4 || v60 == 2 )
    {
      v24 = "%s: country is not different";
      v59 = 8;
      goto LABEL_33;
    }
  }
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: programming new country: %s to firmware",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "reg_set_country",
    a2,
    v61,
    v62);
  is_country_code_valid = (__int64)qdf_mem_copy((char *)&v61 + 4, a2, 3u);
  HIBYTE(v61) = -1;
  if ( (*(_BYTE *)(v27 + 983) & 1) == 0 && (*a2 != 48 || a2[1] != 48) )
  {
    is_country_code_valid = reg_is_country_code_valid(a2);
    if ( (_DWORD)is_country_code_valid )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Unable to set country code: %s\n",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "reg_restore_def_country_for_po",
        a2);
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Restoring to world domain",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "reg_restore_def_country_for_po");
      is_country_code_valid = (__int64)qdf_mem_copy((char *)&v61 + 4, "00", 3u);
    }
  }
  if ( (unsigned __int8)v61 < 3uLL )
  {
    v46 = BYTE5(v61) == 48 && BYTE4(v61) == 48;
    v47 = 91137;
    if ( !v46 )
      v47 = 91128;
    *(_BYTE *)(v26 + v47 + (unsigned __int8)v61) = 1;
    if ( *(_BYTE *)(v27 + 983) != 1 )
    {
      result = reg_set_non_offload_country(a1, (char *)&v61 + 4);
      goto LABEL_34;
    }
    v48 = reg_get_psoc_tx_ops(v11, v30, v31, v32, v33, v34, v35, v36, v37);
    if ( v48 )
    {
      v57 = *(void (__fastcall **)(__int64, char *))(v48 + 40);
      if ( v57 )
      {
        if ( *((_DWORD *)v57 - 1) != -1796695762 )
          __break(0x8228u);
        v57(v11, (char *)&v61 + 4);
        result = 0;
        goto LABEL_34;
      }
      is_country_code_valid = qdf_trace_msg(
                                0x51u,
                                2u,
                                "%s: country set fw handler not present",
                                v49,
                                v50,
                                v51,
                                v52,
                                v53,
                                v54,
                                v55,
                                v56,
                                "reg_set_country");
      if ( (unsigned __int8)v61 <= 2uLL )
      {
        result = 5;
        *(_BYTE *)(v26 + (unsigned __int8)v61 + 91128) = 0;
        goto LABEL_34;
      }
      goto LABEL_41;
    }
LABEL_30:
    result = 16;
LABEL_34:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_41:
  __break(0x5512u);
  return reg_set_non_offload_country(is_country_code_valid, v29);
}

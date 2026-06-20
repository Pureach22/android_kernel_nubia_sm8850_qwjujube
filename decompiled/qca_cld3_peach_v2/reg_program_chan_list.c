__int64 __fastcall reg_program_chan_list(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x20
  __int64 psoc_obj; // x0
  bool v24; // w8
  const char *v25; // x2
  __int64 result; // x0
  const char *v27; // x3
  __int64 v28; // x0
  __int64 v29; // x20
  int v30; // w8
  __int64 v31; // x23
  _DWORD *v32; // x8
  unsigned int v33; // w20
  __int64 v34; // x22
  _DWORD *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  _BYTE v53[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int16 v54[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v55[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v56; // [xsp+18h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53[0] = 0;
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v25 = "%s:  pdev priv obj is NULL";
LABEL_11:
    v27 = "reg_program_chan_list";
LABEL_12:
    qdf_trace_msg(0x51u, 2u, v25, v13, v14, v15, v16, v17, v18, v19, v20, v27);
    goto LABEL_13;
  }
  v21 = *(_QWORD *)(a1 + 80);
  if ( !v21 )
  {
    qdf_trace_msg(0x51u, 2u, "%s: psoc is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "reg_program_chan_list");
    result = 4;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v22 = pdev_obj;
  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !psoc_obj )
  {
    v25 = "%s: psoc reg component is NULL";
    goto LABEL_11;
  }
  if ( *(_BYTE *)(psoc_obj + 91095) != 1 )
  {
    v55[0] = -1;
    v54[0] = -1;
    v28 = _qdf_mem_malloc(0x178u, "reg_program_chan_list_po", 2004);
    if ( !v28 )
    {
      result = 2;
      goto LABEL_14;
    }
    *(_QWORD *)v28 = v21;
    v29 = v28;
    *(_BYTE *)(v28 + 13) = *(_BYTE *)(a1 + 40);
    v30 = a2[4];
    switch ( v30 )
    {
      case 3:
        reg_get_rdpair_from_country_iso(a2, v55, (unsigned __int16 *)v54);
        break;
      case 2:
        if ( (unsigned int)reg_get_rdpair_from_regdmn_id(*(_WORD *)a2, v54) == 16 )
        {
          qdf_trace_msg(
            0x51u,
            2u,
            "%s: Failed to get regdmn idx for regdmn pair: %x",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "reg_program_chan_list_po",
            *(unsigned __int16 *)a2);
          v44 = 16;
LABEL_40:
          _qdf_mem_free(*(_QWORD *)(v29 + 64));
          _qdf_mem_free(*(_QWORD *)(v29 + 72));
          _qdf_mem_free(v29);
          result = v44;
          goto LABEL_14;
        }
        break;
      case 1:
        reg_get_rdpair_from_country_code(*(_WORD *)a2, v55, (unsigned __int16 *)v54);
        break;
    }
    if ( (unsigned int)reg_get_cur_reginfo(v29, v55[0], v54[0]) == 16 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: Unable to set country code\n",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "reg_program_chan_list_po");
      v44 = 16;
    }
    else
    {
      *(_BYTE *)(v29 + 21) = 0;
      reg_process_master_chan_list((__int64 *)v29);
      v44 = 0;
    }
    goto LABEL_40;
  }
  v24 = a2[4] != 3 || a2[2] != 79;
  *(_BYTE *)(v22 + 56760) = v24;
  v31 = *(_QWORD *)(v21 + 2128);
  if ( !v31 )
  {
    v25 = "%s: tx_ops is NULL";
    v27 = "reg_get_psoc_tx_ops";
    goto LABEL_12;
  }
  v32 = *(_DWORD **)(v31 + 984);
  v33 = *(unsigned __int8 *)(a1 + 40);
  if ( !v32 )
  {
    v53[0] = *(_BYTE *)(a1 + 40);
    if ( *(_QWORD *)(v31 + 952) )
      goto LABEL_30;
LABEL_13:
    result = 16;
    goto LABEL_14;
  }
  v34 = psoc_obj;
  if ( *(v32 - 1) != 13449260 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, _BYTE *))v32)(v21, v33, v53);
  psoc_obj = v34;
  if ( !*(_QWORD *)(v31 + 952) )
    goto LABEL_13;
LABEL_30:
  if ( v53[0] <= 2uLL )
  {
    *(_BYTE *)(psoc_obj + v53[0] + 91131) = 1;
    v35 = *(_DWORD **)(v31 + 952);
    if ( *(v35 - 1) != -1906615972 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *))v35)(v21, v33, a2);
    goto LABEL_14;
  }
  __break(0x5512u);
  return reg_get_current_cc(psoc_obj);
}

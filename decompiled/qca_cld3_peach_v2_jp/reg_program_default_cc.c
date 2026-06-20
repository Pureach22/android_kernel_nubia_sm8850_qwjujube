__int64 __fastcall reg_program_default_cc(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 v10; // w20
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x19
  char v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  __int16 v43; // w20
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int16 v52[2]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned __int16 v53[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v54; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v10 = a2;
  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = a2;
  v53[0] = -1;
  v52[0] = -1;
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_obj )
  {
    v21 = pdev_obj;
    v22 = _qdf_mem_malloc(0x178u, "reg_program_default_cc", 1917);
    if ( v22 )
    {
      v31 = *(_QWORD *)(a1 + 80);
      if ( v31 )
      {
        *(_QWORD *)v22 = v31;
        v32 = v22;
        v33 = *(_BYTE *)(a1 + 40);
        *(_BYTE *)(v22 + 12) = 1;
        *(_BYTE *)(v22 + 13) = v33;
        if ( v10 )
        {
          if ( (v10 & 0x8000) == 0 )
          {
            if ( (unsigned int)reg_get_rdpair_from_regdmn_id(v10, v52) == 16 )
            {
              qdf_trace_msg(
                0x51u,
                2u,
                "%s: Failed to get regdmn idx for regdmn pair: %x",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "reg_program_default_cc",
                v10);
LABEL_16:
              _qdf_mem_free(*(_QWORD *)(v32 + 64));
              _qdf_mem_free(*(_QWORD *)(v32 + 72));
              _qdf_mem_free(v32);
              result = 16;
              goto LABEL_19;
            }
            if ( (unsigned int)reg_get_cur_reginfo(v32, 0xFFFFu, v52[0]) == 16 )
            {
LABEL_15:
              qdf_trace_msg(
                0x51u,
                2u,
                "%s: Unable to set country code\n",
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                "reg_program_default_cc");
              goto LABEL_16;
            }
            *(_WORD *)(v21 + 56708) = v10;
LABEL_18:
            *(_BYTE *)(v32 + 21) = 0;
            reg_process_master_chan_list((__int64 *)v32);
            _qdf_mem_free(*(_QWORD *)(v32 + 64));
            _qdf_mem_free(*(_QWORD *)(v32 + 72));
            _qdf_mem_free(v32);
            result = 0;
            goto LABEL_19;
          }
        }
        else
        {
          reg_get_default_country(&v54);
          v10 = v54 | 0x8000;
          v54 |= 0x8000u;
        }
        v43 = v10 & 0x7FFF;
        reg_get_rdpair_from_country_code(v43, v53, (unsigned __int16 *)v52);
        if ( (unsigned int)reg_get_cur_reginfo(v32, v53[0], v52[0]) == 16 )
          goto LABEL_15;
        *(_WORD *)(v21 + 56712) = v43;
        goto LABEL_18;
      }
      qdf_trace_msg(0x51u, 2u, "%s: psoc is NULL", v23, v24, v25, v26, v27, v28, v29, v30, "reg_program_default_cc");
      result = 4;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: reg soc is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "reg_program_default_cc");
    result = 16;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}

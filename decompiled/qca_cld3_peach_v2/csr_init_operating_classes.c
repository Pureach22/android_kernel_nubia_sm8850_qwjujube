__int64 __fastcall csr_init_operating_classes(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  __int64 v37; // x22
  unsigned __int8 v38; // w19
  __int64 v39; // x9
  int v40; // w8
  int v41; // w12
  unsigned int v42; // w13
  __int64 v43; // x14
  unsigned int v44; // w16
  __int64 result; // x0
  _BYTE v46[4]; // [xsp+Ch] [xbp-34h] BYREF
  _BYTE v47[4]; // [xsp+10h] [xbp-30h] BYREF
  __int16 v48; // [xsp+14h] [xbp-2Ch] BYREF
  char v49; // [xsp+16h] [xbp-2Ah]
  __int64 v50; // [xsp+18h] [xbp-28h] BYREF
  __int64 v51; // [xsp+20h] [xbp-20h]
  __int64 v52; // [xsp+28h] [xbp-18h]
  __int64 v53; // [xsp+30h] [xbp-10h]
  __int64 v54; // [xsp+38h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 21624);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v49 = 0;
  v48 = 0;
  wlan_reg_read_current_country(v10, &v48, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Current Country = %s",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "csr_init_operating_classes",
    &v48);
  v19 = *(unsigned __int8 *)(a1 + 16604);
  v47[0] = 0;
  v46[0] = 0;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Num %s channels,  %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "csr_update_op_class_array",
    "20MHz",
    v19);
  if ( (_DWORD)v19 )
  {
    v36 = 4 * v19;
    v37 = 0;
    v38 = 0;
    do
    {
      if ( v38 >= 0x1Fu )
        goto LABEL_40;
      if ( v37 == 400 )
        goto LABEL_50;
      wlan_reg_freq_to_chan_op_class(
        *(_QWORD *)(a1 + 21632),
        *(_DWORD *)(a1 + 16608 + v37),
        1,
        1u,
        (__int64)v47,
        (__int64)v46);
      if ( (unsigned __int8)v50 != v47[0]
        && BYTE1(v50) != v47[0]
        && BYTE2(v50) != v47[0]
        && BYTE3(v50) != v47[0]
        && BYTE4(v50) != v47[0]
        && BYTE5(v50) != v47[0]
        && BYTE6(v50) != v47[0]
        && HIBYTE(v50) != v47[0]
        && (unsigned __int8)v51 != v47[0]
        && BYTE1(v51) != v47[0]
        && BYTE2(v51) != v47[0]
        && BYTE3(v51) != v47[0]
        && BYTE4(v51) != v47[0]
        && BYTE5(v51) != v47[0]
        && BYTE6(v51) != v47[0]
        && HIBYTE(v51) != v47[0]
        && (unsigned __int8)v52 != v47[0]
        && BYTE1(v52) != v47[0]
        && BYTE2(v52) != v47[0]
        && BYTE3(v52) != v47[0]
        && BYTE4(v52) != v47[0]
        && BYTE5(v52) != v47[0]
        && BYTE6(v52) != v47[0]
        && HIBYTE(v52) != v47[0]
        && (unsigned __int8)v53 != v47[0]
        && BYTE1(v53) != v47[0]
        && BYTE2(v53) != v47[0]
        && BYTE3(v53) != v47[0]
        && BYTE4(v53) != v47[0]
        && BYTE5(v53) != v47[0]
        && BYTE6(v53) != v47[0] )
      {
        v39 = v38++;
        *((_BYTE *)&v50 + v39) = v47[0];
      }
      v37 += 4;
    }
    while ( v36 != v37 );
    if ( v38 >= 2u )
    {
LABEL_40:
      v40 = 0;
      v41 = v38 - 1;
      while ( v40 >= v38 - 1 )
      {
LABEL_41:
        --v41;
        v40 = (unsigned __int8)v40 + 1;
        if ( v40 >= (unsigned int)(unsigned __int8)(v38 - 1) )
          goto LABEL_49;
      }
      v42 = (unsigned __int8)v50;
      v43 = 0;
      while ( v43 != 31 )
      {
        v44 = *((unsigned __int8 *)&v50 + v43 + 1);
        if ( v42 > v44 )
        {
          *((_BYTE *)&v50 + v43) = v44;
          *((_BYTE *)&v50 + v43 + 1) = v42;
        }
        else
        {
          v42 = *((unsigned __int8 *)&v50 + v43 + 1);
        }
        if ( v41 == ++v43 )
          goto LABEL_41;
      }
LABEL_50:
      __break(0x5512u);
    }
  }
  else
  {
    v38 = 0;
  }
LABEL_49:
  result = wlan_reg_dmn_set_curr_opclasses(v38, &v50, v28, v29, v30, v31, v32, v33, v34, v35);
  _ReadStatusReg(SP_EL0);
  return result;
}

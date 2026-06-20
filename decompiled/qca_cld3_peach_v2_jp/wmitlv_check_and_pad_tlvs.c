__int64 __fastcall wmitlv_check_and_pad_tlvs(
        unsigned int *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        _QWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w8
  unsigned __int64 v14; // x10
  unsigned int v17; // w27
  unsigned int v18; // w28
  unsigned int v20; // w9
  unsigned int *v21; // x11
  unsigned __int64 v22; // x12
  int v23; // w13
  unsigned __int64 v24; // x12
  const char *v25; // x5
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  __int64 v35; // x5
  unsigned int v36; // w24
  void *v37; // x0
  unsigned __int64 v38; // x20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w9
  __int64 v48; // x24
  int v49; // w21
  unsigned int v50; // w25
  unsigned int v51; // w22
  unsigned int v52; // w28
  unsigned int v53; // w27
  char *v54; // x26
  unsigned int v55; // w11
  int v56; // w12
  int v57; // w20
  int v58; // w22
  unsigned int v59; // w28
  char *v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x5
  char *v70; // x25
  unsigned int v71; // w21
  unsigned int v72; // w22
  __int64 v73; // x23
  char *v74; // x28
  size_t v75; // x2
  int v76; // w9
  size_t v77; // x20
  unsigned int v78; // w22
  char *v79; // x0
  bool v80; // zf
  __int64 result; // x0
  unsigned __int64 v82; // x8
  const char *v83; // x2
  __int64 v84; // x6
  const char *v85; // x2
  __int64 v86; // x5
  unsigned int v87; // [xsp+10h] [xbp-50h]
  int v88; // [xsp+14h] [xbp-4Ch]
  _QWORD *v89; // [xsp+18h] [xbp-48h]
  unsigned __int64 v90; // [xsp+20h] [xbp-40h]
  unsigned __int64 v91; // [xsp+28h] [xbp-38h]
  unsigned int v92; // [xsp+34h] [xbp-2Ch]
  unsigned int v93; // [xsp+38h] [xbp-28h]
  int v94; // [xsp+3Ch] [xbp-24h]
  __int64 v95; // [xsp+40h] [xbp-20h] BYREF
  __int64 v96; // [xsp+48h] [xbp-18h]
  unsigned int v97; // [xsp+50h] [xbp-10h]
  int v98; // [xsp+54h] [xbp-Ch]
  __int64 v99; // [xsp+58h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v13 = 1509;
  else
    v13 = 1058;
  v14 = 4232;
  v17 = a3;
  v18 = a2;
  v20 = 0;
  if ( a3 )
  {
    v14 = 6036;
    v21 = (unsigned int *)&cmd_attr_list;
  }
  else
  {
    v21 = (unsigned int *)&evt_attr_list;
  }
  v97 = 0;
  v95 = 0;
  v96 = 0;
  while ( 1 )
  {
    if ( v14 <= 4 * (unsigned __int64)v20 )
      __break(1u);
    v22 = v21[v20];
    v23 = v22 ^ a4;
    v24 = v22 >> 24;
    if ( (v23 & 0xFFFFFF) == 0 )
      break;
    v20 += v24 + 1;
    if ( v20 >= v13 )
    {
      if ( a3 )
        v25 = "Cmd";
      else
        v25 = "Evt";
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: Didn't found WMI TLV attribute definitions for %s:0x%x\n",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "wmitlv_get_attributes",
        "wmitlv_get_attributes",
        v25,
        a4);
      v34 = "%s: %s: ERROR: Couldn't get expected number of TLVs for Cmd=%d\n";
      v35 = a4;
      goto LABEL_15;
    }
  }
  v98 = v24;
  if ( a2 <= 3 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %s: ERROR: Incorrect param buf length passed\n",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wmitlv_check_and_pad_tlvs",
      "wmitlv_check_and_pad_tlvs");
    goto LABEL_78;
  }
  v36 = 16 * v24;
  v37 = (void *)_qdf_mem_malloc(16 * v24, "wmitlv_check_and_pad_tlvs", 530);
  *a5 = v37;
  if ( !v37 )
  {
    v34 = "%s: %s: Error: unable to alloc memory (size=%d) for TLV\n";
    v35 = v36;
LABEL_15:
    qdf_trace_msg(
      0x38u,
      2u,
      v34,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wmitlv_check_and_pad_tlvs",
      "wmitlv_check_and_pad_tlvs",
      v35);
    goto LABEL_78;
  }
  v38 = (unsigned __int64)v37;
  qdf_mem_set(v37, v36, 0);
  v47 = v98;
  if ( !v98 )
  {
    result = 0;
    goto LABEL_79;
  }
  v91 = v38;
  v48 = 0;
  LODWORD(v38) = 0;
  v49 = 4;
  v92 = v18;
  v93 = v17;
  v90 = v18;
  while ( 1 )
  {
    v50 = *a1;
    v51 = (unsigned __int16)*a1;
    if ( v51 > v18 - v49 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: TLV length overflow",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wmitlv_check_and_pad_tlvs",
        "wmitlv_check_and_pad_tlvs");
      goto LABEL_77;
    }
    v94 = v47;
    qdf_mem_set(&v95, 0x18u, 0);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *))wmitlv_get_attributes)(
                         v17,
                         a4,
                         (unsigned int)v48,
                         &v95) )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: No TLV attributes found for Cmd=%d Tag_order=%d\n",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wmitlv_check_and_pad_tlvs",
        "wmitlv_check_and_pad_tlvs",
        a4,
        (unsigned int)v48);
      goto LABEL_77;
    }
    v52 = HIWORD(v50);
    if ( HIWORD(v50) != HIDWORD(v95) )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: TLV has wrong tag in order for Cmd=0x%x. Given=%d, Expected=%d, total_tlv=%d, remaining tlv=%d.\n",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wmitlv_check_and_pad_tlvs",
        "wmitlv_check_and_pad_tlvs",
        a4,
        v52,
        v98,
        v94);
      goto LABEL_77;
    }
    if ( (v50 & 0xFFF00000) == 0x100000 )
    {
      v53 = v51;
    }
    else
    {
      v49 = v38;
      v53 = v51 + 4;
    }
    v54 = (char *)&a1[(v50 & 0xFFF00000) == 0x100000];
    if ( !HIDWORD(v96) )
      break;
    if ( v52 > 0x14 )
      goto LABEL_71;
    if ( ((1 << SBYTE2(v50)) & 0x1B0000) != 0 )
    {
      v55 = v53 / (unsigned int)v96;
LABEL_56:
      v18 = v92;
      v76 = 0;
      if ( v53 )
        v80 = 1;
      else
        v80 = HIDWORD(v96) == 0;
      if ( v80 )
        v70 = v54;
      else
        v70 = nullptr;
      goto LABEL_62;
    }
    if ( v52 != 18 )
    {
LABEL_71:
      v85 = "%s: %s ERROR Need to handle this tag ID for variable length %d\n";
      v86 = v52;
      goto LABEL_75;
    }
    if ( !v53 )
    {
      v55 = 0;
      goto LABEL_56;
    }
    v86 = (unsigned int)*(unsigned __int16 *)v54 + 4;
    if ( (unsigned int)v86 > v53 )
    {
      v85 = "%s: %s: Invalid in_tlv_len=%d";
      goto LABEL_75;
    }
    v55 = v53 / (unsigned int)v86;
    v57 = v86 - v96;
    if ( (_DWORD)v86 != (_DWORD)v96 )
    {
      v58 = *(unsigned __int16 *)v54;
      v59 = v53 / (unsigned int)v86;
      v60 = (char *)_qdf_mem_malloc((unsigned int)v96 * v55, "wmitlv_check_and_pad_tlvs", 712);
      v69 = (unsigned int)v96 * v59;
      if ( v60 )
      {
        v70 = v60;
        qdf_mem_set(v60, (unsigned int)v69, 0);
        v55 = v59;
        if ( v59 )
        {
          v87 = v59;
          v88 = v49;
          v71 = 0;
          v72 = v58 + 4;
          v89 = a5;
          v73 = v59;
          v74 = v70;
          do
          {
            if ( v57 <= 0 )
              v75 = v72;
            else
              v75 = (unsigned int)v96;
            qdf_mem_copy(v74, &v54[v71], v75);
            --v73;
            v71 += v72;
            v74 += (unsigned int)v96;
          }
          while ( v73 );
          v55 = v87;
          v49 = v88;
          a5 = v89;
        }
        v18 = v92;
        v76 = 1;
        goto LABEL_62;
      }
      v83 = "%s: %s: Error: unable to alloc memory (size=%d) for padding the TLV array %d\n";
      v84 = 18;
LABEL_73:
      qdf_trace_msg(
        0x38u,
        2u,
        v83,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "wmitlv_check_and_pad_tlvs",
        "wmitlv_check_and_pad_tlvs",
        v69,
        v84);
      goto LABEL_76;
    }
LABEL_52:
    if ( (v57 & 0x80000000) == 0 )
      goto LABEL_56;
    v77 = v53 - v57;
    v78 = v55;
    v79 = (char *)_qdf_mem_malloc(v77, "wmitlv_check_and_pad_tlvs", 918);
    if ( !v79 )
    {
      v83 = "%s: %s: Error: unable to alloc memory (size=%d) for padding the TLV %d\n";
      v69 = (unsigned int)v77;
      v84 = v52;
      goto LABEL_73;
    }
    v70 = v79;
    qdf_mem_set(v79, (unsigned int)v77, 0);
    qdf_mem_copy(v70, v54, v53);
    v18 = v92;
    v76 = 1;
    v55 = v78;
LABEL_62:
    v38 = v49 + v53;
    v49 = v38 + 4;
    result = 0;
    v82 = v91 + 16 * v48;
    *(_QWORD *)v82 = v70;
    *(_DWORD *)(v82 + 8) = v55;
    *(_DWORD *)(v82 + 12) = v76;
    if ( v38 + 4 <= v90 )
    {
      a1 = (unsigned int *)&v54[v53];
      v17 = v93;
      ++v48;
      v47 = v94 - 1;
      if ( v94 != 1 )
        continue;
    }
    goto LABEL_79;
  }
  v55 = v53 > 4;
  if ( v97 == 510 )
    v56 = 1;
  else
    v56 = v97;
  if ( v97 != 510 )
    v55 = v97;
  v57 = v53 - v96 * v56;
  if ( v52 != 18 || !v57 )
    goto LABEL_52;
  v85 = "%s: %s: ERROR: TLV (tag=%d) should be variable-length and not fixed length\n";
  v86 = 18;
LABEL_75:
  qdf_trace_msg(
    0x38u,
    2u,
    v85,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "wmitlv_check_and_pad_tlvs",
    "wmitlv_check_and_pad_tlvs",
    v86);
LABEL_76:
  v17 = v93;
LABEL_77:
  wmitlv_free_allocated_tlvs(v17 != 0, a4, a5);
  *a5 = 0;
LABEL_78:
  result = 0xFFFFFFFFLL;
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return result;
}

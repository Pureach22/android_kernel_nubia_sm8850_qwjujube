__int64 __fastcall wmitlv_check_tlv_params(
        _DWORD *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w8
  unsigned __int64 v13; // x10
  unsigned int v18; // w9
  _DWORD *v19; // x11
  unsigned int v20; // w12
  int v21; // w13
  unsigned int v22; // w12
  const char *v23; // x5
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x24
  unsigned int v34; // w23
  __int64 v35; // x8
  int v36; // w28
  __int64 v37; // x25
  unsigned int v38; // w26
  __int64 v39; // x7
  unsigned int v40; // w10
  unsigned __int16 *v41; // x11
  __int64 v42; // x9
  unsigned int v43; // w8
  const char *v44; // x2
  __int64 v45; // x5
  __int64 v46; // x6
  const char *v47; // x2
  __int64 v48; // x5
  __int64 v49; // x6
  int v50; // [xsp+0h] [xbp-40h]
  unsigned int v51; // [xsp+8h] [xbp-38h]
  unsigned int v52; // [xsp+10h] [xbp-30h]
  __int64 v53; // [xsp+20h] [xbp-20h] BYREF
  __int64 v54; // [xsp+28h] [xbp-18h]
  int v55; // [xsp+30h] [xbp-10h]
  unsigned int v56; // [xsp+34h] [xbp-Ch]
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v12 = 1509;
  else
    v12 = 1058;
  v13 = 6036;
  v18 = 0;
  if ( a3 )
  {
    v19 = &cmd_attr_list;
  }
  else
  {
    v13 = 4232;
    v19 = &evt_attr_list;
  }
  v55 = 0;
  v53 = 0;
  v54 = 0;
  while ( 1 )
  {
    if ( v13 <= 4 * (unsigned __int64)v18 )
      __break(1u);
    v20 = v19[v18];
    v21 = v20 ^ a4;
    v22 = HIBYTE(v20);
    if ( (v21 & 0xFFFFFF) == 0 )
      break;
    v18 += v22 + 1;
    if ( v18 >= v12 )
    {
      if ( a3 )
        v23 = "Cmd";
      else
        v23 = "Evt";
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: Didn't found WMI TLV attribute definitions for %s:0x%x\n",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wmitlv_get_attributes",
        "wmitlv_get_attributes",
        v23,
        a4);
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: Couldn't get expected number of TLVs for Cmd=%d\n",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wmitlv_check_tlv_params",
        "wmitlv_check_tlv_params",
        a4);
      goto LABEL_15;
    }
  }
  v56 = v22;
  if ( a2 < 4 )
  {
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  LODWORD(v33) = 0;
  v34 = 0;
  v35 = 4;
  while ( 1 )
  {
    v36 = *a1;
    v37 = (unsigned __int16)*a1;
    v38 = (unsigned __int16)HIWORD(*a1);
    if ( v35 + v37 > (unsigned __int64)a2 )
    {
      v47 = "%s: %s: ERROR: Invalid TLV length for Cmd=%d Tag_order=%d buf_idx=%d Tag:%d Len:%d TotalLen:%d\n";
      v52 = a2;
      v51 = (unsigned __int16)*a1;
      v48 = a4;
      v49 = v34;
      v39 = (unsigned int)v33;
      v50 = (unsigned __int16)HIWORD(*a1);
LABEL_56:
      qdf_trace_msg(
        0x38u,
        2u,
        v47,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wmitlv_check_tlv_params",
        "wmitlv_check_tlv_params",
        v48,
        v49,
        v39,
        v50,
        v51,
        v52);
      goto LABEL_15;
    }
    qdf_mem_set(&v53, 0x18u, 0);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *))wmitlv_get_attributes)(
                         a3,
                         a4,
                         v34,
                         &v53) )
    {
      v44 = "%s: %s: ERROR: No TLV attributes found for Cmd=%d Tag_order=%d\n";
      v45 = a4;
      v46 = v34;
      goto LABEL_55;
    }
    v39 = HIDWORD(v53);
    if ( v38 != HIDWORD(v53) )
    {
      v47 = "%s: %s: ERROR: TLV has wrong tag in order for Cmd=0x%x. Given=%d, Expected=%d.\n";
      v48 = a4;
      v49 = v38;
      goto LABEL_56;
    }
    if ( (v36 & 0xFFF00000) != 0x100000 )
    {
      if ( v37 + 4 != (unsigned int)v54 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: %s: ERROR: TLV has wrong length for Cmd=0x%x. Given=%zu, Expected=%d.\n",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "wmitlv_check_tlv_params",
          "wmitlv_check_tlv_params",
          a4);
        goto LABEL_15;
      }
      goto LABEL_43;
    }
    if ( !HIDWORD(v54) )
    {
      if ( v55 == 510 )
      {
        v44 = "%s: %s: ERROR: array_size can't be invalid for Array TLV Cmd=0x%x Tag=%d\n";
LABEL_54:
        v45 = a4;
        v46 = v38;
LABEL_55:
        qdf_trace_msg(
          0x38u,
          2u,
          v44,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "wmitlv_check_tlv_params",
          "wmitlv_check_tlv_params",
          v45,
          v46);
        goto LABEL_15;
      }
      v43 = v54 * v55;
      if ( v38 == 17 )
        v43 = (v43 + 3) & 0xFFFFFFFC;
      if ( (_DWORD)v37 != v43 )
      {
        v47 = "%s: %s: ERROR: TLV has wrong length for Cmd=0x%x. Tag_order=%d  Tag=%d, Given_Len:%d Expected_Len=%d.\n";
        v51 = v43;
        v48 = a4;
        v49 = v34;
        v39 = v38;
        v50 = v37;
        goto LABEL_56;
      }
      goto LABEL_43;
    }
    if ( v55 != 510 )
    {
      v44 = "%s: %s: ERROR: array_size should be invalid for Array TLV Cmd=0x%x Tag=%d\n";
      goto LABEL_54;
    }
    if ( (_DWORD)v37 )
      break;
LABEL_44:
    ++v34;
    v33 = (unsigned int)(v33 + v37 + 4);
    a1 = (_DWORD *)((char *)a1 + v37 + 4);
    v35 = v33 + 4;
    if ( v33 + 4 > (unsigned __int64)a2 )
      goto LABEL_17;
  }
  v39 = (unsigned int)v54;
  if ( (unsigned int)v37 % (unsigned int)v54 )
  {
    v47 = "%s: %s: ERROR: TLV length %d for Cmd=0x%x is not aligned to size of structure(%d bytes)\n";
    v48 = (unsigned int)v37;
    v49 = a4;
    goto LABEL_56;
  }
  if ( v38 != 18 )
  {
    if ( (v36 & 0x1E0000) != 0x100000 && v38 != 19 )
    {
      v44 = "%s: %s ERROR Need to handle the Array tlv %d for variable length for Cmd=0x%x\n";
      v45 = v38;
      v46 = a4;
      goto LABEL_55;
    }
    goto LABEL_43;
  }
  if ( (unsigned int)v54 > (unsigned int)v37 )
  {
LABEL_43:
    if ( (v37 & 3) != 0 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: %s: ERROR: TLV length %d for Cmd=0x%x is not aligned to %zu bytes\n",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wmitlv_check_tlv_params",
        "wmitlv_check_tlv_params",
        (unsigned int)v37,
        a4,
        4);
      goto LABEL_15;
    }
    goto LABEL_44;
  }
  v40 = 0;
  v41 = (unsigned __int16 *)(a1 + 1);
  while ( 1 )
  {
    v42 = *v41 + 4LL;
    if ( (_DWORD)v42 != (_DWORD)v54 )
      break;
    ++v40;
    v41 = (unsigned __int16 *)((char *)v41 + v42);
    if ( v40 >= (unsigned int)v37 / (unsigned int)v54 )
      goto LABEL_43;
  }
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: %s: ERROR: TLV has wrong length for Cmd=0x%x. Tag_order=%d  Tag=%d, Given_Len:%zu Expected_Len=%d.\n",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wmitlv_check_tlv_params",
    "wmitlv_check_tlv_params",
    a4,
    v34,
    18,
    v42,
    v54);
LABEL_15:
  result = 0xFFFFFFFFLL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

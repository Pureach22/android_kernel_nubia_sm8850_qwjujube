__int64 __fastcall send_scan_chan_list_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v12; // x23
  unsigned int v13; // w26
  unsigned __int16 *v14; // x24
  int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 v24; // w8
  __int16 v25; // w25
  unsigned int *v26; // x22
  unsigned int v27; // w24
  int v28; // w28
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x26
  __int64 v39; // x23
  __int64 v40; // x1
  __int64 (__fastcall *v41)(__int64, __int64); // x8
  int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int *v51; // x22
  unsigned int *v52; // x8
  int v53; // w9
  unsigned int v54; // w11
  unsigned int v55; // w9
  unsigned int v56; // w9
  int v57; // w9
  unsigned int v58; // w10
  unsigned int v59; // w9
  unsigned int v60; // w10
  int v61; // w9
  unsigned int v62; // w9
  int v63; // w9
  __int16 v64; // w10
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 result; // x0
  unsigned int v75; // w19
  _QWORD v76[2]; // [xsp+0h] [xbp-D0h] BYREF

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Total chan %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wmi_scan_chanlist_dump",
    *((unsigned __int16 *)a2 + 2),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  if ( !*((_WORD *)a2 + 2) )
    goto LABEL_49;
  v12 = 0;
  v13 = 0;
  v14 = (unsigned __int16 *)(a2 + 5);
  do
  {
    v16 = scnprintf(
            (char *)v76 + v13,
            192LL - v13,
            " %d[%d][%d][%d]",
            *((_DWORD *)v14 - 1),
            *((char *)v14 + 18),
            (*v14 >> 2) & 1,
            (*v14 >> 10) & 1);
    if ( v15 < 1 )
      break;
    v13 += v15;
    if ( v13 >= 0xAC )
    {
      qdf_trace_msg(0x31u, 8u, "Chan[TXPwr][DFS][nan_disabled]:%s", v16, v17, v18, v19, v20, v21, v22, v23, v76);
      v13 = 0;
    }
    ++v12;
    v14 += 18;
  }
  while ( v12 < *((unsigned __int16 *)a2 + 2) );
  if ( v13 )
    qdf_trace_msg(0x31u, 8u, "Chan[TXPwr][DFS]:%s", v16, v17, v18, v19, v20, v21, v22, v23, v76);
  v24 = *((_WORD *)a2 + 2);
  if ( !v24 )
  {
LABEL_49:
    result = 0;
    goto LABEL_50;
  }
  v25 = 0;
  v26 = a2 + 3;
  while ( 2 )
  {
    if ( v24 >= 0x3Au )
      v27 = 58;
    else
      v27 = v24;
    *((_WORD *)a2 + 2) = v24 - v27;
    v28 = 28 * v27;
    v29 = wmi_buf_alloc_fl(a1, 28 * v27 + 20, "send_scan_chan_list_cmd_tlv", 0x1380u);
    if ( !v29 )
    {
      result = 2;
      goto LABEL_50;
    }
    v38 = *(_DWORD **)(v29 + 224);
    v39 = v29;
    *v38 = 5177356;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: no of channels = %d, len = %d, is_c2c_supp = %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "send_scan_chan_list_cmd_tlv",
      v27,
      (unsigned int)(v28 + 20),
      *((unsigned __int8 *)a2 + 8));
    if ( v25 )
      v38[2] |= 1u;
    if ( *((_BYTE *)a2 + 7) == 1 )
      v38[2] |= 2u;
    if ( *((_BYTE *)a2 + 8) == 1 )
      v38[2] |= 8u;
    v40 = *a2;
    v41 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
    if ( *((_DWORD *)v41 - 1) != -2112860426 )
      __break(0x8228u);
    v42 = v41(a1, v40);
    v38[3] = v42;
    qdf_mtrace(49, 100, 0x183u, v42, 0);
    v51 = v26 + 4;
    v38[1] = v27;
    v38[4] = v28 | 0x120000;
    v52 = v38 + 11;
    do
    {
      *(v52 - 6) = 5242904;
      *(v52 - 5) = *(v51 - 3);
      *(v52 - 4) = *v51;
      *(v52 - 3) = v51[1];
      v61 = *((unsigned __int16 *)v51 - 4);
      if ( (v61 & 0x10) != 0 )
      {
        *(v52 - 2) |= 0x80u;
        v61 = *((unsigned __int16 *)v51 - 4);
        if ( (v61 & 4) == 0 )
        {
LABEL_27:
          if ( (v61 & 8) == 0 )
            goto LABEL_28;
          goto LABEL_39;
        }
      }
      else if ( (v61 & 4) == 0 )
      {
        goto LABEL_27;
      }
      *(v52 - 2) |= 0x400u;
      v61 = *((unsigned __int16 *)v51 - 4);
      if ( (v61 & 8) == 0 )
      {
LABEL_28:
        if ( (v61 & 0x100) == 0 )
          goto LABEL_29;
        goto LABEL_40;
      }
LABEL_39:
      *(v52 - 2) |= 0x10000u;
      v61 = *((unsigned __int16 *)v51 - 4);
      if ( (v61 & 0x100) == 0 )
      {
LABEL_29:
        if ( (v61 & 0x800) == 0 )
          goto LABEL_30;
        goto LABEL_41;
      }
LABEL_40:
      *(v52 - 2) |= 0x20000u;
      v61 = *((unsigned __int16 *)v51 - 4);
      if ( (v61 & 0x800) == 0 )
      {
LABEL_30:
        if ( (v61 & 0x40) == 0 )
          goto LABEL_32;
LABEL_31:
        *(v52 - 2) |= 0x1000u;
        v61 = *((unsigned __int16 *)v51 - 4);
        goto LABEL_32;
      }
LABEL_41:
      *(v52 - 2) |= 0x200000u;
      v61 = *((unsigned __int16 *)v51 - 4);
      if ( (v61 & 0x40) != 0 )
        goto LABEL_31;
LABEL_32:
      v62 = *(v52 - 2) & 0xFFFFFFC0 | (v61 << 6) & 0x800;
      *(v52 - 2) = v62;
      v63 = *(v51 - 1) | v62;
      *(v52 - 2) = v63;
      v64 = *((_WORD *)v51 - 4);
      if ( (v64 & 1) != 0 )
      {
        v63 |= 0x4000u;
        *(v52 - 2) = v63;
        v64 = *((_WORD *)v51 - 4);
        if ( (v64 & 2) == 0 )
        {
LABEL_34:
          if ( (v64 & 0x200) != 0 )
            goto LABEL_45;
          goto LABEL_35;
        }
      }
      else if ( (v64 & 2) == 0 )
      {
        goto LABEL_34;
      }
      v63 |= 0x8000u;
      *(v52 - 2) = v63;
      v64 = *((_WORD *)v51 - 4);
      if ( (v64 & 0x200) != 0 )
      {
LABEL_45:
        v63 |= 0x40000u;
        *(v52 - 2) = v63;
        if ( (*(_WORD *)(v51 - 2) & 0x400) == 0 )
          goto LABEL_24;
        goto LABEL_46;
      }
LABEL_35:
      if ( (v64 & 0x400) == 0 )
        goto LABEL_24;
LABEL_46:
      *(v52 - 2) = v63 | 0x80000;
LABEL_24:
      v53 = *(v52 - 1);
      v54 = *v52;
      --v27;
      *(v52 - 1) = v53 & 0xFFFFFF00;
      v55 = v53 & 0xFFFF0000 | *((unsigned __int8 *)v51 + 9);
      *(v52 - 1) = v55;
      v56 = v55 & 0xFF0000FF | (*((unsigned __int8 *)v51 + 8) << 8);
      *(v52 - 1) = v56;
      v57 = v56 | (*((unsigned __int8 *)v51 + 10) << 16);
      *(v52 - 1) = v57;
      *v52 = v54 & 0xFFFFFF00;
      v58 = v54 & 0xFFFFFF00 | *((unsigned __int8 *)v51 + 11);
      *(v52 - 1) = v57 & 0xFFFFFF;
      *v52 = v58;
      *(v52 - 1) = v57 & 0xFFFFFF | (*((unsigned __int8 *)v51 + 12) << 24);
      *v52 = v58 & 0xFFFF00FF;
      v59 = v58 & 0xFF0000FF | (*((unsigned __int8 *)v51 + 10) << 8);
      *v52 = v59;
      v60 = v51[4];
      v51 += 9;
      *v52 = v59 & 0xFF00FFFF | ((unsigned __int8)v60 << 16);
      v52 += 7;
    }
    while ( v27 );
    v65 = wmi_unified_cmd_send_fl(
            a1,
            v39,
            v28 + 20,
            0x3003u,
            "send_scan_chan_list_cmd_tlv",
            0x13F4u,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50);
    if ( !v65 )
    {
      v24 = *((_WORD *)a2 + 2);
      v26 = v51 - 4;
      ++v25;
      if ( !v24 )
        goto LABEL_49;
      continue;
    }
    break;
  }
  v75 = v65;
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Failed to send WMI_SCAN_CHAN_LIST_CMDID",
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    "send_scan_chan_list_cmd_tlv");
  wmi_buf_free();
  result = v75;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}

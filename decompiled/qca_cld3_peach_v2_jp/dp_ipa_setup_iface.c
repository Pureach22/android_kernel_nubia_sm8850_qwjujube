__int64 __fastcall dp_ipa_setup_iface(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        __int64 a4,
        int a5,
        unsigned __int8 a6,
        char a7,
        int a8)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // [xsp+8h] [xbp-B8h]
  _QWORD *v45; // [xsp+10h] [xbp-B0h] BYREF
  __int64 v46; // [xsp+18h] [xbp-A8h]
  __int64 v47; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v48; // [xsp+28h] [xbp-98h]
  __int64 v49; // [xsp+30h] [xbp-90h]
  __int64 v50; // [xsp+38h] [xbp-88h] BYREF
  __int64 v51; // [xsp+40h] [xbp-80h]
  __int64 v52; // [xsp+48h] [xbp-78h]
  __int128 v53; // [xsp+50h] [xbp-70h] BYREF
  __int128 v54; // [xsp+60h] [xbp-60h] BYREF
  __int64 v55; // [xsp+70h] [xbp-50h] BYREF
  _QWORD v56[2]; // [xsp+78h] [xbp-48h] BYREF
  _QWORD v57[2]; // [xsp+88h] [xbp-38h] BYREF
  __int64 v58; // [xsp+98h] [xbp-28h]
  __int64 v59; // [xsp+A0h] [xbp-20h]
  __int64 v60; // [xsp+A8h] [xbp-18h]
  __int64 v61; // [xsp+B0h] [xbp-10h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = 0;
  v60 = 0;
  v57[1] = 0;
  v58 = 0;
  v56[1] = 0;
  v57[0] = 0;
  v55 = 0;
  v56[0] = 0;
  v45 = nullptr;
  v46 = 0;
  *(_QWORD *)((char *)&v54 + 6) = 0;
  *(_QWORD *)&v54 = 0;
  *(_QWORD *)((char *)&v53 + 6) = 0;
  *(_QWORD *)&v53 = 0;
  LOWORD(v52) = 0;
  v50 = 0;
  v51 = 0;
  LOWORD(v49) = 0;
  v47 = 0;
  v48 = 0;
  qdf_mem_set(&v55, 0x40u, 0);
  qdf_mem_set(&v50, 0x12u, 0);
  qdf_mem_set(&v47, 0x12u, 0);
  if ( a3 )
  {
    v22 = *a3;
    v23 = a3[1];
    v24 = a3[2];
    v25 = a3[5];
  }
  else
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
  }
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Add Partial hdr: %s, %02x:%02x:%02x:**:**:%02x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_ipa_setup_iface",
    a2,
    v22,
    v23,
    v24,
    v25,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54);
  qdf_mem_set(&v45, 0x10u, 0);
  qdf_ether_addr_copy((_WORD *)&v54 + 3, a3);
  WORD6(v54) = 8;
  v45 = &v54;
  LOWORD(v46) = 14;
  HIDWORD(v46) = 1;
  v55 = a2;
  qdf_mem_copy(v56, &v45, 0x10u);
  LODWORD(v58) = a5;
  BYTE4(v58) = 1;
  HIDWORD(v60) = a8;
  LODWORD(v59) = a6 << 8;
  HIDWORD(v59) = 65280;
  v34 = qdf_trace_msg(
          0x45u,
          8u,
          "%s: registering for session_id: %u",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "dp_ipa_setup_iface");
  if ( (a7 & 1) != 0 )
  {
    qdf_mem_copy(&v53, &v54, 0xEu);
    WORD6(v53) = -8826;
    v45 = &v53;
    v34 = (__int64)qdf_mem_copy(v57, &v45, 0x10u);
  }
  if ( (wlan_ipa_is_vlan_enabled(v34) & 1) != 0 )
  {
    qdf_mem_set(&v45, 0x10u, 0);
    qdf_ether_addr_copy((_WORD *)&v50 + 3, a3);
    v45 = &v50;
    LOWORD(v52) = 8;
    WORD2(v51) = 129;
    LOWORD(v46) = 18;
    if ( (a7 & 1) != 0 )
    {
      qdf_mem_copy(&v47, &v50, 0x12u);
      WORD2(v48) = 129;
      LOWORD(v49) = -8826;
      v45 = &v47;
    }
  }
  result = ipa_wdi_reg_intf_per_inst(&v55);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: ipa_wdi_reg_intf: register IPA interface failed: ret=%d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "dp_ipa_setup_iface",
      (unsigned int)result);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

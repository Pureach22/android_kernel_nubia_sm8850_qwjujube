__int64 __fastcall dp_post_dhcp_ind(
        __int64 a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v13; // w21
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _DWORD *v34; // x8
  __int64 v35; // x22
  int v36; // w9
  _DWORD *v37; // x8
  __int64 v38; // x0
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x20
  _BYTE v49[2]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v50; // [xsp+Ah] [xbp-16h] BYREF
  int v51; // [xsp+12h] [xbp-Eh]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v13 = a3 & 1;
  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v14 = *a2;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = 0;
  }
  v51 = 0;
  v50 = 0;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Post DHCP indication,sta_mac=%02x:%02x:%02x:**:**:%02x ,  start=%u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_post_dhcp_ind",
    v14,
    v15,
    v16,
    v17,
    a3 & 1);
  if ( (is_dp_link_valid(a1, v18, v19, v20, v21, v22, v23, v24, v25) & 1) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: NULL DP link", v26, v27, v28, v29, v30, v31, v32, v33, "dp_post_dhcp_ind");
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  v34 = *(_DWORD **)(a1 + 32);
  v35 = *(_QWORD *)v34;
  if ( (*(_BYTE *)(*(_QWORD *)v34 + 371LL) & 1) == 0 && *(_BYTE *)(v35 + 872) == 1 )
  {
    v48 = jiffies;
    if ( dp_post_dhcp_ind___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Device is system suspended, skip DHCP Ind",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "dp_post_dhcp_ind");
      dp_post_dhcp_ind___last_ticks = v48;
    }
    goto LABEL_12;
  }
  v36 = v34[7];
  v49[0] = v13;
  v49[1] = v36;
  qdf_mem_copy(&v50, v34 + 5, 6u);
  qdf_mem_copy((char *)&v50 + 6, a2, 6u);
  v37 = *(_DWORD **)(v35 + 816);
  v38 = *(unsigned __int8 *)(a1 + 24);
  if ( *(v37 - 1) != 1446629237 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _BYTE *))v37)(v38, v49);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Post DHCP Ind MSG fail", v40, v41, v42, v43, v44, v45, v46, v47, "dp_post_dhcp_ind");
    result = 5;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

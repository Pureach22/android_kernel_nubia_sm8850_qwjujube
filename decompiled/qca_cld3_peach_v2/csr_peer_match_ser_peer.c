__int64 __fastcall csr_peer_match_ser_peer(
        unsigned int a1,
        char a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        unsigned __int8 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  int v20; // w8
  int v21; // w9
  int v22; // w3
  int v23; // w4
  int v24; // w5
  int v25; // w6
  int v26; // w7
  int v27; // w8
  int v28; // w9
  int v29; // w10
  bool v31; // zf
  bool v32; // zf
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w8
  int v38; // w9
  int v39; // w10
  int v40; // w11
  int v41; // w12
  const char *v42; // x4
  __int64 v43; // x6
  __int64 v44; // x7
  int v45; // w8
  int v46; // w9
  int v47; // w10
  int v48; // w11
  int v49; // w12
  int v50; // w13
  __int64 result; // x0
  __int64 v52; // [xsp+0h] [xbp-B0h]
  __int64 v53; // [xsp+8h] [xbp-A8h]
  __int64 v54; // [xsp+10h] [xbp-A0h]
  _QWORD v55[11]; // [xsp+58h] [xbp-58h] BYREF

  v55[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(_DWORD *)a4;
  v21 = *((unsigned __int16 *)a4 + 2);
  memset(v55, 0, 78);
  if ( !(v20 | v21) )
    goto LABEL_8;
  if ( !a4 )
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
    if ( a6 )
      goto LABEL_4;
LABEL_6:
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v29 = 0;
    goto LABEL_7;
  }
  v22 = *a4;
  v23 = a4[1];
  v24 = a4[2];
  v25 = a4[5];
  if ( !a6 )
    goto LABEL_6;
LABEL_4:
  v26 = *a6;
  v27 = a6[1];
  v28 = a6[2];
  v29 = a6[5];
LABEL_7:
  a7 = scnprintf(
         v55,
         26,
         " mld: %02x:%02x:%02x:**:**:%02x ser_mld %02x:%02x:%02x:**:**:%02x",
         v22,
         v23,
         v24,
         v25,
         v26,
         v27,
         v28,
         v29);
LABEL_8:
  if ( *(_DWORD *)a3 != *(_DWORD *)a5 || *((unsigned __int16 *)a3 + 2) != *((unsigned __int16 *)a5 + 2) )
  {
    if ( !(*(_DWORD *)a4 | *((unsigned __int16 *)a4 + 2))
      || (*(_DWORD *)a4 == *(_DWORD *)a6
        ? (v31 = *((unsigned __int16 *)a4 + 2) == *((unsigned __int16 *)a6 + 2))
        : (v31 = 0),
          !v31) )
    {
      if ( !(*(_DWORD *)a6 | *((unsigned __int16 *)a6 + 2))
        || (*(_DWORD *)a3 == *(_DWORD *)a6
          ? (v32 = *((unsigned __int16 *)a3 + 2) == *((unsigned __int16 *)a6 + 2))
          : (v32 = 0),
            !v32) )
      {
        if ( !(*(_DWORD *)a4 | *((unsigned __int16 *)a4 + 2)) )
          goto LABEL_43;
        if ( *(_DWORD *)a4 != *(_DWORD *)a5 || *((unsigned __int16 *)a4 + 2) != *((unsigned __int16 *)a5 + 2) )
          goto LABEL_43;
      }
      if ( a3 )
      {
        v34 = *a3;
        v35 = a3[1];
        v36 = a3[2];
        v37 = a3[5];
        if ( a5 )
        {
LABEL_30:
          v38 = *a5;
          v39 = a5[1];
          v40 = a5[2];
          v41 = a5[5];
LABEL_42:
          LODWORD(v54) = v39;
          LODWORD(v53) = v38;
          LODWORD(v52) = v37;
          qdf_trace_msg(
            0x34u,
            4u,
            "%s: cmd %d MLD and peer MAC matching!!!, peer %02x:%02x:%02x:**:**:%02x ser_peer %02x:%02x:%02x:**:**:%02x%s",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "csr_peer_match_ser_peer",
            a1,
            v34,
            v35,
            v36,
            v52,
            v53,
            v54,
            v40,
            v41,
            v55);
LABEL_43:
          result = 0;
          goto LABEL_44;
        }
      }
      else
      {
        v36 = 0;
        v34 = 0;
        v35 = 0;
        v37 = 0;
        if ( a5 )
          goto LABEL_30;
      }
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
      goto LABEL_42;
    }
  }
  if ( (a2 & 1) != 0 )
    v42 = "Act";
  else
    v42 = "Pnd";
  if ( !a3 )
  {
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v46 = 0;
    if ( a5 )
      goto LABEL_36;
LABEL_38:
    v49 = 0;
    v47 = 0;
    v48 = 0;
    v50 = 0;
    goto LABEL_39;
  }
  v43 = *a3;
  v44 = a3[1];
  v45 = a3[2];
  v46 = a3[5];
  if ( !a5 )
    goto LABEL_38;
LABEL_36:
  v47 = *a5;
  v48 = a5[1];
  v49 = a5[2];
  v50 = a5[5];
LABEL_39:
  LODWORD(v54) = v47;
  LODWORD(v53) = v46;
  LODWORD(v52) = v45;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: %s cmd %d found for peer %02x:%02x:%02x:**:**:%02x ser_peer %02x:%02x:%02x:**:**:%02x%s",
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    "csr_peer_match_ser_peer",
    v42,
    a1,
    v43,
    v44,
    v52,
    v53,
    v54,
    v48,
    v49,
    v50,
    v55);
  result = 1;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall sch_qos_update_broadcast(__int64 a1, __int64 a2, const void *a3)
{
  _BYTE *v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  unsigned int v16; // w1
  unsigned int *v17; // x8
  unsigned int v18; // w21
  __int64 v19; // x8
  __int64 v20; // x26
  __int64 v21; // x28
  __int64 result; // x0
  __int64 v23; // x23
  __int64 v24; // x20
  int v25; // w3
  unsigned int v26; // w22
  char v27; // w19
  _BYTE *v28; // x27
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w0
  _DWORD *v38; // x10
  unsigned __int8 *v39; // x9
  unsigned int v40; // w8
  int v41; // w10
  unsigned int v42; // w10
  unsigned int v43; // w11
  int v44; // w13
  unsigned int v45; // w14
  bool v46; // cc
  unsigned __int8 v47; // w12
  int v48; // w11
  int v49; // w10
  unsigned int v50; // w11
  int v51; // w13
  unsigned int v52; // w14
  unsigned __int8 v53; // w12
  char v54; // w11
  char v55; // w10
  int v56; // w11
  int v57; // w12
  __int64 v58; // x20
  unsigned __int8 v59; // w21
  __int64 v60; // x10
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w22
  __int64 v70; // x20
  __int64 v71; // x19
  __int64 v72; // x21
  _BYTE *v73; // x10
  unsigned int v74; // w9
  char v75; // w13
  char v76; // w11
  __int64 v77; // x5
  char v78; // w11
  int v79; // w8
  __int64 v80; // [xsp+0h] [xbp-160h]
  __int64 v81; // [xsp+8h] [xbp-158h]
  _BYTE *v82; // [xsp+18h] [xbp-148h]
  __int64 v83; // [xsp+30h] [xbp-130h]
  __int64 v84; // [xsp+38h] [xbp-128h]
  _DWORD s[68]; // [xsp+40h] [xbp-120h] BYREF
  __int64 v86; // [xsp+150h] [xbp-10h]

  v6 = (_BYTE *)(a2 + 7156);
  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( a3 && v6[2915] )
  {
    qdf_mem_copy(s, a3, 0x110u);
  }
  else if ( (unsigned int)sch_get_params(a1, s, 0) )
  {
    v15 = "%s: QosUpdateBroadcast: failed";
    v16 = 8;
    goto LABEL_66;
  }
  v17 = (unsigned int *)(a2 + 7232);
  v83 = a1;
  if ( !a2 )
    v17 = (unsigned int *)(a1 + 4840);
  v18 = *v17;
  if ( *v17 == 2 )
  {
    v19 = 16;
    v20 = 14;
    v21 = 12;
  }
  else if ( v18 == 1 )
  {
    v19 = 11;
    v20 = 9;
    v21 = 7;
  }
  else
  {
    v19 = 6;
    v20 = 4;
    v21 = 2;
  }
  v84 = v19;
  result = _qdf_mem_malloc(0x200u, "sch_qos_update_broadcast", 301);
  if ( result )
  {
    v23 = result;
    v82 = v6;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = (_BYTE *)(a2 + 7116);
    while ( 1 )
    {
      v38 = &s[17 * v24];
      v39 = &v28[5 * v24];
      v40 = *v39;
      if ( ((v40 >> 4) & 1) != (unsigned __int8)*v38 )
      {
        v27 = 1;
        v40 = (16 * (*v38 & 1)) | v40 & 0xFFFFFFEF;
        *v39 = v40;
      }
      v41 = v38[1];
      if ( (v40 & 0xF) != (unsigned __int8)v41 )
      {
        v40 = v40 & 0xFFFFFFF0 | v41 & 0xF;
        v27 = 1;
        *v39 = v40;
      }
      v42 = v39[1];
      v43 = (unsigned __int16)(s[17 * v24 + 1 + v21] + ((unsigned __int16)s[17 * v24 + v21] << 8));
      if ( !((unsigned __int16)s[17 * v24 + 1 + v21] + ((unsigned __int16)s[17 * v24 + v21] << 8)) )
        break;
      LOBYTE(v44) = 0;
      v45 = (unsigned __int16)(s[17 * v24 + 1 + v21] + ((unsigned __int16)s[17 * v24 + v21] << 8));
      do
      {
        v46 = v45 > 1;
        LOBYTE(v44) = v44 + 1;
        v45 >>= 1;
      }
      while ( v46 );
      v44 = (unsigned __int8)v44;
      if ( (unsigned __int8)v44 >= 0xFu )
        v44 = 15;
      if ( (v42 & 0xF) != v44 )
      {
        v47 = 0;
        do
        {
          v46 = v43 > 1;
          ++v47;
          v43 >>= 1;
        }
        while ( v46 );
LABEL_31:
        v48 = v47;
        v49 = v42 & 0xF0;
        v27 = 1;
        if ( v47 >= 0xFu )
          v48 = 15;
        v42 = v48 | v49;
        v39[1] = v42;
      }
LABEL_34:
      v50 = (unsigned __int16)(s[17 * v24 + 1 + v20] + ((unsigned __int16)s[17 * v24 + v20] << 8));
      if ( (unsigned __int16)s[17 * v24 + 1 + v20] + ((unsigned __int16)s[17 * v24 + v20] << 8) )
      {
        LOBYTE(v51) = 0;
        v52 = (unsigned __int16)(s[17 * v24 + 1 + v20] + ((unsigned __int16)s[17 * v24 + v20] << 8));
        do
        {
          v46 = v52 > 1;
          LOBYTE(v51) = v51 + 1;
          v52 >>= 1;
        }
        while ( v46 );
        v51 = (unsigned __int8)v51;
        if ( (unsigned __int8)v51 >= 0xFu )
          v51 = 15;
        if ( v42 >> 4 == v51 )
          goto LABEL_48;
        v53 = 0;
        do
        {
          v46 = v50 > 1;
          ++v53;
          v50 >>= 1;
        }
        while ( v46 );
        goto LABEL_45;
      }
      if ( v42 >= 0x10 )
      {
        v53 = 0;
LABEL_45:
        v54 = v53;
        v55 = v42 & 0xF;
        v27 = 1;
        if ( v53 >= 0xFu )
          v54 = 15;
        LOBYTE(v42) = v55 | (16 * v54);
        v39[1] = v42;
      }
LABEL_48:
      v56 = *((unsigned __int16 *)v39 + 1);
      v57 = s[17 * v24 + v84];
      if ( v56 != (unsigned __int16)v57 )
      {
        v27 = 1;
        LOWORD(v56) = s[17 * v24 + v84];
        *((_WORD *)v39 + 1) = v57;
      }
      v29 = scnprintf(
              v23 + v26,
              512 - v26,
              "AC[%d]: AIFSN %d ACM %d CWmin %d CWmax %d TxOp %d, ",
              v25,
              v40 & 0xF,
              (v40 >> 4) & 1,
              v42 & 0xF,
              (unsigned __int8)v42 >> 4,
              (unsigned __int16)v56);
      ++v24;
      v26 += v37;
      v25 = v24;
      if ( v24 == 4 )
      {
        qdf_trace_msg(0x35u, 8u, "QosUpdBcast: mode %d, %s", v29, v30, v31, v32, v33, v34, v35, v36, v18, v23);
        _qdf_mem_free(v23);
        if ( !*(_WORD *)(v83 + 3992) )
          goto LABEL_62;
        v58 = *(_QWORD *)(v83 + 12264);
        v59 = 0;
        while ( 1 )
        {
          v60 = v58 + 10792LL * v59;
          if ( *(_BYTE *)(v60 + 70) == 1
            && *(unsigned __int16 *)(v60 + 8) != *(unsigned __int16 *)(a2 + 8)
            && *(_DWORD *)(v60 + 284) == *(_DWORD *)(a2 + 284)
            && *(_DWORD *)(v60 + 88) == 2 )
          {
            break;
          }
          if ( *(unsigned __int16 *)(v83 + 3992) <= (unsigned int)++v59 )
            goto LABEL_62;
        }
        if ( v60 && (unsigned int)qdf_mem_cmp(v28, (const void *)(v60 + 7096), 0x14u) )
        {
          v69 = 0;
          v70 = v58 + 10792LL * v59;
          v71 = 0;
          v72 = v70 + 7096;
          do
          {
            v73 = &v28[v71];
            v74 = *(unsigned __int8 *)(v72 + v71);
            v75 = v28[v71 + 1];
            v76 = v28[v71] & 0xEF | (16 * ((v74 & 0x10) != 0));
            *v73 = v76;
            v77 = *(_BYTE *)(v72 + v71) & 0xF;
            *v73 = v76 & 0xF0 | *(_BYTE *)(v72 + v71) & 0xF;
            v78 = *(_BYTE *)(v72 + v71 + 1);
            v73[1] = v75 & 0xF0 | v78 & 0xF;
            v79 = *(unsigned __int8 *)(v72 + v71 + 1) >> 4;
            v73[1] = *(_BYTE *)(v72 + v71 + 1) & 0xF0 | v78 & 0xF;
            LODWORD(v73) = *(unsigned __int16 *)(v70 + v71 + 7098);
            *(_WORD *)(a2 + v71 + 7118) = (_WORD)v73;
            LODWORD(v81) = (_DWORD)v73;
            LODWORD(v80) = v79;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: QoSUpdateBCast changed again due to concurrent INFRA STA session: AC :%d: AIFSN: %d, ACM %d, CWmin %d,"
              " CWmax %d, TxOp %d",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "broadcast_wmm_of_concurrent_sta_session",
              v69,
              v77,
              (v74 >> 4) & 1,
              v78 & 0xF,
              v80,
              v81);
            v71 += 5;
            ++v69;
          }
          while ( v71 != 20 );
LABEL_63:
          ++*v82;
        }
        else
        {
LABEL_62:
          if ( (v27 & 1) != 0 )
            goto LABEL_63;
        }
        result = ((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(v83, a2);
        if ( (_DWORD)result )
        {
          v15 = "%s: Unable to set beacon fields!";
          v16 = 2;
LABEL_66:
          result = qdf_trace_msg(0x35u, v16, v15, v7, v8, v9, v10, v11, v12, v13, v14, "sch_qos_update_broadcast");
        }
        goto LABEL_67;
      }
    }
    if ( (v42 & 0xF) == 0 )
      goto LABEL_34;
    v47 = 0;
    goto LABEL_31;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}

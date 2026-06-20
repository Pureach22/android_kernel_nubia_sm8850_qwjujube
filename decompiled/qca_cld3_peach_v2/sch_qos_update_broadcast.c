__int64 __fastcall sch_qos_update_broadcast(__int64 a1, __int64 a2, const void *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  unsigned int v15; // w1
  unsigned int *v16; // x8
  unsigned int v17; // w20
  __int64 v18; // x8
  __int64 v19; // x26
  __int64 v20; // x28
  __int64 result; // x0
  __int64 v22; // x23
  __int64 v23; // x20
  int v24; // w3
  unsigned int v25; // w22
  char v26; // w19
  _BYTE *v27; // x27
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w0
  _DWORD *v37; // x10
  unsigned __int8 *v38; // x9
  unsigned int v39; // w8
  int v40; // w10
  unsigned int v41; // w10
  unsigned int v42; // w11
  int v43; // w13
  unsigned int v44; // w14
  bool v45; // cc
  unsigned __int8 v46; // w12
  int v47; // w11
  int v48; // w10
  unsigned int v49; // w11
  int v50; // w13
  unsigned int v51; // w14
  unsigned __int8 v52; // w12
  char v53; // w11
  char v54; // w10
  int v55; // w11
  int v56; // w12
  __int64 v57; // x20
  unsigned __int8 v58; // w21
  __int64 v59; // x10
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w22
  __int64 v69; // x20
  __int64 v70; // x19
  __int64 v71; // x21
  _BYTE *v72; // x10
  unsigned int v73; // w9
  char v74; // w13
  char v75; // w11
  __int64 v76; // x5
  char v77; // w11
  int v78; // w8
  __int64 v79; // [xsp+0h] [xbp-150h]
  __int64 v80; // [xsp+8h] [xbp-148h]
  unsigned int v81; // [xsp+14h] [xbp-13Ch]
  __int64 v82; // [xsp+20h] [xbp-130h]
  __int64 v83; // [xsp+28h] [xbp-128h]
  _DWORD s[68]; // [xsp+30h] [xbp-120h] BYREF
  __int64 v85; // [xsp+140h] [xbp-10h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( a3 && *(_BYTE *)(a2 + 13280) )
  {
    qdf_mem_copy(s, a3, 0x110u);
  }
  else if ( (unsigned int)sch_get_params(a1, s, 0) )
  {
    v14 = "%s: QosUpdateBroadcast: failed";
    v15 = 8;
    goto LABEL_66;
  }
  v16 = (unsigned int *)(a2 + 7232);
  v82 = a1;
  if ( !a2 )
    v16 = (unsigned int *)(a1 + 4840);
  v17 = *v16;
  if ( *v16 == 2 )
  {
    v18 = 16;
    v19 = 14;
    v20 = 12;
  }
  else if ( v17 == 1 )
  {
    v18 = 11;
    v19 = 9;
    v20 = 7;
  }
  else
  {
    v18 = 6;
    v19 = 4;
    v20 = 2;
  }
  v83 = v18;
  result = _qdf_mem_malloc(0x200u, "sch_qos_update_broadcast", 301);
  if ( result )
  {
    v22 = result;
    v81 = v17;
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = (_BYTE *)(a2 + 7116);
    while ( 1 )
    {
      v37 = &s[17 * v23];
      v38 = &v27[5 * v23];
      v39 = *v38;
      if ( ((v39 >> 4) & 1) != (unsigned __int8)*v37 )
      {
        v26 = 1;
        v39 = (16 * (*v37 & 1)) | v39 & 0xFFFFFFEF;
        *v38 = v39;
      }
      v40 = v37[1];
      if ( (v39 & 0xF) != (unsigned __int8)v40 )
      {
        v39 = v39 & 0xFFFFFFF0 | v40 & 0xF;
        v26 = 1;
        *v38 = v39;
      }
      v41 = v38[1];
      v42 = (unsigned __int16)(s[17 * v23 + 1 + v20] + ((unsigned __int16)s[17 * v23 + v20] << 8));
      if ( !((unsigned __int16)s[17 * v23 + 1 + v20] + ((unsigned __int16)s[17 * v23 + v20] << 8)) )
        break;
      LOBYTE(v43) = 0;
      v44 = (unsigned __int16)(s[17 * v23 + 1 + v20] + ((unsigned __int16)s[17 * v23 + v20] << 8));
      do
      {
        v45 = v44 > 1;
        LOBYTE(v43) = v43 + 1;
        v44 >>= 1;
      }
      while ( v45 );
      v43 = (unsigned __int8)v43;
      if ( (unsigned __int8)v43 >= 0xFu )
        v43 = 15;
      if ( (v41 & 0xF) != v43 )
      {
        v46 = 0;
        do
        {
          v45 = v42 > 1;
          ++v46;
          v42 >>= 1;
        }
        while ( v45 );
LABEL_31:
        v47 = v46;
        v48 = v41 & 0xF0;
        v26 = 1;
        if ( v46 >= 0xFu )
          v47 = 15;
        v41 = v47 | v48;
        v38[1] = v41;
      }
LABEL_34:
      v49 = (unsigned __int16)(s[17 * v23 + 1 + v19] + ((unsigned __int16)s[17 * v23 + v19] << 8));
      if ( (unsigned __int16)s[17 * v23 + 1 + v19] + ((unsigned __int16)s[17 * v23 + v19] << 8) )
      {
        LOBYTE(v50) = 0;
        v51 = (unsigned __int16)(s[17 * v23 + 1 + v19] + ((unsigned __int16)s[17 * v23 + v19] << 8));
        do
        {
          v45 = v51 > 1;
          LOBYTE(v50) = v50 + 1;
          v51 >>= 1;
        }
        while ( v45 );
        v50 = (unsigned __int8)v50;
        if ( (unsigned __int8)v50 >= 0xFu )
          v50 = 15;
        if ( v41 >> 4 == v50 )
          goto LABEL_48;
        v52 = 0;
        do
        {
          v45 = v49 > 1;
          ++v52;
          v49 >>= 1;
        }
        while ( v45 );
        goto LABEL_45;
      }
      if ( v41 >= 0x10 )
      {
        v52 = 0;
LABEL_45:
        v53 = v52;
        v54 = v41 & 0xF;
        v26 = 1;
        if ( v52 >= 0xFu )
          v53 = 15;
        LOBYTE(v41) = v54 | (16 * v53);
        v38[1] = v41;
      }
LABEL_48:
      v55 = *((unsigned __int16 *)v38 + 1);
      v56 = s[17 * v23 + v83];
      if ( v55 != (unsigned __int16)v56 )
      {
        v26 = 1;
        LOWORD(v55) = s[17 * v23 + v83];
        *((_WORD *)v38 + 1) = v56;
      }
      v28 = scnprintf(
              v22 + v25,
              512 - v25,
              "AC[%d]: AIFSN %d ACM %d CWmin %d CWmax %d TxOp %d, ",
              v24,
              v39 & 0xF,
              (v39 >> 4) & 1,
              v41 & 0xF,
              (unsigned __int8)v41 >> 4,
              (unsigned __int16)v55);
      ++v23;
      v25 += v36;
      v24 = v23;
      if ( v23 == 4 )
      {
        qdf_trace_msg(0x35u, 8u, "QosUpdBcast: mode %d, %s", v28, v29, v30, v31, v32, v33, v34, v35, v81, v22);
        _qdf_mem_free(v22);
        if ( !*(_WORD *)(v82 + 3992) )
          goto LABEL_62;
        v57 = *(_QWORD *)(v82 + 12264);
        v58 = 0;
        while ( 1 )
        {
          v59 = v57 + 14000LL * v58;
          if ( *(_BYTE *)(v59 + 70) == 1
            && *(unsigned __int16 *)(v59 + 8) != *(unsigned __int16 *)(a2 + 8)
            && *(_DWORD *)(v59 + 284) == *(_DWORD *)(a2 + 284)
            && *(_DWORD *)(v59 + 88) == 2 )
          {
            break;
          }
          if ( *(unsigned __int16 *)(v82 + 3992) <= (unsigned int)++v58 )
            goto LABEL_62;
        }
        if ( v59 && (unsigned int)qdf_mem_cmp(v27, (const void *)(v59 + 7096), 0x14u) )
        {
          v68 = 0;
          v69 = v57 + 14000LL * v58;
          v70 = 0;
          v71 = v69 + 7096;
          do
          {
            v72 = &v27[v70];
            v73 = *(unsigned __int8 *)(v71 + v70);
            v74 = v27[v70 + 1];
            v75 = v27[v70] & 0xEF | (16 * ((v73 & 0x10) != 0));
            *v72 = v75;
            v76 = *(_BYTE *)(v71 + v70) & 0xF;
            *v72 = v75 & 0xF0 | *(_BYTE *)(v71 + v70) & 0xF;
            v77 = *(_BYTE *)(v71 + v70 + 1);
            v72[1] = v74 & 0xF0 | v77 & 0xF;
            v78 = *(unsigned __int8 *)(v71 + v70 + 1) >> 4;
            v72[1] = *(_BYTE *)(v71 + v70 + 1) & 0xF0 | v77 & 0xF;
            LODWORD(v72) = *(unsigned __int16 *)(v69 + v70 + 7098);
            *(_WORD *)(a2 + v70 + 7118) = (_WORD)v72;
            LODWORD(v80) = (_DWORD)v72;
            LODWORD(v79) = v78;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: QoSUpdateBCast changed again due to concurrent INFRA STA session: AC :%d: AIFSN: %d, ACM %d, CWmin %d,"
              " CWmax %d, TxOp %d",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "broadcast_wmm_of_concurrent_sta_session",
              v68,
              v76,
              (v73 >> 4) & 1,
              v77 & 0xF,
              v79,
              v80);
            v70 += 5;
            ++v68;
          }
          while ( v70 != 20 );
LABEL_63:
          ++*(_BYTE *)(a2 + 7156);
        }
        else
        {
LABEL_62:
          if ( (v26 & 1) != 0 )
            goto LABEL_63;
        }
        result = sch_set_fixed_beacon_fields(v82, a2);
        if ( (_DWORD)result )
        {
          v14 = "%s: Unable to set beacon fields!";
          v15 = 2;
LABEL_66:
          result = qdf_trace_msg(0x35u, v15, v14, v6, v7, v8, v9, v10, v11, v12, v13, "sch_qos_update_broadcast");
        }
        goto LABEL_67;
      }
    }
    if ( (v41 & 0xF) == 0 )
      goto LABEL_34;
    v46 = 0;
    goto LABEL_31;
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}

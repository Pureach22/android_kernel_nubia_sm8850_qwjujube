__int64 __fastcall lim_decide_ap_protection(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int v26; // w25
  int v27; // w27
  int v28; // w26
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x22
  unsigned __int8 *v42; // x28
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 v47; // x8
  __int64 v48; // x21
  const char *v49; // x2
  unsigned int v50; // w1
  const char *v51; // x2
  __int64 v52; // x23
  __int64 v53; // x23
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x23
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x23
  __int64 v72; // x23
  __int16 v73; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v74; // [xsp+8h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)(a3 + 14) = 0;
  v73 = 0;
  result = dph_lookup_hash_entry(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2, &v73, a4 + 360);
  if ( !result )
    goto LABEL_57;
  if ( !a4 )
    goto LABEL_8;
  v25 = *(_DWORD *)(a4 + 168);
  if ( v25 )
  {
    if ( v25 == 1 && *(_BYTE *)(a4 + 155) == 1 && (*(_BYTE *)(result + 32) & 8) == 0 )
    {
      result = lim_update_11a_protection(a1, 1, 0, a3, a4);
      goto LABEL_57;
    }
LABEL_8:
    v26 = 0;
    goto LABEL_9;
  }
  if ( *(_DWORD *)(a4 + 7232) != 2 || *(_BYTE *)(a4 + 155) || (*(_WORD *)result & 4) != 0 )
  {
    v26 = 0;
  }
  else
  {
    v53 = result;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Enabling protection from 11B",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_decide_ap_protection");
    v26 = 1;
    lim_enable11g_protection(a1, 1, 0, a3, a4, v54, v55, v56, v57, v58, v59, v60, v61);
    result = v53;
  }
  if ( *(_BYTE *)(a4 + 155) == 1 )
  {
    if ( *(_WORD *)result & 4 | *(_BYTE *)(result + 32) & 8 )
    {
      if ( (*(_BYTE *)(result + 32) & 8) == 0 )
      {
        v72 = result;
        lim_enable_ht_protection_from11g(a1, 1, 0, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24);
        result = v72;
        v26 = 2;
      }
    }
    else
    {
      v62 = result;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Enabling protection from 11B",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_decide_ap_protection");
      v26 = 1;
      lim_enable11g_protection(a1, 1, 0, a3, a4, v63, v64, v65, v66, v67, v68, v69, v70);
      result = v62;
    }
  }
LABEL_9:
  if ( *(_BYTE *)(a4 + 155) != 1 || (*(_BYTE *)(result + 32) & 8) == 0 )
  {
    v27 = 0;
    v28 = 1;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(result + 344) & 1) != 0 )
  {
    v28 = 1;
    if ( (*(_BYTE *)(result + 346) & 8) != 0 )
      goto LABEL_48;
LABEL_46:
    if ( *(_BYTE *)(a4 + 160) )
    {
      v71 = result;
      lim_enable_ht20_protection(a1, 1, 0, a3, a4);
      result = v71;
      v26 = 3;
    }
    goto LABEL_48;
  }
  v52 = result;
  lim_enable_ht_non_gf_protection(a1, 1, 0, a3, a4);
  result = v52;
  v28 = 0;
  if ( (*(_BYTE *)(v52 + 346) & 8) == 0 )
    goto LABEL_46;
LABEL_48:
  if ( (*(_BYTE *)(result + 344) & 0x10) != 0 )
  {
    v27 = 0;
  }
  else
  {
    lim_enable_ht_lsig_txop_protection(a1, 0, 0, a3, a4);
    v27 = 1;
  }
LABEL_12:
  if ( a2 )
  {
    v29 = *a2;
    v30 = a2[1];
    v31 = a2[2];
    v32 = a2[5];
  }
  else
  {
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Associated STA addr is: %02x:%02x:%02x:**:**:%02x",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "lim_update_prot_sta_params",
    v29,
    v30,
    v31,
    v32);
  v41 = 0;
  v42 = (unsigned __int8 *)(a4 + 1236);
  do
  {
    if ( *v42 )
    {
      if ( v42 == (unsigned __int8 *)-1LL )
      {
        v45 = 0;
        v43 = 0;
        v44 = 0;
        v46 = 0;
      }
      else
      {
        v43 = v42[1];
        v44 = v42[2];
        v45 = v42[3];
        v46 = v42[6];
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Addr:%02x:%02x:%02x:**:**:%02x",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_update_prot_sta_params",
        v43,
        v44,
        v45,
        v46);
      if ( !(unsigned int)qdf_mem_cmp(v42 + 1, a2, 6u) )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: matching cache entry at: %d already active",
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   "lim_update_prot_sta_params",
                   (unsigned int)v41);
        goto LABEL_57;
      }
    }
    ++v41;
    v42 += 12;
  }
  while ( v41 != 32 );
  v47 = 0;
  while ( 1 )
  {
    v48 = a4 + v47;
    if ( !*(_BYTE *)(a4 + v47 + 1236) )
      break;
    v47 += 12;
    if ( v47 == 384 )
    {
      v49 = "%s: No space in ProtStaCache";
      v50 = 2;
      goto LABEL_56;
    }
  }
  result = (__int64)qdf_mem_copy((void *)(v48 + 1237), a2, 6u);
  *(_DWORD *)(v48 + 1244) = v26;
  *(_BYTE *)(v48 + 1236) = 1;
  switch ( v26 )
  {
    case 3:
      v51 = "%s: HT20,";
      ++*(_BYTE *)(a4 + 444);
      break;
    case 2:
      v51 = "%s: 11G,";
      ++*(_BYTE *)(a4 + 440);
      break;
    case 1:
      v51 = "%s: 11B,";
      ++*(_BYTE *)(a4 + 436);
      break;
    default:
      if ( !v28 )
        goto LABEL_54;
LABEL_32:
      if ( !v27 )
        goto LABEL_57;
      goto LABEL_55;
  }
  result = qdf_trace_msg(0x35u, 8u, v51, v33, v34, v35, v36, v37, v38, v39, v40, "lim_update_prot_sta_params");
  if ( v28 )
    goto LABEL_32;
LABEL_54:
  ++*(_BYTE *)(a4 + 442);
  result = qdf_trace_msg(0x35u, 8u, "%s: NonGf,", v33, v34, v35, v36, v37, v38, v39, v40, "lim_update_prot_sta_params");
  if ( !v27 )
    goto LABEL_57;
LABEL_55:
  v49 = "%s: !lsigTxopSupported";
  v50 = 8;
  ++*(_BYTE *)(a4 + 446);
LABEL_56:
  result = qdf_trace_msg(0x35u, v50, v49, v33, v34, v35, v36, v37, v38, v39, v40, "lim_update_prot_sta_params");
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}

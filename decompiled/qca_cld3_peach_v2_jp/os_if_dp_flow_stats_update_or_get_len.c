__int64 __fastcall os_if_dp_flow_stats_update_or_get_len(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x27
  int v6; // w0
  __int64 v7; // x1
  char v8; // w23
  __int64 result; // x0
  __int64 v10; // x8
  int v11; // w19
  int v12; // w25
  __int64 v13; // x21
  __int64 v14; // x22
  int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  _WORD *v25; // x22
  __int64 v26; // x21
  __int64 v27; // x23
  int v28; // w0
  _WORD *v29; // x23
  int v30; // w24
  int v31; // w19
  int v32; // w8
  const char *v33; // x3
  int v34; // w22
  __int64 v35; // x19
  __int64 v36; // x21
  _WORD *v37; // x8
  int v38; // w26
  __int64 v39; // x8
  __int64 v40; // x27
  _WORD *v41; // x25
  _WORD *v42; // x28
  __int64 v43; // x22
  __int64 v44; // x19
  __int64 v45; // x21
  __int64 v46; // x19
  __int64 v47; // x21
  __int64 v48; // x19
  __int64 v49; // x21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w23
  _WORD *v59; // x19
  int v60; // w0
  int v61; // w21
  __int64 v62; // x19
  __int64 v63; // x24
  int v64; // w0
  __int64 v65; // x21
  int v66; // w0
  int v67; // w19
  __int64 v68; // x23
  __int64 v69; // x24
  int v70; // w0
  int v71; // w0
  int v72; // w19
  __int64 v73; // x23
  __int64 v74; // x24
  int v75; // w0
  int v76; // w0
  int v77; // w8
  _WORD *v78; // [xsp+8h] [xbp-28h]
  char v79; // [xsp+10h] [xbp-20h]
  __int64 v80; // [xsp+18h] [xbp-18h]
  int v81; // [xsp+20h] [xbp-10h]
  _BYTE v82[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v83; // [xsp+28h] [xbp-8h]

  v3 = a2;
  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = os_if_dp_fill_flow_tuple(a1, a2 + 4);
  if ( v6 < 0 )
    goto LABEL_79;
  v8 = a3;
  if ( (a3 & 4) != 0 )
  {
    if ( a1 )
    {
      v31 = v6;
      v82[0] = 0;
      v32 = nla_put(a1, 2, 1, v82);
      v6 = v31;
      if ( v32 )
      {
        v24 = "%s: STC: traffic type put failed";
        v33 = "os_if_dp_flow_stats_update_or_get_len";
LABEL_78:
        qdf_trace_msg(0x48u, 2u, v24, v16, v17, v18, v19, v20, v21, v22, v23, v33);
        goto LABEL_79;
      }
    }
    result = (unsigned int)(v6 + 24);
    if ( (v8 & 1) == 0 )
    {
LABEL_4:
      if ( (v8 & 2) == 0 )
        goto LABEL_80;
LABEL_5:
      v10 = *(unsigned __int8 *)(v3 + 1688);
      v11 = v10 - 1;
      if ( (unsigned __int64)(v10 - 1) >= 3 )
      {
        __break(0x5512u);
        return os_if_dp_fill_flow_tuple(result, v7);
      }
      v12 = result;
      if ( a1 )
      {
        v13 = *(_QWORD *)(a1 + 216);
        v14 = *(unsigned int *)(a1 + 208);
        v15 = nla_put(a1, 32772, 0, 0);
        v24 = "%s: STC: burst_samples start put fail";
        if ( v15 < 0 )
          goto LABEL_77;
        v25 = (_WORD *)(v13 + v14);
        if ( !v25 )
          goto LABEL_77;
        v26 = *(_QWORD *)(a1 + 216);
        v27 = *(unsigned int *)(a1 + 208);
        v28 = nla_put(a1, 32769, 0, 0);
        v24 = "%s: STC: burst_samples:txrx start put fail";
        if ( v28 < 0 )
          goto LABEL_77;
        v29 = (_WORD *)(v26 + v27);
        v30 = 0;
        if ( !v29 )
          goto LABEL_77;
      }
      else
      {
        v25 = nullptr;
        v29 = nullptr;
        v30 = 8;
      }
      v65 = v3 + 216LL * v11 + 1256;
      v66 = os_if_dp_fill_txrx_one_win_samples(a1, v65);
      if ( v66 < 0 )
      {
LABEL_79:
        result = 4294967274LL;
        goto LABEL_80;
      }
      v67 = v66 + v30;
      if ( a1 && v29 )
      {
        *v29 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v29;
      }
      else if ( !a1 )
      {
        v67 += 4;
        goto LABEL_70;
      }
      v68 = *(_QWORD *)(a1 + 216);
      v69 = *(unsigned int *)(a1 + 208);
      v70 = nla_put(a1, 32770, 0, 0);
      v24 = "%s: STC: burst_samples:ul start put fail";
      if ( v70 < 0 )
        goto LABEL_77;
      v29 = (_WORD *)(v68 + v69);
      if ( !v29 )
        goto LABEL_77;
LABEL_70:
      v71 = os_if_dp_fill_burst_stats(a1, v65 + 120, v24);
      if ( v71 < 0 )
        goto LABEL_79;
      v72 = v71 + v67;
      if ( a1 && v29 )
      {
        *v29 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v29;
      }
      else if ( !a1 )
      {
        v72 += 4;
LABEL_82:
        v76 = os_if_dp_fill_burst_stats(a1, v65 + 168, v24);
        if ( (v76 & 0x80000000) == 0 )
        {
          v77 = v76 + v72;
          if ( a1 && v29 )
            *v29 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v29;
          if ( a1 )
          {
            if ( v25 )
              *v25 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v25;
          }
          if ( (v77 & 0x80000000) == 0 )
          {
            result = (unsigned int)(v77 + v12);
            goto LABEL_80;
          }
        }
        goto LABEL_79;
      }
      v73 = *(_QWORD *)(a1 + 216);
      v74 = *(unsigned int *)(a1 + 208);
      v75 = nla_put(a1, 32771, 0, 0);
      v24 = "%s: STC: burst_samples:dl start put fail";
      if ( v75 < 0 || (v29 = (_WORD *)(v73 + v74)) == nullptr )
      {
LABEL_77:
        v33 = "os_if_dp_fill_burst_samples";
        goto LABEL_78;
      }
      goto LABEL_82;
    }
  }
  else
  {
    result = (unsigned int)(v6 + 16);
    if ( (a3 & 1) == 0 )
      goto LABEL_4;
  }
  v34 = result;
  if ( a1 )
  {
    v35 = *(_QWORD *)(a1 + 216);
    v36 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 32771, 0, 0) & 0x80000000) != 0 || (v37 = (_WORD *)(v35 + v36), v38 = 0, !(v35 + v36)) )
    {
LABEL_19:
      v24 = "%s: STC: txrx samples start put failed";
LABEL_20:
      v33 = "os_if_dp_fill_txrx_samples";
      goto LABEL_78;
    }
  }
  else
  {
    v37 = nullptr;
    v38 = 4;
  }
  v78 = v37;
  v79 = v8;
  v39 = v3;
  v40 = 0;
  v81 = v34;
  v41 = nullptr;
  v42 = nullptr;
  v43 = v39 + 176;
  v80 = v39;
  do
  {
    if ( a1 )
    {
      v44 = *(_QWORD *)(a1 + 216);
      v45 = *(unsigned int *)(a1 + 208);
      if ( (nla_put(a1, (unsigned int)v40 | 0x8000, 0, 0) & 0x80000000) != 0 || (v42 = (_WORD *)(v44 + v45)) == nullptr )
      {
        v24 = "%s: STC: txrx samples array start put failed";
        goto LABEL_20;
      }
      v46 = *(_QWORD *)(a1 + 216);
      v47 = *(unsigned int *)(a1 + 208);
      if ( (nla_put(a1, 32769, 0, 0) & 0x80000000) != 0 )
        goto LABEL_19;
      v41 = (_WORD *)(v46 + v47);
      if ( !(v46 + v47) )
        goto LABEL_19;
      v48 = *(_QWORD *)(a1 + 216);
      v49 = *(unsigned int *)(a1 + 208);
      v58 = 0;
      if ( (nla_put(a1, 0x8000, 0, 0) & 0x80000000) != 0 || (v59 = (_WORD *)(v48 + v49)) == nullptr )
      {
LABEL_57:
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: STC: win array[%d] start put failed",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "os_if_dp_fill_txrx_win_samples",
          v58);
        goto LABEL_79;
      }
    }
    else
    {
      v59 = nullptr;
      v38 += 8;
      v58 = 4;
    }
    v60 = os_if_dp_fill_txrx_one_win_samples(a1, v43 - 120);
    if ( v60 < 0 )
      goto LABEL_79;
    v61 = v60 + v58;
    if ( a1 && v59 )
    {
      *v59 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v59;
    }
    else if ( !a1 )
    {
      v61 += 4;
      goto LABEL_40;
    }
    v62 = *(_QWORD *)(a1 + 216);
    v63 = *(unsigned int *)(a1 + 208);
    v58 = 1;
    if ( (nla_put(a1, 32769, 0, 0) & 0x80000000) != 0 )
      goto LABEL_57;
    v59 = (_WORD *)(v62 + v63);
    if ( !v59 )
      goto LABEL_57;
LABEL_40:
    v64 = os_if_dp_fill_txrx_one_win_samples(a1, v43);
    if ( v64 < 0 )
      goto LABEL_79;
    if ( a1 && v59 )
      *v59 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v59;
    if ( v64 + v61 < 0 )
      goto LABEL_79;
    if ( a1 && v41 )
      *v41 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v41;
    if ( a1 && v42 )
      *v42 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v42;
    ++v40;
    v38 += v64 + v61;
    v43 += 240;
  }
  while ( v40 != 5 );
  if ( a1 && v78 )
    *v78 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v78;
  v3 = v80;
  if ( v38 < 0 )
    goto LABEL_79;
  result = (unsigned int)(v38 + v81);
  if ( (v79 & 2) != 0 )
    goto LABEL_5;
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}

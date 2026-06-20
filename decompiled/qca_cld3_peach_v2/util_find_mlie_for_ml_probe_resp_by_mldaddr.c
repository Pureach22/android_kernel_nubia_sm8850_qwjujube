__int64 __fastcall util_find_mlie_for_ml_probe_resp_by_mldaddr(
        __int64 a1,
        unsigned __int64 a2,
        _QWORD *a3,
        unsigned __int64 *a4,
        __int64 a5)
{
  __int64 result; // x0
  unsigned __int8 *v7; // x9
  unsigned __int64 v8; // x19
  unsigned __int8 *v9; // x26
  __int64 v10; // x25
  _QWORD *v11; // x20
  unsigned __int64 *v12; // x21
  unsigned __int8 *v13; // x8
  unsigned __int64 v14; // x24
  unsigned __int64 v15; // x27
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x22
  unsigned __int64 v25; // x23
  _BYTE *v26; // x26
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v36; // w19
  unsigned __int64 v37; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 *v38; // [xsp+10h] [xbp-20h] BYREF
  int v39; // [xsp+18h] [xbp-18h] BYREF
  __int16 v40; // [xsp+1Ch] [xbp-14h]
  int v41; // [xsp+20h] [xbp-10h]
  __int16 v42; // [xsp+24h] [xbp-Ch]
  __int64 v43; // [xsp+28h] [xbp-8h]

  result = 29;
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = a5;
  v42 = WORD2(a5);
  v40 = 0;
  v39 = 0;
  if ( !a1 || !a2 || !a3 || !a4 )
    goto LABEL_35;
  v7 = nullptr;
  v8 = a1 + a2;
  *a3 = 0;
  *a4 = 0;
  while ( 2 )
  {
    v9 = &v7[a1];
    if ( !&v7[a1] )
    {
      result = 29;
      break;
    }
    v10 = a1;
    v11 = a3;
    v12 = a4;
    v13 = nullptr;
    v14 = a2;
    v15 = a2 - (_QWORD)v7;
    v37 = 0;
    v38 = nullptr;
    while ( 1 )
    {
      result = util_find_mlie(&v13[(_QWORD)v9], v15 - (_QWORD)v13, &v38, &v37);
      if ( (_DWORD)result )
        goto LABEL_35;
      v24 = v38;
      if ( !v38 )
      {
        result = 0;
        goto LABEL_35;
      }
      v25 = v37;
      if ( !v37 )
      {
        v36 = 29;
        goto LABEL_34;
      }
      if ( v37 < 5 || *v38 != 255 || v38[2] != 107 )
      {
        v36 = 4;
LABEL_34:
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Unable to get Multi-link element variant",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "util_find_mlie_by_variant");
        result = v36;
        goto LABEL_35;
      }
      if ( (*(_WORD *)(v38 + 3) & 7u) >= 5 )
      {
        v36 = 27;
        goto LABEL_34;
      }
      if ( (*(_WORD *)(v38 + 3) & 7) == 0 )
        break;
      v13 = (unsigned __int8 *)(&v38[v37] - v9);
      if ( (unsigned __int64)v13 >= v15 )
        goto LABEL_32;
    }
    qdf_mem_set(&v39, 6u, 0);
    v26 = v24 + 2;
    if ( *v24 != 255 || *v26 != 107 || (*(_WORD *)(v24 + 3) & 7) != 0 )
    {
LABEL_32:
      result = 4;
      break;
    }
    if ( v25 < 0xC || v24[5] < 7u )
    {
      result = 27;
    }
    else
    {
      qdf_mem_copy(&v39, v24 + 6, 6u);
      if ( v39 == v41 && v40 == v42 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Basic variant Multi-link element with MLD mac addr %02x:%02x:%02x:**:**:%02x found",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "util_find_mlie_for_ml_probe_resp_by_mldaddr",
          (unsigned __int8)v39,
          BYTE1(v39),
          BYTE2(v39),
          HIBYTE(v40));
        result = 4;
        if ( (unsigned __int64)v26 <= v8 && (unsigned __int64)&v24[v25] <= v8 )
        {
          result = 0;
          *v11 = v24;
          *v12 = v25;
        }
      }
      else
      {
        a1 = v10;
        a2 = v14;
        v7 = &v24[v25 - v10];
        result = 0;
        a4 = v12;
        a3 = v11;
        if ( (unsigned __int64)v7 < v14 )
          continue;
      }
    }
    break;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}

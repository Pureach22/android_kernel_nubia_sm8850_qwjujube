__int64 __fastcall cm_print_candidate_list(_QWORD *a1)
{
  _QWORD *v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  _QWORD *v11; // x1
  const char *v12; // x21
  const char *v13; // x20
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  const char *v18; // x7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *v27; // x28
  __int64 v28; // x25
  unsigned int v29; // w0
  __int64 v30; // x8
  unsigned int v31; // w23
  const char *v32; // x19
  const char *v33; // x20
  unsigned __int64 v34; // x21
  unsigned __int8 *v35; // x24
  int v36; // w3
  int v37; // w4
  int v38; // w5
  int v39; // w6
  int v40; // w0
  __int64 v41; // [xsp+0h] [xbp-150h]
  __int64 v42; // [xsp+8h] [xbp-148h]
  __int64 v43; // [xsp+18h] [xbp-138h]
  _QWORD *v44; // [xsp+28h] [xbp-128h]
  _QWORD *v45; // [xsp+30h] [xbp-120h] BYREF
  _QWORD *v46; // [xsp+38h] [xbp-118h] BYREF
  _QWORD v47[30]; // [xsp+40h] [xbp-110h] BYREF
  _QWORD v48[4]; // [xsp+130h] [xbp-20h]

  v1 = a1;
  v48[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = nullptr;
  v46 = nullptr;
  *(_QWORD *)((char *)v48 + 7) = 0;
  v48[0] = 0;
  memset(v47, 0, sizeof(v47));
  if ( !(unsigned int)qdf_list_peek_front(a1, &v46) )
  {
    result = qdf_trace_msg(
               0x68u,
               8u,
               "Sorted candidate list for SSID: %.*s",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               *(unsigned __int8 *)(v46[3] + 13LL),
               v46[3] + 14LL);
    v11 = v46;
    if ( !v46 )
      goto LABEL_3;
    v12 = "MLO";
    v13 = "NON MLO";
    v44 = v1;
    while ( 1 )
    {
      qdf_list_peek_next(v1, v11, &v45);
      v27 = v46;
      v28 = v46[3];
      if ( !*(_BYTE *)(v28 + 1918) )
        goto LABEL_20;
      v29 = scnprintf(v47, 255, "num_link %d partners ", *(unsigned __int8 *)(v28 + 1918));
      v30 = v27[3];
      if ( *(_BYTE *)(v30 + 1918) )
        break;
      v28 = v27[3];
      if ( v30 == -1 )
      {
LABEL_21:
        v16 = 0;
        v14 = 0;
        v15 = 0;
        v17 = 0;
        goto LABEL_7;
      }
LABEL_6:
      v14 = *(unsigned __int8 *)(v28 + 1);
      v15 = *(unsigned __int8 *)(v28 + 2);
      v16 = *(unsigned __int8 *)(v28 + 3);
      v17 = *(unsigned __int8 *)(v28 + 6);
LABEL_7:
      if ( *(_QWORD *)(v28 + 1824) )
        v18 = v12;
      else
        v18 = v13;
      LODWORD(v43) = *(_DWORD *)(v28 + 1260);
      LODWORD(v42) = *(unsigned __int8 *)(v28 + 1919);
      LODWORD(v41) = *(_DWORD *)(v28 + 1192);
      result = qdf_trace_msg(
                 0x68u,
                 8u,
                 "Candidate(%02x:%02x:%02x:**:**:%02x %s freq %d self_link_id %d): %s bss_score %d ",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v41,
                 v42,
                 v47,
                 v43);
      v11 = v45;
      LOBYTE(v47[0]) = 0;
      v45 = nullptr;
      v46 = v11;
      if ( !v11 )
        goto LABEL_3;
    }
    v31 = v29;
    v32 = v13;
    v33 = v12;
    v34 = 0;
    v35 = (unsigned __int8 *)(v28 + 1920);
    do
    {
      if ( v31 > 0xFF )
        __break(0x5512u);
      if ( v35 )
      {
        v36 = *v35;
        v37 = v35[1];
        v38 = v35[2];
        v39 = v35[5];
      }
      else
      {
        v38 = 0;
        v36 = 0;
        v37 = 0;
        v39 = 0;
      }
      v40 = scnprintf(
              (char *)v47 + v31,
              255 - v31,
              "%02x:%02x:%02x:**:**:%02x freq (%d) link_id %d is_valid_link %d ",
              v36,
              v37,
              v38,
              v39,
              *((unsigned __int16 *)v35 + 3),
              v35[10],
              v35[40]);
      v28 = v27[3];
      ++v34;
      v31 += v40;
      v35 += 48;
    }
    while ( v34 < *(unsigned __int8 *)(v28 + 1918) );
    v12 = v33;
    v13 = v32;
    v1 = v44;
LABEL_20:
    if ( v28 == -1 )
      goto LABEL_21;
    goto LABEL_6;
  }
  result = qdf_trace_msg(
             0x68u,
             2u,
             "%s: failed to get front of candidate_list",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "cm_print_candidate_list");
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}

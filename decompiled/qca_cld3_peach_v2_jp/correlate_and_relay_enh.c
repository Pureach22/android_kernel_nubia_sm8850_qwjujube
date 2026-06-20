__int64 __fastcall correlate_and_relay_enh(__int64 a1, unsigned int a2, char *a3, char a4)
{
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD *v17; // x21
  __int64 v18; // x0
  int target_type; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w9
  unsigned int v29; // w8
  const char *v30; // x2
  unsigned __int64 v31; // x8
  int v32; // w23
  unsigned __int64 v33; // x9
  __int64 v34; // x5
  const char *v35; // x2
  __int64 v36; // x9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w8
  unsigned int v47; // w9

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v30 = "%s: pdev object for CFR is null";
LABEL_9:
    qdf_trace_msg(0x6Au, 2u, v30, v9, v10, v11, v12, v13, v14, v15, v16, "correlate_and_relay_enh");
    return (unsigned int)-1;
  }
  v17 = (_QWORD *)comp_private_obj;
  v18 = *(_QWORD *)(a1 + 80);
  if ( !v18 )
  {
    v30 = "%s: psoc is null";
    goto LABEL_9;
  }
  target_type = target_if_cfr_get_target_type(v18, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( a4 != 1 )
  {
    ++v17[14];
    *a3 = 1;
    goto LABEL_11;
  }
  if ( a3[1] == 1 )
    ++v17[179];
  v28 = *a3;
  v29 = 1;
  a3[1] = 1;
  if ( (v28 & 1) != 0 )
  {
LABEL_11:
    if ( a3[1] == 1 )
    {
      if ( *((unsigned __int16 *)a3 + 10) == *((unsigned __int16 *)a3 + 11) )
      {
        v31 = *((_QWORD *)a3 + 27);
        v32 = target_type;
        v17[178] = v31;
        v33 = *((_QWORD *)a3 + 26);
        v34 = v31 - v33;
        if ( v31 <= v33 )
        {
          v34 = v33 - v31;
          if ( v33 <= v31 )
            goto LABEL_21;
          v35 = "%s: <CORRELATE><%u>: DBR evt -> TXRX evt(delay = %llu ms)\n";
        }
        else
        {
          v35 = "%s: <CORRELATE><%u>: TXRX evt -> DBR evt(delay = %llu ms)\n";
        }
        qdf_trace_msg(0x6Au, 8u, v35, v20, v21, v22, v23, v24, v25, v26, v27, "correlate_and_relay_enh", a2, v34);
LABEL_21:
        cfr_free_pending_dbr_events(a1, v20, v21, v22, v23, v24, v25, v26, v27);
        if ( v32 <= 31 )
        {
          if ( v32 == 26 )
          {
            if ( *((_DWORD *)a3 + 56) > 0x32u )
              goto LABEL_51;
            goto LABEL_39;
          }
          if ( v32 == 29 )
          {
            if ( *((_DWORD *)a3 + 56) > 0x10u || *((_DWORD *)a3 + 57) > 0x1000u )
              goto LABEL_51;
            goto LABEL_50;
          }
          if ( v32 != 30 )
            goto LABEL_41;
        }
        else
        {
          if ( v32 <= 35 )
          {
            if ( v32 != 32 )
            {
              if ( v32 == 35 )
              {
                if ( *((_DWORD *)a3 + 56) > 0x16u || *((_DWORD *)a3 + 57) > 0x2000u )
                  goto LABEL_51;
LABEL_50:
                ++v17[15];
                qdf_trace_msg(
                  0x6Au,
                  8u,
                  "%s: <CORRELATE><%u>:Stream and release CFR data for ppdu_id:0x%04x\n",
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  "correlate_and_relay_enh",
                  a2,
                  *((unsigned __int16 *)a3 + 11));
                return 0;
              }
LABEL_41:
              if ( *((_DWORD *)a3 + 56) > 0x10u || *((_DWORD *)a3 + 57) > 0x3EC0u )
                goto LABEL_51;
              goto LABEL_50;
            }
            if ( *((_DWORD *)a3 + 56) <= 0x58u )
            {
              v46 = *((_DWORD *)a3 + 57);
              v47 = 64513;
LABEL_46:
              if ( v46 < v47 )
                goto LABEL_50;
              goto LABEL_51;
            }
            goto LABEL_51;
          }
          if ( v32 != 36 )
          {
            if ( v32 != 39 )
              goto LABEL_41;
            if ( *((_DWORD *)a3 + 56) <= 0x1Eu )
            {
              v46 = *((_DWORD *)a3 + 57);
              v47 = 32153;
              goto LABEL_46;
            }
LABEL_51:
            ++v17[175];
            qdf_trace_msg(
              0x6Au,
              2u,
              "%s: <CORRELATE><%u>:CFR buffers received with invalid length header_length_words = %d cfr_payload_length_b"
              "ytes = %d ppdu_id:0x%04x\n",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "correlate_and_relay_enh",
              a2,
              *((unsigned int *)a3 + 56),
              *((unsigned int *)a3 + 57),
              *((unsigned __int16 *)a3 + 11));
            return (unsigned int)-1;
          }
        }
        if ( *((_DWORD *)a3 + 56) > 0x10u )
          goto LABEL_51;
LABEL_39:
        if ( *((_DWORD *)a3 + 57) <= 0x4000u )
          goto LABEL_50;
        goto LABEL_51;
      }
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: Received new dbr event for same cookie %u\n",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "correlate_and_relay_enh",
        a2);
      a3[1] = 0;
      *((_WORD *)a3 + 11) = 0;
      v36 = v17[179] + 1LL;
      ++v17[177];
      v17[179] = v36;
    }
    return 1;
  }
  return v29;
}

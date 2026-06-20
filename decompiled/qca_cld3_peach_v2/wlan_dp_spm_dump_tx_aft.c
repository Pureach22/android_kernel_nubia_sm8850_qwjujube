__int64 __fastcall wlan_dp_spm_dump_tx_aft(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w22
  unsigned int v29; // w21
  __int64 i; // x28
  unsigned __int8 *v31; // x24
  unsigned __int16 v32; // w0
  unsigned __int16 v33; // w27
  __int16 v34; // w0
  unsigned __int16 v35; // w27
  __int16 v36; // w0
  unsigned __int16 v37; // w27
  __int16 v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+0h] [xbp-140h]
  __int64 v48; // [xsp+8h] [xbp-138h]
  __int64 v49; // [xsp+10h] [xbp-130h]
  __int64 v50; // [xsp+20h] [xbp-120h]
  _QWORD v51[34]; // [xsp+30h] [xbp-110h] BYREF

  v51[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 2952) )
  {
    v2 = result;
    memset(v51, 0, 256);
    v3 = sched_clock(result, a2);
    qdf_trace_msg(0x45u, 5u, "%s: cur_ts %llu", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_dp_spm_dump_tx_aft", v3);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Flow <id> [<tuple>] <num_pkts> <classified> <selected_to_sample> <track_flow_stats> <c_flow_id> <inactivity_ti"
      "meout> <ul_tid> <active_ts> ",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_dp_spm_dump_tx_aft");
    v28 = 0;
    v29 = 0;
    for ( i = 184; i != 49336; i += 192 )
    {
      v31 = (unsigned __int8 *)(*(_QWORD *)(v2 + 2952) + i);
      if ( *(v31 - 134) )
      {
        ++v29;
        scnprintf(v51, 256, "0x%x", *((_DWORD *)v31 - 33));
        v33 = v32;
        scnprintf((char *)v51 + v32, 256 - v32, " 0x%x", *((_DWORD *)v31 - 29));
        v35 = v34 + v33;
        scnprintf((char *)v51 + v35, 256 - v35, " %u", *((unsigned __int16 *)v31 - 50));
        v37 = v36 + v35;
        scnprintf((char *)v51 + v37, 256 - v37, " %u", *((unsigned __int16 *)v31 - 49));
        v39 = scnprintf(
                (char *)v51 + (unsigned __int16)(v38 + v37),
                256 - (unsigned __int16)(v38 + v37),
                " %u",
                *(v31 - 96));
        LODWORD(v50) = *v31;
        LODWORD(v49) = *(v31 - 24);
        LODWORD(v48) = *(v31 - 23);
        LODWORD(v47) = *(v31 - 22);
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Flow %u [%s] %llu %u %u %u %u %llu %u: %llu",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_dp_spm_dump_tx_aft",
          v28,
          v51,
          *((_QWORD *)v31 - 4),
          *(v31 - 21),
          v47,
          v48,
          v49,
          *((_QWORD *)v31 - 1),
          v50,
          *((_QWORD *)v31 - 5));
      }
      ++v28;
    }
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: Printed %d flow entries of TX AFT",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "wlan_dp_spm_dump_tx_aft",
               v29);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

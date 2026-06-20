__int64 __fastcall extract_pdev_power_boost_event_tlv(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x8
  __int64 (*v13)(void); // x9
  unsigned int v14; // w0
  __int64 v15; // x6
  __int64 v16; // x7
  int v17; // w8
  int v18; // w9
  int v19; // w10
  int v20; // w11
  int v21; // w12
  int v22; // w13
  __int64 v23; // x4
  int v24; // w14
  int v25; // w15
  int v26; // w16
  int v27; // w17
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v37; // [xsp+0h] [xbp-50h]
  int v38; // [xsp+8h] [xbp-48h]
  int v39; // [xsp+10h] [xbp-40h]
  int v40; // [xsp+18h] [xbp-38h]
  int v41; // [xsp+20h] [xbp-30h]
  int v42; // [xsp+28h] [xbp-28h]
  int v43; // [xsp+30h] [xbp-20h]
  int v44; // [xsp+38h] [xbp-18h]
  int v45; // [xsp+40h] [xbp-10h]
  int v46; // [xsp+48h] [xbp-8h]

  if ( a2 )
  {
    v11 = *(_DWORD **)a2;
    a3[5] = *(_DWORD *)(*(_QWORD *)a2 + 8LL);
    a3[6] = v11[3];
    a3[7] = v11[4];
    a3[8] = v11[5];
    a3[9] = v11[6];
    a3[10] = v11[7];
    a3[11] = v11[8];
    a3[12] = v11[9];
    a3[13] = v11[10];
    a3[14] = v11[14];
    a3[16] = v11[12];
    a3[17] = v11[13];
    a3[18] = v11[11];
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3672LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8229u);
    v14 = v13();
    v15 = (unsigned int)a3[5];
    v16 = (unsigned int)a3[6];
    v17 = a3[7];
    v18 = a3[8];
    v19 = a3[9];
    v20 = a3[10];
    v21 = a3[11];
    v22 = a3[12];
    v24 = a3[13];
    v23 = (unsigned int)a3[14];
    v25 = a3[16];
    v26 = a3[17];
    v27 = a3[18];
    a3[4] = v14;
    v46 = v27;
    v45 = v26;
    v44 = v25;
    v43 = v24;
    v42 = v22;
    v41 = v21;
    v40 = v20;
    v39 = v19;
    v38 = v18;
    v37 = v17;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: TPB: WMI Host params: req_id: %u pdev_id: %u status: %u inf_stage: %u mcs: %u BW: %u temperature_degreeC: %d p"
      "rimary_chan_mhz: %u center_freq1: %u center_freq2: %u phy_mode: %u tx_pwr: %d tx_chain_idx: %u iq_sample_buf_size: %u",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "extract_pdev_power_boost_event_tlv",
      v23,
      v14,
      v15,
      v16,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: TPB: Invalid Power Boost event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_pdev_power_boost_event_tlv");
    return 16;
  }
}

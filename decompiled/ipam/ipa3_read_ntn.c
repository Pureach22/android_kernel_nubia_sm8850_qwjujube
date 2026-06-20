__int64 __fastcall ipa3_read_ntn(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w24
  unsigned int v10; // w24
  __int64 result; // x0
  __int64 v12; // [xsp+B8h] [xbp-E8h] BYREF
  __int64 v13; // [xsp+C0h] [xbp-E0h]
  __int64 v14; // [xsp+C8h] [xbp-D8h]
  __int64 v15; // [xsp+D0h] [xbp-D0h]
  __int64 v16; // [xsp+D8h] [xbp-C8h]
  __int64 v17; // [xsp+E0h] [xbp-C0h]
  __int64 v18; // [xsp+E8h] [xbp-B8h]
  __int64 v19; // [xsp+F0h] [xbp-B0h]
  __int64 v20; // [xsp+F8h] [xbp-A8h]
  __int64 v21; // [xsp+100h] [xbp-A0h]
  __int64 v22; // [xsp+108h] [xbp-98h]
  __int64 v23; // [xsp+110h] [xbp-90h]
  __int64 v24; // [xsp+118h] [xbp-88h]
  __int64 v25; // [xsp+120h] [xbp-80h]
  __int64 v26; // [xsp+128h] [xbp-78h]
  __int64 v27; // [xsp+130h] [xbp-70h]
  __int64 v28; // [xsp+138h] [xbp-68h]
  __int64 v29; // [xsp+140h] [xbp-60h]
  __int64 v30; // [xsp+148h] [xbp-58h]
  __int64 v31; // [xsp+150h] [xbp-50h]
  __int64 v32; // [xsp+158h] [xbp-48h]
  __int64 v33; // [xsp+160h] [xbp-40h]
  __int64 v34; // [xsp+168h] [xbp-38h]
  __int64 v35; // [xsp+170h] [xbp-30h]
  __int64 v36; // [xsp+178h] [xbp-28h]
  __int64 v37; // [xsp+180h] [xbp-20h]
  __int64 v38; // [xsp+188h] [xbp-18h]
  __int64 v39; // [xsp+190h] [xbp-10h]
  __int64 v40; // [xsp+198h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  if ( (unsigned int)ipa3_get_ntn_stats(&v12) )
  {
    v7 = scnprintf(dbg_buff, 4096, "Fail to read NTN stats\n");
  }
  else
  {
    v8 = scnprintf(
           dbg_buff,
           4096,
           "TX%d num_pkts_psr=%u\n"
           "TX%d ringFull=%u\n"
           "TX%d ringEmpty=%u\n"
           "TX%d ringUsageHigh=%u\n"
           "TX%d ringUsageLow=%u\n"
           "TX%d RingUtilCount=%u\n"
           "TX%d bamFifoFull=%u\n"
           "TX%d bamFifoEmpty=%u\n"
           "TX%d bamFifoUsageHigh=%u\n"
           "TX%d bamFifoUsageLow=%u\n"
           "TX%d bamUtilCount=%u\n"
           "TX%d num_db=%u\n"
           "TX%d num_qmb_int_handled=%u\n"
           "TX%d ipa_pipe_number=%u\n",
           0,
           v26,
           0,
           HIDWORD(v26),
           0,
           v27,
           0,
           HIDWORD(v27),
           0,
           v28,
           0,
           HIDWORD(v28),
           0,
           v29,
           0,
           HIDWORD(v29),
           0,
           v30,
           0,
           HIDWORD(v30),
           0,
           v31,
           0,
           HIDWORD(v31),
           0,
           v32,
           0,
           HIDWORD(v32));
    if ( v8 >> 1 > 0x800
      || (v9 = scnprintf(
                 &dbg_buff[v8],
                 (int)(4096 - v8),
                 "TX%d num_pkts_psr=%u\n"
                 "TX%d ringFull=%u\n"
                 "TX%d ringEmpty=%u\n"
                 "TX%d ringUsageHigh=%u\n"
                 "TX%d ringUsageLow=%u\n"
                 "TX%d RingUtilCount=%u\n"
                 "TX%d bamFifoFull=%u\n"
                 "TX%d bamFifoEmpty=%u\n"
                 "TX%d bamFifoUsageHigh=%u\n"
                 "TX%d bamFifoUsageLow=%u\n"
                 "TX%d bamUtilCount=%u\n"
                 "TX%d num_db=%u\n"
                 "TX%d num_qmb_int_handled=%u\n"
                 "TX%d ipa_pipe_number=%u\n",
                 1,
                 v33,
                 1,
                 HIDWORD(v33),
                 1,
                 v34,
                 1,
                 HIDWORD(v34),
                 1,
                 v35,
                 1,
                 HIDWORD(v35),
                 1,
                 v36,
                 1,
                 HIDWORD(v36),
                 1,
                 v37,
                 1,
                 HIDWORD(v37),
                 1,
                 v38,
                 1,
                 HIDWORD(v38),
                 1,
                 v39,
                 1,
                 HIDWORD(v39))
             + v8,
          v9 >> 1 > 0x800)
      || (v10 = scnprintf(
                  &dbg_buff[v9],
                  (int)(4096 - v9),
                  "RX%d num_pkts_psr=%u\n"
                  "RX%d ringFull=%u\n"
                  "RX%d ringEmpty=%u\n"
                  "RX%d ringUsageHigh=%u\n"
                  "RX%d ringUsageLow=%u\n"
                  "RX%d RingUtilCount=%u\n"
                  "RX%d bamFifoFull=%u\n"
                  "RX%d bamFifoEmpty=%u\n"
                  "RX%d bamFifoUsageHigh=%u\n"
                  "RX%d bamFifoUsageLow=%u\n"
                  "RX%d bamUtilCount=%u\n"
                  "RX%d num_db=%u\n"
                  "RX%d num_qmb_int_handled=%u\n"
                  "RX%d ipa_pipe_number=%u\n",
                  0,
                  v12,
                  0,
                  HIDWORD(v12),
                  0,
                  v13,
                  0,
                  HIDWORD(v13),
                  0,
                  v14,
                  0,
                  HIDWORD(v14),
                  0,
                  v15,
                  0,
                  HIDWORD(v15),
                  0,
                  v16,
                  0,
                  HIDWORD(v16),
                  0,
                  v17,
                  0,
                  HIDWORD(v17),
                  0,
                  v18,
                  0,
                  HIDWORD(v18))
              + v9,
          v10 >> 1 > 0x800) )
    {
      __break(0x5512u);
    }
    v7 = scnprintf(
           &dbg_buff[v10],
           (int)(4096 - v10),
           "RX%d num_pkts_psr=%u\n"
           "RX%d ringFull=%u\n"
           "RX%d ringEmpty=%u\n"
           "RX%d ringUsageHigh=%u\n"
           "RX%d ringUsageLow=%u\n"
           "RX%d RingUtilCount=%u\n"
           "RX%d bamFifoFull=%u\n"
           "RX%d bamFifoEmpty=%u\n"
           "RX%d bamFifoUsageHigh=%u\n"
           "RX%d bamFifoUsageLow=%u\n"
           "RX%d bamUtilCount=%u\n"
           "RX%d num_db=%u\n"
           "RX%d num_qmb_int_handled=%u\n"
           "RX%d ipa_pipe_number=%u\n",
           1,
           v19,
           1,
           HIDWORD(v19),
           1,
           v20,
           1,
           HIDWORD(v20),
           1,
           v21,
           1,
           HIDWORD(v21),
           1,
           v22,
           1,
           HIDWORD(v22),
           1,
           v23,
           1,
           HIDWORD(v23),
           1,
           v24,
           1,
           HIDWORD(v24),
           1,
           v25,
           1,
           HIDWORD(v25))
       + v10;
  }
  result = simple_read_from_buffer(a2, a3, a4, dbg_buff, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}

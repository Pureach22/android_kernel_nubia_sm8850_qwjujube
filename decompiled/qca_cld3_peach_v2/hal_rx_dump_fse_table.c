__int64 __fastcall hal_rx_dump_fse_table(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x22
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w9
  unsigned __int64 v21; // x20
  unsigned __int64 *v22; // x25
  unsigned __int64 v23; // x8
  unsigned int v24; // w10
  unsigned int v25; // w10
  unsigned int v26; // w10
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+0h] [xbp-90h]
  __int64 v36; // [xsp+8h] [xbp-88h]
  __int64 v37; // [xsp+10h] [xbp-80h]
  __int64 v38; // [xsp+18h] [xbp-78h]
  __int64 v39; // [xsp+20h] [xbp-70h]
  __int64 v40; // [xsp+28h] [xbp-68h]
  __int64 v41; // [xsp+30h] [xbp-60h]
  __int64 v42; // [xsp+38h] [xbp-58h]
  __int64 v43; // [xsp+40h] [xbp-50h]
  __int64 v44; // [xsp+48h] [xbp-48h]
  __int64 v45; // [xsp+50h] [xbp-40h]
  __int64 v46; // [xsp+58h] [xbp-38h]
  _DWORD v47[2]; // [xsp+68h] [xbp-28h] BYREF
  unsigned __int64 v48; // [xsp+70h] [xbp-20h]
  _DWORD v49[4]; // [xsp+78h] [xbp-18h] BYREF
  __int64 v50; // [xsp+88h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: Flow table Max Entries %d",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hal_rx_dump_fse_table",
             *((unsigned __int16 *)a1 + 12));
  v20 = *((unsigned __int16 *)a1 + 12);
  if ( *((_WORD *)a1 + 12) )
  {
    v21 = 0;
    v22 = (unsigned __int64 *)(v10 + 32);
    do
    {
      v23 = *v22;
      if ( (*v22 & 0x10000000000LL) != 0 )
      {
        v24 = bswap32(*((_DWORD *)v22 - 6));
        v49[0] = bswap32(*((_DWORD *)v22 - 5));
        v49[1] = v24;
        v25 = bswap32(*((_DWORD *)v22 - 8));
        v49[2] = bswap32(*((_DWORD *)v22 - 7));
        v49[3] = v25;
        v26 = bswap32(*((_DWORD *)v22 - 2));
        v47[0] = bswap32(*((_DWORD *)v22 - 1));
        v47[1] = v26;
        v48 = __PAIR64__(bswap32(*((_DWORD *)v22 - 4)), bswap32(*((_DWORD *)v22 - 3)));
        LODWORD(v42) = v23 >> 62;
        LODWORD(v41) = (v23 & 0x2000000000000000LL) != 0;
        LODWORD(v40) = HIBYTE(v23) & 0x1F;
        LODWORD(v45) = v22[2];
        LODWORD(v43) = v22[1];
        LODWORD(v46) = HIDWORD(v22[2]);
        LODWORD(v44) = v22[1] >> 40;
        LODWORD(v39) = 1;
        LODWORD(v38) = BYTE4(v23);
        LODWORD(v37) = WORD1(v23);
        LODWORD(v36) = (unsigned __int16)v23;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: index %d: src_ip_v6 %pI6c src_ip_v4 %pI4 dest_ip_v6 %pI6c dest_ip_v4 %pI4 src_port %u dest_port %u l4_prot"
          "ocol 0x%x valid 0x%x reo_destination_indication 0x%x msdu_drop %u reo_destination_handler 0x%x metadata 0x%x m"
          "sdu_count 0x%x msdu_byte_count %u timestamp 0x%x",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hal_rx_dump_fse",
          (unsigned int)v21,
          v49,
          v49,
          v47,
          v47,
          v36,
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
        LODWORD(v35) = HIDWORD(v22[3]);
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s:  aggregation_count 0x%x lro_eligible 0x%x cumulative_ip_length_pmac1/l4_checksum %x cumulative_ip"
                   "_length 0x%x tcp_sequence_number 0x%x",
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   v33,
                   v34,
                   "hal_rx_dump_fse_ext",
                   HIDWORD(v22[1]) & 0x7F,
                   (v22[1] >> 39) & 1,
                   (unsigned __int16)v22[3],
                   WORD1(v22[3]),
                   v35);
        v20 = *((unsigned __int16 *)a1 + 12);
      }
      ++v21;
      v22 += 8;
    }
    while ( v21 < v20 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall dp_print_common_rates_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  const char *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  const char *v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  const char *v39; // x20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  const char *v49; // x20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x22
  const char *v59; // x20
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  const char *v69; // x20

  DP_PRINT_STATS("MSDU Count", a2, a3, a4, a5, a6, a7, a8, a9);
  v18 = 0;
  v19 = "OFDM 48 Mbps";
  do
  {
    if ( v19[34] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v19, *(unsigned int *)(a1 + v18));
    v18 += 4;
    v19 += 35;
  }
  while ( v18 != 68 );
  DP_PRINT_STATS("\n", v10, v11, v12, v13, v14, v15, v16, v17);
  v28 = 0;
  v29 = "CCK 11 Mbps Long  ";
  do
  {
    if ( v29[34] )
      DP_PRINT_STATS("\t%s = %d", v20, v21, v22, v23, v24, v25, v26, v27, v29, *(unsigned int *)(a1 + 68 + v28));
    v28 += 4;
    v29 += 35;
  }
  while ( v28 != 68 );
  DP_PRINT_STATS("\n", v20, v21, v22, v23, v24, v25, v26, v27);
  v38 = 0;
  v39 = "HT MCS 0 (BPSK 1/2)  ";
  do
  {
    if ( v39[34] )
      DP_PRINT_STATS("\t%s = %d", v30, v31, v32, v33, v34, v35, v36, v37, v39, *(unsigned int *)(a1 + 136 + v38));
    v38 += 4;
    v39 += 35;
  }
  while ( v38 != 68 );
  DP_PRINT_STATS("\n", v30, v31, v32, v33, v34, v35, v36, v37);
  v48 = 0;
  v49 = "VHT MCS 0 (BPSK 1/2)     ";
  do
  {
    if ( v49[34] )
      DP_PRINT_STATS("\t%s = %d", v40, v41, v42, v43, v44, v45, v46, v47, v49, *(unsigned int *)(a1 + 204 + v48));
    v48 += 4;
    v49 += 35;
  }
  while ( v48 != 68 );
  DP_PRINT_STATS("\n", v40, v41, v42, v43, v44, v45, v46, v47);
  v58 = 0;
  v59 = "HE MCS 0 (BPSK 1/2)     ";
  do
  {
    if ( v59[34] )
      DP_PRINT_STATS("\t%s = %d", v50, v51, v52, v53, v54, v55, v56, v57, v59, *(unsigned int *)(a1 + 272 + v58));
    v58 += 4;
    v59 += 35;
  }
  while ( v58 != 68 );
  DP_PRINT_STATS("\n", v50, v51, v52, v53, v54, v55, v56, v57);
  v68 = 0;
  v69 = "EHT MCS 0 (BPSK 1/2)     ";
  do
  {
    if ( v69[34] )
      DP_PRINT_STATS("\t%s = %d", v60, v61, v62, v63, v64, v65, v66, v67, v69, *(unsigned int *)(a1 + 340 + v68));
    v68 += 4;
    v69 += 35;
  }
  while ( v68 != 68 );
  return DP_PRINT_STATS("\n", v60, v61, v62, v63, v64, v65, v66, v67);
}

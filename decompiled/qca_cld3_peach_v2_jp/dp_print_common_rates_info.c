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
  unsigned int *v19; // x24
  __int64 result; // x0
  char *v21; // x21
  char *v22; // x21
  char *v23; // x21
  char *v24; // x21
  char *v25; // x21
  char *v26; // x21
  char *v27; // x21

  DP_PRINT_STATS("MSDU Count", a2, a3, a4, a5, a6, a7, a8, a9);
  v18 = 0;
  v19 = (unsigned int *)(a1 + 28);
  do
  {
    v21 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 34] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, &cdp_rate_string[v18], *(v19 - 7));
    if ( v21[69] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v21 + 35, *(v19 - 6));
    v22 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 104] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v22 + 70, *(v19 - 5));
    if ( v22[139] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v22 + 105, *(v19 - 4));
    v23 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 174] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v23 + 140, *(v19 - 3));
    if ( v23[209] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v23 + 175, *(v19 - 2));
    v24 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 244] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v24 + 210, *(v19 - 1));
    if ( v24[279] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v24 + 245, *v19);
    v25 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 314] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v25 + 280, v19[1]);
    if ( v25[349] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v25 + 315, v19[2]);
    v26 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 384] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v26 + 350, v19[3]);
    if ( v26[419] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v26 + 385, v19[4]);
    v27 = &cdp_rate_string[v18];
    if ( cdp_rate_string[v18 + 454] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v27 + 420, v19[5]);
    if ( v27[489] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, v27 + 455, v19[6]);
    if ( cdp_rate_string[v18 + 524] )
      DP_PRINT_STATS("\t%s = %d", v10, v11, v12, v13, v14, v15, v16, v17, &cdp_rate_string[v18 + 490], v19[7]);
    result = DP_PRINT_STATS("\n", v10, v11, v12, v13, v14, v15, v16, v17);
    v18 += 525;
    v19 += 15;
  }
  while ( v18 != 2625 );
  return result;
}

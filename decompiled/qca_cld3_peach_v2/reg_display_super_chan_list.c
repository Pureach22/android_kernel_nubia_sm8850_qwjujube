__int64 __fastcall reg_display_super_chan_list(
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
  __int64 pdev_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x25
  __int64 v19; // x19
  __int64 v20; // x23
  __int64 v21; // x24
  __int64 v22; // x27
  __int64 v23; // x26
  __int64 v24; // x20
  __int64 v25; // x28
  bool v26; // cf
  __int64 v28; // x20
  __int64 v29; // [xsp+0h] [xbp-40h]
  __int64 v30; // [xsp+8h] [xbp-38h]
  __int64 v31; // [xsp+10h] [xbp-30h]
  __int64 v32; // [xsp+18h] [xbp-28h]
  __int64 v33; // [xsp+20h] [xbp-20h]
  __int64 v34; // [xsp+28h] [xbp-18h]
  __int64 v35; // [xsp+30h] [xbp-10h]
  __int64 v36; // [xsp+38h] [xbp-8h]

  pdev_obj = reg_get_pdev_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( pdev_obj )
  {
    v18 = 36950;
    v19 = pdev_obj;
    v20 = 0;
    v21 = 0;
    v22 = pdev_obj + 36950;
    v23 = 37004;
    v34 = pdev_obj + 36940;
    do
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Freq = %d\tPower types = 0x%x\tBest power mode = 0x%x\n",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "reg_display_super_chan_list",
        *(unsigned int *)(v19 + 36 * v21 + 1512),
        *(unsigned __int16 *)(v34 + 268 * v21),
        *(unsigned int *)(v34 + 268 * v21 + 4));
      v24 = -12;
      v25 = v23;
      v35 = v18;
      v36 = v20;
      do
      {
        LODWORD(v33) = HIWORD(*(_DWORD *)(v19 + v25)) & 1;
        LODWORD(v32) = *(unsigned __int16 *)(v19 + v18 + 26);
        LODWORD(v31) = *(unsigned __int16 *)(v19 + v18);
        LODWORD(v30) = *(_DWORD *)(v19 + v25 + 156);
        LODWORD(v29) = *(_DWORD *)(v19 + v25);
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Power mode = %d\tPSD flag = %d\tPSD power = %d\tEIRP power = %d\tChan flags = 0x%x\tChannel state = %d\tMi"
          "n bw = %d\tMax bw = %d\tAFC_NOT_DONE = %d\n",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "reg_display_super_chan_list",
          (unsigned int)(v24 + 13),
          *(unsigned __int8 *)(v22 + v20 + 110),
          *(unsigned __int16 *)(v22 + v20 + 112),
          *(unsigned int *)(v22 + v20 + 114),
          v29,
          v30,
          v31,
          v32,
          v33);
        v26 = __CFADD__(v24++, 1);
        v18 += 2;
        v25 += 4;
        v20 += 8;
      }
      while ( !v26 );
      ++v21;
      v23 += 268;
      v18 = v35 + 268;
      v20 = v36 + 268;
    }
    while ( v21 != 60 );
    return 0;
  }
  else
  {
    v28 = jiffies;
    if ( reg_display_super_chan_list___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: pdev reg component is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "reg_display_super_chan_list");
      reg_display_super_chan_list___last_ticks = v28;
    }
    return 16;
  }
}

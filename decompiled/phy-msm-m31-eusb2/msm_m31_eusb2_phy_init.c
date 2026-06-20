__int64 __fastcall msm_m31_eusb2_phy_init(_QWORD *a1)
{
  unsigned int **v2; // x23
  __int64 result; // x0
  unsigned int v4; // w0
  int v5; // w24
  unsigned int *v6; // x25
  unsigned __int64 v7; // x26
  __int64 v8; // x21
  __int64 v9; // x27
  unsigned int v10; // w22
  int v11; // w0
  __int64 rate; // x0
  __int64 v13; // x20
  int v14; // w0
  __int64 v15; // x1
  __int64 v16; // x20
  int v17; // w0
  int v18; // w24
  unsigned int *v19; // x25
  unsigned __int64 v20; // x26
  __int64 v21; // x21
  __int64 v22; // x27
  unsigned int v23; // w22
  int v24; // w0
  int v25; // w20
  unsigned int *v26; // x22
  __int64 v27; // x21
  int i; // w24
  int v29; // w8
  __int64 v30; // x21
  unsigned int v31; // w25
  __int64 v32; // x24
  unsigned int v33; // w20
  int v34; // w0
  unsigned int v35; // w20
  __int64 v36; // x21
  unsigned int v37; // w25
  __int64 v38; // x24
  int v39; // w0
  unsigned int v40; // w20
  __int64 v41; // x21
  unsigned int v42; // w25
  __int64 v43; // x24
  int v44; // w0
  unsigned int v45; // w20
  __int64 v46; // x21
  unsigned int v47; // w22
  __int64 v48; // x24
  int v49; // w0
  int v50; // w24
  unsigned int *v51; // x23
  unsigned __int64 v52; // x25
  __int64 v53; // x21
  __int64 v54; // x26
  unsigned int v55; // w22
  int v56; // w0
  __int64 v57; // x8
  unsigned int v58; // w19

  v2 = (unsigned int **)a1[71];
  if ( a1[48] && (((__int64 (*)(void))readl_relaxed)() & 1) != 0 )
  {
    if ( (a1[2] & 1) == 0 )
    {
      msm_m31_eusb2_phy_power(a1, 1);
      msm_m31_eusb2_phy_clocks(a1, 1);
      return msm_m31_eusb2_repeater_reset_and_init(a1);
    }
    qcom_scm_io_writel(a1[47], 0);
    *((_BYTE *)a1 + 400) = 1;
  }
  result = msm_m31_eusb2_phy_power(a1, 1);
  if ( !(_DWORD)result )
  {
    v4 = msm_m31_eusb2_repeater_reset_and_init(a1);
    if ( v4 )
    {
      v57 = *a1;
      v58 = v4;
      dev_err(v57, "repeater powerup failed.\n");
      return v58;
    }
    msm_m31_eusb2_phy_clocks(a1, 1);
    if ( (unsigned int)reset_control_assert(a1[53]) )
      dev_err(*a1, "phy reset assert failed\n");
    usleep_range_state(100, 150, 2);
    if ( (unsigned int)reset_control_deassert(a1[53]) )
      dev_err(*a1, "phy reset deassert failed\n");
    v5 = *((_DWORD *)v2 + 2);
    if ( v5 >= 1 )
    {
      v6 = *v2;
      do
      {
        v7 = v6[1];
        v8 = *v6;
        v9 = a1[46];
        v10 = v6[2] << __clz(__rbit64(v7));
        v11 = readl_relaxed(v9 + v8);
        writel_relaxed(v10 | v11 & ~(_DWORD)v7, v9 + v8);
        if ( ((unsigned int)readl_relaxed(v9 + v8) & (unsigned int)v7) != v10 )
          printk(&unk_7A3F, v10, (unsigned int)v8);
        --v5;
        v6 += 3;
      }
      while ( v5 );
    }
    rate = clk_get_rate(a1[51]);
    if ( rate == 38400000 )
    {
      v16 = a1[46];
      v17 = readl_relaxed(v16 + 84);
      writel_relaxed(v17 & 0xFFFFFF8F | 0x60, v16 + 84);
      if ( (readl_relaxed(v16 + 84) & 0x70) != 0x60 )
      {
        v15 = 96;
        goto LABEL_52;
      }
    }
    else if ( rate == 19200000 )
    {
      v13 = a1[46];
      v14 = readl_relaxed(v13 + 84);
      writel_relaxed(v14 & 0xFFFFFF8F | 0x40, v13 + 84);
      if ( (readl_relaxed(v13 + 84) & 0x70) != 0x40 )
      {
        v15 = 64;
LABEL_52:
        printk(&unk_7A3F, v15, 84);
      }
    }
    else
    {
      dev_err(*a1, "unsupported ref_clk_freq:%lu\n", rate);
    }
    v18 = *((_DWORD *)v2 + 6);
    if ( v18 >= 1 )
    {
      v19 = v2[2];
      do
      {
        v20 = v19[1];
        v21 = *v19;
        v22 = a1[46];
        v23 = v19[2] << __clz(__rbit64(v20));
        v24 = readl_relaxed(v22 + v21);
        writel_relaxed(v23 | v24 & ~(_DWORD)v20, v22 + v21);
        if ( ((unsigned int)readl_relaxed(v22 + v21) & (unsigned int)v20) != v23 )
          printk(&unk_7A3F, v23, (unsigned int)v21);
        --v18;
        v19 += 3;
      }
      while ( v18 );
    }
    v25 = *((_DWORD *)a1 + 134);
    v26 = *(unsigned int **)(a1[71] + 16LL);
    if ( v25 >= 1 )
    {
      v27 = a1[66];
      for ( i = 0; i < v25; i += 2 )
        writel_relaxed(*(unsigned int *)(v27 + 4LL * i), a1[46] + *(unsigned int *)(v27 + 4LL * (i + 1)));
    }
    v29 = *((unsigned __int8 *)a1 + 552);
    if ( v29 != 255 )
    {
      v30 = *v26;
      v31 = v26[1];
      v32 = a1[46];
      v33 = 4 * v29;
      v34 = readl_relaxed(v32 + v30);
      writel_relaxed(v34 & ~v31 | v33, v32 + v30);
      if ( ((unsigned int)readl_relaxed(v32 + v30) & v31) != v33 )
        printk(&unk_7A3F, v33, (unsigned int)v30);
    }
    v35 = *((unsigned __int8 *)a1 + 553);
    if ( v35 != 255 )
    {
      v36 = v26[3];
      v37 = v26[4];
      v38 = a1[46];
      v39 = readl_relaxed(v38 + v36);
      writel_relaxed(v39 & ~v37 | v35, v38 + v36);
      if ( ((unsigned int)readl_relaxed(v38 + v36) & v37) != v35 )
        printk(&unk_7A3F, v35, (unsigned int)v36);
    }
    v40 = *((unsigned __int8 *)a1 + 554);
    if ( v40 != 255 )
    {
      v41 = v26[6];
      v42 = v26[7];
      v43 = a1[46];
      v44 = readl_relaxed(v43 + v41);
      writel_relaxed(v44 & ~v42 | v40, v43 + v41);
      if ( ((unsigned int)readl_relaxed(v43 + v41) & v42) != v40 )
        printk(&unk_7A3F, v40, (unsigned int)v41);
    }
    v45 = *((unsigned __int8 *)a1 + 555);
    if ( v45 != 255 )
    {
      v46 = v26[9];
      v47 = v26[10];
      v48 = a1[46];
      v49 = readl_relaxed(v48 + v46);
      writel_relaxed(v49 & ~v47 | v45, v48 + v46);
      if ( ((unsigned int)readl_relaxed(v48 + v46) & v47) != v45 )
        printk(&unk_7A3F, v45, (unsigned int)v46);
    }
    v50 = *((_DWORD *)v2 + 10);
    if ( v50 >= 1 )
    {
      v51 = v2[4];
      do
      {
        v52 = v51[1];
        v53 = *v51;
        v54 = a1[46];
        v55 = v51[2] << __clz(__rbit64(v52));
        v56 = readl_relaxed(v54 + v53);
        writel_relaxed(v55 | v56 & ~(_DWORD)v52, v54 + v53);
        if ( ((unsigned int)readl_relaxed(v54 + v53) & (unsigned int)v52) != v55 )
          printk(&unk_7A3F, v55, (unsigned int)v53);
        --v50;
        v51 += 3;
      }
      while ( v50 );
    }
    return 0;
  }
  return result;
}

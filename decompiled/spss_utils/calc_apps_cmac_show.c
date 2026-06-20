__int64 __fastcall calc_apps_cmac_show(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned int *v4; // x24
  int v5; // w20
  int v6; // w21
  int v7; // w22
  int v8; // w0
  int v9; // w20
  int v10; // w21
  int v11; // w22
  int v12; // w0
  int v13; // w20
  int v14; // w21
  int v15; // w22
  int v16; // w0
  int v17; // w20
  int v18; // w21
  int v19; // w22
  int v20; // w0
  int v21; // w20
  int v22; // w21
  int v23; // w22
  int v24; // w0
  int v25; // w20
  int v26; // w21
  int v27; // w22
  int v28; // w0
  int v29; // w20
  int v30; // w21
  int v31; // w22
  int v32; // w0
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x10
  __int64 v40; // x11
  __int64 v41; // x8
  __int64 v42; // x10
  __int64 v43; // x11

  if ( a1 && a2 && a3 )
  {
    v4 = (unsigned int *)cmac_mem;
    if ( cmac_mem )
    {
      qword_9888 = 0;
      qword_9890 = 0;
      qword_9878 = 0;
      qword_9880 = 0;
      qword_9868 = 0;
      qword_9870 = 0;
      qword_9858 = 0;
      qword_9860 = 0;
      qword_9848 = 0;
      qword_9850 = 0;
      qword_9838 = 0;
      qword_9840 = 0;
      calc_apps_cmac = 0;
      qword_9830 = 0;
      v5 = readl_relaxed((unsigned int *)(cmac_mem + 48));
      v6 = readl_relaxed(v4 + 13);
      v7 = readl_relaxed(v4 + 14);
      v8 = readl_relaxed(v4 + 15);
      if ( v5 != v6 )
      {
        LODWORD(qword_9830) = v7;
        HIDWORD(qword_9830) = v8;
        LODWORD(calc_apps_cmac) = v5;
        HIDWORD(calc_apps_cmac) = v6;
        v9 = readl_relaxed(v4 + 20);
        v10 = readl_relaxed(v4 + 21);
        v11 = readl_relaxed(v4 + 22);
        v12 = readl_relaxed(v4 + 23);
        if ( v9 != v10 )
        {
          LODWORD(qword_9840) = v11;
          HIDWORD(qword_9840) = v12;
          LODWORD(qword_9838) = v9;
          HIDWORD(qword_9838) = v10;
          v13 = readl_relaxed(v4 + 28);
          v14 = readl_relaxed(v4 + 29);
          v15 = readl_relaxed(v4 + 30);
          v16 = readl_relaxed(v4 + 31);
          if ( v13 != v14 )
          {
            LODWORD(qword_9850) = v15;
            HIDWORD(qword_9850) = v16;
            LODWORD(qword_9848) = v13;
            HIDWORD(qword_9848) = v14;
            v17 = readl_relaxed(v4 + 36);
            v18 = readl_relaxed(v4 + 37);
            v19 = readl_relaxed(v4 + 38);
            v20 = readl_relaxed(v4 + 39);
            if ( v17 != v18 )
            {
              LODWORD(qword_9860) = v19;
              HIDWORD(qword_9860) = v20;
              LODWORD(qword_9858) = v17;
              HIDWORD(qword_9858) = v18;
              v21 = readl_relaxed(v4 + 44);
              v22 = readl_relaxed(v4 + 45);
              v23 = readl_relaxed(v4 + 46);
              v24 = readl_relaxed(v4 + 47);
              if ( v21 != v22 )
              {
                LODWORD(qword_9870) = v23;
                HIDWORD(qword_9870) = v24;
                LODWORD(qword_9868) = v21;
                HIDWORD(qword_9868) = v22;
                v25 = readl_relaxed(v4 + 52);
                v26 = readl_relaxed(v4 + 53);
                v27 = readl_relaxed(v4 + 54);
                v28 = readl_relaxed(v4 + 55);
                if ( v25 != v26 )
                {
                  LODWORD(qword_9880) = v27;
                  HIDWORD(qword_9880) = v28;
                  LODWORD(qword_9878) = v25;
                  HIDWORD(qword_9878) = v26;
                  v29 = readl_relaxed(v4 + 60);
                  v30 = readl_relaxed(v4 + 61);
                  v31 = readl_relaxed(v4 + 62);
                  v32 = readl_relaxed(v4 + 63);
                  if ( v29 != v30 )
                  {
                    LODWORD(qword_9888) = v29;
                    HIDWORD(qword_9888) = v30;
                    LODWORD(qword_9890) = v31;
                    HIDWORD(qword_9890) = v32;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      printk(&unk_866E, "spss_get_apps_calc_cmac");
    }
    v34 = qword_9830;
    *a3 = calc_apps_cmac;
    a3[1] = v34;
    v35 = qword_9850;
    v36 = qword_9838;
    v37 = qword_9840;
    a3[4] = qword_9848;
    a3[5] = v35;
    a3[2] = v36;
    a3[3] = v37;
    v38 = qword_9870;
    v39 = qword_9858;
    v40 = qword_9860;
    a3[8] = qword_9868;
    a3[9] = v38;
    a3[6] = v39;
    a3[7] = v40;
    v41 = qword_9890;
    v42 = qword_9878;
    v43 = qword_9880;
    a3[12] = qword_9888;
    a3[13] = v41;
    a3[10] = v42;
    a3[11] = v43;
    return 112;
  }
  else
  {
    printk(&unk_8619, "calc_apps_cmac_show");
    return -22;
  }
}

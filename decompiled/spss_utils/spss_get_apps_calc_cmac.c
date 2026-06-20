__int64 spss_get_apps_calc_cmac()
{
  unsigned int *v0; // x22
  int v1; // w19
  int v2; // w20
  int v3; // w21
  __int64 result; // x0
  int v5; // w19
  int v6; // w20
  int v7; // w21
  int v8; // w19
  int v9; // w20
  int v10; // w21
  int v11; // w19
  int v12; // w20
  int v13; // w21
  int v14; // w19
  int v15; // w20
  int v16; // w21
  int v17; // w19
  int v18; // w20
  int v19; // w21
  int v20; // w19
  int v21; // w20
  int v22; // w21

  v0 = (unsigned int *)cmac_mem;
  if ( !cmac_mem )
    return printk(&unk_866E, "spss_get_apps_calc_cmac");
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
  v1 = readl_relaxed((unsigned int *)(cmac_mem + 48));
  v2 = readl_relaxed(v0 + 13);
  v3 = readl_relaxed(v0 + 14);
  result = readl_relaxed(v0 + 15);
  if ( v1 != v2 )
  {
    LODWORD(qword_9830) = v3;
    HIDWORD(qword_9830) = result;
    LODWORD(calc_apps_cmac) = v1;
    HIDWORD(calc_apps_cmac) = v2;
    v5 = readl_relaxed(v0 + 20);
    v6 = readl_relaxed(v0 + 21);
    v7 = readl_relaxed(v0 + 22);
    result = readl_relaxed(v0 + 23);
    if ( v5 != v6 )
    {
      LODWORD(qword_9840) = v7;
      HIDWORD(qword_9840) = result;
      LODWORD(qword_9838) = v5;
      HIDWORD(qword_9838) = v6;
      v8 = readl_relaxed(v0 + 28);
      v9 = readl_relaxed(v0 + 29);
      v10 = readl_relaxed(v0 + 30);
      result = readl_relaxed(v0 + 31);
      if ( v8 != v9 )
      {
        LODWORD(qword_9850) = v10;
        HIDWORD(qword_9850) = result;
        LODWORD(qword_9848) = v8;
        HIDWORD(qword_9848) = v9;
        v11 = readl_relaxed(v0 + 36);
        v12 = readl_relaxed(v0 + 37);
        v13 = readl_relaxed(v0 + 38);
        result = readl_relaxed(v0 + 39);
        if ( v11 != v12 )
        {
          LODWORD(qword_9860) = v13;
          HIDWORD(qword_9860) = result;
          LODWORD(qword_9858) = v11;
          HIDWORD(qword_9858) = v12;
          v14 = readl_relaxed(v0 + 44);
          v15 = readl_relaxed(v0 + 45);
          v16 = readl_relaxed(v0 + 46);
          result = readl_relaxed(v0 + 47);
          if ( v14 != v15 )
          {
            LODWORD(qword_9870) = v16;
            HIDWORD(qword_9870) = result;
            LODWORD(qword_9868) = v14;
            HIDWORD(qword_9868) = v15;
            v17 = readl_relaxed(v0 + 52);
            v18 = readl_relaxed(v0 + 53);
            v19 = readl_relaxed(v0 + 54);
            result = readl_relaxed(v0 + 55);
            if ( v17 != v18 )
            {
              LODWORD(qword_9880) = v19;
              HIDWORD(qword_9880) = result;
              LODWORD(qword_9878) = v17;
              HIDWORD(qword_9878) = v18;
              v20 = readl_relaxed(v0 + 60);
              v21 = readl_relaxed(v0 + 61);
              v22 = readl_relaxed(v0 + 62);
              result = readl_relaxed(v0 + 63);
              if ( v20 != v21 )
              {
                LODWORD(qword_9888) = v20;
                HIDWORD(qword_9888) = v21;
                LODWORD(qword_9890) = v22;
                HIDWORD(qword_9890) = result;
              }
            }
          }
        }
      }
    }
  }
  return result;
}

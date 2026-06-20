__int64 __fastcall msm_m31_eusb2_phy_set_suspend(__int64 a1, int a2)
{
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  void (*v8)(void); // x8
  void (*v9)(void); // x8
  __int64 v10; // x21
  __int64 v11; // x21
  __int64 v12; // x21
  __int64 v13; // x0

  if ( !a2 || (*(_BYTE *)(a1 + 470) & 1) == 0 )
  {
    if ( a2 )
    {
      if ( (*(_BYTE *)(a1 + 471) & 1) != 0 || (v4 = *(_DWORD *)(a1 + 16), (v4 & 1) != 0) )
      {
        if ( *(_BYTE *)(a1 + 468) )
        {
          v10 = *(_QWORD *)(a1 + 416);
          if ( v10 )
          {
            clk_disable(*(_QWORD *)(a1 + 416));
            clk_unprepare(v10);
          }
          v11 = *(_QWORD *)(a1 + 408);
          clk_disable(v11);
          clk_unprepare(v11);
          *(_BYTE *)(a1 + 468) = 0;
        }
        v12 = *(_QWORD *)(a1 + 416);
        if ( v12 )
        {
          if ( (*(_BYTE *)(a1 + 472) & 1) == 0 )
          {
            v13 = *(_QWORD *)(a1 + 416);
            *(_BYTE *)(a1 + 472) = 1;
            if ( !(unsigned int)clk_prepare(v13) )
            {
              if ( (unsigned int)clk_enable(v12) )
                clk_unprepare(v12);
            }
          }
        }
      }
      else
      {
        if ( *(_BYTE *)(a1 + 400) == 1 )
        {
          qcom_scm_io_writel(*(_QWORD *)(a1 + 376), 1);
          v4 = *(_DWORD *)(a1 + 16);
          *(_BYTE *)(a1 + 400) = 0;
        }
        if ( (v4 & 0x40) == 0 )
        {
          v5 = *(_QWORD *)(a1 + 384);
          if ( !v5 || (readl_relaxed(v5) & 1) == 0 )
          {
            v6 = *(_QWORD *)(a1 + 416);
            if ( v6 && *(_BYTE *)(a1 + 472) == 1 )
            {
              clk_disable(*(_QWORD *)(a1 + 416));
              clk_unprepare(v6);
              *(_BYTE *)(a1 + 472) = 0;
            }
            msm_m31_eusb2_phy_clocks(a1, 0);
            msm_m31_eusb2_phy_power(a1, 0);
            v7 = *(_QWORD *)(a1 + 560);
            if ( v7 )
            {
              v8 = *(void (**)(void))(v7 + 40);
              if ( !v8 )
                goto LABEL_19;
              if ( *((_DWORD *)v8 - 1) != -2106062652 )
                __break(0x8228u);
              v8();
              v7 = *(_QWORD *)(a1 + 560);
              if ( v7 )
              {
LABEL_19:
                v9 = *(void (**)(void))(v7 + 72);
                if ( v9 )
                {
                  if ( *((_DWORD *)v9 - 1) != -867545059 )
                    __break(0x8228u);
                  v9();
                }
              }
            }
          }
        }
      }
    }
    else
    {
      msm_m31_eusb2_phy_clocks(a1, 1);
    }
    *(_BYTE *)(a1 + 470) = a2 != 0;
  }
  return 0;
}

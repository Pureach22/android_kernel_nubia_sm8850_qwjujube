__int64 __fastcall msm_m31_eusb2_phy_clocks(__int64 result, char a2)
{
  char v2; // w21
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // x20

  v2 = a2 & 1;
  if ( *(_BYTE *)(result + 468) != (a2 & 1) )
  {
    v3 = result;
    if ( (a2 & 1) != 0 )
    {
      v4 = *(_QWORD *)(result + 408);
      if ( !(unsigned int)clk_prepare(v4) && (unsigned int)clk_enable(v4) )
        clk_unprepare(v4);
      v5 = *(_QWORD *)(v3 + 416);
      if ( v5 && !(unsigned int)clk_prepare(*(_QWORD *)(v3 + 416)) )
      {
        if ( (unsigned int)clk_enable(v5) )
          clk_unprepare(v5);
      }
      result = usleep_range_state(1500, 2000, 2);
    }
    else
    {
      v6 = *(_QWORD *)(result + 416);
      if ( v6 )
      {
        clk_disable(*(_QWORD *)(result + 416));
        clk_unprepare(v6);
      }
      v7 = *(_QWORD *)(v3 + 408);
      clk_disable(v7);
      result = clk_unprepare(v7);
    }
    *(_BYTE *)(v3 + 468) = v2;
  }
  return result;
}

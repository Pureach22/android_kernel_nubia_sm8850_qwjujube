__int64 __fastcall m31eusb2_phy_clocks(__int64 a1, char a2)
{
  char v2; // w21
  __int64 result; // x0
  __int64 v5; // x20
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 v8; // x20
  __int64 v9; // x20

  v2 = a2 & 1;
  if ( *(_BYTE *)(a1 + 96) == (a2 & 1) )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    v8 = *(_QWORD *)(a1 + 80);
    if ( v8 )
    {
      clk_disable(*(_QWORD *)(a1 + 80));
      clk_unprepare(v8);
    }
    v9 = *(_QWORD *)(a1 + 72);
    clk_disable(v9);
LABEL_10:
    clk_unprepare(v9);
    goto LABEL_11;
  }
  v5 = *(_QWORD *)(a1 + 72);
  result = clk_prepare(v5);
  if ( (_DWORD)result )
    return result;
  v6 = clk_enable(v5);
  if ( v6 )
  {
    v7 = v6;
    clk_unprepare(v5);
    return v7;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( v9 && !(unsigned int)clk_prepare(*(_QWORD *)(a1 + 80)) && (unsigned int)clk_enable(v9) )
    goto LABEL_10;
LABEL_11:
  result = 0;
  *(_BYTE *)(a1 + 96) = v2;
  return result;
}

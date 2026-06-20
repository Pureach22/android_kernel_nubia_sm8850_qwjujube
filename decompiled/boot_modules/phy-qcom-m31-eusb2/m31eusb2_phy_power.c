__int64 __fastcall m31eusb2_phy_power(__int64 result, char a2)
{
  char v2; // w20
  __int64 v3; // x19
  int v4; // w0

  v2 = a2 & 1;
  if ( *(_BYTE *)(result + 97) != (a2 & 1) )
  {
    v3 = result;
    if ( (a2 & 1) != 0 )
    {
      result = regulator_bulk_enable(3, *(_QWORD *)(result + 48));
      if ( (_DWORD)result )
        return result;
      result = writel_relaxed(1, *(_QWORD *)(v3 + 24));
    }
    else
    {
      v4 = readl_relaxed(*(_QWORD *)(result + 24));
      writel_relaxed(v4 & 0xFFFFFFFE, *(_QWORD *)(v3 + 24));
      __dsb(0xFu);
      result = regulator_bulk_disable(3, *(_QWORD *)(v3 + 48));
    }
    *(_BYTE *)(v3 + 97) = v2;
  }
  return result;
}

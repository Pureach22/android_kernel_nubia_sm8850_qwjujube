__int64 __fastcall sdam_read(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  unsigned int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w22

  v4 = *(_QWORD *)(a1 + 8);
  if ( a4
    && (a2 >= 0x40 && (v7 = *(_DWORD *)(a1 + 164) + 63, v7 >= a2) && a4 + (unsigned __int64)a2 - 1 <= v7
     || a2 - 229 <= 1 && a4 == 1) )
  {
    result = regmap_bulk_read(*(_QWORD *)a1, *(_DWORD *)(a1 + 160) + a2, a3, a4);
    if ( (result & 0x80000000) != 0 )
    {
      v9 = result;
      dev_err(v4, "Failed to read SDAM offset %#x len=%zd, rc=%d\n", a2, a4, result);
      return v9;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 8), "Invalid SDAM offset %#x len=%zd\n", a2, a4);
    return 4294967274LL;
  }
  return result;
}

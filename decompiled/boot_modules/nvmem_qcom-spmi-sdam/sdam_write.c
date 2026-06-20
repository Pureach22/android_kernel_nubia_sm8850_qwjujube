__int64 __fastcall sdam_write(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  unsigned int v7; // w9
  unsigned __int64 v8; // x8
  __int64 result; // x0
  unsigned int v10; // w22

  v4 = *(_QWORD *)(a1 + 8);
  if ( !a4 )
    goto LABEL_17;
  if ( a2 >= 0x40 )
  {
    v7 = *(_DWORD *)(a1 + 164) + 63;
    if ( v7 >= a2 )
    {
      v8 = a2 + a4;
      if ( v8 - 1 <= v7 )
      {
        if ( (a2 > 0x40 || v8 <= 0x40) && (a2 > 0x41 || v8 <= 0x41) && (a2 > 0x44 || v8 < 0x45) )
          goto LABEL_7;
        dev_err(*(_QWORD *)(a1 + 8), "Invalid write offset %#x len=%zd\n", a2, a4);
        return 4294967274LL;
      }
    }
  }
  if ( a2 - 229 > 1 || a4 != 1 )
  {
LABEL_17:
    dev_err(*(_QWORD *)(a1 + 8), "Invalid SDAM offset %#x len=%zd\n", a2, a4);
    return 4294967274LL;
  }
LABEL_7:
  result = regmap_bulk_write(*(_QWORD *)a1, *(_DWORD *)(a1 + 160) + a2, a3, a4);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = result;
    dev_err(v4, "Failed to write SDAM offset %#x len=%zd, rc=%d\n", a2, a4, result);
    return v10;
  }
  return result;
}

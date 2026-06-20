__int64 __fastcall gmu_core_enable_clks(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  unsigned int v5; // w20
  __int64 v6; // x21
  unsigned int v7; // w0
  unsigned int v8; // w22

  v2 = *(_DWORD *)(a1 + 8652);
  *(_DWORD *)(a1 + 8656) = v2;
  result = gmu_core_clock_set_rate(a1, a2, v2);
  if ( !(_DWORD)result )
  {
    v5 = *(_DWORD *)(a1 + 8320);
    v6 = *(_QWORD *)(a1 + 8312);
    v7 = clk_bulk_prepare(v5, v6);
    if ( v7 )
    {
      v8 = v7;
    }
    else
    {
      result = clk_bulk_enable(v5, v6);
      if ( !(_DWORD)result )
      {
        *(_DWORD *)(a1 + 11120) = 32;
        return result;
      }
      v8 = result;
      clk_bulk_unprepare(v5, v6);
    }
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Cannot enable GMU clocks ret %d\n", v8);
    return v8;
  }
  return result;
}

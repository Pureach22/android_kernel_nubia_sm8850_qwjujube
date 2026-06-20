__int64 __usercall gmu_core_clock_set_rate@<X0>(__int64 a1@<X0>, unsigned int a2@<W1>, unsigned int a3@<W8>)
{
  int v3; // w9
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v7; // x8
  unsigned int v8; // w21
  int v9; // w0
  unsigned int v10; // w10
  int v11; // w10
  bool v12; // zf
  unsigned int v13; // w20
  __int64 result; // x0
  int v15; // w0
  __int64 v16; // x8
  unsigned int v17; // w19
  __int64 v18; // x8
  unsigned int v19; // w19

  if ( a2 >= 0x10 )
    goto LABEL_62;
  v5 = a2;
  v7 = *(_QWORD *)(a1 + 8288);
  v4 = a1;
  v8 = *(_DWORD *)(a1 + 8324 + 4LL * a2);
  if ( v7 )
  {
    writel_relaxed_0(v8 / 0xF4240, (unsigned int *)(v7 + *(unsigned int *)(a1 + 8304)));
    __dsb(0xEu);
  }
  v9 = kgsl_clk_set_rate(*(_QWORD *)(v4 + 8312), *(_DWORD *)(v4 + 8320), "gmu_clk");
  if ( v9 )
  {
    v16 = *(_QWORD *)(v4 + 1544);
    v17 = v9;
    dev_err(v16 + 16, "GMU clock:%d set failed:%d\n", v8, v9);
    return v17;
  }
  else
  {
    a3 = *(_DWORD *)(v4 + 8520);
    if ( a3 > 0xF )
      goto LABEL_62;
    v3 = *(_DWORD *)(v4 + 8652);
    *(_DWORD *)(v4 + 8520) = a2;
    a3 = v3 - 1;
    if ( v3 < 1 || (v10 = *(_DWORD *)(v4 + 4 * v5 + 8392), *(_DWORD *)(v4 + 8588) <= v10) )
    {
      v11 = 0;
    }
    else if ( v3 == 1 || *(_DWORD *)(v4 + 8592) <= v10 )
    {
      v11 = 1;
    }
    else if ( v3 == 2 || *(_DWORD *)(v4 + 8596) <= v10 )
    {
      v11 = 2;
    }
    else if ( v3 == 3 || *(_DWORD *)(v4 + 8600) <= v10 )
    {
      v11 = 3;
    }
    else if ( v3 == 4 || *(_DWORD *)(v4 + 8604) <= v10 )
    {
      v11 = 4;
    }
    else if ( v3 == 5 || *(_DWORD *)(v4 + 8608) <= v10 )
    {
      v11 = 5;
    }
    else if ( v3 == 6 || *(_DWORD *)(v4 + 8612) <= v10 )
    {
      v11 = 6;
    }
    else if ( v3 == 7 || *(_DWORD *)(v4 + 8616) <= v10 )
    {
      v11 = 7;
    }
    else if ( v3 == 8 || *(_DWORD *)(v4 + 8620) <= v10 )
    {
      v11 = 8;
    }
    else if ( v3 == 9 || *(_DWORD *)(v4 + 8624) <= v10 )
    {
      v11 = 9;
    }
    else
    {
      if ( v3 == 10 || *(_DWORD *)(v4 + 8628) <= v10 )
        goto LABEL_63;
      if ( v3 == 11 || *(_DWORD *)(v4 + 8632) <= v10 )
      {
        v11 = 11;
      }
      else if ( v3 == 12 || *(_DWORD *)(v4 + 8636) <= v10 )
      {
        v11 = 12;
      }
      else if ( v3 == 13 || *(_DWORD *)(v4 + 8640) <= v10 )
      {
        v11 = 13;
      }
      else if ( v3 == 14 || *(_DWORD *)(v4 + 8644) <= v10 )
      {
        v11 = 14;
      }
      else if ( v3 == 15 || *(_DWORD *)(v4 + 8648) <= v10 )
      {
        v11 = 15;
      }
      else
      {
        if ( v3 != 16 )
          goto LABEL_62;
        v11 = 16;
      }
    }
    while ( 1 )
    {
      v12 = v11 == v3;
      v3 = *(_DWORD *)(v4 + 8656);
      if ( v12 )
        v13 = a3;
      else
        v13 = v11;
      if ( v13 == v3 )
        return 0;
      if ( v13 <= 0xF )
        break;
LABEL_62:
      __break(0x5512u);
LABEL_63:
      v11 = 10;
    }
    v15 = kgsl_clk_set_rate(*(_QWORD *)(v4 + 8312), *(_DWORD *)(v4 + 8320), "hub_clk");
    if ( v15 != -19 && v15 )
    {
      v18 = *(_QWORD *)(v4 + 1544);
      v19 = v15;
      dev_err(v18 + 16, "Unable to set the HUB clock ret %d\n", v15);
      return v19;
    }
    else
    {
      result = 0;
      *(_DWORD *)(v4 + 8656) = v13;
    }
  }
  return result;
}

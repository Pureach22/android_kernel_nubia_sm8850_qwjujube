__int64 __fastcall dp_hw_link_desc_ring_free(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w20
  __int64 v10; // x19
  __int64 (*v11)(void); // x8
  __int64 i; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v9 = *(_DWORD *)(result + 12952);
  v10 = result;
  v11 = *(__int64 (**)(void))(*(_QWORD *)(result + 8) + 200LL);
  if ( !v11 )
    goto LABEL_13;
  if ( *((_DWORD *)v11 - 1) != 1696218653 )
    __break(0x8228u);
  result = v11();
  if ( (_DWORD)result != 5 )
  {
LABEL_13:
    if ( *(_QWORD *)(v10 + 2168) )
    {
      for ( i = 0; i != 128; i += 8 )
      {
        if ( *(_QWORD *)(v10 + i + 2168) )
          result = _qdf_mem_free_consistent(*(_QWORD *)(v10 + 24), *(_QWORD *)(*(_QWORD *)(v10 + 24) + 40LL), v9);
      }
    }
    else
    {
      wlan_minidump_remove(
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        *(_QWORD *)(v10 + 1968),
        *(unsigned int *)(v10 + 2000),
        *(_QWORD *)(v10 + 16));
      return dp_srng_free(v10, v10 + 1960, v13, v14, v15, v16, v17, v18, v19, v20);
    }
  }
  return result;
}

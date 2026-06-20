__int64 __fastcall gen7_set_isdb_breakpoint_registers(__int64 result)
{
  __int64 v1; // x22
  _QWORD *v2; // x19
  __int64 (*v3)(void); // x8
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x20
  int v6; // w0
  int v7; // w0
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned __int64 v10; // t2
  int v11; // w21

  v1 = result + 0x2000;
  if ( *(_BYTE *)(result + 11303) == 1 )
  {
    v2 = (_QWORD *)result;
    v3 = *(__int64 (**)(void))(*(_QWORD *)(result + 8752) + 240LL);
    if ( *((_DWORD *)v3 - 1) != 33171575 )
      __break(0x8228u);
    result = v3();
    if ( (result & 1) == 0 && v2[4] && *(_BYTE *)(v1 + 3108) == 1 )
    {
      v4 = clk_get(v2[1396] + 16LL, "apb_pclk");
      if ( v4 >= 0xFFFFFFFFFFFFF001LL )
      {
        result = dev_err(*v2, "Unable to get QDSS clock\n");
        *(_BYTE *)(v1 + 3108) = 0;
        return result;
      }
      v5 = v4;
      v6 = clk_prepare();
      if ( v6 )
      {
        v11 = v6;
      }
      else
      {
        v7 = clk_enable(v5);
        if ( !v7 )
        {
          isdb_write(v2[4], 0);
          isdb_write(v2[4], 4096);
          isdb_write(v2[4], 0x2000);
          isdb_write(v2[4], 12288);
          isdb_write(v2[4], 0x4000);
          isdb_write(v2[4], 20480);
          isdb_write(v2[4], 24576);
          isdb_write(v2[4], 28672);
          v8 = *(_DWORD *)v2[1783];
          if ( v8 - 459264 < 2
            || v8 == 460288
            || v8 >> 1 == 230528
            || (HIDWORD(v10) = v8 - 461568, LODWORD(v10) = v8 - 461568, v9 = v10 >> 8, v9 <= 6)
            && ((1 << v9) & 0x59) != 0 )
          {
            isdb_write(v2[4], 0x8000);
            isdb_write(v2[4], 36864);
            isdb_write(v2[4], 40960);
            isdb_write(v2[4], 45056);
          }
          clk_disable(v5);
          clk_unprepare(v5);
          return clk_put(v5);
        }
        v11 = v7;
        clk_unprepare(v5);
      }
      dev_err(*v2, "QDSS Clock enable error: %d\n", v11);
      result = clk_put(v5);
      *(_BYTE *)(v1 + 3108) = 0;
    }
  }
  return result;
}

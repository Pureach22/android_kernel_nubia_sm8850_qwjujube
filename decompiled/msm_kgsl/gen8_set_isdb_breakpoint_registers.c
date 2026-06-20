__int64 __fastcall gen8_set_isdb_breakpoint_registers(__int64 result)
{
  __int64 v1; // x22
  _QWORD *v2; // x19
  __int64 (*v3)(void); // x8
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x20
  int v6; // w0
  int v7; // w0
  int v8; // w21

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
      }
      else
      {
        v5 = v4;
        v6 = clk_prepare();
        if ( v6 )
        {
          v8 = v6;
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
            isdb_write(v2[4], 0x8000);
            isdb_write(v2[4], 36864);
            isdb_write(v2[4], 40960);
            isdb_write(v2[4], 45056);
            clk_disable(v5);
            clk_unprepare(v5);
            return clk_put(v5);
          }
          v8 = v7;
          clk_unprepare(v5);
        }
        dev_err(*v2, "QDSS Clock enable error: %d\n", v8);
        result = clk_put(v5);
      }
      *(_BYTE *)(v1 + 3108) = 0;
    }
  }
  return result;
}

__int64 __fastcall bimc_clk_prepare_enable(_QWORD *a1, __int64 a2)
{
  int v4; // w0
  __int64 result; // x0
  int v6; // w21

  v4 = clk_prepare(a2);
  if ( v4 )
  {
    v6 = v4;
    return dev_err(*a1, "GPU clock %s enable error:%d\n", "bimc_gpu_clk", v6);
  }
  result = clk_enable(a2);
  if ( (_DWORD)result )
  {
    v6 = result;
    clk_unprepare(a2);
    return dev_err(*a1, "GPU clock %s enable error:%d\n", "bimc_gpu_clk", v6);
  }
  return result;
}

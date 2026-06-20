__int64 __fastcall sde_connector_clk_get_rate_esync(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  __int64 v6; // x1

  if ( a1 )
  {
    result = *(_QWORD *)(a1 + 2760);
    if ( result )
    {
      v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 3016);
      if ( v5 )
      {
        v6 = *(unsigned int *)(result + 836);
        if ( *((_DWORD *)v5 - 1) != -1798534149 )
          __break(0x8228u);
        return v5(result, v6, 4, a3);
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_clk_get_rate_esync");
    return 4294967274LL;
  }
  return result;
}

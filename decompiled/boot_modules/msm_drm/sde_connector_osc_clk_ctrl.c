__int64 __fastcall sde_connector_osc_clk_ctrl(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v3)(void); // x8

  if ( a1 )
  {
    result = *(_QWORD *)(a1 + 2760);
    if ( result )
    {
      v3 = *(__int64 (**)(void))(a1 + 3008);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != -1378032659 )
          __break(0x8228u);
        return v3();
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_osc_clk_ctrl");
    return 4294967274LL;
  }
  return result;
}

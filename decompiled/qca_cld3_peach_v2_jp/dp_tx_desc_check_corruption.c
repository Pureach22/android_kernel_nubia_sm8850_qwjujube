__int64 __fastcall dp_tx_desc_check_corruption(
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
  __int64 v9; // x29
  __int64 v10; // x30
  int v11; // w8
  __int64 v12; // x20

  v11 = *(_DWORD *)(result + 20);
  if ( v11 != -1412623820 && v11 != -559038737 )
  {
    v12 = jiffies;
    if ( dp_tx_desc_check_corruption___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: tx_desc %u is corrupted",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "dp_tx_desc_check_corruption",
        *(unsigned int *)(result + 36),
        v9,
        v10);
      dp_tx_desc_check_corruption___last_ticks = v12;
    }
    return _qdf_trigger_self_recovery();
  }
  return result;
}

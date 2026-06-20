__int64 __fastcall hif_register_tbl_attach(__int64 result, int a2)
{
  const char *v2; // x2

  if ( a2 <= 25 )
  {
    switch ( a2 )
    {
      case 8:
        *(_QWORD *)(result + 632) = &ar6320v2_hostdef;
        break;
      case 10:
        *(_QWORD *)(result + 632) = &adrastea_hostdef;
        *(_QWORD *)(result + 640) = &adrastea_host_shadow_regs;
        break;
      case 17:
        *(_QWORD *)(result + 632) = &genoa_hostdef;
        *(_QWORD *)(result + 640) = &genoa_host_shadow_regs;
        break;
    }
  }
  else
  {
    if ( a2 > 31 )
    {
      if ( a2 == 32 )
      {
        v2 = "%s: HIF_TYPE_PEACH";
      }
      else
      {
        if ( a2 != 38 )
          return result;
        v2 = "%s: HIF_TYPE_FIG";
      }
    }
    else if ( a2 == 26 )
    {
      v2 = "%s: HIF_TYPE_KIWI";
    }
    else
    {
      if ( a2 != 29 )
        return result;
      v2 = "%s: HIF_TYPE_MANGO";
    }
    *(_QWORD *)(result + 632) = KIWI_HOSTdef;
    return qdf_trace_msg(61, 5, v2, "hif_register_tbl_attach");
  }
  return result;
}

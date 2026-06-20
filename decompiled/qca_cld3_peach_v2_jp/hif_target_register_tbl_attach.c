__int64 __fastcall hif_target_register_tbl_attach(__int64 result, int a2)
{
  const char *v2; // x2
  void *v3; // x9

  if ( a2 > 30 )
  {
    if ( a2 > 36 )
    {
      if ( a2 == 37 )
      {
        v2 = "%s: TARGET_TYPE_PEACH";
      }
      else
      {
        if ( a2 != 43 )
          return result;
        v2 = "%s: TARGET_TYPE_FIG";
      }
    }
    else if ( a2 == 31 )
    {
      v2 = "%s: TARGET_TYPE_KIWI";
    }
    else
    {
      if ( a2 != 34 )
        return result;
      v2 = "%s: TARGET_TYPE_MANGO";
    }
    v3 = KIWI_CE_TARGETdef;
    *(_QWORD *)(result + 616) = KIWI_TARGETdef;
    *(_QWORD *)(result + 624) = v3;
    return qdf_trace_msg(61, 5, v2, "hif_target_register_tbl_attach");
  }
  else if ( a2 > 18 )
  {
    if ( a2 == 19 )
    {
      *(_QWORD *)(result + 616) = &adrastea_targetdef;
      *(_QWORD *)(result + 624) = &adrastea_ce_targetdef;
    }
    else if ( a2 == 22 )
    {
      *(_QWORD *)(result + 616) = &genoa_targetdef;
      *(_QWORD *)(result + 624) = &genoa_ce_targetdef;
    }
  }
  else if ( a2 == 8 )
  {
    *(_QWORD *)(result + 616) = &ar6320_targetdef;
    *(_QWORD *)(result + 624) = &ar6320_ce_targetdef;
  }
  else if ( a2 == 12 )
  {
    *(_QWORD *)(result + 616) = &ar6320v2_targetdef;
    *(_QWORD *)(result + 624) = &ar6320v2_ce_targetdef;
  }
  return result;
}

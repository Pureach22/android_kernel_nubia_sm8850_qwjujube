__int64 __fastcall wlan_objmgr_psoc_obj_free(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 i; // x22

  if ( (unsigned int)wlan_objmgr_psoc_object_detach(a1) == 16 )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: PSOC object detach failed",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_objmgr_psoc_obj_free");
    return 16;
  }
  else
  {
    for ( i = 144; i != 1680; i += 24 )
    {
      if ( *(_DWORD *)(a1 + i) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          "qdf_list_destroy");
    }
    _qdf_mem_free(a1);
    return 0;
  }
}

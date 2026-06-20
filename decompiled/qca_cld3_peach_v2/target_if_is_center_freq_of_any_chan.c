__int64 __fastcall target_if_is_center_freq_of_any_chan(
        __int64 a1,
        int a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  void *v14; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v24; // x2
  __int64 v26; // x9

  if ( !a1 )
  {
    v24 = "%s: pdev object is null";
LABEL_8:
    qdf_trace_msg(0x56u, 2u, v24, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_is_center_freq_of_any_chan");
    return 16;
  }
  if ( !a3 )
  {
    v24 = "%s: is valid argument is null";
    goto LABEL_8;
  }
  v14 = (void *)_qdf_mem_malloc(0xE58u, "target_if_is_center_freq_of_any_chan", 4274);
  if ( !v14 )
    return 16;
  v15 = (__int64)v14;
  if ( (unsigned int)wlan_reg_get_current_chan_list(a1, v14) )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Failed to get cur_chan list",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_is_center_freq_of_any_chan");
    _qdf_mem_free(v15);
    return 16;
  }
  v26 = 0;
  *a3 = 0;
  while ( (*(_BYTE *)(v15 + v26 + 12) & 1) != 0 || *(_DWORD *)(v15 + v26) != a2 )
  {
    v26 += 36;
    if ( v26 == 3672 )
      goto LABEL_16;
  }
  *a3 = 1;
LABEL_16:
  _qdf_mem_free(v15);
  return 0;
}

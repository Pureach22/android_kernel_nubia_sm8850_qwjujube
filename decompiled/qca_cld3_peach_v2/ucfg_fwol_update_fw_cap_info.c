void *__fastcall ucfg_fwol_update_fw_cap_info(__int64 a1, const void *a2)
{
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
    return qdf_mem_copy((void *)(psoc_obj + 1440), a2, 1u);
  else
    return (void *)qdf_trace_msg(
                     0x66u,
                     2u,
                     "%s: Failed to get fwol obj",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "ucfg_fwol_update_fw_cap_info");
}

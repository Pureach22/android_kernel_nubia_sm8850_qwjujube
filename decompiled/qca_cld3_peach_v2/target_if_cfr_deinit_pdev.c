__int64 __fastcall target_if_cfr_deinit_pdev(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  unsigned int v14; // w0
  __int64 comp_private_obj; // x0
  const char *v17; // x2
  const char *v18; // x3
  const char *v19; // x2

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v11 = *(__int64 (**)(void))(v10 + 1736);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 1468042957 )
        __break(0x8228u);
      v14 = v11();
      if ( v14 <= 0x2B )
      {
        if ( ((1LL << v14) & 0xD6498000000LL) != 0 )
        {
          if ( a2 )
          {
            comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a2, 0x1Eu);
            if ( comp_private_obj )
            {
              if ( *(_BYTE *)(comp_private_obj + 8) )
                return cfr_enh_deinit_pdev(a1, a2);
              v17 = "%s: cfr disabled or FW not support";
              v18 = "target_if_cfr_deinit_target";
              goto LABEL_14;
            }
            v19 = "%s: null pdev cfr";
          }
          else
          {
            v19 = "%s: null pdev or psoc";
          }
          qdf_trace_msg(0x6Au, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_deinit_target");
          return 16;
        }
        if ( v14 == 19 )
          return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cfr_get_target_type");
  }
  v17 = "%s: unsupported chip";
  v18 = "target_if_cfr_deinit_pdev";
LABEL_14:
  qdf_trace_msg(0x6Au, 4u, v17, a3, a4, a5, a6, a7, a8, a9, a10, v18);
  return 0;
}

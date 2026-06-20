__int64 __fastcall nan_cfg_psoc_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
    {
      v19 = comp_private_obj;
      *(_DWORD *)(comp_private_obj + 208) = *(_DWORD *)(comp_private_obj + 208) & 0xFFFFFFFE
                                          | *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10428);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFEF
                             | (16 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10436) & 1));
      *(_WORD *)(v19 + 214) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10432);
      *(_DWORD *)(v19 + 216) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10448);
      *(_DWORD *)(v19 + 220) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10452);
      *(_DWORD *)(v19 + 224) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10456);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFDF
                             | (32 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10429) & 1));
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFBF
                             | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 10460) & 1) << 6);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFF7F
                             | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 3993) & 1) << 7);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFEFF
                             | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 3995) & 1) << 8);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFDFF
                             | ((*(_BYTE *)(cfg_psoc_get_values(a1) + 3996) & 1) << 9);
      *(_DWORD *)(v19 + 228) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10464);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFFD
                             | (2 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10437) & 1));
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFFB
                             | (4 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10438) & 1));
      *(_WORD *)(v19 + 212) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10440);
      *(_DWORD *)(v19 + 208) = *(_DWORD *)(v19 + 208) & 0xFFFFFFF7
                             | (8 * (*(_BYTE *)(cfg_psoc_get_values(a1) + 10444) & 1));
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: nan psoc priv object is NULL",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "nan_cfg_psoc_open");
  return 29;
}

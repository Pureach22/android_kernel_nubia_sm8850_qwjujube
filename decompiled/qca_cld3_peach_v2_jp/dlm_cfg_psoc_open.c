__int64 __fastcall dlm_cfg_psoc_open(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 values; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x20u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    *(_QWORD *)(comp_private_obj + 8) = *(unsigned int *)cfg_psoc_get_values(a1);
    *(_QWORD *)(v11 + 16) = *(unsigned int *)(cfg_psoc_get_values(a1) + 8);
    *(_QWORD *)(v11 + 24) = *(unsigned int *)(cfg_psoc_get_values(a1) + 12);
    *(_BYTE *)(v11 + 40) = *(_DWORD *)(cfg_psoc_get_values(a1) + 4);
    *(_DWORD *)(v11 + 44) = *(_DWORD *)(cfg_psoc_get_values(a1) + 16);
    values = cfg_psoc_get_values(a1);
    *(_QWORD *)(v11 + 32) = *(unsigned int *)(values + 20);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x6Du, 2u, "%s: DLM psoc obj NULL", v3, v4, v5, v6, v7, v8, v9, v10, "dlm_cfg_psoc_open");
    return 16;
  }
}

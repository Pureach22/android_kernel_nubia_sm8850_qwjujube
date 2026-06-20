__int64 __fastcall ucfg_dlm_resume_handler(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  psoc_obj = dlm_get_psoc_obj(a1);
  if ( psoc_obj )
    *(_BYTE *)(psoc_obj + 1) = 0;
  else
    qdf_trace_msg(0x6Du, 2u, "%s: DLM psoc obj NULL", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_dlm_psoc_set_suspended");
  dlm_update_reject_ap_list_to_fw(a1);
  return 0;
}

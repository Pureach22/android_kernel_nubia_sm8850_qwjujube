__int64 __fastcall ucfg_dlm_suspend_handler(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  psoc_obj = dlm_get_psoc_obj(a1);
  if ( psoc_obj )
    *(_BYTE *)(psoc_obj + 1) = 1;
  else
    qdf_trace_msg(0x6Du, 2u, "%s: DLM psoc obj NULL", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_dlm_psoc_set_suspended");
  return 0;
}

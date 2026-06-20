__int64 __fastcall ucfg_dlm_psoc_set_suspended(__int64 a1, char a2)
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
  __int64 v12; // x8

  psoc_obj = dlm_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = psoc_obj;
    *(_BYTE *)(v12 + 1) = a2 & 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x6Du, 2u, "%s: DLM psoc obj NULL", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_dlm_psoc_set_suspended");
    return 16;
  }
}

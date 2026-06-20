__int64 __fastcall ucfg_dlm_psoc_get_suspended(__int64 a1, char *a2)
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
  char v12; // w8
  __int64 result; // x0

  psoc_obj = dlm_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = *(_BYTE *)(psoc_obj + 1);
    result = 0;
  }
  else
  {
    qdf_trace_msg(0x6Du, 2u, "%s: DLM psoc obj NULL", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_dlm_psoc_get_suspended");
    result = 16;
    v12 = 1;
  }
  *a2 = v12;
  return result;
}

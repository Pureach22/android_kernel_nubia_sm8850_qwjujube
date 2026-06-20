__int64 __fastcall lim_translate_rsn_oui_to_akm_type(const void *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _DWORD *v10; // x21
  unsigned int v11; // w19
  int v12; // w0

  if ( (unsigned int)qdf_mem_cmp(a1, &unk_A09534, 4u) )
  {
    v10 = &unk_A0953C;
    do
    {
      v11 = *(v10 - 1);
      if ( v11 == 255 )
        break;
      v12 = qdf_mem_cmp(a1, v10, 4u);
      v10 += 2;
    }
    while ( v12 );
  }
  else
  {
    v11 = 1;
  }
  qdf_trace_msg(0x35u, 8u, "%s: akm_type: %d", v2, v3, v4, v5, v6, v7, v8, v9, "lim_translate_rsn_oui_to_akm_type", v11);
  return v11;
}

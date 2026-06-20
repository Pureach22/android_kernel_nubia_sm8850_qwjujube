double __fastcall reg_set_socpriv_vars(
        __int64 a1,
        _WORD *a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v15; // x20
  bool v16; // zf
  double result; // d0
  int v18; // w8
  _WORD *v21; // x23

  if ( a4 >= 3u )
  {
    __break(0x5512u);
    return reg_propagate_mas_chan_list_and_fill_legacy_list(a1, a2, a3);
  }
  v15 = a1 + 90112;
  v16 = *(_BYTE *)(a1 + 91128 + a4) == 1;
  *(_BYTE *)(a1 + a4 + 91092) = 1;
  if ( v16 )
  {
    *(_BYTE *)(a1 + 91128 + a4) = 0;
    *(_DWORD *)(a1 + 91112) = 4;
    *(_BYTE *)(a1 + 91165) = 1;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: new user country is set",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "reg_set_socpriv_vars",
      v12,
      v13);
LABEL_12:
    reg_run_11d_state_machine(a3);
    return result;
  }
  if ( *(_BYTE *)(a1 + 91131 + a4) == 1 )
  {
    *(_BYTE *)(a1 + 91131 + a4) = 0;
    *(_DWORD *)(a1 + 91112) = 4;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: new init country is set",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "reg_set_socpriv_vars",
      v12,
      v13);
    return result;
  }
  if ( *(_BYTE *)(a1 + 91134 + a4) == 1 )
  {
    *(_BYTE *)(a1 + 91134 + a4) = 0;
    v18 = 5;
LABEL_11:
    *(_DWORD *)(a1 + 91112) = v18;
    *(_BYTE *)(a1 + 91165) = 0;
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a1 + 91137 + a4) == 1 )
  {
    *(_BYTE *)(a1 + 91137 + a4) = 0;
    v18 = 2;
    goto LABEL_11;
  }
  if ( !*(_DWORD *)(a1 + 91112) && *(unsigned __int8 *)(a1 + 91098) == a4 + 1 )
    *(_DWORD *)(a1 + 91112) = 3;
  v21 = (_WORD *)(a1 + 30364LL * a4);
  qdf_mem_copy(v21 + 14802, a2 + 9, 3u);
  v21[14806] = a2[8];
  v21[14805] = a2[7];
  if ( *(_DWORD *)(v15 + 1000) == 3 )
  {
    qdf_mem_copy((void *)(a1 + 91102), a2 + 9, 3u);
    *(_WORD *)(v15 + 994) = a2[8];
    *(_WORD *)(v15 + 996) = a2[7];
    if ( (reg_is_world_alpha2(a2 + 9) & 1) != 0 )
    {
      *(_DWORD *)(v15 + 1000) = 2;
      goto LABEL_12;
    }
  }
  return result;
}

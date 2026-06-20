__int64 __fastcall wdi_event_sub(
        __int64 a1,
        char a2,
        __int64 a3,
        int a4,
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
  __int64 v14; // x8
  __int64 v15; // x10
  const char *v16; // x2
  __int64 result; // x0
  __int64 v18; // x10

  if ( a2 )
  {
    __break(0x5512u);
    JUMPOUT(0x5D9534);
  }
  v14 = *(_QWORD *)(a1 + 24);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 56)) == 0 )
  {
    v16 = "Invalid txrx_pdev or wdi_event_list in %s";
    goto LABEL_8;
  }
  if ( !a3 )
  {
    v16 = "Invalid callback in %s";
    goto LABEL_8;
  }
  if ( (unsigned int)(a4 - 306) <= 0xFFFFFFCD )
  {
    v16 = "Invalid event in %s";
LABEL_8:
    qdf_trace_msg(0x3Fu, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "wdi_event_sub", v12, v13);
    return 4294967274LL;
  }
  v18 = *(_QWORD *)(v15 + 8LL * (unsigned int)(a4 - 256));
  result = 0;
  if ( v18 )
  {
    *(_QWORD *)(a3 + 16) = v18;
    *(_QWORD *)(a3 + 24) = 0;
    *(_QWORD *)(v18 + 24) = a3;
  }
  else
  {
    *(_QWORD *)(a3 + 16) = 0;
    *(_QWORD *)(a3 + 24) = 0;
  }
  *(_QWORD *)(*(_QWORD *)(v14 + 56) + 8LL * (unsigned int)(a4 - 256)) = a3;
  return result;
}

__int64 __fastcall cds_set_ac_specs_params(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x10
  __int64 v17; // x11
  int v18; // w9
  __int64 v19; // x10
  __int64 v20; // x8

  v11 = gp_cds_context;
  if ( !gp_cds_context )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: cds context pointer is null (via %s)",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "__cds_get_context",
             "cds_set_ac_specs_params",
             v9,
             v10);
  v13 = *(_QWORD *)(gp_cds_context + 160);
  v12 = *(_QWORD *)(gp_cds_context + 168);
  *(_DWORD *)(result + 56) = *(_DWORD *)(gp_cds_context + 176);
  *(_QWORD *)(result + 40) = v13;
  *(_QWORD *)(result + 48) = v12;
  v14 = *(_QWORD *)(v11 + 188);
  v15 = *(_QWORD *)(v11 + 180);
  *(_DWORD *)(result + 76) = *(_DWORD *)(v11 + 196);
  *(_QWORD *)(result + 68) = v14;
  *(_QWORD *)(result + 60) = v15;
  v17 = *(_QWORD *)(v11 + 200);
  v16 = *(_QWORD *)(v11 + 208);
  *(_DWORD *)(result + 96) = *(_DWORD *)(v11 + 216);
  *(_QWORD *)(result + 80) = v17;
  *(_QWORD *)(result + 88) = v16;
  v18 = *(_DWORD *)(v11 + 236);
  v19 = *(_QWORD *)(v11 + 228);
  v20 = *(_QWORD *)(v11 + 220);
  *(_DWORD *)(result + 116) = v18;
  *(_QWORD *)(result + 108) = v19;
  *(_QWORD *)(result + 100) = v20;
  return result;
}

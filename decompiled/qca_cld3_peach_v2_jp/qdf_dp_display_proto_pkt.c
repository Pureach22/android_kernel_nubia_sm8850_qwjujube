__int64 __fastcall qdf_dp_display_proto_pkt(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  int v7; // w21
  unsigned int v8; // w19
  unsigned int v9; // w21
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x10
  _QWORD v30[12]; // [xsp+50h] [xbp-70h] BYREF
  int v31; // [xsp+B0h] [xbp-10h]
  __int64 v32; // [xsp+B8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  qdf_mem_set(v30, 0x64u, 0);
  qdf_dp_trace_fill_meta_str(v30, 100, a2, a4, a1);
  v7 = *(unsigned __int8 *)(a1 + 21);
  v8 = *(unsigned __int8 *)(a1 + 25);
  if ( v7 == 1 )
  {
    v9 = *(unsigned __int16 *)(a1 + 33);
    v10 = qdf_dp_subtype_to_str(*(unsigned __int8 *)(a1 + 27));
    result = qdf_trace_msg(
               0x38u,
               8u,
               "%s [%d] [%d] [%s] SA: %02x:%02x:%02x:**:**:%02x %s DA:%02x:%02x:%02x:**:**:%02x proto priv data = %08x",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v30,
               v8,
               v9,
               v10,
               *(unsigned __int8 *)(a1 + 9),
               *(unsigned __int8 *)(a1 + 10),
               *(unsigned __int8 *)(a1 + 11),
               *(unsigned __int8 *)(a1 + 14),
               " <-- ",
               *(unsigned __int8 *)(a1 + 15),
               *(unsigned __int8 *)(a1 + 16),
               *(unsigned __int8 *)(a1 + 17),
               *(unsigned __int8 *)(a1 + 20),
               *(_DWORD *)(a1 + 29));
  }
  else
  {
    v20 = qdf_dp_subtype_to_str(*(unsigned __int8 *)(a1 + 27));
    v29 = "invalid";
    if ( !v7 )
      v29 = " --> ";
    result = qdf_trace_msg(
               0x38u,
               8u,
               "%s [%d] [%s] SA: %02x:%02x:%02x:**:**:%02x %s DA:%02x:%02x:%02x:**:**:%02x proto priv data = %08x",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v30,
               v8,
               v20,
               *(unsigned __int8 *)(a1 + 9),
               *(unsigned __int8 *)(a1 + 10),
               *(unsigned __int8 *)(a1 + 11),
               *(unsigned __int8 *)(a1 + 14),
               v29,
               *(unsigned __int8 *)(a1 + 15),
               *(unsigned __int8 *)(a1 + 16),
               *(unsigned __int8 *)(a1 + 17),
               *(unsigned __int8 *)(a1 + 20),
               *(_DWORD *)(a1 + 29));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

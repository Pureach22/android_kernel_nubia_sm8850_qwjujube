__int64 __fastcall scheduler_register_module(__int64 a1, __int64 a2)
{
  unsigned int v3; // w21
  __int64 context; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  unsigned __int64 v23; // x8

  v3 = a1;
  context = scheduler_get_context(a1);
  qdf_trace_msg(0x4Au, 8u, "%s: Enter", v5, v6, v7, v8, v9, v10, v11, v12, "scheduler_register_module");
  if ( !context )
    return 16;
  v21 = *(unsigned __int8 *)(context + 680);
  if ( v21 >= 6 )
  {
    qdf_trace_msg(
      0x4Au,
      2u,
      "%s: Already registered max %d no of message queues",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "scheduler_register_module",
      6);
    return 16;
  }
  if ( v3 >= 0xA7
    || (*(_BYTE *)(context + v3 + 288) = v21, *(unsigned __int8 *)(context + 680) > 5uLL)
    || (*(_DWORD *)(context + 48LL * *(unsigned __int8 *)(context + 680) + 40) = v3,
        v23 = *(unsigned __int8 *)(context + 680),
        v23 > 5) )
  {
    __break(0x5512u);
    JUMPOUT(0x18ADC4);
  }
  *(_QWORD *)(context + 8 * v23 + 456) = a2;
  ++*(_BYTE *)(context + 680);
  qdf_trace_msg(0x4Au, 8u, "%s: Exit", v13, v14, v15, v16, v17, v18, v19, v20, "scheduler_register_module");
  return 0;
}

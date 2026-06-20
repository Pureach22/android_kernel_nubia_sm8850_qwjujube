__int64 __fastcall target_if_disa_register_ev_handlers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x0
  unsigned int v11; // w19
  const char *v12; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    if ( !(unsigned int)wmi_unified_register_event(v10, 173, (__int64)target_if_encrypt_decrypt_event_handler) )
      return 0;
    v11 = 16;
    v12 = "%s: Failed to register Scan match event cb";
  }
  else
  {
    v11 = 4;
    v12 = "%s: Invalid wmi handle";
  }
  qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_disa_register_ev_handlers");
  return v11;
}

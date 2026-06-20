__int64 __fastcall target_if_crypto_set_ltf_keyseed(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  const char *v20; // x4

  if ( !a1 )
  {
    v20 = "psoc";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 || !*(_QWORD *)(v9 + 16) )
  {
    v20 = "wmi_handle";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, "%s: %s is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_crypto_set_ltf_keyseed", v20);
    return 4;
  }
  result = wmi_send_vdev_set_ltf_key_seed_cmd();
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: set LTF keyseed failed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_crypto_set_ltf_keyseed");
    return v19;
  }
  return result;
}

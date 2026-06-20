__int64 __fastcall tgt_disa_encrypt_decrypt_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_disa_encrypt_decrypt_req");
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(wlan_objmgr_psoc_get_comp_private_obj(a1, 0x15u) + 8);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != -126869082 )
      __break(0x8228u);
    v21 = v12(a1, a2);
  }
  else
  {
    v21 = 16;
  }
  qdf_trace_msg(0x5Cu, 8u, "%s: exit", v13, v14, v15, v16, v17, v18, v19, v20, "tgt_disa_encrypt_decrypt_req");
  return v21;
}

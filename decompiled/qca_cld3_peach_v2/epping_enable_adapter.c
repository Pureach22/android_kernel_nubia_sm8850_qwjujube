__int64 __fastcall epping_enable_adapter(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x19
  __int64 result; // x0
  const char *v10; // x2
  __int64 v11; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = g_epping_ctx;
  WORD2(v11) = 0;
  LODWORD(v11) = 0;
  if ( !g_epping_ctx )
  {
    v10 = "epping context is NULL";
    goto LABEL_5;
  }
  epping_get_dummy_mac_addr((__int64)&v11);
  result = epping_add_adapter(v8, &v11, 0, 1);
  *(_QWORD *)(v8 + 48) = result;
  if ( !result )
  {
    v10 = "epping add adapter failed";
LABEL_5:
    result = qdf_trace_msg(0x33u, 1u, v10, a1, a2, a3, a4, a5, a6, a7, a8, v11, v12);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

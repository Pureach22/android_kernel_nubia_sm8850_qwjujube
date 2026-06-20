__int64 __fastcall target_if_request_ml_link_state_info(
        __int64 a1,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 result; // x0
  const char *v13; // x2
  char v14; // [xsp+0h] [xbp-10h] BYREF
  int v15; // [xsp+1h] [xbp-Fh] BYREF
  __int16 v16; // [xsp+5h] [xbp-Bh]
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15 = 0;
  if ( !a1 )
  {
    v13 = "%s: null pdev";
    goto LABEL_8;
  }
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v13 = "%s: null wmi handle";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_request_ml_link_state_info");
    result = 29;
    goto LABEL_9;
  }
  if ( !a2 )
  {
    v13 = "%s: cmd is null";
    goto LABEL_8;
  }
  v14 = *a2;
  qdf_mem_copy(&v15, a2 + 1, 6u);
  result = wmi_send_mlo_link_state_request_cmd(v11, &v14);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

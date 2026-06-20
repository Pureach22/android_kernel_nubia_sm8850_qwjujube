__int64 __fastcall ucfg_tdls_responder(
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
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 result; // x0
  unsigned int v13; // w19
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v16)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v17)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = nullptr;
  v17 = nullptr;
  v14 = 0;
  v15 = 0;
  if ( !a1 || !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0, 2u, "%s: invalid input %pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_responder", a1);
    goto LABEL_7;
  }
  v10 = _qdf_mem_malloc(0x10u, "ucfg_tdls_responder", 988);
  if ( !v10 )
  {
LABEL_7:
    result = 29;
    goto LABEL_8;
  }
  v11 = v10;
  *(_BYTE *)(v10 + 14) = *(_BYTE *)(a1 + 14);
  *(_QWORD *)v10 = *(_QWORD *)a1;
  qdf_mem_copy((void *)(v10 + 8), (const void *)(a1 + 8), 6u);
  v15 = v11;
  v16 = tdls_process_cmd;
  v17 = ucfg_tdls_post_msg_flush_cb;
  LOWORD(v14) = 11;
  result = scheduler_post_message_debug(0x33u, 0, 72, (unsigned __int16 *)&v14, 0x3EAu, (__int64)"ucfg_tdls_responder");
  if ( (_DWORD)result )
  {
    v13 = result;
    _qdf_mem_free(v11);
    result = v13;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}

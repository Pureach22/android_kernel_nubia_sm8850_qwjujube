__int64 __fastcall ce_send_cb_register(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 (*v4)(void); // x8

  if ( !a1 )
    return qdf_trace_msg(61, 2, "%s: Error CE state = NULL", "ce_send_cb_register");
  v3 = *a1;
  if ( !*a1 )
    return qdf_trace_msg(61, 2, "%s: Error HIF state = NULL", "ce_send_cb_register");
  a1[9] = a2;
  a1[10] = a3;
  v4 = *(__int64 (**)(void))(*(_QWORD *)(v3 + 30696) + 104LL);
  if ( *((_DWORD *)v4 - 1) != -1108450135 )
    __break(0x8228u);
  return v4();
}

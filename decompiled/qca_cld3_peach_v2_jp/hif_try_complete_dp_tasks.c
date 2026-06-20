__int64 __fastcall hif_try_complete_dp_tasks(__int64 a1)
{
  int v2; // w19
  int v3; // w24
  int v4; // w23
  __int64 result; // x0

  v2 = 0;
  v3 = 25;
  v4 = *(_DWORD *)(a1 + 676);
  if ( v4 )
  {
LABEL_3:
    while ( v3 )
    {
      qdf_trace_msg(61, 5, "%s: waiting for grp tasklets %d work %d", "hif_try_complete_dp_tasks", v4, v2);
      msleep(10);
      --v3;
      v4 = *(_DWORD *)(a1 + 676);
      if ( !v4 )
        goto LABEL_2;
    }
    qdf_trace_msg(61, 2, "%s: pending grp tasklets %d work %d", "hif_try_complete_dp_tasks", v4, v2);
    return 5;
  }
  else
  {
LABEL_2:
    result = hal_get_reg_write_pending_work(*(_QWORD *)(a1 + 2560));
    v2 = result;
    if ( (_DWORD)result )
      goto LABEL_3;
  }
  return result;
}

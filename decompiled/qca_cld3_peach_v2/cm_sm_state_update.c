_DWORD *__fastcall cm_sm_state_update(
        _DWORD *result,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v12; // x20

  if ( result )
  {
    if ( a2 > 4 )
    {
      v12 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d mlme state (%d) is invalid",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "cm_set_state",
        *(unsigned __int8 *)(*(_QWORD *)result + 168LL),
        a2);
      result = v12;
    }
    else
    {
      result[20] = a2;
    }
    if ( a3 - 6 > 8 )
      return (_DWORD *)qdf_trace_msg(
                         0x68u,
                         2u,
                         "%s: vdev %d mlme sub state (%d) is invalid",
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11,
                         "cm_set_substate",
                         *(unsigned __int8 *)(*(_QWORD *)result + 168LL),
                         a3);
    else
      result[21] = a3;
  }
  return result;
}

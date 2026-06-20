_DWORD *__fastcall cm_set_substate(
        _DWORD *result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a2 - 6 > 8 )
    return (_DWORD *)qdf_trace_msg(
                       0x68u,
                       2u,
                       "%s: vdev %d mlme sub state (%d) is invalid",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "cm_set_substate",
                       *(unsigned __int8 *)(*(_QWORD *)result + 168LL),
                       a2,
                       v10,
                       v11);
  result[21] = a2;
  return result;
}

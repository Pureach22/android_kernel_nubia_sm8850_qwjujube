__int64 __fastcall cm_bearer_switch_resp(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: Continue connect after bearer switch %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "cm_bearer_switch_resp",
    (unsigned __int8)a2,
    a3,
    a4);
  return cm_cont_connect_for_event(a1, a2, a3, 0x26u);
}

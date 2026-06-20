__int64 __fastcall target_if_crypto_vdev_set_param(
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
  __int64 v12; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v12 = *(_QWORD *)(a1 + 2800)) != 0 && *(_QWORD *)(v12 + 16) )
  {
    if ( a2 < 6 )
    {
      result = wmi_unified_vdev_set_param_send();
      goto LABEL_8;
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev_id: %d is invalid, reject the req: param id %d val %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_crypto_vdev_set_param",
      a2,
      a3,
      a4);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_crypto_vdev_set_param");
  }
  result = 4;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 sub_7108()
{
  __asm { STZG            X30, [SP,#arg_B10] }
  return qcom_notify_ssr_clients();
}

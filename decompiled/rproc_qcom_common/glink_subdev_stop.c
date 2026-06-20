__int64 __fastcall glink_subdev_stop(__int64 result, char a2, __int64 a3)
{
  _QWORD *v3; // x19
  const char *v4; // x3
  __int64 v5; // x0

  if ( *(_QWORD *)(result + 72) )
  {
    v3 = (_QWORD *)result;
    if ( (a2 & 1) != 0 )
      v4 = "crash stop";
    else
      v4 = "stop";
    if ( (unsigned int)srcu_notifier_chain_unregister(*(_QWORD *)(result + 104), result + 80, a3, v4) )
      dev_err(v3[7], "Error in unregistering notifier\n");
    v5 = v3[9];
    v3[13] = 0;
    result = qcom_glink_smem_unregister(v5);
    v3[9] = 0;
  }
  return result;
}

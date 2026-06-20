_QWORD *__fastcall target_if_nan_register_tx_ops(_QWORD *result)
{
  *result = target_if_nan_discovery_req;
  result[1] = target_if_nan_datapath_req;
  return result;
}

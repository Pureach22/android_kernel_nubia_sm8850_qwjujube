__int64 __fastcall hdd_set_ap_ops(__int64 result)
{
  *(_QWORD *)(result + 8) = &net_ops_struct;
  return result;
}

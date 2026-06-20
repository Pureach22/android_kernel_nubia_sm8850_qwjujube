__int64 __fastcall txn_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  int txn_id; // w0

  txn_id = qcom_sysmon_get_txn_id(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 1152LL));
  return (int)sysfs_emit(a3, "%u\n", txn_id);
}

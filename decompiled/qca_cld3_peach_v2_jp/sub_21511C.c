__int64 sub_21511C()
{
  __int64 v0; // x13
  __int64 v1; // d13
  __int64 v2; // d27

  *(_QWORD *)(v0 - 504) = v1;
  *(_QWORD *)(v0 - 496) = v2;
  return wmi_offchan_data_tx_cmd_send();
}

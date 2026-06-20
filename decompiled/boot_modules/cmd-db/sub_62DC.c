__int64 sub_62DC()
{
  __int64 v0; // x10
  __int64 v1; // x15
  __int64 v2; // x16

  *(_QWORD *)(v1 + 200) = v0;
  *(_QWORD *)(v1 + 208) = v2;
  return cmd_db_read_slave_id();
}

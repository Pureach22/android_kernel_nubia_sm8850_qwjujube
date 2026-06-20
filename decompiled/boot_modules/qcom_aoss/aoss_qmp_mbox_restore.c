__int64 __fastcall aoss_qmp_mbox_restore(__int64 a1)
{
  int v2; // w0

  v2 = qmp_open(*(_QWORD *)(a1 + 152));
  if ( v2 < 0 )
    dev_err(a1, "QMP restore failed, ret = %d\n", v2);
  return 0;
}

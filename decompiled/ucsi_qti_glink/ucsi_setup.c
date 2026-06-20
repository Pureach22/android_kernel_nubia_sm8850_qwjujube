__int64 __fastcall ucsi_setup(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned int v3; // w20

  if ( a1[1] )
  {
    dev_err(*a1, "ucsi is not NULL\n");
    return (unsigned int)-22;
  }
  mutex_lock(a1 + 28);
  v2 = ucsi_create(*a1, ucsi_qti_ops);
  a1[1] = v2;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    v3 = v2;
    dev_err(*a1, "ucsi_create failed rc=%d\n", v2);
LABEL_9:
    a1[1] = 0;
    goto LABEL_4;
  }
  ucsi_set_drvdata();
  v3 = ucsi_register(a1[1]);
  if ( v3 )
  {
    dev_err(*a1, "ucsi_register failed rc=%d\n", v3);
    ucsi_destroy(a1[1]);
    goto LABEL_9;
  }
LABEL_4:
  mutex_unlock(a1 + 28);
  return v3;
}

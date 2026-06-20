__int64 __fastcall kgsl_free_snapshot(_QWORD *a1)
{
  _QWORD *v2; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x22
  __int64 v5; // x0

  v2 = (_QWORD *)a1[31];
  wait_for_completion(a1 + 24);
  v3 = (_QWORD *)a1[16];
  if ( v3 != a1 + 16 )
  {
    do
    {
      v4 = (_QWORD *)*v3;
      kgsl_snapshot_put_object(v3 - 5);
      v3 = v4;
    }
    while ( v4 != a1 + 16 );
  }
  v5 = a1[14];
  if ( v5 )
    vfree(v5);
  kfree(a1);
  return dev_err(*v2, "snapshot: objects released\n");
}

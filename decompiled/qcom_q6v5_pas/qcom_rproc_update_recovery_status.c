__int64 __fastcall qcom_rproc_update_recovery_status(__int64 result, char a2, char a3)
{
  __int64 v3; // x21
  __int64 v4; // x20
  char v6; // w22
  void *v7; // x8

  if ( result )
  {
    v3 = *(_QWORD *)(result + 40);
    v4 = result;
    if ( (a3 & 1) != 0 )
    {
      v6 = a2;
      mutex_lock(result + 984);
      a2 = v6;
      result = v4;
    }
    if ( (a2 & 1) != 0 )
    {
      *(_BYTE *)(v3 + 785) = *(_BYTE *)(result + 1204);
      v7 = &unk_ADB1;
      *(_BYTE *)(result + 1204) = 0;
    }
    else
    {
      *(_BYTE *)(result + 1204) = *(_BYTE *)(v3 + 785);
      v7 = &unk_ACC1;
    }
    result = printk(v7, *(_QWORD *)(result + 24));
    if ( (a3 & 1) != 0 )
      return mutex_unlock(v4 + 984);
  }
  return result;
}

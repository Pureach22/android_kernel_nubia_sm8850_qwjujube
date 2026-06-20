__int64 __fastcall mhi_update_transfer_state(_QWORD *a1, int a2)
{
  __int64 v2; // x23
  __int64 v3; // x21
  __int64 v6; // x19
  unsigned int updated; // w0
  __int64 v8; // x22
  unsigned int v9; // w23

  v2 = a1[4];
  v3 = a1[2];
  if ( v2 )
  {
    v6 = v2 + 288;
    mutex_lock(v2 + 288);
    updated = mhi_update_channel_state(v3, v2, a2);
    if ( updated )
      goto LABEL_6;
    mutex_unlock(v2 + 288);
  }
  v8 = a1[3];
  if ( !v8 )
    return 0;
  v6 = v8 + 288;
  mutex_lock(v8 + 288);
  updated = mhi_update_channel_state(v3, v8, a2);
LABEL_6:
  v9 = updated;
  mutex_unlock(v6);
  return v9;
}

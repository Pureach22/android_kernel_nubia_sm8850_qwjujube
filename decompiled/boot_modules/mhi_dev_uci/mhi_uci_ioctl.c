__int64 __fastcall mhi_uci_ioctl(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v6; // x19
  __int64 v7; // x21
  __int64 v8; // x20

  v3 = *(_QWORD *)(a1 + 32);
  v6 = *(_QWORD *)(v3 + 32);
  mutex_lock(v3 + 48);
  if ( a2 == 21525 )
  {
    v7 = v3 + 232;
    raw_spin_lock_bh(v3 + 232);
    v8 = *(unsigned int *)(v3 + 344);
LABEL_3:
    raw_spin_unlock_bh(v7);
    goto LABEL_8;
  }
  if ( *(_BYTE *)(v3 + 340) != 1 )
  {
    v8 = -515;
    goto LABEL_8;
  }
  v8 = mhi_device_ioctl(v6, a2, a3);
  if ( !v8 )
  {
    v7 = v3 + 232;
    raw_spin_lock_bh(v3 + 232);
    *(_DWORD *)(v3 + 344) = *(_DWORD *)(v6 + 976);
    goto LABEL_3;
  }
LABEL_8:
  mutex_unlock(v3 + 48);
  return v8;
}

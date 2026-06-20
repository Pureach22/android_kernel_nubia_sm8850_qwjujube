__int64 __fastcall qmp_mbox_of_xlate(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x20

  if ( *(_DWORD *)(a1 + 140) < *(_DWORD *)(a1 + 24) && *(_QWORD *)(a1 + 16) )
  {
    mutex_lock(a1 + 256);
    v2 = *(_DWORD *)(a1 + 140);
    v3 = *(_QWORD *)(a1 + 16) + 248LL * v2;
    *(_DWORD *)(a1 + 140) = v2 + 1;
    mutex_unlock(a1 + 256);
  }
  else
  {
    printk(&unk_844E, "qmp_mbox_of_xlate");
    return -12;
  }
  return v3;
}

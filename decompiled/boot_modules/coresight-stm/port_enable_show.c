__int64 __fastcall port_enable_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  unsigned int v5; // w21

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(v4 + 24) + 968LL) )
  {
    raw_spin_lock(v4 + 32);
    v5 = *(_DWORD *)(*(_QWORD *)v4 + 3584LL);
    raw_spin_unlock(v4 + 32);
  }
  else
  {
    v5 = *(_DWORD *)(v4 + 152);
  }
  return (int)scnprintf(a3, 4096, "%#lx\n", v5);
}

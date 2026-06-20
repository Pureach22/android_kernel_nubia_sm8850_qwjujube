__int64 __fastcall ce_recv_entries_avail(__int64 a1)
{
  _DWORD *v1; // x20
  unsigned int v3; // w21
  int v4; // w22

  v1 = *(_DWORD **)(a1 + 144);
  v3 = v1[1];
  raw_spin_lock(a1 + 168);
  v4 = v1[2];
  LODWORD(v1) = v1[3];
  raw_spin_unlock(a1 + 168);
  return (v4 + ~(_DWORD)v1) & v3;
}

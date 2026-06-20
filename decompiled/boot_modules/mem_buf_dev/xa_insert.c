__int64 __fastcall xa_insert(__int64 a1, __int64 a2)
{
  raw_spin_lock(&vmperm_xa);
  LODWORD(a2) = _xa_insert(&vmperm_xa, a1, a2, 3264);
  raw_spin_unlock(&vmperm_xa);
  return (unsigned int)a2;
}

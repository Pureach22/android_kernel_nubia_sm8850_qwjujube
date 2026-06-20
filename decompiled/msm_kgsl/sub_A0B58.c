_QWORD *__usercall sub_A0B58@<X0>(_QWORD *a1@<X8>)
{
  atomic_ullong *v1; // x9
  atomic_ullong *v2; // x22
  atomic_ullong *v3; // x25

  atomic_exchange(v1, (unsigned __int64)a1);
  atomic_exchange(v2, (unsigned __int64)a1);
  atomic_exchange(v1, (unsigned __int64)a1);
  atomic_exchange(v3, (unsigned __int64)a1);
  return adreno_drawctxt_dump(a1);
}

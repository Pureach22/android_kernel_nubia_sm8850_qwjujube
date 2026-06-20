__int64 __usercall sub_187CEC@<X0>(unsigned __int64 *a1@<X8>)
{
  unsigned __int64 v1; // x14

  atomic_store(v1, a1);
  return qdf_flex_mem_free();
}

__int64 __fastcall dp_soc_set_qref_debug_list(__int64 result)
{
  __int64 v1; // x22
  _QWORD *v2; // x19

  v1 = *(unsigned int *)(*(_QWORD *)(result + 40) + 132LL);
  if ( (_DWORD)v1 )
  {
    v2 = (_QWORD *)result;
    *(_QWORD *)(result + 20192) = _qdf_mem_malloc(24 * v1, "dp_soc_set_qref_debug_list", 15330);
    v2[2525] = _qdf_mem_malloc(24 * v1, "dp_soc_set_qref_debug_list", 15334);
    v2[2526] = _qdf_mem_malloc(56 * v1, "dp_soc_set_qref_debug_list", 15338);
    result = _qdf_mem_malloc(56 * v1, "dp_soc_set_qref_debug_list", 15342);
    v2[2527] = result;
  }
  return result;
}
